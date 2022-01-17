// chrono::system_clock::now().time_since_epoch().count()
#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

void yes(){
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}
ll fact[5010];
ll const MOD = 998244353;


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
    return (fact[n] * powM((fact[k]*fact[n-k])%MOD,MOD-2))%MOD;
}

void solve() {
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vi a;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            a.pb(i);
        }
    }
    ll ans = 1;
    for(int i=0;i+k-1<a.size();i++){
        int l;
        if(i==0){
            l = 0;
        }else{
            l = a[i-1]+1;
        }

        int r;
        if(i+k-1==a.size()-1){
            r = n-1;
        }else{
            r = a[i+k]-1;
        }

        ll cur = C(r-l+1,k)-1;
        if(cur<0){
            cur+=MOD;
        }
        ans = (ans+cur)%MOD;
    }
    

    for(int i=0;i+k-2<a.size();i++){
        int l;
        if(i==0){
            l = 0;
            continue;
        }else{
            l = a[i-1]+1;
        }

        int r;
        if(i+k-2==a.size()-1){
            r = n-1;
            continue;
        }else{
            r = a[i+k-1]-1;
        }

        ll cur = C(r-l+1,k-1)-1;
        if(cur<0){
            cur+=MOD;
        }
        ans = ans-cur;
        if(ans<0){
            ans+=MOD;
        }
    }

    cout<<ans%MOD<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fact[0] = fact[1] = 1;

    for(int i=2;i<5001;i++){
        fact[i] = (fact[i-1]*i)%MOD;
    }
    int tt = 1;
    //cin>>tt;
    while (tt--) {
        solve();
    }

    return 0;
}

