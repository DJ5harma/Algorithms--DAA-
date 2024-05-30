#include <iostream>
using namespace std;

const int R = 3;
const int P = 5;

int processes[P] = { 0, 1, 2, 3, 4 };
int avail[P] = { 3, 3, 2 };

int req[P][R] = {
    {7, 5, 3},
    {3, 2, 2},
    {9, 0, 2},
    {2, 2, 2},
    {4, 3, 3}
};

int allot[P][R] = {
    {0, 1, 0},
    {2, 0, 0},
    {3, 0, 2},
    {2, 1, 1},
    {0, 0, 2}
};
int order[P];
int orderItr = 0;

bool completed[P];


bool canRunProcess(int process) {
    for (int i = 0; i < R; i++)
        if (req[process][i] > allot[process][i] + avail[i])
            return false;
    return true;
}

bool isSafe() {
    while (orderItr < P) {
        bool aProcessRan = false;

        for (int process = 0; process < P; process++) {
            if (!completed[process] && canRunProcess(process)) {

                // Let the process run and release the resources
                for (int i = 0; i < R; i++)
                    avail[i] += allot[process][i];

                completed[process] = true;
                order[orderItr] = process; orderItr++;
                aProcessRan = true;
            }
        }
        if (!aProcessRan) return false;
    }
    return true;
}

int main() {
    for (int f = 0; f < P; f++) {
        completed[f] = false;
    }
    if (isSafe()) {
        cout << "SAFE!\nOrder: ";
        for (int c = 0; c < P; c++) cout << order[c] << ' ';
    }
    else cout << "DEADLOCK!";
    return 0;
}