//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <stdlib.h>
#include <cmath>
//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//


#ifndef MARMOSET_TESTING

#include <iostream>

using namespace std;
#endif

#define NaN std::numeric_limits<float>::quiet_NaN()
#define isNaN(X) (X != X) // NaN is the only float that is not equal to itself

//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove

bool hitTargetGivenVelocity(const float h, const float v, const float m,
                            const float d, const float t, const float b,
                            const float w, float &theta);

bool hitTargetGivenAngle(const float h, const float m, const float theta,
                         const float d, const float t, const float b,
                         const float w, float &v);

//////////////////////////////////////////////////////////////
bool hitTargetGivenVelocity(const float h, const float v, const float m,
                            const float d, const float t, const float b,
                            const float w, float &theta) {
    const float g = 9.8;

    //error checks
    if (h < 0 || w <= 0 || v <= 0 || m < 0 || b < 0) {
        return false;
    }

    //kinematics equation retrieved from the following website
    //http://board.flashkit.com/board/showthread.php?754442-Determining-fire-angle-to-hit-a-specific-point

    theta = atan(((pow(v, 2)) + sqrt((pow(v, 4)) - g * ((g*pow(d, 2)) + (2*(t-h) * (pow(v, 2))))))/((g*d)));
    theta = theta * (180/ 3.14);

    return true;
}

bool hitTargetGivenAngle(const float h, const float m, const float theta,
                         const float d, const float t, const float b,
                         const float w, float &v) {
    const float g = 9.8;

    //error checks
    if (h < 0 || w <= 0 || m < 0 || b < 0 || theta == 0 || theta == 90 || theta == 270) {
        return false;
    }

    //kinematics equation retrieved from the following website
    //https://physics.stackexchange.com/questions/27992/solving-for-initial-velocity-required-to-launch-a-projectile-to-a-given-destinat

    float radiansTheta = theta * (3.14 / 180);
    v = (1/cos(radiansTheta)) * sqrt(((0.5) * g * (pow(d, 2)))/ ((d*tan(radiansTheta)) - (t-h)));

    return true;
}


#ifndef MARMOSET_TESTING

int main() {

    // Some test driver code here ....

    float h = 50;
    float d = 60;
    float b = 40;
    float t = 30;
    float w = 30;
    float m = 1;

    float theta = 45; // Angle in degrees;
    float v = 25;

    cout << "Given angle: " << theta << endl;
    cout << "Target at (" << d << "," << t << ")" << endl;
    if (hitTargetGivenAngle(h, m, theta, d, t, b, w, v)) {
        cout << "required initial velocity: " << v << endl << endl;
    } else {
        cout << "cannot calculate the velocity\n\n";
    }

    cout << "Given initial velocity: " << v << endl;
    cout << "Target at (" << d << "," << t << ")" << endl;
    if (hitTargetGivenVelocity(h, v, m, d, t, b, w, theta)) {
        cout << "required angle: " << theta << endl << endl;
    } else {
        cout << "cannot calculate the angle\n\n";
    }

    return 0;
}

#endif
