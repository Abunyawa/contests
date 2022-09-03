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
    vi in(n+1,0);
    vi p(n+1,0);
    vi used(n+1,0);

    for(int i=1;i<=n;i++){
        cin>>p[i];
        if(i!=p[i]) in[p[i]]++;
    }

    vector<vi> ans;
    for(int i=1;i<=n;i++){
        if(in[i]==0){
            vi path;
            int cur = i;
            while(!used[cur]){
                path.pb(cur);
                used[cur] = 1;
                if(p[cur]==cur){
                    break;
                }
                cur = p[cur];
            }
            
            ans.pb(path);
        }
    }

    cout<<ans.size()<<'\n';

    for(int i=0;i<ans.size();i++){
        reverse(all(ans[i]));
        cout<<ans[i].size()<<'\n';
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<' ';
        }
        cout<<'\n';
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

