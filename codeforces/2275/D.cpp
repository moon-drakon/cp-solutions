
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Lab {
    ll sum, extra;
    bool locked;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        ll k;
        cin >> n >> k;

        vector<Lab> labs(n);
        ll low = LLONG_MAX;

        for (int i = 0; i < n; i++) {
            ll a, b, c;
            cin >> a >> b >> c;

            labs[i].sum = a + b + c;
            labs[i].extra = 0;
            labs[i].locked = (a == b && b == c);

            if (!labs[i].locked && a <= b && b <= c) {
                ll moves = min(b - a, c - b) + 1;
                labs[i].extra = 2 * moves;
            }

            low = min(low, labs[i].sum);
        }

        auto possible = [&](ll target) -> bool {
            ll used = 0;

            for (const auto &lab : labs) {
                if (lab.sum >= target)
                    continue;

                if (lab.locked)
                    return false;

                ll cost = target - lab.sum + lab.extra;

                if (cost > k - used)
                    return false;

                used += cost;
            }

            return true;
        };

        ll high = low + k + 1;

        while (low + 1 < high) {
            ll mid = low + (high - low) / 2;

            if (possible(mid))
                low = mid;
            else
                high = mid;
        }

        cout << low << '\n';
    }

    return 0;
}
