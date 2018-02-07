//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//
#include <stdlib.h>

//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING

#include <iostream>

using namespace std;

float NthRoot(const float S, const int N, const float precision);

#endif

//////////////////////////////////////////////////////////////
//
// Your code here ...
//  
// Return std::numeric_limits<float>::quiet_NaN() (comes from
// <limits>) if cannot compute the Nth root of S with
// precision.
//

//piazza Julien Parkin answer
#ifndef NAN
#define NAN (0.0 / 0.0)
#endif

float rootFuncAbs(float x) {
    do {
        x *= -1;
    } while (x < 0);
    return x;
}

float NthRoot(const float S, const int N, const float precision) {
    if (N % 2 == 0 && S < 0) {
        return NAN;
    } else if (N < 2) {
        return NAN;
    } else if (precision <= 0) {
        return NAN;
    }

    float ro = (float) N;
    float holder1 = 0;
    float holdNew = S / ro;
    float holder2 = 0;

    //calculate nthRoot and precision
    do {
        holder1 = holdNew;
        holder2 = holdNew;

        int x = 0;
        do{
            holder2 *= holder1;
            x++;
        } while(x < ro - 2);

        holdNew = (((ro - 1) / ro) * holder1) + (S / (ro * holder2));
    } while (rootFuncAbs(holder1 - holdNew) > precision);

    return holdNew;
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

    if (argc < 4) {
        cerr << "Error: Usage: " << argv[0] << " <number> <root> <precision>; exiting" << endl;
        return -1;
    }

    float root = NthRoot(atof(argv[1]), atoi(argv[2]), atof(argv[3]));
    if (isNaN(root))
        cerr << "Unable to compute " << argv[2] << "th root of " << argv[1] << " with precision " << argv[3] << endl;
    else
        cout << "Root(" << argv[1] << "," << argv[2] << ") = " << root << endl
             << "(with precision " << argv[3] << ")" << endl;

    return 0;
}

#endif