
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1000000007;

int addmod(int a, int b) {
    int s = a + b;
    if (s >= MOD) s -= MOD;
    return s;
}

int submod(int a, int b) {
    int s = a - b;
    if (s < 0) s += MOD;
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> a(n * m), b(n * m);

        for (int &x : a) {
            cin >> x;
            if (x < 0) x += MOD;
        }

        for (int j = 0; j < m; j++) {
            if (n & 1) {
                int sum = 0;

                for (int i = 0; i < n; i += 2)
                    sum = addmod(sum, a[i * m + j]);

                for (int i = 0; i < n; i++)
                    b[i * m + j] = (i & 1) ? 0 : submod(0, sum);
            } else {
                int suffix = 0, prefix = 0;

                for (int i = 1; i < n; i += 2)
                    suffix = addmod(suffix, a[i * m + j]);

                for (int i = 0; i < n; i++) {
                    int id = i * m + j;

                    if (i & 1) {
                        b[id] = prefix;
                        suffix = submod(suffix, a[id]);
                    } else {
                        b[id] = suffix;
                        prefix = addmod(prefix, a[id]);
                    }
                }
            }
        }

        ll ans = 0;

        for (int i = 0; i < n; i++) {
            int pa = 0, pb = 0;

            if (m & 1) {
                for (int j = 0; j < m; j += 2) {
                    int id = i * m + j;
                    pa = addmod(pa, a[id]);
                    pb = addmod(pb, b[id]);
                }

                ans = (ans - 1LL * pa * pb % MOD + MOD) % MOD;
            } else {
                for (int j = 0; j < m; j++) {
                    int id = i * m + j;

                    if (j & 1) {
                        ans = (ans + 1LL * a[id] * pb
                                  + 1LL * b[id] * pa) % MOD;
                    } else {
                        pa = addmod(pa, a[id]);
                        pb = addmod(pb, b[id]);
                    }
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
