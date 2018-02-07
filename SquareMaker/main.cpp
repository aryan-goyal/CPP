#include <iostream>

using namespace std;

int main(const int argc, const char *const argv[]) {

    int size = 8;

    for (int row = 0; row < (2 * size - 1); row++) {
        for (int column = 0; column < (2 * size - 1); column++) {
            if (row == 0 || row == (2 * size - 2) || row == (size - 1)) {
                if (column == 0 || column == (size - 1)) {
                    cout << "+";
                } else if (column == (2 * size - 2)) {
                    cout << "+" << endl;
                } else {
                    cout << "-";
                }
            } else {
                if (column == 0 || column == (size - 1)) {
                    cout << "|";
                } else if (column == (2 * size - 2)) {
                    cout << "|" << endl;
                } else {
                    cout << " ";
                }
            }
        }
    }

    return 0;
}
