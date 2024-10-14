#include <bits/stdc++.h>
using namespace std;

void SJF(vector<pair<int, int>> processes)
{
    int n = processes.size();
    int waiting_time[n];
    int turn_around_time[n];
    sort(processes.begin(), processes.end(), [](pair<int, int> a, pair<int, int> b)
         { return a.second < b.second; });
    waiting_time[0] = 0;
    turn_around_time[0] = processes[0].second;
    for (int i = 1; i < n; i++)
    {
        waiting_time[i] = turn_around_time[i - 1];
        turn_around_time[i] = waiting_time[i] + processes[i].second;
    }
    cout << "PID\tBT\tWT\tTAT\n";
    for (int i = 0; i < n; i++)
    {
        cout << processes[i].first << "\t" << processes[i].second << "\t" << waiting_time[i] << "\t" << turn_around_time[i] << "\n";
    }
}


int main()
{
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    vector<pair<int, int>> processes(n);
    cout << "Enter the process ID and burst time for each process:\n";
    for (int i = 0; i < n; i++)
    {
        int pid, bt;
        cin >> pid >> bt;
        processes[i] = make_pair(pid, bt);
    }
   
    cout << "SJF:\n\n";
    SJF(processes);
    cout<<endl;
}
