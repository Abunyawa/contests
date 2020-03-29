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
    int n,k;
    cin>>n>>k;
    vector<int> h(n);
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    vector<ll> dp(n,999999999);
    dp[0] = 0;
    for(int i =0;i<n-1;i++){
        for(int j=i+1;j<min(n,i+k+1);j++){
            dp[j] = min(dp[j],dp[i]+abs(h[i]-h[j]));
        }
    }
    cout<<dp[n-1]<<endl;

    return 0;
}