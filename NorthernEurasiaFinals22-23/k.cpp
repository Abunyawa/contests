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
    int n,k;
    cin>>n>>k;

    bool has[n][n];

    for(int i=0;i<n;i++){
        has[i][i] =false;
        for(int j=i+1;j<n;j++){
            has[i][j] = true;
            has[j][i] = true;
        }
    }

    int cur = 1;
    int gap = 1;
    int ctr = n-2;
    while(cur<k){
        for(int i=ctr;i>=0;i--){
            int nxt = (i-gap+ctr)%ctr;
            if(nxt==i){
                no();
                return;
            }
            has[nxt][i] = false;
            has[i][nxt] = false;
        }
        cur++;
        ctr--;
        gap++;
    }

    vector<pii> ans;
    for(int i = 0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(has[i][j]) ans.pb({i+1,j+1});
        }
    }

    yes();
    cout<<ans.size()<<'\n';

    for(pii x: ans){
        cout<<x.fi<<' '<<x.se<<'\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    
    while (tt--) {
        solve();
    }

    return 0;
}

