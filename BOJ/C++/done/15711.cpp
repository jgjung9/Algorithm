#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;
int t;
ll a, b;
vector<int> prime;
vector<bool> isPrime(1.5e6, true);

bool check(ll a, ll b)
{
    ll sum = a + b;
    if (sum == 2)
        return false;
    if (sum % 2 == 0)
        return true;
    if ((sum - 2) < 1.5e6)
        return isPrime[sum - 2];
    for (int i = 0; i < prime.size(); i++)
    {
        if ((sum - 2) % prime[i] == 0)
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string ans = "";
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i < isPrime.size(); i++)
    {
        for (int j = i + i; j < isPrime.size(); j += i)
            isPrime[j] = false;
    }

    for (int i = 2; i < isPrime.size(); i++)
    {
        if (isPrime[i])
            prime.push_back(i);
    }

    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        if (check(a, b))
            ans += "YES\n";
        else
            ans += "NO\n";
    }

    cout << ans;
    return 0;
}