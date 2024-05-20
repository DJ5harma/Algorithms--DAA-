#include <iostream>
#include<algorithm>
using namespace std;

// n=7
//Jobs:      J1 J2 J3 J4 J5 J6 J7
//Profits:   35 30 25 20 15 12 5
//Deadlines:  3  4  4  2  3  1 2

// Aim: To achieve max profit by doing jobs
// Every single job requires 1 unit of time

// Approach: Perform the most profitable jobs first just before their deadline or in an earlier time frame if the latest time frame is already taken. Todo this, sort them by their profits in descending order

struct Job {
    char id;
    int profit;
    int deadline;
};
bool comparisonJobSequencing(Job a, Job b) { //function used in sort() to arrange them in descending order
    return (a.profit) > (b.profit);
}
void jobSequencing() {

    int profit = 0;

    Job jobs[] = { {'a', 35, 3}, {'b', 30, 4}, {'c', 25,4}, {'d', 20,2}, {'e', 15,3}, {'f', 12, 1}, {'g', 5, 2} };

    int n = sizeof(jobs) / sizeof(Job);

    int maxDeadline = 0;
    for (auto job : jobs) {
        maxDeadline = max(job.deadline, maxDeadline);
    }
    bool timeAvailable[maxDeadline + 1];//Tracks if the timeFrame is taken/available //We'll leave 0th index out of interest
    for (int t = 1; t <= maxDeadline; t++) {
        timeAvailable[t] = true;
    }
    sort(jobs, jobs + n, comparisonJobSequencing);

    for (auto job : jobs) {
        int itsTurn = job.deadline;

        while (!timeAvailable[itsTurn] && itsTurn > 0) {
            itsTurn--;
        }
        if (itsTurn != 0) { //TimeFrame available for it
            timeAvailable[itsTurn] = false;

            profit += job.profit;
            cout << job.id << ": " << itsTurn << " " << endl;
        }
    }

    cout << "Profit: " << profit;
}

int main() {

    jobSequencing();

    return 0;
}