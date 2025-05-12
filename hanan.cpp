#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// GCD helper
ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll &x : a)
        cin >> x;

    ll min_val = *min_element(a.begin(), a.end());

    vector<ll> reduced;
    for (ll x : a)
        if (x % min_val == 0)
            reduced.push_back(x / min_val);

    if (reduced.size() < 2) {
        cout << "No\n";
        return;
    }

    ll total_gcd = 0;
    for (ll x : reduced)
        total_gcd = gcd(total_gcd, x);

    if (total_gcd != 1) {
        cout << "No\n";
        return;
    }

    int m = reduced.size();
    vector<ll> prefix(m), suffix(m);
    prefix[0] = reduced[0];
    for (int i = 1; i < m; ++i)
        prefix[i] = gcd(prefix[i - 1], reduced[i]);

    suffix[m - 1] = reduced[m - 1];
    for (int i = m - 2; i >= 0; --i)
        suffix[i] = gcd(suffix[i + 1], reduced[i]);

    for (int i = 0; i < m; ++i) {
        if (reduced[i] == 1) {
            ll g = 0;
            if (i > 0) g = prefix[i - 1];
            if (i + 1 < m)
                g = g == 0 ? suffix[i + 1] : gcd(g, suffix[i + 1]);

            if (g == 1) {
                cout << "Yes\n";
                return;
            }
        }
    }

    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
