#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int func(int num)
{
    map<int, int> m;

    for (int i = 1; i <= num; i++)
    {
        m[i] = 1;
    }
    int cc = 3;
    while (cc)
    {
        cout << "\nhell\n";
        int xflagl = 1;

        for (auto &mi : m)
        {
            int key = mi.first;
            int value = mi.second;
            if (value == -1)
                continue;
            if (xflagl)
            {
                m[key] = -1;
                xflagl = 0;
            }
            else
                xflagl = 1;
        }

        int xflagr = 1;

        int c = 0, ans = 0;
        for (int j = 1; j <= num; j++)
        {
            int key = j;
            int value = m[j];
            cout << "value: " << value << " key: " << key << " " << endl;
            if (value == 1)
            {
                ans = key;
                c++;
            }
        }

        if (c == 1)
            return ans;

        for (int j = num; j >= 1; j--)
        {
            int key = j;
            int value = m[j];
            if (value == -1)
                continue;
            if (xflagr)
            {
                m[key] = -1;
                xflagr = 0;
            }
            else
                xflagr = 1;
        }

        c = 0;
        ans = 0;
        for (int j = 1; j <= num; j++)
        {
            int key = j;
            int value = m[j];
            cout << "value: " << value << " key: " << key << " " << endl;
            if (value == 1)
            {
                ans = key;
                c++;
            }
        }

        if (c == 1)
            return ans;

        cc--;
    }

    return 0;
}

int main()
{

    int i = 9;
    cout << func(i);
    return 0;
}