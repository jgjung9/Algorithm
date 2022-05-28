#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while (n--)
    {
        int p;
        cin >> p;
        int max = 0;
        string player;
        while (p--)
        {
            int price;
            string name;
            cin >> price >> name;
            if (max < price)
            {
                max = price;
                player = name;
            }
        }
        cout << player << '\n';
    }
    return 0;
}