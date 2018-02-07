#include <iostream>
#include <stdlib.h>
#include <math.h>


using namespace std;

int main(const int argc, const char *argv[]) {
    if (argc <= 3) {
        cerr << "Error: Insufficient arguments; number of arguments are less than 3" << endl;
        return 1;
    }
    if (atof(argv[1]) <= 0 || atof(argv[1]) >= 1) {
        cerr << "Error: Incorrect argument; alpha must be in between 1 and 0" << endl;
        return 1;
    }
    if (atoi(argv[2]) < 1) {
        cerr << "Error: Incorrect argument; age limit must be greater than or equal to 1" << endl;
        return 1;
    }

    int x = 3;
    float alpha = atof(argv[1]);
    int limit = atoi(argv[2]);
    float sum = 0;
    float min = atof(argv[3]);
    float max = atof(argv[3]);

    int limitSetMin = 0;
    int limitSetMax = 0;

    float EWMA = atof(argv[x]);

    if (argc >= 3) {
        sum = sum + atof(argv[3]);
        cout << "Sample  Value  Minimum  EWMA  Maximum" << endl;
        while (x != argc) {
            if (limitSetMin < limit) {
                if (atof(argv[x]) <= min) {
                    min = atof(argv[x]);
                    limitSetMin = 0;
                }
            } else {
                min = atof(argv[x]);
                limitSetMin = 0;
            }
            if (limitSetMax < limit) {
                if (atof(argv[x]) >= max) {
                    max = atof(argv[x]);
                    limitSetMax = 0;
                }
            } else {
                max = atof(argv[x]);
                limitSetMax = 0;
            }
            limitSetMax++;
            limitSetMin++;

            EWMA = (alpha * atof(argv[x])) + ((1 - alpha) * EWMA);

            if (x == 3) {
                cout << (x - 2) << "    " << atof(argv[x]) << "    " << min << "    " << atof(argv[x])
                     << "       " << max
                     << endl;
            } else {
                cout << (x - 1) << "    " << atof(argv[x]) << "    " << min << "    " << EWMA << "     "
                     << max
                     << endl;
            }
            x++;
        }
        return 0;
    }
}