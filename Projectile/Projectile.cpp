//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <stdlib.h>
#include <math.h>

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

bool projectileDestination(const float h, const float v, const float m,
                           const float theta, const float d,
                           const float t, const float b, const float w,
                           float &destX, float &destY);

//////////////////////////////////////////////////////////////
//
// Your code here ...
//  
// Return std::numeric_limits<float>::quiet_NaN() (comes from
// <limits>) if cannot compute the root for some reason
//

bool projectileDestination(const float h, const float v, const float m,
                           const float theta, const float d,
                           const float t, const float b, const float w,
                           float &destX, float &destY) {
    const float g = 9.8;
    float angle = (theta * 3.141592653 / 180);
    float vX = v * cos(angle);
    float vY = v * sin(angle);
    float vFy;

    float xT = b / vX;
    float dstY = h + (vY * xT) - (4.9 * pow(xT, 2));

    float xT1 = (b + w) / vX;
    float dstY1 = h + (vY * xT1) - (4.9 * pow(xT1, 2));

    //error checks
    if (h < 0 || w <= 0 || v < 0 || m < 0 || b < 0) {
        return false;
    }
    //if velocity is zero, angle is 90 or 270
    if (v == 0 || theta == 90 || theta == 270) {
        destX = 0;
        destY = h;
        return true;
    }

    //if projectile is fired forwards
    //calculating the time required to reach delta ground
    vFy = sqrt((vY * vY) - (2 * g * -h));
    float t1 = (vFy + vY) / g;
    float xDist = vX * t1;

    //if the projectile hits the left side of the building
    if (dstY > 0 && dstY < t) {

        if (t > 0) {
            destX = b;
            destY = dstY;
            return true;
        }
    }
        //projectile hits the right side of the building
    else if (dstY1 < 0 && dstY1 > t) {
        destX = (b + w);
        destY = dstY1;
        return true;
    }

    //if projectile lands before the building or is launched backwards
    if (xDist > (b + w) || (xDist < b && xDist > 0) || (theta > 90 && theta < 270)) {
        destX = xDist;
        destY = 0;
        return true;
    }

    //if the projectile lands on the building
    if (xDist > b || xDist < (b + w)) { //took off the equals
        destX = vX * t1;
        destY = t;
        return true;
    }

    return true;
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



    float h = 50;
    float v = 18.4;
    float m = 1;
    float theta = 17.89;        // Angle in degrees; will need to be converted by function
    float d = 20;
    float t = 60;
    float b = 30;
    float w = 20;

    float hitsAtX;
    float hitsAtY;

    if (projectileDestination(h, v, m, theta, d, t, b, w, hitsAtX, hitsAtY))
        cout << "Projectile hit at (" << hitsAtX << ", " << hitsAtY << ")" << endl;
    else
        cout << "Unable to calculate where projectile hits." << endl;
    return 0;
}

#endif
