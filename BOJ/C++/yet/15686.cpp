#include <iostream>
#include <vector>
using namespace std;

struct Position
{
    int x;
    int y;
};
int n, m, temp, cnt = 0;
vector<Position> houses;
vector<Position> chickens;

int check()
{
}

void Select(int m, int idx)
{
    if (m == cnt)
    {
        check();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> temp;
            if (temp == 1)
                houses.push_back({i, j});
            else if (temp == 2)
                chickens.push_back({i, j});
        }
    }
}