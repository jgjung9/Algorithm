/**
 * https://www.acmicpc.net/problem/1373
 *
 * 2진수를 8진수로 변환
 */
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string binary;
    cin >> binary;
    int size = binary.size();
    int remain = size % 3;
    if (remain == 1)
        cout << (binary[0] - '0');
    else if (remain == 2)
        cout << 2 * (binary[0] - '0') + (binary[1] - '0');

    for (int i = remain; i < size; i += 3)
        cout << 4 * (binary[i] - '0') + 2 * (binary[i + 1] - '0') + (binary[i + 2] - '0');

    return 0;
}