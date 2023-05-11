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
    map<ll,int> m;
    for(int i=0;i<n;i++){
        cin>>a[i];

        ll cur = a[i];

        for(int j=2;j<=sqrt(a[i]);j++){
            while(cur%j==0){
                m[j]++;
                cur/=j;
            }
        }

        if(cur>1){
            m[cur]++;
        }
    }

    int ans = 0;
    for(auto x: m){
        ans+=x.se/2;
        m[x.fi]%=2;
    }

    ll cur = 1;
    ll ctr = 0;

    for(auto x: m){
        if(x.se!=0){
            ctr++;
            if(ctr==3){
                ans++;
                ctr = 0;
            }
        }
    }

    if(ans==0){
        cout<<0<<'\n';
    }else{
        cout<<ans<<'\n';
    }
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

