#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
typedef long long ll;
bool isprime(ll y){
    if (y < 2) return false;
    if (y == 2) return true;
    if (y % 2 == 0) return false;
    for (ll i = 3; i * i <= y; i += 2) {
        if (y % i == 0) return false;
    }
    return true;
}

ll generation_y(ll x,int k){
    string y;
    string s=to_string(x);
    for(int i=0;i<k;i++){
        y+=s;
    }
    try {
        return stoll(y);
    } catch (...) {
        return -1;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ll x;
        int k;
        cin>>x>>k;
        cout<<(isprime(generation_y(x,k)) ?"YES":"NO")<<'\n';
    }
    return 0;

}