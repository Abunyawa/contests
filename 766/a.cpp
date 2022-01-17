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
    int n, m, r,c;
    cin>>n>>m>>r>>c;
    int ans = 1e8;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char x;
            cin>>x;
            if(x=='B'){
                if(r==i && c==j){
                    ans = min(ans,0);
                }else if(r==i || c==j){
                    ans = min(ans,1);
                }else{
                    ans = min(ans,2);
                }
            }
        }   
    }
    if(ans!=1e8){
        cout<<ans<<'\n';
    }else{
        cout<<-1<<'\n';
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

