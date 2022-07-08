#include <iostream>
using namespace std;
int n, students;
int switches[101];

void boy(int number)
{
    int temp = number;
    while (temp <= n)
    {
        switches[temp] = !switches[temp];
        temp += number;
    }
}

void girl(int number)
{
    int lt, rt;
    lt = rt = number;

    while (switches[lt] == switches[rt])
    {
        lt--;
        rt++;
        if (lt < 1 || rt > n)
            break;
    }
    lt++, rt--;
    for (int i = lt; i <= rt; i++)
        switches[i] = !switches[i];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> switches[i];

    cin >> students;
    for (int i = 0; i < students; i++)
    {
        int sex, number;
        cin >> sex >> number;
        if (sex == 1)
            boy(number);
        else
            girl(number);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << switches[i] << ' ';
        if (i % 20 == 0)
            cout << '\n';
    }
    return 0;
}