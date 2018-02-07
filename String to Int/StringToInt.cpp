//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//
#include <limits.h>
#include <cmath>

//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING

#include <iostream>

using namespace std;
#endif

//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove
// Replace "..." in bisectionHelper() with any parameter(s)
// you need to ensure termination when precision and
// minIntervalSize are too tightly specified.
//

bool stringToInt(const char input[], int &value);

//////////////////////////////////////////////////////////////
//
// Your code here ...
//
// Return std::numeric_limits<float>::quiet_NaN() (comes from
// <limits>) if cannot compute the root for some reason
//
bool stringToInt(const char input[], int &value) {
    int number = 0;
    //partial solution on piazza
    //if positive
    if (input[0] == '+') {
        for (int x = 1; input[x] != 0; x++) {
            if (input[x] < 48 || input[x] > 57) {
                return false;
            }
            number = number * 10 + input[x] - 48;
        }
        value = number;
        if (value < 0) {
            return false;
        } else {
            return true;
        }
    }
        //if negative
    else if (input[0] == '-') {
        for (int x = 1; input[x] != 0; x++) {
            if (input[x] < 48 || input[x] > 57) {
                return false;
            }
            number = number * 10 + input[x] - 48;
        }
        number = (-1) * number;
        value = number;
        if (value > 0) {
            return false;
        } else {
            return true;
        }
    }

        //if there is no sign, assume to be positive
    else if (input[0] >= 48 || input[0] <= 57) {
        for (int x = 0; input[x] != 0; x++) {
            if (input[x] < 48 || input[x] > 57) {
                return false;
            }
            number = number * 10 + input[x] - 48;
        }
        value = number;
        if (value < 0) {
            return false;
        } else {
            return true;
        }
    }
    return false;
}

//////////////////////////////////////////////////////////////
//
// Test Driver
//
// Do not remove the #ifndef and its associated #endif
// This is required so that when you submit your code,
// this test driver will be ignored by Marmoset
//

#ifndef MARMOSET_TESTING

#define isNaN(X) (X != X)  // NaN is the only float that is not equal to itself

int main(const int argc, const char *const argv[]) {

    // Some test driver code here ....
    int argv1;

    if (argc < 2) {
        cerr << "Error: Usage: " << argv[0] << " <int>" << endl;
        return -1;
    }

    if (stringToInt(argv[1], argv1))
        cout << "argv[1] is an int with value: " << argv1 << endl;
    else
        cout << "argv[1] is not an int." << endl;
    return 0;
}

#endif
