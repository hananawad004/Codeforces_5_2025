#include <bits/stdc++.h>
using namespace std;

void B(int t, int testCases, int n, int k, vector<long long>& a, vector<long long>& b, string& ans) {
    long long sum = 0;
    vector<long long> c(n);

    for (int i = 0; i < n; ++i) {
        sum += max(a[i], b[i]);
        c[i] = min(a[i], b[i]);
    }

    sort(c.rbegin(), c.rend());  // sort in descending order

    long long prefixSum = 0;
    for (int i = 0; i < k - 1; ++i) {
        prefixSum += c[i];
    }

    prefixSum += 1;
    sum += prefixSum;

    ans += to_string(sum);
    if (t != testCases) {
        ans += "\n";
    }
}

int main() {
    int testCases;
    cin >> testCases;
    string ans;

    for (int t = 1; t <= testCases; ++t) {
        int n, k;
        cin >> n >> k;
        vector<long long> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];

        B(t, testCases, n, k, a, b, ans);
    }

    cout << ans << "\n";
    return 0;
}
