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

int par[100100];

int get(int u){
    if (u<0) return -get(-u);
    if(par[u]==u) return u;
    return par[u] = get(par[u]);
}

void union_set(int u, int v){
    u = get(u);
    v = get(v);
    //cout<<u<<' '<<v<<"inside"<<endl;
    if(abs(u)!=abs(v)){
        if(u<0){
            par[-u] = -v;
        }else{
            par[u] = v;
        }
    }
}

void solve(){
    int n;
    cin>>n;

    int a[n+2][n+2];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }

    for(int i=0;i<=n;i++){
        par[i] = i;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            //cout<<i<<' '<<j<<endl;
            if(a[i][j] < a[j][i]) union_set(i,j);
            if(a[i][j] > a[j][i]) union_set(i,-j);
            
            
        }
    }


    for(int i=1;i<=n;i++){
        if(get(i)<0) continue;
        for(int j=1;j<=n;j++){
            swap(a[i][j], a[j][i]);
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<a[i][j]<<' ';
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

