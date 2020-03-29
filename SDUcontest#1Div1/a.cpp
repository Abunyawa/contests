#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,t;
    cin>>n>>t;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int l = 0;
    int r = 0;
    int ans = 0;
    long long sm=a[r];
    while(r<n){
        while(sm<=t && r<n){
            sm+=a[++r];
        }
        if(r-l>ans && sm-a[r]<=t){
            ans = r-l;
        }
        
        while(sm>t && l<=r){
            sm-=a[l++];
        }
    }
    int rr = r-1;
    if(rr-l>ans){
        ans = rr-l+1;
    }
        
    cout<<ans<<endl;
    return 0;
}