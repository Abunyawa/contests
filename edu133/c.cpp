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
    ll a[2][n];

    for(int i=0;i<n;i++){
        cin>>a[0][i];
    }

    for(int i=0;i<n;i++){
        cin>>a[1][i];
    }

    ll tt[2][n];

    tt[0][0] = 0;

    for(int i =1;i<n;i++){
        tt[0][i] = max(a[0][i]+1LL, tt[0][i-1]+1LL);
    }
    

    tt[1][n-1] = max(a[1][n-1]+1LL, tt[0][n-1]+1LL);

    for(int i=n-2;i>=0;i--){
        tt[1][i] = max(tt[1][i+1]+1LL, a[1][i]+1LL);
    }

    ll ans = tt[1][0];

    ll loc = 0;

    for(int i=2;i<n;i+=2){
        loc = max(loc+1LL, a[1][i-2]+1LL);
        loc = max(loc+1LL, a[1][i-1]+1LL);
        loc = max(loc+1LL, a[0][i-1]+1LL);
        loc = max(loc+1LL, a[0][i]+1LL);

        ll curAns = loc + tt[1][i] - tt[0][i];

        ans = min(ans, curAns);

        //cout<<curAns<<' ';
    }


    
    tt[0][0] = 0;

    tt[1][0] = max(1LL,a[1][0]+1LL);

    for(int i=1;i<n;i++){
        tt[1][i] = max(tt[1][i-1]+1LL, a[1][i]+1LL);
    }

    tt[0][n-1] = max(a[0][n-1]+1LL, tt[1][n-1]+1LL);

    for(int i=n-2;i>0;i--){
        tt[0][i] = max(tt[0][i+1]+1LL, a[0][i]+1LL);
    }


    ans = min(ans, tt[0][1]);
    loc = tt[1][1];
    for(int i=3;i<n;i+=2){
        loc = max(loc+1LL, a[0][i-2]+1LL);
        loc = max(loc+1LL, a[0][i-1]+1LL);
        loc = max(loc+1LL, a[1][i-1]+1LL);
        loc = max(loc+1LL, a[1][i]+1LL);

        ll curAns = loc+tt[0][i]-tt[1][i];

        ans = min(ans, curAns);
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

