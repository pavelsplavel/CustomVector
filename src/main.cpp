#include "CustomVector.h"
#include <iostream>

using namespace std;

int main()
{
    // std::nothrow constructor
    cout << "Creating vector_nothrow with size 5 using nothrow constructor" << endl;
    Vector vector_nothrow(5, std::nothrow);

    // Fill std::nothrow constructor
    for (int i = 0; i < vector_nothrow.GetSize(); i++)
    {
        vector_nothrow.PushBack(i + 1);
    }

    vector_nothrow.Print();

    // Default constructor
    Vector vector_default;

    // Initialized constructor
    Vector vector_init(3);

    // Fill array
    for (int i = 0; i < vector_init.GetSize(); i++)
    {
        vector_init.PushBack(i + 1);
    }

    // Print all elements from vector
    vector_init.Print();

    // Receive error when try push new element
    vector_init.PushBack(4);
    vector_init.PushBack(7);

    // Copy constructor
    Vector vector_copy(vector_init);

    // Print Vector copy constructor
    vector_copy.Print();

    // Overloaded assignment operator
    Vector vector_assign;
    vector_assign = vector_copy;

    // ERROR when trying add new value vector that was assigned
    vector_assign.PushBack(4);
    vector_assign.PushBack(5);

    // Print Vector copy constructor
    vector_assign.Print();

    // Print elements using []
    cout << "Printing using [] with object" << endl;
    for (size_t i = 0; i < vector_assign.GetSize(); i++)
    {
        cout << vector_assign[i] << endl;
    }

    // Add to objects
    Vector vector_sum;
    vector_sum = vector_assign + vector_init;

    // Print final result
    vector_sum.Print();

    // Test the Resize function
    cout << "Resizing vector_init to size 3 using nothrow" << endl;
    vector_init.Resize(3, std::nothrow);

    // Print the vector after resizing
    vector_init.Print();

    // Test resizing to a smaller size
    cout << "Resizing vector_init to size 2 using nothrow" << endl;
    vector_init.Resize(2, std::nothrow);

    // Print the vector after resizing
    vector_init.Print();

    // Demonstrate iteration using the custom iterator
    cout << "Iterating over vector_sum:" << endl;
    for (auto it = vector_sum.begin(); it != vector_sum.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    // Pause before exiting
    cout << "Press Enter to continue...";
    cin.ignore();

    return 0;
}