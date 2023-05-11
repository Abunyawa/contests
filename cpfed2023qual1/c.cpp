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
int n,m;
int dy[] = {1,0,-1,0};
int dx[] = {0,-1,0,1};
int gr[110][110];
vector<pii> g[110][110];
int in[110][110];
int used[110][110];
bool bad = false;
vector<pii> moves;

void solve() {
    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char x;
            cin>>x;

            gr[i][j] = x-'0';
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int xto = i+dx[gr[i][j]];
            int yto = j+dy[gr[i][j]];
            //cout<<i<<' '<<j<<'\n';
            while(xto>=0&&xto<n && yto>=0 && yto<m){
                //cout<<"-----"<<xto<<' '<<yto<<'\n';
                g[xto][yto].pb({i,j});
                in[i][j]++;
                xto+=dx[gr[i][j]];
                yto+=dy[gr[i][j]];
            }
        }
    }

    int ctr = 0;

    while(ctr<n*m){
        int dif = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(in[i][j]==0){
                    //cout<<i<<' '<<j<<'\n';
                    moves.pb({i,j});
                    for(int k=0;k<g[i][j].size();k++){
                        in[g[i][j][k].fi][g[i][j][k].se]--;
                    }
                    ctr++;
                    dif++;
                    in[i][j] = -1;
                }
            }
        }
        if(dif==0){
            if(ctr!=n*m){
                bad = true;
            }
            break;
        }
    }

    if(bad){
        no();
    }else{
        yes();
        for(int i=0;i<moves.size();i++){
            cout<<moves[i].fi+1<<' '<<moves[i].se+1<<'\n';
        }
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

