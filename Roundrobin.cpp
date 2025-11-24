#include <iostream>
#include <queue>
using namespace std;

int main() {
    const int n = 5;
    int arrival[n] = {0, 1, 2, 3, 4};
    int burst[n]   = {5, 3, 1, 2, 3};
    int remaining[n];
    // Copy burst → remaining time
    for (int i = 0; i < n; i++)
        remaining[i] = burst[i];
    int tq = 2; // time quantum
    int time = 0;
    queue<int> q;
    q.push(0); // first process arrives at time 0
    int completed = 0;
    bool inQueue[n] = {false};
    inQueue[0] = true;
    cout << "Gantt Chart: ";
    while (!q.empty()) {
        int p = q.front();
        q.pop();
        // CPU executes process p for tq or remaining time
        int exec = min(tq, remaining[p]);
        remaining[p] -= exec;
        time += exec;
        cout << " | P" << p + 1 << " ";
        // Add newly arrived processes to queue
        for (int i = 0; i < n; i++) {
            if (!inQueue[i] && arrival[i] <= time) {
                q.push(i);
                inQueue[i] = true;
            }
        }
        // If process still has work → push back to queue
        if (remaining[p] > 0) {
            q.push(p);
        } else {
            completed++;
        }
    }

    cout << "|\n\nProgram Finished.\n";

    return 0;
}
