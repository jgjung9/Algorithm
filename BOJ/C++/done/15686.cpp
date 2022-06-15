/**
 * check =>O(nxm) => 50 * 13 = 약 1000 정도로 생각하면,
 *
 */
#include <iostream>
#include <vector>
using namespace std;
struct Position
{
    int x;
    int y;
};
int n, m, ans = 1e9;
vector<Position> houses;
vector<Position> chickens;
vector<Position> selected;

int check()
{
    int minDis, ans = 0;
    int diffX, diffY;
    for (int i = 0; i < houses.size(); i++)
    {
        minDis = 100;
        for (int j = 0; j < selected.size(); j++)
        {
            diffX = abs(houses[i].x - selected[j].x);
            diffY = abs(houses[i].y - selected[j].y);
            minDis = min(minDis, diffX + diffY);
        }
        ans += minDis;
    }
    return ans;
}

void select(int m, int idx, int cnt)
{
    if (m == cnt)
    {
        ans = min(check(), ans);
        return;
    }
    if (idx == chickens.size())
        return;

    selected.push_back(chickens[idx]);
    select(m, idx + 1, cnt + 1);
    selected.pop_back();
    select(m, idx + 1, cnt);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int temp;
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
    select(m, 0, 0);
    cout << ans;
    return 0;
}