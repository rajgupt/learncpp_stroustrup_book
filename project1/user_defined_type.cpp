
#include <iostream>
#include <type_traits>
#include <exception>
#include <stdexcept>

// User defined types


// 1. Classes
// 2. Enumerations


struct Vector{
    int sz;// number of elems
    double* elem; // pointer to elements
};

// Note: This is not the correct way to use vector
// example below is for understanding
void vector_init(Vector &v, int s)
{
    // define vector of 5 doubles
    v.elem = new double[s]; // allocate the 5 double space
    v.sz = s; // set size = 5
}

double read_and_sum(int s)
{
    Vector v;
    vector_init(v,s);

    double sum=0;

    for (auto i=0; i<s; i++)
        cin >> v.elem[i];

    for (auto i=0; i<s; i++)
        sum += v.elem[i];

    delete v.elem;

    return sum;
}


// Class implementation of Vector
// Advantage compared to struct:
// Encapsulates the data away from the user
// only the behavior is exposed
class Vector2 {
public:
    Vector2(int s) {
        elem = new double[s];
        sz = s;
    }
    double &operator[](int i) {
        // check out of bounds
        // check and report exception
        if (i < 0 || size() <= i ) throw std::out_of_range("Vector::operator[]");
        return elem[i];
    }
    int size() {
        return sz;
    }
    ~Vector2() { delete elem; } // destructor releases memory

    double read_and_sum()
    {
        double sum=0;

        for (auto i=0; i<sz; i++)
            cin >> elem[i];

        for (auto i=0; i<sz; i++)
            sum += elem[i];
        return sum;
    }

private:
    double* elem;
    int sz;
};

void test_struct_class()
{
    cout << "The sum is: " << read_and_sum(3) << endl;

    Vector2 v(3);
    cout << "The sum is: " << v.read_and_sum() << endl;

    // Exception handling with reported message
    try {
        cout << "Testing out of bounds" << v[3];
    }
    catch(out_of_range& e) {
        cerr << "Error " << e.what() << endl;
    }

    return;
}

// Enumerations
// Simple form of UDT for which we can enumerate the values

enum class colors {red, green, blue};
void test_enum()
{
    colors c1 = colors::red;
    cout << static_cast<int>(c1) << endl;
}

