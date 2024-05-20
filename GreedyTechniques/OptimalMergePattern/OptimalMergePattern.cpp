#include <iostream>
using namespace std;

// We will be given some n number of sorted lists (actually only lengths of those lists).
// We have to find the least amount of time in which we can merge all those n lists (yes, like we did in merge sort)

// It takes p + q time to merge two sorted lists of lengths p & q

//Approach: We will get the minimum time overall if at every point, we merge the two lists with the least lengths at that time and add their lengths' sum to the total time taken. 
// ofc those 2 lists will make a bigger list and then that will also be part of our considerations in the future

struct List {
    char id;
    int items;
};

int totalTime = 0;

void changeTwoMinAndAddSum(int v[], int n) {

    int firstMinIdx = 0;
    for (int i = 0; i < n; i++) {
        if (v[firstMinIdx] > v[i] && v[i] != -1) {
            firstMinIdx = i;
        }
    }
    int store1stVal = v[firstMinIdx];
    v[firstMinIdx] = -1;

    //-1 means that we will ignore it in later comparisons
    int secondMinIdx = 0;
    for (int i = 0; i < n; i++) {
        if (v[secondMinIdx] > v[i] && v[i] != -1) {
            secondMinIdx = i;
        }
    }
    v[secondMinIdx] += store1stVal; // We'll just put it in place of a previous length.

    totalTime += v[secondMinIdx]; // as timeTaken = lengthOf(x) + lengthOf(y)
}
bool areOnlyTwoRemaining(int v[], int n) {
    int nonMinusOnes = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] != -1) {
            nonMinusOnes++;
            if (nonMinusOnes > 2) {
                return false;
            }
        }
    }
    return true;
}
void optimalMergePattern() {
    // List lists[] = { {'a',6}, {'b', 5}, {'c', 2}, {'d', 3}, {'e', 8} };
    int listLengths[] = { 6,5,2,3 };
    int n = sizeof(listLengths) / sizeof(int);

    while (!areOnlyTwoRemaining(listLengths, n)) {
        changeTwoMinAndAddSum(listLengths, n);
    }
    for (int i = 0; i < n; i++) {
        if (listLengths[i] != -1) {
            totalTime += listLengths[i];
        }
    }
    cout << "Total time taken to merge all two by two (mins) at a time: " << totalTime;
}

int main() {
    optimalMergePattern();
    return 0;
}