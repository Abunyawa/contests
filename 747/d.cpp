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

vi crew[200100];
vi impo[200100];
int col[200100];
int ans;
int ctrB;
int ctr;
void dfs(int v){
    ctr++;
    if(col[v]==2){
        ctrB++;
    }
    for(int to: crew[v]){
        if(col[v] == 1){
            if(col[to]==0){
                col[to] = 1;
                dfs(to);
            }else{
                if(col[to]==2){
                    ans = -1;
                }
            }
        }else{
            if(col[to]==0){
                col[to] = 2;
                dfs(to);
            }else{
                if(col[to]==1){
                    ans = -1;
                }
            }
        }
    }

    for(int to: impo[v]){
        if(col[v] == 1){
            if(col[to]==0){
                col[to] = 2;
                dfs(to);
            }else{
                if(col[to]==1){
                    ans = -1;
                }
            }
        }else{
            if(col[to]==0){
                col[to] = 1;
                dfs(to);
            }else{
                if(col[to]==2){
                    ans = -1;
                }
            }
        }
    }
}

void solve() {
    int n,m;
    cin>>n>>m;
    ans = 0;
    for(int i=0;i<=n;i++){
        crew[i].clear();
        impo[i].clear();
        col[i] = 0;
    }

    for(int i=0;i<m;i++){
        int x,y;
        string s;
        cin>>x>>y>>s;
        if(s=="imposter"){
            impo[x].pb(y);
            impo[y].pb(x);
        }else{
            crew[x].pb(y);
            crew[y].pb(x);
        }
    }

    int tot = 0;
    for(int i=1;i<=n;i++){
        if(col[i]==0){
            ctr=0;
            ctrB=0;
            col[i] = 1;
            dfs(i);
            if(ans==-1){
                cout<<-1<<'\n';
                return;
            }
            if(ctrB > ctr-ctrB){
                tot+=ctrB;
            }else{
                tot+=ctr-ctrB;
            }
        }
    }

    cout<<tot<<'\n';
    
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

