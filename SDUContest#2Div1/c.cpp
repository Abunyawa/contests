#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define pii pair<int, int>
using namespace std;

void yes(){
    cout<<"YES"<<endl;
}

void no(){
    cout<<"NO"<<endl;
}

int main(){
    int n;
    cin>>n;
    ll ans = 0;
    int dp[n];
    dp[3] = 6;
    for(int i=4;i<=n;i++){
        dp[i] = dp[i-1]+i*(i-1);
    }
    
    cout<<dp[n]<<endl;
    return 0;
}