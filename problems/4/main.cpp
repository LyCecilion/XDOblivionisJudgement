/* 命令行选项 for problem 4 on XDOJ by LyCecilion - C++ version */

#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

#ifdef LOCAL
#define debug(x) cerr << "[debug] " << #x << " = " << (x) << '\n'
#else
#define debug(x) ((void)0)
#endif

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    set<string> options;

    string token;
    while (cin >> token) {
        if (token.front() == '-')
            options.insert(token);
    }

    if (options.empty()) {
        cout << "no";
        return 0;
    }

    bool first = true;
    for (const auto& opt : options) {
        if (first) {
            first = false;
        } else {
            cout << ' ';
        }
        cout << opt;
    }

    return 0;
}
