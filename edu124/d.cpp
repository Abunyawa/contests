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

map<pii, int> ctr;
map<pii, int> used;
map<pii, int> dist;
map<pii, pii> pt;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void bfs(vector<pii> s){
    queue<pii> q;
    
    for(int i=0;i<s.size();i++){
        q.push({s[i].first, s[i].second});
        used[{s[i].first, s[i].second}] = 1;
    }
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for(int k=0;k<4;k++){
            int tox = x+dx[k];
            int toy = y+dy[k];
            if(tox>=-1e6 && tox<=1e6 && toy>=-1e6 && toy<=1e6){
                if(used[{tox,toy}]==0){
                    if(ctr[{tox,toy}]==1){
                        q.push({tox,toy});
                        used[{tox,toy}]++;
                        dist[{tox,toy}] = dist[{x,y}]+1;
                        pt[{tox,toy}] = pt[{x,y}];
                    }
                }
            }
        }
    }


}

void solve() {
    int n;
    cin>>n;
    vector<pii> a;

    vector<pii> good;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        ctr[{x,y}]++;
        a.pb({x,y});
    }

    for(int i=0;i<n;i++){
        int x = a[i].first;
        int y = a[i].second;

        for(int k=0;k<4;k++){
            int tox = x+dx[k];
            int toy = y+dy[k];
            if(tox>=-1e6 && tox<=1e6 && toy>=-1e6 && toy<=1e6){
                if(ctr[{tox,toy}]==0){
                    good.pb({x,y});
                    pt[{x,y}] = {tox,toy};
                    dist[{x,y}] = 1;
                }
            }
        }
    }

    bfs(good);
    
    for(int i=0;i<n;i++){
        cout<<pt[{a[i].first, a[i].second}].first<<' '<<pt[{a[i].first, a[i].second}].second<<'\n';
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    //cin>>tt;
    while (tt--) {
        solve();
    }

    return 0;
}

