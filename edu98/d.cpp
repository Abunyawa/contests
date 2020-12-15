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


ll dp[200100];
ll MOD = 998244353;

ll powM(ll a, ll p){
    if(p==0){
        return 1;
    }
    if(p==1){
        return a;
    }
    if(p%2==0){
        ll tmp = powM(a,p/2);
        return (tmp*tmp)%MOD;
    }else{
        return a*powM(a,p-1)%MOD;
    }
}

void solve() {
    int n;
    cin>>n;
    dp[1]=1;
    dp[2] = 1;
    ll mn = 1;
    for(int i=3;i<=n;i++){
        dp[i] =dp[i-1]+dp[i-2];
        
        dp[i]%=MOD;
    }    

    ll num = dp[n];;
    ll den = powM(2,n)%MOD;
    debug(num);
    debug(den);
    ll gcd = __gcd(num,den);
    num/=gcd;
    den/=gcd;
    
    // a * b^mod-2;
    cout<<(num%MOD * powM(den%MOD,MOD-2))%MOD<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    //cin>>tt;
    while (tt--) {
        solve();
    }

    return 0;
}

