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
ll ans = 1;
int mX[] = {1,-1,0,0};
int mY[] = {0,0,1,-1};
int n,m;

char g[2010][2010];
pair<ll,ll> was[2010][2010];
bool used[2010][2010];

void bfs(int x, int y,ll l, ll r){
    used[x][y] = true;
    priority_queue<pair<pll,pii>> q;
    q.push({{l,r},{x,y}});

    while(!q.empty()){
        int curX = q.top().S.F;
        int curY = q.top().S.S;
        ll stepL = q.top().F.F;
        ll stepR = q.top().F.S;
        q.pop();
        g[curX][curY] = '+';
        for(int i = 0;i<4;i++){
            int toX = curX+mX[i];
            int toY = curY+mY[i];
            if(i==2){
                if(stepR<=0){
                    continue;
                }
            }
            if(i==3){
                if(stepL<=0){
                    continue;
                }
            }
            if(i==2){
                if(toX>=0 && toX<n && toY>=0 && toY<m && !used[toX][toY] && g[toX][toY]=='.'){
                    if(!used[toX][toY]){
                        used[toX][toY]=true;
                        ans++;
                    }
                    q.push({{stepL,stepR-1},{toX,toY}});
                }
            }else if(i==3){
                if(toX>=0 && toX<n && toY>=0 && toY<m && !used[toX][toY] && g[toX][toY]=='.'){
                    if(!used[toX][toY]){
                        used[toX][toY]=true;
                        ans++;
                    }
                    q.push({{stepL-1,stepR},{toX,toY}});
                }
            }else{
                if(toX>=0 && toX<n && toY>=0 && toY<m && !used[toX][toY] && g[toX][toY]=='.'){
                    if(!used[toX][toY]){
                        used[toX][toY]=true;
                        ans++;
                    }
                    q.push({{stepL,stepR},{toX,toY}});
                }
            }
              
        }
    }

}


void solve(){
    int r,c;
    cin>>n>>m;
    cin>>r>>c;
    r--;
    c--;
    ll li,ri;
    cin>>li>>ri;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
        }
    }
    bfs(r,c,li,ri);
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
