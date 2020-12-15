// chrono::system_clock::now().time_since_epoch().count()
#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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



struct segtreeMN {

    vl tree;
    int size;

    void init(int n){
        size = 1;
        while(size < n) size*=2;
        tree.assign(2*size-1,0);
    }
    void build(vl &a,int x, int lx, int rx){
        if(rx-lx == 1){
            if(lx<a.size())
                tree[x] = a[lx];
        }else{
            int m = (lx+rx)/2;
            build(a,2*x+1,lx,m);
            build(a,2*x+2,m,rx);
            tree[x] = min(tree[2*x+1],tree[2*x+2]);
        }
    }

    void build(vl &a){
        init(a.size());
        build(a,0,0,size);
    }


    ll sum(int l, int r, int x, int lx, int rx){
        if(l>=rx || lx>=r){
            return 999999999999;
        }
        if(lx>=l && rx<=r){
            return tree[x];
        }
        int m = (rx+lx)/2;
        ll s1 = sum(l,r,2*x+1,lx,m);
        ll s2 = sum(l,r,2*x+2,m,rx);
        return min(s1,s2);
    }

    ll sum (int l,int r){
        return sum(l,r,0,0,size);
    }

};
struct segtreeMX {

    vl tree;
    int size;

    void init(int n){
        size = 1;
        while(size < n) size*=2;
        tree.assign(2*size-1,0);
    }
    void build(vl &a,int x, int lx, int rx){
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

    void build(vl &a){
        init(a.size());
        build(a,0,0,size);
    }

    

    ll sum(int l, int r, int x, int lx, int rx){
        if(l>=rx || lx>=r){
            return -999999999999;
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

vi g[200100];
int h[200100];
ll cnt[200100];
bool used[200100];
int k =0;
vi cycle;

void dfs1(int v){
    used[v] = true;
    for(auto x: g[v]){
        if(!used[x]){
            h[x] = v;
            dfs1(x);
        }else{
            if(x!=h[v] && cycle.size()==0){
                int cur = v;

                while(cur!=x){
                    cycle.pb(cur);
                    cur = h[cur];
                }
                cycle.pb(x);
                
                
            }
        }
    }
}
void dfs2(int v){
    used[v] = 1;
    cnt[v] =1;
    for(auto x: g[v]){
        if(!used[x]){
            dfs2(x);
            cnt[v] += cnt[x];
        }
    }
}


void solve() {
    int n;
    cin>>n;
    cycle.clear();
    for(int i=0;i<=n;i++){
        g[i].clear();
        h[i] = -1;
        used[i] = 0;
    }
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }

    h[1] = 1;
    dfs1(1);
    for(int i=0;i<=n;i++){
        used[i] = 0;
    }
    for(auto x: cycle){
        used[x] = 1;
    }

    for(auto x: cycle){
        dfs2(x);
    }
    ll ans = 0;
    for(int x: cycle){
        ans+=cnt[x]*(cnt[x]-1)/2;
        ans+=cnt[x]*(n-cnt[x]);
    }
    cout<<ans<<'\n';

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

