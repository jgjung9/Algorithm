#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    string n;
    cin >> n;
    int count[10] = {0};
    for (int i = 0; i < n.size(); i++)
    {
        int value = n[i] - '0';
        count[value]++;
    }

    int max = 0, temp = 0;
    for (int i = 0; i < 10; i++)
    {
        if (i == 6 || i == 9)
        {
            temp += count[i];
            continue;
        }

        if (max < count[i])
            max = count[i];
    }

    if (temp % 2 == 0)
    {
        if (temp / 2 >= max)
            cout << temp / 2;
        else
            cout << max;
    }
    else
    {
        if (2 * max > temp)
            cout << max;
        else
            cout << temp / 2 + 1;
    }
    return 0;
}