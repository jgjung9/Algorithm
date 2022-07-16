#include <iostream>
#include <string>
#include <cstring>
const int MAX = 1100000;
using namespace std;
int n;
bool isPrime[MAX + 1];

bool isPalindrome(string str)
{
    int lp = 0, rp = str.size() - 1;
    while (lp < rp)
    {
        if (str[lp++] != str[rp--])
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= MAX; i++)
    {
        if (!isPrime[i])
            continue;
        for (int j = i + i; j <= MAX; j += i)
            isPrime[j] = false;
    }
    cin >> n;
    for (int i = n; i <= MAX; i++)
    {
        if (!isPrime[i])
            continue;
        string num = to_string(i);
        if (isPalindrome(num))
        {
            cout << num;
            break;
        }
    }

    return 0;
}