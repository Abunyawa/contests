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

int n,m;
ll dp[2001][2001];
char g[2001][2001];
int xm[] = {1,0};
int ym[] = {0,1};


void solve(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
        }
    }
    dp[0][0] = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<2;k++){
                int xto = i+xm[k];
                int yto = j+ym[k];
                if(xto<n && yto<m && g[xto][yto]=='.'){
                    dp[xto][yto] = dp[xto][yto] + dp[i][j];
                    if(dp[xto][yto]>=MOD){
                        dp[xto][yto]-=MOD;
                    }
                }
            } 
        }
    }

    cout<<dp[n-1][m-1]<<'\n';
    

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
