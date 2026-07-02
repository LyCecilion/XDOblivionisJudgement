#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(x) cerr << "[debug] " << #x << " = " << (x) << '\n'
#else
#define debug(x) ((void)0)
#endif

static int find(vector<bool>& occupied);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<bool> occupied(101, false);

    for (int i = 0; i < n; i++) {
        find(occupied);
    }

    return 0;
}

static int find(vector<bool>& occupied) {
    int p;
    cin >> p;

    /* note 1-index */

    // for p <= 5, find continuous p numbers in a row
    // check from (1, 5), till we find a row to settle p people
    for (int i = 0; i < 20; i++) {
        const int row_begin = 5 * i + 1; // 1-index
        const int row_end = 5 * (i + 1); // 1-index

        // suppose we have p seats at end of one row, then seats are (row_end - (p-1), row_end,
        // therefore we let seats_begin from row_begin to row_end - (p-1).
        for (int seats_begin = row_begin; seats_begin <= row_end - (p - 1); seats_begin++) {
            bool available = true;
            for (int j = 0; j < p; j++) {
                if (occupied[seats_begin + j]) {
                    available = false;
                    break;
                }
            }
            if (available) {
                for (int j = 0; j < p; j++) {
                    occupied[seats_begin + j] = true;
                    cout << seats_begin + j << ' ';
                }
                cout << '\n';
                return 0;
            }
        }
    }

    // for conditions that do not having continuous p seats, we have
    int found = 0;
    for (int i = 0; found < p; i++) {
        if (!occupied[i + 1]) {
            cout << i + 1 << ' ';
            occupied[i + 1] = true;

            found++;
        }
    }
    cout << '\n';
    return 0;
}