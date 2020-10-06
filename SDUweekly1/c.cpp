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


void solve(){
    int n;
    cin>>n;
    ll x,y;
    cin>>y>>x;
    y = -1*y;
    vector<pll> b;
    vector<pll> r;
    for(int i = 0;i<n;i++){
        char tp;
        cin>>tp;
        ll u,v;
        cin>>v>>u;
        v*=-1;
        if(tp == 'B'){
            b.pb({u,v});
        }else if(tp=='R'){
            r.pb({u,v});
        }else{
            b.pb({u,v});
            r.pb({u,v});
        }
    }
    bool flag1= false;
    bool flag2= false;
    bool flag3= false;
    bool flag4= false;
    pll minUR = {10000000000000,10000000000000};
    pll minLL = {-1000000000000,-100000000000000};
    pll minUL = {-100000000000000,100000000000000};
    pll minLR = {100000000000000,-100000000000000};
    
    for(auto c: b){
        if(c.F > x && c.S > y){
            //cout<<'h'<<'\n';
            if(c.F-c.S == x-y){
                if(c.F<minUR.F && c.S<minUR.S){
                    flag1 = true;
                    minUR = c;
                }
            }
        }else if(c.F<x && c.S<y){
            if(c.F-c.S == x-y){
                if(c.F>minLL.F && c.S>minLL.S){
                    flag2 = true;
                    minLL = c;
                }
            }
        }else if(c.F<x && c.S>y){
            if(c.F+c.S == x+y){
                if(c.F>minUL.F && c.S<minUL.S){
                    flag3 = true;
                    minUL = c;
                }
            }
        }else{
            if(c.F+c.S == x+y){
                if(c.F<minLR.F && c.S>minLR.S){
                    flag4 = true;
                    minLR = c;
                }
            }
        }
    } 
    for(auto c: r){
        if(c.F > x && c.S > y){
            if(c.F-c.S == x-y){
                if(c.F<minUR.F && c.S<minUR.S){
                    flag1 = false;
                }
            }
        }else if(c.F<x && c.S<y){
            if(c.F-c.S == x-y){
                if(c.F>minLL.F && c.S>minLL.S){
                    flag2 = false;
                }
            }
        }else if(c.F<x && c.S>y){
            if(c.F+c.S == x+y){
                if(c.F>minUL.F && c.S<minUL.S){
                    flag3 = false;
                }
            }
        }else{
            if(c.F+c.S == x+y){
                if(c.F<minLR.F && c.S>minLR.S){
                    flag4 = false;
                }
            }
        }
    }
    
        
    bool flag5= false;
    bool flag6= false;
    bool flag7= false;
    bool flag8= false;
    ll minU = 100000000000;
    ll minR = 100000000000;
    ll minL = -100000000000;
    ll minD = -1000000000000;
    for(auto c: r){
        if(x == c.F){
            if(c.S > y){
                flag5 = true;
                minU = min(minU,c.S);
            }else{
                flag6 = true;
                minD = max(minD,c.S);
            }
        }   
        if(y == c.S){
            if(c.F > x){
                flag7 = true;
                minR = min(minR,c.F);
            }else{
                flag8 =true;
                minL = max(minL,c.F);
            }
        }
    }
    //cout<<flag5<<flag6<<flag7<<flag8<<'\n';
    for(auto c: b){
        if(x == c.F){
            if(c.S > y){
                if(c.S<minU) flag5 = false;
            }else{
                if(c.S>minD) flag6 = false;
            }
        }   
        if(y == c.S){
            if(c.F > x){
                if(c.F<minR) flag7 = false;
            }else{
                if(c.F>minL) flag8 = false;
            }
        }
    }
    //cout<<flag5<<flag6<<flag7<<flag8<<'\n';   
    
    
    if(flag1 || flag2 || flag3 || flag4 || flag5 || flag6 || flag7 || flag8){
        yes();
    }else{
        no();
    }
    
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