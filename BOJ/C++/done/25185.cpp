#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int t;
int s[10], p[10], m[10];

bool isStraight()
{
    int sn = 0, pn = 0, mn = 0;
    for (int i = 1; i <= 9; i++)
    {
        sn++, pn++, mn++;
        if (s[i] == 0)
            sn = 0;
        if (p[i] == 0)
            pn = 0;
        if (m[i] == 0)
            mn = 0;

        if (sn == 3 || pn == 3 || mn == 3)
            return true;
    }
    return false;
}

bool isEqual()
{
    for (int i = 1; i <= 9; i++)
    {
        if (s[i] > 2 || p[i] > 2 || m[i] > 2)
            return true;
    }
    return false;
}

bool isCouple()
{
    int count = 0;
    for (int i = 1; i <= 9; i++)
    {
        if (s[i] == 2)
            count++;
        if (m[i] == 2)
            count++;
        if (p[i] == 2)
            count++;
    }
    return count == 2 ? true : false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> t;
    while (t--)
    {
        memset(s, 0, sizeof(s));
        memset(m, 0, sizeof(m));
        memset(p, 0, sizeof(p));
        string card;
        for (int i = 0; i < 4; i++)
        {
            cin >> card;
            if (card[1] == 's')
                s[card[0] - '0']++;
            else if (card[1] == 'p')
                p[card[0] - '0']++;
            else
                m[card[0] - '0']++;
        }

        if (isStraight() || isEqual() || isCouple())
            cout << ":)\n";
        else
            cout << ":(\n";
    }
    return 0;
}