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


int dp[20010][20010];

void solve(){
    string s,t;
    cin>>s;
    cin>>t;
    int n = s.length();
    int m = t.length();
    if(s[0]==t[0]) dp[0][0] = 1;
    else dp[0][0] = 0;
    for(int i=1;i<n;i++){
        if(t[0] == s[i]){
            dp[0][i] = 1;
        }else{
            dp[0][i] = dp[0][i-1];
        }
    }
    for(int i=1;i<m;i++){
        if(t[i] == s[0]){
            dp[i][0] = 1;
        }else{
            dp[i][0] = dp[i-1][0];
        }
    }

    for(int j=1;j<n;j++){
        for(int i=1;i<m;i++){
            if(s[j] == t[i]){
                dp[i][j] = dp[i-1][j-1]+1;
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    

    int x = m-1;
    int y = n-1;
    string ans = "";
    while(x>=0 && y>=0){
        if(t[x] == s[y]){
            ans=s[y]+ans;
            x--;
            y--;
        }else{
            if(x>0 && y>0){
                if(dp[x-1][y]>dp[x][y-1]){
                    x--;
                }else{
                    y--;
                }
            }else{
                if(x>0){
                    x--;
                }else if(y>0){
                    y--;
                }else{
                    break;
                }
            }
        }
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
