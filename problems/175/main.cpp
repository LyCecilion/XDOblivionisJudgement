#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

#ifdef LOCAL
#define debug(x) cerr << "[debug] " << #x << " = " << (x) << '\n'
#else
#define debug(x) ((void)0)
#endif

struct window {
    int x1, y1, x2, y2; // where (x1, y1), (x2, y2)
    int id;             // higher -> upper
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<window> windows(n);
    for (int i = 0; i < n; i++) {
        cin >> windows[i].x1 >> windows[i].y1 >> windows[i].x2 >> windows[i].y2;
        windows[i].id = i + 1;
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        bool found = false;
        for (int j = n - 1; j >= 0; j--) {
            bool x_in_range = (windows[j].x1 <= x) && (x <= windows[j].x2);
            bool y_in_range = (windows[j].y1 <= y) && (y <= windows[j].y2);
            if (x_in_range && y_in_range) {
                window top_w = windows[j];
                windows.erase(windows.begin() + j);
                windows.push_back(top_w);
                cout << top_w.id << '\n';
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "IGNORED" << '\n';
        }
    }

    return 0;
}