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
    ll n,k;
    cin>>n>>k;
    ll l1,r1;
    cin>>l1>>r1;
    ll l2,r2;
    cin>>l2>>r2;
    if(l1>l2){
        ll tmp = l1;
        l1 = l2;
        l2 = tmp;
        tmp = r1;
        r1 = r2;
        r2 = tmp;
    }
    if(l1==l2){
        if(r2>r1){
            ll tmp = l1;
            l1 = l2;
            l2 = tmp;
            tmp = r1;
            r1 = r2;
            r2 = tmp;
        }
    }
    ll distBet;
    ll totD;
    ll cur = 0;
    if(r1>=r2){
        cur = n*(r2-l2);
        distBet = 0;
        totD = r1-l1;
    }else{
        totD = r2-l1;
        if(r1>=l2){
            cur = n*(r1-l2);
            distBet = 0;
        }else{
            distBet = l2-r1;
        }
    }
    totD-=cur/n;
    //cout<<cur<<'\n';
    if(cur>=k){
        cout<<0<<'\n';
        return;
    }
    k-=cur;
    /*
    cout<<cur<<'\n';
    cout<<cur/n<<'\n';
    cout<<l1<<r1<<'\n';
    cout<<l2<<r2<<'\n';
    cout<<distBet<<'\n';
    cout<<totD<<'\n';
    */
    ll ans = 0;
    if(k>=totD*n){
        ans = n*(totD*2 - (r1-l1 )- (r2-l2));
        ans += 2*(k - totD*n);
    }else{
        int mn = k/totD;
        //cout<<mn<<'\n';
        ans = mn*(totD*2 - (r1-l1) - (r2-l2));
        //cout<<ans<<'\n';
        k %= totD;
        if(mn!=0){
            ans += min(distBet+k,k*2);
        }else{
            ans += distBet+k;
        }
    }
    cout<<ans<<'\n';
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
