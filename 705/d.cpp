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
ll MOD = 1e9+7;

ll GCD(int a, int b, int moda, int modb){
    
}

struct segtree {

    vl tree;
    vl mods;
    int size;

    void init(int n){
        size = 1;
        while(size < n) size*=2;
        tree.assign(2*size-1,0);
        mods.assign(2*size-1,0);

    }
    void build(vl &a,int x, int lx, int rx){
        if(rx-lx == 1){
            if(lx<a.size())
                tree[x] = a[lx];
                mods[x] = 0;
        }else{
            int m = (lx+rx)/2;
            build(a,2*x+1,lx,m);
            build(a,2*x+2,m,rx);
            tree[x] = __gcd(tree[2*x+1],tree[2*x+2])%MOD;
        }
    }

    void build(vl &a){
        init(a.size());
        build(a,0,0,size);
    }

    void set(int i, ll v, int x, int lx, int rx){
        if(rx-lx==1){
            mods[x]+=(tree[x]*v)/MOD;
            tree[x] = (tree[x]*v)%MOD;
            return;
        }
        int m = (lx+rx)/2;
        if(i<m){
            set(i,v,2*x+1,lx,m);
        }else{
            set(i,v,2*x+2,m,rx);
        }
        if(mods[2*x+1]==mods[2*2+2] && mods[2*2+2]==0){
            tree[x] = __gcd(tree[2*x+1],tree[2*x+2])%MOD;
            mods[x] = 0;
        }else{
            mods[x] = 1;
            tree[x] = 1;
        }
        
    }

    void set(int i, ll v){
        set(i,v,0,0,size);
    }

    ll sum(int l, int r, int x, int lx, int rx){
        if(l>=rx || lx>=r){
            return 0;
        }
        if(lx>=l && rx<=r){
            return tree[x];
        }
        int m = (rx+lx)/2;
        ll s1 = sum(l,r,2*x+1,lx,m);
        ll s2 = sum(l,r,2*x+2,m,rx);
        if(mods[2*x+1]==mods[2*2+2] && mods[2*2+2]==0){
            return __gcd(s1,s2);
        }else{
            return 1;
        }
    }

    ll sum (int l,int r){
        return sum(l,r,0,0,size);
    }

};
void solve() {
    int n,q;
    cin>>n>>q;
    vl a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    segtree st;
    st.build(a);

    for(int i=0;i<q;i++){
        ll j,x;
        cin>>j>>x;
        st.set(j-1,x);
        cout<<st.sum(0,n)<<'\n';
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

