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

ll num(int a, int b){
    ll ans = 0;
    if(min(a/2,b)>=2){
        ans+=min(a/2,b)-1;
    }

    if(min(b/2,a)>=2){
        ans+=min(b/2,a)-1;
    }
    return ans;
}


int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};

int d[310][310];
bool used[310][310];
int dist[310][310];

int n,m;
int ans = 0;

void dfs(int x, int y, int st){
    used[x][y] = true;
    for(int p = 0;p<4;p++){
        int tox = x+dx[p];
        int toy = y+dy[p];
        if(tox>=0 && tox<n && toy>=0 && toy<m){
            if(!used[tox][toy]){
                dist[tox][toy] = dist[x][y]+1;
                int val = max(0,st-dist[tox][toy]);

                if(d[tox][toy]<val){
                    ans+=abs(val-d[tox][toy]);
                }
                dfs(tox,toy,st);
            }
        }

    }
}

void solve() {
    cin>>n>>m;
    priority_queue<pair<int,pii>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>d[i][j];
            q.push({d[i][j],{i,j}});
        }
    }

    for(int i=0;i<n;i++){
        for(int j = 0;j<m;i++){
            dist[i][j] = 0;
            dfs(i,j,d[i][j]);
        }
    }    
    

    cout<<'\n';
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<d[i][j]<<' ';
        }

        cout<<'\n';
    }
    
    cout<<ans<<'\n';

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    cin>>tt;
    for(int i=1;i<=tt;i++) {
        cout<<"Case #"<<i<<": ";
        solve();
    }

    return 0;
}

