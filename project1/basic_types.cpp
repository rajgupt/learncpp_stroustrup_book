#include <iostream>

using namespace std;


// auto keyword uses
void test_basic_types()
{
    auto i=0;
    cout << i << endl;
    return;
}

// auto usage in loops
void auto_in_loops()
{
    int v[] = {1,2,3,4};
    for(auto x: v)
        cout << x << endl;

    // array defination on the go
    for(auto x: {4,3,2,1})
        cout << x << endl;
    return;
}

// change the array element in a loop
void change_in_loop()
{
    int v[] = {1,2,3,4};
    for (auto& x: v)
        ++x;

    for(auto x: v)
        cout << x << ", "; // 2, 3, 4, 5
    return;
}


int count_char(char* str, char ch)
{
    if (str == nullptr) return 0;
    int count = 0;
    while(*str != 0) // char array ends with ASC 0
    {
        if (*str == ch)
            ++count;
        ++str; // move to next char
    }
    return count;
}

void test_count_char()
{
    cout << "number of chars: " << count_char("rajat", 'a') << endl;
    cout << "number of chars: " << count_char("rajat", 'r') << endl;
    cout << "number of chars: " << count_char("rajat", 'z') << endl;
    return;
}
