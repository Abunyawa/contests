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

const ll INF = 1e9+7;

void solve() {
    int n,m;
    cin>>n>>m;
    vector<vi> days(m+1);
    for(int i=1;i<=m;i++){
        int k;
        cin>>k;
        for(int j = 0;j<k;j++){
            int x;
            cin>>x;
            days[i].pb(x);
        }
    }
    vector<int> sm(n+1,0);
    vi ans(m+1,0);
    for(int i=1;i<=m;i++){
        if(days[i].size()==1){
            sm[days[i][0]]++;
            ans[i] = days[i][0];
            if(sm[days[i][0]]>(m+1)/2){
                no();
                return;
            }
        }
    }

    for(int i=1;i<=m;i++){
        if(ans[i]==0){
            for(int j =0;j<days[i].size();j++){
                if(sm[days[i][j]]+1<=(m+1)/2){
                    ans[i] = days[i][j];
                    sm[days[i][j]]++;
                    break;
                }
            }
        }
    }
    yes();
    for(int i=1;i<=m;i++){
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

