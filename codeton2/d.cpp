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

    ll a[n][m];
    ll b[n][m];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            b[i][j] = a[i][j];
        }
    }

    vl ltr(n,0);

    for(int j=0;j<m-1;j++){
        ll mn = 1e13;

        for(int i=0;i<n;i++){
            mn=min(mn,a[i][j]);
        }

        for(int i=0;i<n;i++){
            ltr[i]+=a[i][j]-mn;
            a[i][j+1]+=a[i][j]-mn;
        }
    }

    vl rtl(n,0);

    for(int j=m-1;j>0;j--){
        ll mn = 1e13;

        for(int i=0;i<n;i++){
            mn=min(mn,b[i][j]);
        }

        for(int i=0;i<n;i++){
            rtl[i]+=b[i][j]-mn;
            b[i][j-1]+=b[i][j]-mn;
        }
    }
    
    map<pair<ll,ll>,int> ctr;
    ll ans = 0; 
    for(int i=0;i<n;i++){
        ctr[{ltr[i], rtl[i]}]++;

        //cout<<ltr[i]<<' '<<rtl[i]<<'\n';
        if(ctr[{ltr[i],rtl[i]}]>1){
            ans = ltr[i]-rtl[i];
        }
    }
    //cout<<'\n';
    for(int i=0;i<n;i++){
        if(ctr[{ltr[i],rtl[i]}]==1){
            cout<<i+1<<' '<<(ans+rtl[i]-ltr[i])/2LL<<'\n';
            return;            
        }
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

