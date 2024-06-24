#pragma once

#include <iostream>
#include <string>
#include <new>
#include <algorithm> // For std::copy

using namespace std;

class Vector
{
public:
    // Default constructor
    Vector() : size(0), data(nullptr), last_index(0), name("Default")
    {
        cout << "_" << name << " constructor." << endl;
    }

    // Initialized constructor
    Vector(int size) : size(size), data(new int[size]), last_index(0), name("Initialized")
    {
        cout << "_" << name << " constructor." << endl;
    }

    // Constructor using nothrow_t
    Vector(size_t newSize, std::nothrow_t) : size(0), data(nullptr), last_index(0), name("NoThrow")
    {
        Resize(newSize, std::nothrow);
        cout << "_" << name << " constructor." << endl;
    }

    // Copy constructor
    Vector(const Vector& other) : size(other.size), data(new int[other.size]), last_index(other.last_index), name("Copy")
    {
        std::copy(other.data, other.data + other.size, data);
        cout << "_" << name << " constructor." << endl;
    }

    // Assignment operator
    Vector& operator=(const Vector& other)
    {
        if (this != &other)
        {
            delete[] data;

            size = other.size;
            data = new int[size];
            std::copy(other.data, other.data + other.size, data);
            last_index = other.last_index;
            name = "Assignment";

            cout << "_" << name << " operator." << endl;
        }
        else
        {
            cout << "Error. You are trying to assign the same object." << endl;
        }

        return *this;
    }

    // Destructor
    ~Vector()
    {
        delete[] data;
        cout << "~" << name << " destructor." << endl;
    }

    // Operator []
    int operator[](int index) const
    {
        return data[index];
    }

    // Operator ADD
    Vector operator+(const Vector& other) const
    {
        Vector result(size + other.size);

        std::copy(data, data + size, result.data);
        std::copy(other.data, other.data + other.size, result.data + size);

        return result;
    }

    // Add new value to array
    void PushBack(const int& item)
    {
        if ((last_index + 1) <= size)
        {
            data[last_index] = item;
            cout << "Added new value: " << item << endl;
            last_index += 1;
        }
        else
        {
            cout << "Error. Array is out of size to add new value: " << item << endl;
        }
    }

    // Print vector array
    void Print() const
    {
        cout << "\nPrint vector '" << name << "' array:" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << "Element: " << i << ", value: " << data[i] << "." << endl;
        }
        cout << endl;
    }

    // Get size from array
    int GetSize() const
    {
        return size;
    }

    // Resize function using nothrow
    void Resize(size_t newSize, std::nothrow_t)
    {
        int* newData = new (std::nothrow) int[newSize];

        if (newData == nullptr)
        {
            std::cerr << "Failed memory allocation." << std::endl;
            return;
        }

        // Copy data to new array
        std::copy(data, data + std::min(newSize, static_cast<size_t>(size)), newData);
        delete[] data;
        data = newData;
        size = newSize;
        last_index = (newSize < last_index) ? newSize : last_index;
    }

    // Simplified Iterator Implementation
    class Iterator
    {
    public:
        Iterator(int* ptr) : m_ptr(ptr) {}

        int& operator*() { return *m_ptr; }

        Iterator& operator++()
        {
            m_ptr++;
            return *this;
        }

        bool operator!=(const Iterator& other) const
        {
            return m_ptr != other.m_ptr;
        }

    private:
        int* m_ptr;
    };

    Iterator begin() { return Iterator(data); }
    Iterator end() { return Iterator(data + size); }

private:
    int size;
    int last_index;
    int* data;
    std::string name;
};