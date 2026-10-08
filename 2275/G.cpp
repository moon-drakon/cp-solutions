
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct soulsold {
    int u, v;
    ll d;

    bool operator<(const soulsold& other) const {
        return d < other.d;
    }
};

struct DSU {
    vector<int> p, sz;

    DSU(int n) {
        p.resize(n + 1);
        sz.assign(n + 1, 1);
        iota(p.begin(), p.end(), 0);
    }

    int find(int x) {
        if (p[x] == x) return x;
        return p[x] = find(p[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return false;

        if (sz[a] < sz[b]) swap(a, b);

        p[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m, q;
        cin >> n >> m >> q;

        vector<soulsold> edges(m);
        ll total = 0;

        for (auto &e : edges) {
            cin >> e.u >> e.v >> e.d;
            total += e.d;
        }

        sort(edges.begin(), edges.end());

        DSU dsu(n);
        vector<ll> w;

        for (auto &e : edges) {
            if (dsu.unite(e.u, e.v)) {
                w.push_back(e.d);
            }
        }

        int p = (int)w.size();

        vector<ll> pref(p + 1, 0);

        for (int i = 0; i < p; i++) {
            pref[i + 1] = pref[i] + w[i];
        }

        while (q--) {
            ll x;
            cin >> x;

            int l = 0, r = p;

            while (l < r) {
                int mid = (l + r + 1) / 2;

                if (w[mid - 1] <= x * (n - mid)) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }

            ll k = n - l - 1;
            ll cost = pref[l] + x * k * (k + 1) / 2;

            cout << total - cost;
            cout << (q ? ' ' : '\n');
        }
    }

    return 0;
}
