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

double fact(double n){
    double ans = 1;
    for(double i=2;i<=n;i++){
        ans = (ans*i);
    }

    return ans;
}


double C(double n, double k){
    return fact(n) /(fact(k)*fact(n-k));
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

double xs,ys,zs;
double xa,ya,za,rad;
double xt,yt,zt;
double vx,vy,vz;

double func(double times){
    double newX = xs+times*vx;
    double newY = ys+times*vy;
    double newZ = zs+times*vz;
    return sqrt((xa-newX)*(xa-newX) + (ya-newY)*(ya-newY)+ (za-newZ)*(za-newZ));
}


void solve(){
    
    cin>>xs>>ys>>zs;
    cin>>xa>>ya>>za>>rad;
    cin>>xt>>yt>>zt;
    vx = xt-xs;
    vy = yt-ys; 
    vz = zt-zs;
    double l = 0;
    double r = 1000000;
    while(r-l>0.000000000001){
        double a = (l*2+r)/3;
        double b = (l+r*2)/3;
        if(func(a)<func(b)){
            r = b;
        }else{
            l = a;
        }
    }
    double ans = (l+r)/2;
    double mnD = func(ans);
    if(mnD-rad<=0.0000001){
        printf("HIT\n");    
    }else{
        printf("MISS\n");
    }
    printf("%.16f",mnD);
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    abu;
    said;
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
