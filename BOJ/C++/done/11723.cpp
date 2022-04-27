#include <iostream>
using namespace std;

int set = 0;

void add(int x) {
    set |= (1 << (x - 1));
}

void remove(int x) {
    set &= ~(1 << (x - 1));
}

void check(int x) {
    if (set & (1 << (x - 1))) {
        cout << 1 << '\n';
    } else {
        cout << 0 << '\n';
    }
}

void toggle(int x) {
    set ^= (1 << (x - 1));
}

void all() {
    set = (1 << 20) - 1;
}

void empty() {
    set = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        string func;
        int x;
        cin >> func;
        if (func == "add") {
            cin >> x;
            add(x);
        } else if (func == "remove") {
            cin >> x;
            remove(x);
        } else if (func == "check") {
            cin >> x;
            check(x);
        } else if (func == "toggle") {
            cin >> x;
            toggle(x);
        } else if (func == "all") {
            all();
        } else if (func == "empty") {
            empty();
        }
    }

    return 0;
}