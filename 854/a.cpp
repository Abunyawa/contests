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
    vi ans(n,-1);
    vi was(m+1,0);
    int ctr = n-1;
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        x-=n;
        if(!was[x]){
            was[x] = 1;
            if(ctr>=0){
                ans[ctr] = i+1;
                ctr--;
            }
        }
    }

    for(int i=0;i<n;i++){
        cout<<ans[i]<<' ';
    }

    cout<<'\n';
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

