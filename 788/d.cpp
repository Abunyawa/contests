// chrono::system_clock::now().time_since_epoch().count()
#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

void yes(){
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}

ll ans[100000];

void solve() {
    ll n;
    cin>>n;
    if(n<3){
        cout<<"2\n";
        return;
    }

    int l = 3;
    int r = 38730;
    while(l<r-1){
        int m = (l+r)/2;

        if(ans[m]>=n){
            r = m;
        }else{
            l = m+1;
        }
    }
    if(ans[l]>=n){
        cout<<l<<'\n';
    }else{
        cout<<r<<'\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    ll cur = 6;
    ll ctr1 = 1;
    ll ctr2 = 1;
    ll ctr3 = 1;
    ans[ctr1+ctr2+ctr3] = cur;

    while(cur<1e9){
        if(ctr1==ctr2 && ctr2 == ctr3){
            cur+=2LL*ctr3;

            cur+=2LL*ctr2;
            ctr1++;
        }else if(ctr1!=ctr2){
            cur+=2LL*ctr3;
            cur+=2LL*ctr1;
            ctr2++;
        }else{
            cur+=2LL*ctr2;
            cur+=2LL*ctr1;
            ctr3++;
        }
        ans[ctr1+ctr2+ctr3] = cur;
    }


    int tt = 1;
    cin>>tt;
    while (tt--) {
        solve();
    }

    return 0;
}



