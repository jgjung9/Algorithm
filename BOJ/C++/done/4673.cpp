// BOJ 4673 셀프넘버

#include <iostream>
using namespace std;
#define MAX_SIZE 10000

void NotSelfNumber(bool num[], int n) {
    int temp;

    for (int i = 1; i < n; i++)
    {
        temp = i + (i % 10) + (i % 100 / 10) + (i % 1000 / 100) + (i / 1000);
        if (temp < 10000)
            num[temp] = true;
    }
}

void PrintSelfNumber(bool selfnum[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (!selfnum[i])
            cout << i << endl;
    }
}

int main()
{
    bool num[MAX_SIZE] = {0};
    NotSelfNumber(num, MAX_SIZE);
    PrintSelfNumber(num, MAX_SIZE);
}