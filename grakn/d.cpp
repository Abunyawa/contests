#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second
#define vi vector<int>
#define vl vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define watch(x) (#x)<<" : "<<(x)<<"\t"
#define abu ios_base::sync_with_stdio(0)
#define said cin.tie(0)
using namespace std;
ll const MOD = 998244353;

void yes(){
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}

ll fact(int n){
    ll ans = 1;
    for(int i=2;i<=n;i++){
        ans = (ans*i)%MOD;
    }

    return ans;
}

ll powM(int n, int x){
    if(x==0){
        return 1;
    }
    if(x==1){
        return n%MOD;
    }

    if(x%2==0){
        ll a = powM(n,x/2);
        return (a*a)%MOD;
    }else{
        return (n*powM(n,x-1))%MOD;
    }
}

ll C(int n, int k){
    return (fact(n) * powM((fact(k)*fact(n-k))%MOD,MOD-2))%MOD;
}

ll A(int n, int k){
    return (fact(n) * powM(fact(n-k)%MOD,MOD-2))%MOD;
}

void add_self(int &a, int b){
    a += b;
    if(a>=MOD){
        a-=MOD;
    }
}

void sub_self(int &a, int b){
    a -= b;
    if(a<0){
        a+=MOD;
    }
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
            tree[x] = tree[2*x+1]+tree[2*x+2];
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
        tree[x] = tree[2*x+1] + tree[2*x+2];
    }

    void set(int i, int v){
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
        return s1+s2;
    }

    ll sum (int l,int r){
        return sum(l,r,0,0,size);
    }

};


void solve(){
    int n,m;
    cin>>n>>m;
    vector<pll> g(n);
    for(int i = 0;i<n;i++){
        cin>>g[i].F>>g[i].S;
    }
    vector<pll> p(m);
    for(int i=0;i<m;i++){
        cin>>p[i].F>>p[i].S;
    }
    sort(rall(p));
    sort(rall(g));
    vector<pll> need(n,{0,0});
    ll curR = 0;
    ll curU = 0;
    for(int i=0;i<n;i++){
        for(int j = 0;j<m;j++){
            ll curX = g[i].F;
            ll curY = g[i].S;
            ll projX = p[j].F;
            ll projY = p[j].S;
            //cout<<watch(curX)<<watch(curY)<<watch(projX)<<watch(projY)<<'\n';
            if(curX<=projX && curY<=projY){
                need[i].F = max(need[i].F,projX-curX+1);
                need[i].S = max(need[i].S,projY-curY+1);
            }
        }
    }
    
    for(auto x: need){
        cout<<x.F<<' '<<x.S<<'\n';
    }
    
    ll ans = 100000000000000;
    for(int i=0;i<n;i++){
        ll curR = need[i].F;
        ll curU = 0;
        for(int j=0;j<n;j++){
            if(i!=j){
                if(curR<need[j].F){
                    curU = max(curU,need[j].S);
                }
            }
        }
        cout<<curR+curU<<" 1 "<<i<<'\n';
        ans = min(ans,curR+curU);
    }

    for(int i=0;i<n;i++){
        ll curU = need[i].S;
        ll curR = 0;
        for(int j=0;j<n;j++){
            if(i!=j){
                if(curU<need[j].S){
                    curR = max(curR,need[j].F);
                }
            }
        }
        cout<<curR+curU<<" 2 "<<i<<'\n';

        ans = min(ans,curR+curU);
    }

    cout<<ans<<'\n';
}

int main(){
    abu;
    said;
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
