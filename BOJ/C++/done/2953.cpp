#include <iostream>
using namespace std;
int score[5][4];
int maxSum = 0, idx = 0, sum;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 4; j++)
            cin >> score[i][j];

    for (int i = 0; i < 5; i++)
    {
        sum = 0;
        for (int j = 0; j < 4; j++)
        {
            sum += score[i][j];
            if (j == 3 && sum > maxSum)
            {
                maxSum = sum;
                idx = i;
            }
        }
    }
    cout << idx + 1 << ' ' << maxSum;
    return 0;
}