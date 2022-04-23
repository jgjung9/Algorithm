// BOJ 1065 한수

#include <iostream>
using namespace std;

int SequenceCount(int n)
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        int temp1;
        int temp2;
        if (i < 100)
            cnt++;
        else if (i < 1000)
        {
            temp1 = ((i % 100) / 10) - (i % 10);
            temp2 = (i / 100) - ((i % 100) / 10);
            if (temp1 == temp2)
                cnt++;
        }    
    }
    return cnt;
}

int main()
{
    int n;
    cin >> n;
    cout << SequenceCount(n) << endl;
}