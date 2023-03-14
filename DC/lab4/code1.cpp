#include <bits/stdc++.h>
using namespace std;

int main()
{

    map<int, vector<int>> m;

    for (int i = 0; i < 61; i = i + 6)
        m[0].push_back(i);

    for (int i = 0; i < 81; i = i + 8)
        m[1].push_back(i);

    for (int i = 0; i < 101; i = i + 10)
        m[2].push_back(i);

    for (int i = 0; i < 11; i++)
    {

        cout << m[0][i] << "\t" << m[1][i] << "\t" << m[2][i];

        cout << endl;
    }

    int exit;

    int pulse = 0;

    do
    {

        int sender = 0, reciever = 0;

        cout << "\nEnter which process is sending the message and which process is receiving message: ";
        cin >> sender >> reciever;

        if (reciever == 0)
            pulse = 6;

        else if (reciever == 1)
            pulse = 8;

        else
            pulse = 10;

        int send = 0, receive = 0;

        cout << "\nEnter send and receive time: ";

        cin >> send >> receive;

        int sindex = 0, rindex = 0;

        auto it = find(m[sender].begin(), m[sender].end(), send);

        if (it != m[sender].end())
        {

            sindex = it - m[sender].begin();
        }

        auto it1 = find(m[reciever].begin(), m[reciever].end(), receive);

        if (it1 != m[reciever].end())
        {

            rindex = it1 - m[reciever].begin();
        }

        if (m[sender][sindex] > m[reciever][rindex])
        {

            m[reciever][rindex] = m[sender][sindex] + 1;

            for (int j = rindex + 1; j < 11; j++)
            {

                m[reciever][j] = m[reciever][j - 1] + pulse;
            }
        }

        cout << endl;

        for (int i = 0; i < 11; i++)
        {

            cout << m[0][i] << "\t" << m[1][i] << "\t" << m[2][i];

            cout << endl;
        }

        cout << "Do you want to continue?(1/0): ";

        cin >> exit;

    } while (exit == 1);

    return 0;
}