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
    vector<vector<int>> r(n+1, vi());

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        r[x].pb(i);
    }

    for(int i=1;i<=n;i++){
        if(r[i].size()==0){
            cout<<0<<' ';
            continue;
        }

        int ans = 1;
        int cur = 1;
        
        int ls = 0;
        for(int j = 1;j<r[i].size();j++){
            if(r[i][j]%2!=r[i][ls]%2){
                ls = j;
                cur++;
            }
        }

        ans = max(ans,cur);

        cout<<cur<<' ';
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

