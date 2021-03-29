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



void solve() {
    int n;
    cin>>n;
    vl a(n);
    int ans = n-1;
    ll sum = 0;
    vl sms;
    vl sms2;

    rep(i,0,n){
        cin>>a[i];
        sum+=a[i];
        sms.pb(sum);
    }
    sum = 0;
    for(int i = n-1;i>=0;i--){
        sum+=a[i];
        sms2.pb(sum);
    }

    for(int i = 0;i<n;i++){
        ll cur = sms[i];
        ll init = cur;
        bool flag = false;
        int ctr = 1;
        for(int j = i+1;j<n;j++){
            if(sms[j]==init+cur){
                ctr++;
                init+=cur;
                if(j==n-1){
                    flag = true;
                }
            }
        }
        if(flag) ans = min(ans,n-ctr);
    }

    for(int i = 0;i<n;i++){
        ll cur = sms2[i];
        ll init = cur;
        int ctr = 1;
        bool flag = false;
        for(int j = i+1;j<n;j++){
            if(sms2[j]==init+cur){
                ctr++;
                init+=cur;
                if(j==n-1){
                    flag = true;
                }
            }

        }
        if(flag) ans = min(ans,n-ctr);
    }
    cout<<ans<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    cin>>tt;
    while (tt--) {
        solve();
    }

    return 0;
}

