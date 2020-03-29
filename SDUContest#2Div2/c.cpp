#include<bits/stdc++.h>
using namespace std;


int main(){
    long long y,k,n;
    cin>>y>>k>>n;
    vector<long long> ans;
    for(long long p = y+k;p/k*k<=n;p+=k){
        ans.push_back(p/k*k-y);
    }
    if(ans.size()==0){
        cout<<-1<<endl;
        return 0;
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;
}