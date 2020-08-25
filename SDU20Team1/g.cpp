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

int d[1010][1010];
int n,m;
bool used[1010][1010];
int mX[] = {0,0,1,-1};
int mY[] = {1,-1,0,0};
bool horu[1010][1010];
bool veru[1010][1010];
vector<pii> hor;
vector<pii> ver;



void solve(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char x;
            cin>>x;
            if(x=='.'){
                d[i][j]=0;
            }else{
                d[i][j] =1;
            }
        }
    }
    
    for(int i=0;i<n;i++){
        int last = -1;
        for(int j=0;j<m;j++){
            if(d[i][j]==1){
                if(last==-1){
                    last = j;
                }else{
                    if(!horu[last][j-1]){
                        hor.pb({last,j-1});
                        horu[last][j-1] = true;;
                    }
                    last = j;
                }
            }
        }
    }
    for(int i=0;i<m;i++){
        int last = -1;
        for(int j=0;j<n;j++){
            if(d[j][i]==1){
                if(last==-1){
                    last = j;
                }else{
                    if(!veru[last][j-1]){
                        ver.pb({last,j-1});
                        veru[last][j-1] = true;;
                    }
                    last = j;
                }
            }
        }
    }
    
    
    for(int i=0;i<hor.size();i++){
        int ctr = 0;
        for(int j=0;j<hor.size();j++){
            if(i!=j){
                if(hor[i].F>=hor[j].F && hor[i].S<=hor[j].S){
                    hor.erase(hor.begin()+j);
                    if(j<i){
                        i--;
                    }
                    j--;
                }
            }
        }
    }
    

    sort(all(hor));
    /*
    for(auto x: hor){
        cout<<x.F<<' '<<x.S<<'\n';
    }
    cout<<'\n'<<'\n';
    */
    int ans = 0;
    for(int i=0;i<hor.size();i++){
        int next = i+1;
        while(next<hor.size() && hor[i].S>=hor[next].F){
            next++;
        }
        ans++;
        i = next-1;
    }


    for(int i=0;i<ver.size();i++){
        for(int j=0;j<ver.size();j++){
            if(i!=j){
                if(ver[i].F>=ver[j].F && ver[i].S<=ver[j].S){
                    ver.erase(ver.begin()+j);
                    if(j<i){
                        i--;
                    }
                    j--;
                }
            }
        }
    }
    sort(all(ver));
    /*
    for(auto x: ver){
        cout<<x.F<<' '<<x.S<<'\n';
    }
    cout<<'\n';
    */
    for(int i=0;i<ver.size();i++){
        int next = i+1;
        while(next<ver.size() && ver[i].S>=ver[next].F){
            next++;
        }
        ans++;
        i = next-1;
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
