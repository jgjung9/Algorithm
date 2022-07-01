/**
 * https://www.acmicpc.net/problem/11444
 *
 * solution: 피보나치 수열을 행열을 활용해
 * 행열의 거듭제곱의 형태로 나타내고 분할정복으로 해결한다.
 */
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using mat = vector<vector<ll>>;
const int mod = 1e9 + 7;

mat F = {{1, 1}, {1, 0}};
mat I = {{1, 0}, {0, 1}};

mat operator*(mat a, mat b)
{
    mat c = {{0, 0}, {0, 0}};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {

            for (int k = 0; k < 2; k++)
                c[i][j] += a[i][k] * b[k][j];
            c[i][j] %= mod;
        }
    }
    return c;
}

mat fibo(ll n)
{
    if (n == 0)
        return I;
    if (n == 1)
        return F;

    if (n % 2 == 0)
    {
        mat tmp = fibo(n / 2);
        return tmp * tmp;
    }
    else
    {
        mat tmp = fibo(n / 2);
        return tmp * tmp * F;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    cout << fibo(n)[0][1];
    return 0;
}