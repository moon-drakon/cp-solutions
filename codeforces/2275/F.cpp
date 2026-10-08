
#include <bits/stdc++.h>
using namespace std;

const int MAXA = 1000000;
const int BASE = 1 << 20;
const int CAP = MAXA + 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> spf(MAXA + 1);

    for (int i = 2; i <= MAXA; ++i) {
        if (!spf[i]) {
            spf[i] = i;
            if (1LL * i * i <= MAXA) {
                for (int j = i * i; j <= MAXA; j += i) {
                    if (!spf[j]) spf[j] = i;
                }
            }
        }
    }

    vector<int> tree(2 * BASE), treeStamp(2 * BASE);
    vector<int> freq(MAXA + 1), freqStamp(MAXA + 1);

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; ++tc) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int &x : a) cin >> x;

        for (int x : a) {
            int kernel = 1;

            while (x > 1) {
                int p = spf[x], parity = 0;

                do {
                    x /= p;
                    parity ^= 1;
                } while (x % p == 0);

                if (parity) kernel *= p;
            }

            if (freqStamp[kernel] != tc) {
                freqStamp[kernel] = tc;
                freq[kernel] = 0;
            }

            ++freq[kernel];
        }

        long long ans = 0;
        int unblended = 0;

        for (int x : a) {
            while (x > 1) {
                int p = spf[x], parity = 0;

                do {
                    x /= p;
                    parity ^= 1;
                } while (x % p == 0);

                if (!parity) continue;

                int v = BASE + p;

                tree[v] = (treeStamp[v] == tc && tree[v] == p) ? 1 : p;
                treeStamp[v] = tc;

                for (v >>= 1; v; v >>= 1) {
                    int l = v * 2;
                    int left = treeStamp[l] == tc ? tree[l] : 1;
                    int right = treeStamp[l + 1] == tc ? tree[l + 1] : 1;

                    tree[v] = (int)min(1LL * CAP, 1LL * left * right);
                    treeStamp[v] = tc;
                }
            }

            int kernel = treeStamp[1] == tc ? tree[1] : 1;

            if (kernel <= MAXA && freqStamp[kernel] == tc) {
                ans += freq[kernel];
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
