/* 购票系统 for problem 173 on XDOJ by LyCecilion - C++ version */

#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

#ifdef LOCAL
#define debug(x) cerr << "[debug] " << #x << " = " << (x) << '\n'
#else
#define debug(x) ((void)0)
#endif

namespace {
constexpr int ROWS = 20;
constexpr int SEATS_PER_ROW = 5;
constexpr int MAX_SEAT = ROWS * SEATS_PER_ROW;
} // namespace

static void find(bitset<MAX_SEAT + 1>& occupied);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    bitset<MAX_SEAT + 1> occupied;

    for (int i = 0; i < n; i++) {
        if (i) {
            cout << '\n';
        }
        find(occupied);
    }

    return 0;
}

static void find(bitset<MAX_SEAT + 1>& occupied) {
    int p;
    cin >> p;

    /* 注意 1-index */

    // 对于 p <= SEATS_PER_ROW，在一排中找到连续的 p 个空位
    for (int i = 0; i < ROWS; i++) {
        const int row_begin = SEATS_PER_ROW * i + 1; // 1-index
        const int row_end = SEATS_PER_ROW * (i + 1); // 1-index

        // 例如我们的 p 个座位恰位于排尾，则座位分布于 row_end - (p-1) 到 row_end，从而遍历
        // seats_begin 从 row_begin 到 row_end - (p-1)
        for (int seats_begin = row_begin; seats_begin <= row_end - (p - 1); seats_begin++) {
            bool available = true;
            for (int j = 0; j < p; j++) {
                if (occupied[seats_begin + j]) {
                    available = false;
                    break;
                }
            }
            if (available) {
                bool first = true;
                for (int j = 0; j < p; j++) {
                    occupied[seats_begin + j] = true;
                    if (!first) {
                        cout << ' ';
                    }
                    first = false;
                    cout << seats_begin + j;
                }
                return;
            }
        }
    }

    // fallback 分支
    int found = 0;
    for (int i = 0; found < p && i < MAX_SEAT; i++) {
        if (!occupied[i + 1]) {
            if (found) {
                cout << ' ';
            }
            cout << i + 1;
            occupied[i + 1] = true;

            found++;
        }
    }
}