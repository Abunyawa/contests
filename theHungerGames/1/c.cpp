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

struct segtree {

    vl tree;
    int size;

    void init(int n){
        size = 1;
        while(size < n) size*=2;
        tree.assign(2*size-1,0);
    }
    void build(vi &a,int x, int lx, int rx){
        if(rx-lx == 1){
            if(lx<a.size())
                tree[x] = a[lx];
        }else{
            int m = (lx+rx)/2;
            build(a,2*x+1,lx,m);
            build(a,2*x+2,m,rx);
            tree[x] = max(tree[2*x+1],tree[2*x+2]);
        }
    }

    void build(vi &a){
        init(a.size());
        build(a,0,0,size);
    }

    void set(int i, int v, int x, int lx, int rx){
        if(rx-lx==1){
            tree[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        if(i<m){
            set(i,v,2*x+1,lx,m);
        }else{
            set(i,v,2*x+2,m,rx);
        }
        tree[x] = max(tree[2*x+1], tree[2*x+2]);
    }

    void set(int i, int v){
        set(i,v,0,0,size);
    }

    ll sum(int l, int r, int x, int lx, int rx){
        if(l>=rx || lx>=r){
            return -10000000;
        }
        if(lx>=l && rx<=r){
            return tree[x];
        }
        int m = (rx+lx)/2;
        ll s1 = sum(l,r,2*x+1,lx,m);
        ll s2 = sum(l,r,2*x+2,m,rx);
        return max(s1,s2);
    }

    ll sum (int l,int r){
        return sum(l,r,0,0,size);
    }

};
const int N = 5010;
int d[N][N];
int pref[N][N];
int n,m;

void pre(){
    for(int i=1;i<N;i++){
        for(int j=1;j<N;j++){
            pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
            if(d[i][j]==1){
                pref[i][j]++;
            }
        }
    }
}

int box(int i, int j, int k){
    return pref[i][j] - pref[i-k][j] - pref[i][j-k] + pref[i-k][j-k];
}

int count(int k){
    int ans = 0;
    for(int i=k;i<=n+k-1;i+=k){
        for(int j = k;j<=m+k-1;j+=k){
            int ones = box(i,j,k);
            //cout<<ones<<' '<<i<<' '<<j<<'\n';
            ans += min(ones,k*k-ones);
        }
    }


    return ans;
}

void solve() {
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            char x;
            cin>>x;
            d[i][j] = x-'0';
        }
    }
    pre();
    
    /*for(int i=1;i<=6;i++){
        for(int j = 1;j<=6;j++){
            cout<<pref[i][j]<<' ';
        }
        cout<<'\n';
    }
    */
    int ans = max(n,m)*max(n,m);
    
    
    for(int k = 2;k<=max(n,m);k++){
        //cout<<count(k)<<'\n';
        ans = min(ans, count(k));
    }
    cout<<ans<<'\n';


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

