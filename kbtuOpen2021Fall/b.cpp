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

int ctr = 1;
map<string,int> ver;
int d[100100];
int p[100100];
bool used[100100];
vi g[100100];

vi depth;
int lv = 0;


void dfs(int v, int par){
            
    int ret = 0;
    for(int to: g[v]){
        if(to!=par){
            d[to] = d[v]+1;
            p[to] = v;
            dfs(to,v);        
        }
    }
}


void countLeaves(int v){
    
    //cout<<v<<"nnnnnnnnn\n";
    used[v] = true;
    int n = 0;
    for(int to: g[v]){
        if(!used[to]){
            //cout<<to<<endl;
            n++;
            countLeaves(to);
        }
    }

    if(n==0){
        lv++;
    }else if (g[v].size()==1){
        lv++;    
    }
}


void solve() {
    int n;
    cin>>n;
    string root;
    cin>>root;
    ver[root] = ctr++;
    for(int i=0;i<n-1;i++){
        string x, y;
        cin>>x>>y;

        if(ver[x]==0){
            ver[x] = ctr++;
        }

        if(ver[y]==0){
            ver[y] = ctr++;
        }
        g[ver[x]].pb(ver[y]);
        g[ver[y]].pb(ver[x]);
    }
    dfs(1,0);
    int mx=1;
    for(int i=2;i<=n;i++){
        if(d[mx]<d[i]){
            mx= i;
        }
    }
    //cout<<mx<<endl;
    d[mx] = 0;
    dfs(mx,0);

    int st = mx;
    mx = 0;


    for(int i=1;i<=n;i++){
        if(i==st){
            continue;
        }
        if(d[mx]<d[i]){
            mx= i;
        }
    }


    int cur = mx;
    while(cur!=st){
        //cout<<cur<<endl;
        used[cur] = true;
        cur = p[cur];
    }
    used[st] = true;
    //cout<<d[8]<<endl;
    //cout<<st<<' '<<mx<<endl;
    vi leaves;
    for(int i=1;i<=ctr-1;i++){
        if(i==st || i == mx){

            continue;
        }

        if(g[i].size()==1){
            //cout<<i<<endl;
            leaves.pb(i);
        }
    }
    int ans = 0;
    /*
    for(auto x: ver){
        cout<<x.fi<<' '<<x.se<<endl;
    }
    */
    for(int to: leaves){
        //cout<<to<<endl;
        if(!used[to]){
            lv = 0;
            countLeaves(to);
            //cout<<lv<<' '<<to<<endl;
            if(lv<=2){
                ans += 1;
            }else{
                ans += lv-1;
            }
        }
    }

    cout<<ans+1<<'\n';
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

