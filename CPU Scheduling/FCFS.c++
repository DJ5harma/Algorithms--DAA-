#include<iostream>
#include<algorithm>
using namespace std;


struct Process {
    int id, arrivalTime, burstTime, waitingTime = 0;
};

bool compare(Process a, Process b) {
    return a.arrivalTime < b.arrivalTime;
}

int main() {
    int n;cout << "Enter number of processes: ";cin >> n;

    Process process[n];

    for (int i = 0; i < n; i++) {
        process[i].id = i + 1;
        cout << "\nEnter burst time for process " << i + 1 << " : "; cin >> process[i].burstTime;
        cout << "Enter arrival time for process " << i + 1 << " : "; cin >> process[i].arrivalTime;
    }
    sort(process, process + n, compare);

    int doing = 0;
    int currTime = 0;

    while (true) {
        for (int i = doing + 1; i < n; i++) { // check for all which arrived after the one being executed
            if (process[i].arrivalTime < currTime + process[doing].burstTime)
                process[i].waitingTime += process[doing].burstTime + currTime - process[i].arrivalTime;
        }
        cout << "\nProcess " << doing << ": AT=" << process[doing].arrivalTime << ", BT=" << process[doing].burstTime << ", WT=" << process[doing].waitingTime << ", TAT=" << process[doing].burstTime + process[doing].waitingTime;
        currTime += process[doing].burstTime;
        doing++;
        if (doing == n) break;
    }
    return 0;
}