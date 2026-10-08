
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

        vector<int> a(n), b(n);

        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < n; i++)
            cin >> b[i];

        long long current = 1 + (a[n - 1] == b[n - 1]);

        for (int i = 0; i < n - 1; i++) {
            current += 2 + (a[i] == b[i])
                         + (a[i + 1] == b[i]);
        }

        long long thegrilla = current;

        for (int i = n - 2; i >= 0; i--) {
            current += (a[i] == b[i + 1])
                     - (a[i] == b[i]);

            thegrilla = max(thegrilla, current);
        }

        cout << thegrilla << '\n';
    }

    return 0;
}
