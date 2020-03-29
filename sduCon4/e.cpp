#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    vector<int> a(n);
    int dp[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int ans = a[1]-a[0];
    ans+=a[n-1]-a[n-2];
    for(int i=2;i<n-2;i++){
        if(a[i]-a[i-1]<a[i+1]-a[i]){
            ans+=a[i]-a[i-1];
        }else{
            ans+=a[i+1]-a[i];
            i++;
        }
    }
    
    if(n==2){
        ans/=2;
    }
    cout<<ans<<endl;
}