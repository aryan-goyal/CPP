//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <stdlib.h>
#include <limits>
//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING

#include <iostream>

using namespace std;


// Sample function for which you need to find the root

float f(const float x) {
    return 3.2 * x * x * x - 2.1 * x - 23.0;
}

#endif

//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove
// Replace "..." in bisectionHelper() with any parameter(s)
// you need to ensure termination when precision and
// minIntervalSize are too tightly specified.
//

float bisectionHelper(const float left, const float right,
                      const float precision, const float minIntervalSize, int bShit);

float bisection(const float left, const float right,
                const float precision, const float minIntervalSize);
float abs(float x);

//////////////////////////////////////////////////////////////
//
// Your code here ...
//
// Return std::numeric_limits<float>::quiet_NaN() (comes from
// <limits>) if cannot compute the root for some reason
//

float bisectionHelper(const float left, const float right,
                      const float precision, const float minIntervalSize, int bShit) {
    //if limit is reached then stop the program
    if (bShit > 5000) {
        return std::numeric_limits<float>::quiet_NaN();
    }
    float midPoint = (left + right) / 2;

    if (abs(f(midPoint)) <= precision) {
        return midPoint;
    }
    if (abs(right - left) <= minIntervalSize) {
        return midPoint;
    }
    if (f(midPoint) * f(right) > 0) {
        return bisectionHelper(left, midPoint, precision, minIntervalSize, ++bShit);
    } else {
        return bisectionHelper(midPoint, right, precision, minIntervalSize, ++bShit);
    }
}

float bisection(const float left, const float right,
                const float precision, const float minIntervalSize) {

    if (precision < 0) {
        return std::numeric_limits<float>::quiet_NaN();
    }
    if ((f(left) * f(right)) > 0) {
        return std::numeric_limits<float>::quiet_NaN();
    }
    if (minIntervalSize < 0) {
        return std::numeric_limits<float>::quiet_NaN();
    }
    if (left >= right) {
        return std::numeric_limits<float>::quiet_NaN();
    }
    if ((left != left) || (right != right)) {
        return std::numeric_limits<float>::quiet_NaN();
    }
    if (f(left) != f(left) || f(right) != f(right)) {
        return std::numeric_limits<float>::quiet_NaN();
    }

    return bisectionHelper(left, right, precision, minIntervalSize, 0);
}

float abs(float x){
    if (x < 0){
        return (-1)*x;
    }
    return x;
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

    cout << "bisection" << bisection(-10, 15, 0.5, 0.05) <<endl;

    return 0;
}

#endif
