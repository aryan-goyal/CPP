#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main(const int argc, const char *const argv[]) {
    if (argc <= 3) {
        cerr << "Error: Insufficient arguments; expecting three arguments." << endl;
        return 1;
    } else if (argc > 4) {
        cerr << "Warning: Expecting three command-line arguments; received " << (argc - 1)
             << "; ignoring extraneous arguments." << endl;
    }

    float iniV = atof(argv[1]); //initial velocity of car
    float dToO = atof(argv[2]); //Distance to obstacle
    float MARD = atof(argv[3]); //Maximum acceptable rate of deceleration
    float minDeclReq = ((iniV * iniV) / (2 * dToO));

    bool negCheck = false;

    if (dToO < 0 && iniV < 0) {
        negCheck = true;
    }

    if (iniV == 0) {
        cout << "There is no possibility of collision because the self-driving car is not moving." << endl;

    } else if (dToO == 0) {
        cout << "Crash will occur in 0 seconds at velocity " << iniV << "m/s; deploying airbags." << endl;

    } else if (iniV < 0 && dToO > 0) {
        cout << "There is no possibility of collision because the self-driving car is moving away from the obstacle."
             << endl;
    } else if (iniV > 0 && dToO < 0) {
        cout << "There is no possibility of collision because the self-driving car is moving in front of the obstacle."
             << endl;

    } else {
        iniV = fabs(iniV);
        dToO = fabs(dToO);
        minDeclReq = fabs(minDeclReq);

        float minTime = iniV / minDeclReq;

        if (minDeclReq <= MARD) {
            if (negCheck) {
                cout << "Initial car velocity: " << -iniV << " m/s" << endl;
                cout << "Distance to obstacle: " << -dToO << " m" << endl;
            } else if (!negCheck) {
                cout << "Initial car velocity: " << iniV << " m/s" << endl;
                cout << "Distance to obstacle: " << dToO << " m" << endl;
            }

            cout << "Minimum deceleration: " << minDeclReq << " m/s/s" << endl;
            cout << "Maximum stopping time: " << minTime << " s" << endl;
        } else if (minDeclReq > MARD) {
            float vF = sqrt((iniV * iniV) - (2 * MARD * dToO));
            float cT = 0;

            if (MARD == 0) {
                cT = dToO / vF;
            } else {
                cT = fabs((vF - iniV) / MARD);
            }

            if (negCheck) {
                cout << "Crash will occur in " << cT << " seconds at velocity " << -vF << "m/s; deploying airbags."
                     << endl;
            } else if (!negCheck) {
                cout << "Crash will occur in " << cT << " seconds at velocity " << vF << "m/s; deploying airbags."
                     << endl;
            }
        }
    }

    return 0;
}