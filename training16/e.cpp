#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define vi vector<int>
#define vl vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define abu ios_base::sync_with_stdio(0)
#define said cin.tie(0)
using namespace std;

void yes(){
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}
ll dp[200100];

void solve(){
    string s;
    cin>>s;
    ll sm=0;
    int n = s.length();
    int ans = 0;
    dp[0] = 0;
    int prev1=0;
    int prev2=0;
    for(int i=0;i<n;i++){
        int cur = s[i]-'0';
        if(cur%3==0 || (cur+prev1)%3==0 || (cur+prev1+prev2)%3==0){
            ans++;
            prev1=0;
            prev2=0;
        }else{
            prev2 = prev1;
            prev1 = cur;
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
