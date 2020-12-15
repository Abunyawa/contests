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
    int n,m;
    cin>>n>>m;
    vi a(n+1);
    rep(i,1,n+1){
        cin>>a[i];
    }
    double ans = 1;
    double cur = 1;
    int r = n;
    while(r>=1 && a[r]==r){
        r--;
    }

    if(r <= 0){
        rep(i,0,m){
            int rl;
            double p;
            cin>>rl>>p;
        }
        printf("%.10f\n",1.0);
        return;
    }
    rep(i,0,m){
        int rl;
        double p;
        cin>>rl>>p;
        if(rl>=r){
            cur *= (1.0-p);
        }
    }


    printf("%.10f\n",1.0-cur);

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

