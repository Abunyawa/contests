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
ll const MOD = 1000000007;

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

ll const MAXN = 300100;
long long t[4*MAXN],a[MAXN+10];


void build(int v, int tl, int tr){
    if(tl==tr){
        t[v] = a[tl];
        return;
    }else{
        int tm = (tl+tr)/2;
        build(2*v,tl,tm);
        build(2*v+1,tm+1,tr);
        t[v] = max(t[2*v],t[2*v+1]);
        return;
    }
}

void change(int v, int tl, int tr, int pos, ll x){
    if(tr<pos || pos < tl){
        return;
    }
    if(tl==tr){
        a[tl]=x;
        t[v]=x;
        return; 
    }
    int tm = (tl+tr)/2;
    change(v*2,tl, tm,pos,x);
    change(v*2+1,tm+1,tr,pos,x);
    t[v] = max(t[v*2],t[v*2+1]);
}

long long sum(int v, int tl, int tr, int l, int r){
    if(tr<l || r<tl){
        return -999999999999;
    }
    if(l <= tl && tr <= r){
        return t[v];  
    }   
    //push(v,tl,tr);
    int tm = (tl+tr)/2;
    long long sl = sum(v*2,tl,tm,l,r);
    long long sr = sum(v*2+1,tm+1,tr,l,r);
    return max(sl,sr);
    
}





void solve(){
    int n;
    cin>>n;
    vl h(n+1);
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    vl b(n+1);
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    build(1,0,n);
    for(int i=1;i<=n;i++){
        ll best = sum(1,0,n,0,h[i]-1);
        change(1,0,n,h[i],best+b[i]);
        
    }
    cout<<sum(1,0,n,1,n)<<'\n';

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
