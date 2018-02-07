//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//
#include <iostream>
#include <stdlib.h>
#include <limits.h>

//////////////////////////////////////////////////////////////
//s
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING

#include <iostream>

using namespace std;

int greatestCommonDenominator(const int, const int);

int leastCommonMultiple(const int, const int);

#endif

//////////////////////////////////////////////////////////////
int GCD = 0;
int LCM = 0;
bool on = true;

int greatestCommonDenominator(const int a, const int b) {
    if (on) {
        if (a < 1 || b < 1) {
            return -1;
        } else {
            on = false;
        }
    }

    if (b != 0) {
        return greatestCommonDenominator(b, a % b);
    } else {
        GCD = a;
        return a;
    }
}

int leastCommonMultiple(const int a, const int b) {
    if (a < 1 || b < 1) {
        return -1;
    } else if ((INT_MAX/b) < a/greatestCommonDenominator(a, b)) {
        return -2;
    } else {
        greatestCommonDenominator(a, b);
        LCM = (a / GCD) * b;
        return LCM;
    }
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

int main(const int argc, const char *const argv[]) {

    if (argc < 3) {
        cerr << "Error: Usage: " << argv[0] << "<num1> <num2>; exiting" << endl;
        return -1;
    }

    int gcd = greatestCommonDenominator(atoi(argv[1]), atoi(argv[2]));
    if (gcd < 0)
        cerr << "Unable to compute GCD(" << argv[1] << "," << argv[2] << ")" << endl;
    else
        cout << "GCD(" << argv[1] << "," << argv[2] << ") = " << gcd << endl;

    int lcm = leastCommonMultiple(atoi(argv[1]), atoi(argv[2]));
    if (lcm < 0)
        cerr << "Unable to compute LCM(" << argv[1] << "," << argv[2] << ")" << endl;
    else
        cout << "LCM(" << argv[1] << "," << argv[2] << ") = " << lcm << endl;

    return 0;
}

#endif
