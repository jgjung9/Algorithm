#include <iostream>
#include <string>
using namespace std;

int main()
{
    int secPerHour = 60 * 60;
    int secPerMinute = 60;
    int time, hour, minute, sec;
    string now;
    string target;
    cin >> now >> target;

    // 두 시간의 차이 구하기 초 단위로 구하기
    int nowTime = stoi(now.substr(0, 2)) * secPerHour + stoi(now.substr(3, 5)) * secPerMinute + stoi(now.substr(6, 8));
    int targetTime = stoi(target.substr(0, 2)) * secPerHour + stoi(target.substr(3, 5)) * secPerMinute + stoi(target.substr(6, 8));
    if (targetTime < nowTime)
        targetTime += secPerHour * 24;
    time = targetTime - nowTime;

    // 초 단위로 구한 시간을 변환하기
    hour = time / secPerHour;
    time %= secPerHour;
    minute = time / secPerMinute;
    time %= secPerMinute;
    sec = time;

    // 시간 출력하기
    if (hour < 10)
        cout << '0' << hour << ':';
    else
        cout << hour << ':';

    if (minute < 10)
        cout << '0' << minute << ':';
    else
        cout << minute << ':';

    if (sec < 10)
        cout << '0' << sec;
    else
        cout << sec;

    return 0;
}