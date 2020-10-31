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
#define watch(x) (#x)<<" : "<<(x)<<" ";
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
ll c[7];
ll countP3(ll pyr,ll y){
    return pyr*c[1]+pyr*c[3] + (y-pyr)*c[2];
}
ll countP4(ll pyr,ll y){
    return pyr*c[6]+pyr*c[4] + (abs(y)-pyr)*c[5];
}

ll countP1(ll movL, ll x, ll y){
    ll path = movL*c[6] + (x-movL)*c[1];
    ll yd = y - (x-movL);
    if(yd>=0){
        ll l = 0;
        ll r = yd;
        while(r-l>1){
            ll a = (l * 2 + r) / 3;
            ll b = (l + r * 2) / 3;
            if(  countP3(a,yd)< countP3(b,yd)){
                r = b;
            }else{
                l = a;
            }
        }

        path+=countP3((l + r) / 2,yd);
    }else{

        ll l = 0;
        ll r = abs(yd);
        while(r-l>1){
            ll a = (l * 2 + r) / 3;
            ll b = (l + r * 2) / 3;
            if(  countP4(a,abs(yd))< countP4(b,abs(yd))){
                r = b;
            }else{
                l = a;
            }
        }

        path+=countP4((l + r) / 2,abs(yd));
    }
    return path;
}
ll countP2(ll movL, ll x, ll y){
    ll path = movL*c[4] + (abs(x)-movL)*c[3];
    ll yd = y + movL;
    
    if(yd>=0){
        ll l = 0;
        ll r = yd;
        while(r-l>1){
            ll a = (l * 2 + r) / 3;
            ll b = (l + r * 2) / 3;
            if(  countP3(a,yd)< countP3(b,yd)){
                r = b;
            }else{
                l = a;
            }
        }

        path+=countP3((l + r) / 2,yd);
    }else{

        ll l = 0;
        ll r = abs(yd);
        while(r-l>1){
            ll a = (l * 2 + r) / 3;
            ll b = (l + r * 2) / 3;
            if(  countP4(a,yd)< countP4(b,yd)){
                r = b;
            }else{
                l = a;
            }
        }

        path+=countP4((l + r) / 2,abs(yd));
    }
    return path;
}


void solve(){
    ll x,y;
    cin>>x>>y;
    for(int i=1;i<=6;i++){
        cin>>c[i];
    }
    ll ans;
    
    if(x<=0){
        ll r = abs(x);
        ll l = 0;
        while(r-l>1){
            ll a = (l * 2 + r) / 3;
            ll b = (l + r * 2) / 3;
            if( countP2(a,x,y) < countP2(b,x,y)){
                r = b;
            }else{
                l = a;
            }
        }
        cout<<countP2((l + r) / 2,x,y)<<'\n';
    }else{
        ll r = x;
        ll l = 0;
        while(r-l>1){
            ll a = (l * 2 + r) / 3;
            ll b = (l + r * 2) / 3;
            if( countP1(a,x,y) < countP1(b,x,y)){
                r = b;
            }else{
                l = a;
            }
        }
        cout<<countP1((l + r) / 2,x,y)<<'\n';
    }
}

int main(){
    abu;
    said;
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
