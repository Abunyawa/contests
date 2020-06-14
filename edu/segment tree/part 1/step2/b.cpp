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
    
    vector<int> tree;
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
            tree[x] = tree[2*x+1]+tree[2*x+2];
        }
    }

    void build(vl &a){
        init(a.size());
        build(a,0,0,size);
    }

    void set(int i, int x, int lx, int rx){
        if(rx-lx==1){
            tree[x] ^= 1; 
            return;
        }
        int m = (lx+rx)/2;
        if(i<m){
            set(i,2*x+1,lx,m);
        }else{
            set(i,2*x+2,m,rx);
        }
        tree[x] = tree[2*x+1] + tree[2*x+2];

    }

    void set(int i){
        set(i,0,0,size);
    }


    int find(int k, int x, int lx, int rx){
        if(rx-lx==1){
            return lx;
        }
        if(tree[2*x+1]>k){
            return find(k,2*x+1,lx,(lx+rx)/2);
        }else{
            return find(k-tree[2*x+1],2*x+2,(lx+rx)/2,rx);
        }
    }


    int find(int k){
        return find(k,0,0,size);
    }

};



void solve(){
    int n,m;
    cin>>n>>m;
    segtree st;
    vl a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    st.build(a);
    for(int i=0;i<m;i++){
        int c;
        cin>>c;
        if(c==1){
            int pos;
            cin>>pos;
            st.set(pos);
        }else{
            int k;
            cin>>k;
            cout<<st.find(k)<<'\n';
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
