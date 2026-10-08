
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> freq(60001, 0);
        vector<int> val(n - 4);

        long long ans = 0;

        for (int i = 0; i < n - 4; i++) {
            val[i] = a[i] + a[i + 2] - a[i + 4];

            int x = val[i] + 30000;

            ans += freq[x];

            if (i >= 2 && val[i] == val[i - 2])
                ans--;

            if (i >= 4 && val[i] == val[i - 4])
                ans--;

            freq[x]++;
        }

        cout << ans << '\n';
    }

    return 0;
}
