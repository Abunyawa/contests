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

vi g[200100];
int used[200100];
int p[200100];
int in[200100];
int meet=-1, good=-1;
int n,m,s;


void dfs(int v, int mark){
    used[v] = mark;

    for(int to: g[v]){
        if(to==s) continue;
        if(!used[to]){
            p[to] = v;
            dfs(to, mark);
        }else if(used[to]!= mark){
            meet = to;
            good = v;
        }
    }

}

void solve() {
    cin>>n>>m>>s;

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
    }
    int ptr = 1;
    for(int to: g[s]){
        if(!used[to]){
            p[to] = s;
            dfs(to, ptr++);
        }else{
            meet = to;
            good = s;
        }
        if(meet!=-1){
            vi path1;
            path1.pb(meet);
            int cur = good;
            while(cur!=s){
                path1.pb(cur);
                cur = p[cur];
            }

            path1.pb(s);

            vi path2;
            cur = meet;
            while(cur!=s){
                path2.pb(cur);
                cur = p[cur];
            }
            path2.pb(s);

            reverse(all(path1));
            reverse(all(path2));
            cout<<"Possible\n";
            cout<<path1.size()<<'\n';
            for(int k: path1){
                cout<<k<<' ';
            }
            cout<<'\n';

            cout<<path2.size()<<'\n';
            for(int k: path2){
                cout<<k<<' ';
            }
            cout<<'\n';

            return;
        }
    }

    cout<<"Impossible\n";
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

