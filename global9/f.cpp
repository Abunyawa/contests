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
    vector<pair<ll,int>> a(3);
    cin>>a[0].F>>a[1].F>>a[2].F;
    a[0].S = 1;
    a[1].S = 2;
    a[2].S = 3;
    sort(all(a));
    ll y = 2*a[2].F-a[0].F-a[1].F;
    cout<<"First"<<endl;
    fflush(stdout);
    cout<<y<<endl;
    fflush(stdout);
    int x;
    cin>>x;
    /*
    a b c
    y = 2c-a-b
    if a:
        2c-b b c
        y = c-b    
    if b:
        a 2c-a c
        y = c-a
    */
    for(int i=0;i<3;i++){
        if(a[i].S==x){
            if(i==0){
                y = a[2].F-a[1].F;
                cout<<y<<endl;
                fflush(stdout);
                cin>>x;
                return;
            }
            if(i==1){
                y = a[2].F-a[0].F;
                cout<<y<<endl;
                fflush(stdout);
                cin>>x;
                return;
            }
            if(i==2){
                a[2].F += y;
                y = 2*a[2].F-a[0].F-a[1].F;
                cout<<y<<endl;
                fflush(stdout);
                cin>>x;
                if(x==a[0].S){
                    y = a[2].F-a[1].F;
                    cout<<y<<endl;
                    fflush(stdout);
                    cin>>x;
                    return;
                }else{
                    y = a[2].F-a[0].F;
                    cout<<y<<endl;
                    fflush(stdout);
                    cin>>x;
                    return;
                }
            }
        }
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
