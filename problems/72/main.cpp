#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(x) cerr << "[debug] " << #x << " = " << (x) << '\n'
#else
#define debug(x) ((void)0)
#endif

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    string best;
    size_t max_len = 0;
    
    while (getline(cin, line))
    {
        if (line == "***end***") break;
        const size_t len = line.size();
        if (len > max_len)
        {
            max_len = len;
            best = std::move(line);
        }
    }

    if ((max_len == 0) & best.empty()) return 0;

    cout << max_len << '\n' << best << '\n';
    return 0;
}
