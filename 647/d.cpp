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
        return n;
    }

    if(x%2==0){
        ll a = powM(n,x/2);
        return (a*a);
    }else{
        return (n*powM(n,x-1));
    }
}

ll C(int n, int k){
    return (fact(n) * powM((fact(k)*fact(n-k))%MOD,MOD-2))%MOD;
}

ll A(int n, int k){
    return (fact(n) * powM(fact(n-k)%MOD,MOD-2))%MOD;
}

priority_queue<pair<int,int>> g[500100];
bool used[500100];
int nm[500100];
bool flag = true;
vector<int> ans;


void dfs(int v){
    int prev = nm[v];
    ans.pb(v);
    while(!g[v].empty()){
        pair<int,int> cur = g[v].top();
        g[v].pop();
        if(prev-cur.F>1){
            flag = false;
        }
        prev = cur.F;
    }
    if(prev!=1){
        flag = false;
    }
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> a(m);
    for(int i=0;i<m;i++){
        cin>>a[i].F>>a[i].S;
    }
    vector<pair<int,int>> t(n);
    for(int i=1;i<=n;i++){
        cin>>nm[i];
        t[i-1].F = nm[i];
        t[i-1].S = i;
    }
    for(int i=0;i<m;i++){
        int u = a[i].F;
        int v = a[i].S;
        if(nm[u]>nm[v]){
            g[u].push({nm[v],v});
        }else if(nm[u]<nm[v]){
            g[v].push({nm[u],u});
        }else{
            cout<<-1<<'\n';
            return;
        }
    }

    sort(rall(t));

    for(int i=0;i<n;i++){
        dfs(t[i].S);
    }   
    reverse(all(ans));
    if(flag){
        for(auto x: ans){
            cout<<x<<' ';
        }
        cout<<'\n';
    }else{
        cout<<-1<<'\n';
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
