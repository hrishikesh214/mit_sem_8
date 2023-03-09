#include <bits/stdc++.h>

using namespace std;

int main()
{
    unordered_map<int, vector<int>> mp;
    cout << "Initial State: \n";
    for (int i = 0; i <= 61; i += 6)
        mp[0].push_back(i);
    for (int i = 0; i <= 81; i += 8)
        mp[1].push_back(i);
    for (int i = 0; i <= 101; i += 10)
        mp[2].push_back(i);
    for (int i = 0; i <= 10; i++)
    {
        cout << mp[0][i] << "\t " << mp[1][i] << " \t" << mp[2][i] << endl;
    }
    cout << "Enter the time: ";
    int n;
    cin >> n;
    int t1 = mp[0][n];
    if (t1 <= mp[1][n + 1])
    {
        cout << "Reciever time stamp for process P2 is greater than the senders time of process P1\n";
    }
    n += 2;
    int t2 = mp[1][n];
    if (t2 <= mp[2][n + 1])
    {
        cout << "Reciever time stamp for process P3 is greater than the senders time of process P2\n";
    }
    n += 3;
    t2 = mp[2][n];
    if (t2 > mp[1][n + 1])
    {
        mp[1][n + 1] = t2 + 1;
        int temp = n + 2;
        while (temp <= 10)
        {
            mp[1][temp] = mp[1][temp - 1] + 8;
            temp++;
        }
    }
    n += 2;
    t1 = mp[1][n];
    if (t1 > mp[0][n + 1])
    {
        mp[0][n + 1] = t1 + 1;
        int temp = n + 2;
        while (temp <= 10)
        {
            mp[0][temp] = mp[0][temp - 1] + 6;
            temp++;
        }
    }
    cout << "Final State after Lamport adjustment: \n";
    for (int i = 0; i <= 10; i++)
    {
        cout << mp[0][i] << "\t " << mp[1][i] << " \t" << mp[2][i] << endl;
    }
    return 0;
}