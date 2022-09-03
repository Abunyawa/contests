// chrono::system_clock::now().time_since_epoch().count()
#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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
    int n,m;
    cin>>n>>m;

    vl a(m);

    for(int i=0;i<m;i++){
        cin>>a[i];
    }

    sort(all(a));

    vl bl;
    
    for(int i=0;i<m-1;i++){
        bl.pb(a[i+1]-a[i]-1);
    }

    bl.pb(n-a[m-1] + a[0] - 1);


    sort(rall(bl));
    ll ans = 0;
    ll stp =0;
    for(int i=0;i<bl.size();i++){
        //cout<<bl[i]<<' ';
        ll cur = bl[i] - stp*2;
        if(cur>1){
            ans+= max(0LL, cur-1);
            stp+=2;
        }else{
            ans+= max(0LL, cur);
            stp+=1;
        }
    }
    //cout<<'\n';
    cout<<n-ans<<'\n';
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

