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


void solve(){
    string s;
    cin>>s;
    int n = s.length();
    s = '#' + s;
    vi pref(n+1);
    pref[0] = 0;
    for(int i = 1;i<=n;i++){
        if(s[i] == '0'){
            pref[i] = pref[i-1];
        }else{
            pref[i] = pref[i-1]+1;
        }
        
    }

    vi dp(n+1);
    int minA = 999999999;
    for(int i=1;i<=n;i++){
        dp[i] = min(i-pref[i]+pref[n]-pref[i],pref[i]+(n-i-pref[n]+pref[i]));
        if(dp[i]<minA){
            minA = dp[i];
        }
    }

    cout<<minA<<'\n';

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
