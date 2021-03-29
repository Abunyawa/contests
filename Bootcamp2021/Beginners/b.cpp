#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a.begin(), a.end());
        int ans = 1111;
        for(int i=0;i<n-1;i++){
            ans = min(a[i+1]-a[i],ans);
        }

        cout<<ans<<'\n';
    }
    return 0;
    return 0;
}