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
bool isObr[300100];

void solve(){
    int n;
    cin>>n;
    vi a(n);
    stack<int> r;
    stack<int> c;
    queue<int> on;
    queue<int> tw;
    queue<int> th;
    vector<bool> used(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
        r.push(i);
        if(a[i]==1){
            on.push(i);
        }else if(a[i]==2){
            tw.push(i);
        }else if(a[i]==3){
            th.push(i);
        }
    }
    vector<pll> ans;
    while(!on.empty() && !tw.empty() && !th.empty()){
        if(on.front()<tw.front() && on.front()<th.front()){
            if(!r.empty()){
                ans.pb({on.front(),r.top()});
                on.pop();
                r.pop();
            }else{
                cout<<-1<<'\n';
                return;
            }
        }else if(tw.front()<on.front() && tw.front()<th.front()){
            if(!r.empty()){
                ans.pb({tw.front(),r.top()});
                tw.pop();
                ans.pb({on.front(),r.top()});
                on.pop();
                r.pop();
            }else{
                cout<<-1<<'\n';
                return;
            }
        }else if(th.front()<on.front() && th.front()<tw.front()){
            if(!r.empty()){
                ans.pb({th.front(),r.top()});
                th.pop();
                if(!on.empty() && !th.empty() && !tw.empty()){
                    if(on.front()<th.front() && on.front()<tw.front()){
                        ans.pb({on.front(),r.top()});
                    }else if(tw.front()<th.front() && tw.front()<on.front()){
                        ans.pb({tw.front(),r.top()});
                    }else{
                        ans.pb({th.front(),r.top()});
                    }
                }else if(!on.empty() && !th.empty()){
                    if(on.front()<th.front()){
                        ans.pb({on.front(),r.top()});
                    }else{
                        ans.pb({th.front(),r.top()});
                    }
                }else if(!on.empty() && !tw.empty()){
                    if(on.front()<tw.front()){
                        ans.pb({on.front(),r.top()});
                    }else{
                        ans.pb({tw.front(),r.top()});
                    }
                }else if(!tw.empty() && !th.empty()){
                    if(tw.front()<th.front()){
                        ans.pb({tw.front(),r.top()});
                    }else{
                        ans.pb({th.front(),r.top()});
                    }
                }else if(!on.empty()){ 
                    ans.pb({on.front(),r.top()});
                }else if(!th.empty()){ 
                    ans.pb({th.front(),r.top()});
                }else if(!tw.empty()){ 
                    ans.pb({tw.front(),r.top()});
                }
                r.pop();
            }else{
                cout<<-1<<'\n';
                return;
            }
        }
    }

    while(!on.empty() && !tw.empty()){
        if(on.front()<tw.front()){
            if(!r.empty()){
                ans.pb({on.front(),r.top()});
                on.pop();
                r.pop();
            }else{
                cout<<-1<<'\n';
                return;
            }
        }else{
            if(!r.empty()){
                ans.pb({tw.front(),r.top()});
                tw.pop();
                ans.pb({on.front(),r.top()});
                on.pop();
                r.pop();
            }else{
                cout<<-1<<'\n';
                return;
            }
        }
    }

    while(!on.empty() && !th.empty()){
        if(on.front()<th.front()){
            if(!r.empty()){
                ans.pb({on.front(),r.top()});
                on.pop();
                r.pop();
            }else{
                cout<<-1<<'\n';
                return;
            }
        }else{
            if(!r.empty()){
                ans.pb({th.front(),r.top()});
                th.pop();
                if(!on.empty() && !th.empty() && !tw.empty()){
                    if(on.front()<th.front() && on.front()<tw.front()){
                        ans.pb({on.front(),r.top()});
                    }else if(tw.front()<th.front() && tw.front()<on.front()){
                        ans.pb({tw.front(),r.top()});
                    }else{
                        ans.pb({th.front(),r.top()});
                    }
                }else if(!on.empty() && !th.empty()){
                    if(on.front()<th.front()){
                        ans.pb({on.front(),r.top()});
                    }else{
                        ans.pb({th.front(),r.top()});
                    }
                }else if(!on.empty() && !tw.empty()){
                    if(on.front()<tw.front()){
                        ans.pb({on.front(),r.top()});
                    }else{
                        ans.pb({tw.front(),r.top()});
                    }
                }else if(!tw.empty() && !th.empty()){
                    if(tw.front()<th.front()){
                        ans.pb({tw.front(),r.top()});
                    }else{
                        ans.pb({th.front(),r.top()});
                    }
                }else if(!on.empty()){ 
                    ans.pb({on.front(),r.top()});
                }else if(!th.empty()){ 
                    ans.pb({th.front(),r.top()});
                }else if(!tw.empty()){ 
                    ans.pb({tw.front(),r.top()});
                }
                r.pop();
            }else{
                cout<<-1<<'\n';
                return;
            }
        }
    }
    if(!tw.empty() || !th.empty()){
        cout<<-1<<'\n';
        return;
    }
    while(!on.empty()){
        if(!r.empty()){
            ans.pb({on.front(),r.top()});
            on.pop();
            r.pop();
        }else{
            cout<<-1<<'\n';
            return;
        }
    }
    cout<<ans.size()<<'\n';
    for(auto x: ans){
        cout<<n-x.S<<' '<<x.F+1<<'\n';
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