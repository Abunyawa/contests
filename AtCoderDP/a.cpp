#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<long long, long long>
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
    vector<int> h(n);
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    vector<ll> dp(n,999999999);
    dp[0] = 0;
    for(int i =0;i<n-1;i++){
        dp[i+1] = min(dp[i+1],dp[i]+abs(h[i]-h[i+1]));
        dp[min(i+2,n-1)] = min(dp[min(i+2,n-1)],dp[i]+abs(h[i]-h[min(i+2,n-1)]));
    }
    cout<<dp[n-1]<<endl;

    return 0;
}