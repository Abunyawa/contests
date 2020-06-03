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

ll dp[410][410];
ll sm[410][410];


void solve(){
    int n;
    cin>>n;
    vl a(n);
    for(int i=0;i<n;i++){
        dp[i][i] = 0;
        cin>>a[i];
    }   

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k = i;k<=j;k++){
                sm[i][j]+=a[k];
            }
        }
    }
    ll ans = 0;
    for(int i=1;i<=n;i++){
        for(int l = 0;l<=n-i;l++){
            dp[l][l+i] = 1e18L;
            for(int j=l;j<=l+i;j++){
                dp[l][l+i] = min(dp[l][l+i],dp[l][j]+dp[j+1][l+i]+sm[l][l+i]);
            }
        }
    }
    cout<<dp[0][n-1]<<'\n';
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
