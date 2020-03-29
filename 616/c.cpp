#include<bits/stdc++.h>
using namespace std;
int m;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>m>>k;
        vector<long long> ans;
        vector<long long> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        };
        
        for(int i=0;i+n-m<n;i++){
            ans.push_back(max(a[i],a[i+n-m]));
        }

        sort(ans.begin(),ans.end());

        int shift;
        if(k>ans.size()-1){
            shift = ans.size()-1;
        }else{
            shift = k;
        }
        cout<<ans[shift]<<endl;
    }


    return 0;
}