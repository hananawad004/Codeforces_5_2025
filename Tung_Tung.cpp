#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
typedef long long ll;


bool isValid(string &s1,string &s2) {
    int x = 0, y = 0;
    int n = s1.size(), m = s2.size();

    while (x < n && y < m) {
        char p = s1[x];
        ll cnt1 = 0, cnt2 = 0;

        while (x < n && s1[x] == p) {
            cnt1++;
            x++;
        }


        while (y < m && s2[y] == p) {
            cnt2++;
            y++;
        }


        if (cnt2 < cnt1 || cnt2 > 2 * cnt1) {
            return false;
        }
    }


    return (x == n && y == m);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string p, s;
        cin >> p >> s;
        cout << (isValid(p, s) ? "YES" : "NO") << '\n';
    }
    return 0;
}