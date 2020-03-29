#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,k,q;
    cin>>n>>k>>q;
    long long t[n];
    for(int i=0;i<n;i++){
        cin>>t[i];
    }
    vector<int> us;
    while(q--){
        int p,id;
        cin>>p>>id;
        if(p==1){
            us.push_back(t[id-1]);
            sort(us.begin(),us.end());
            if(us.size()>k){
                us.erase(us.begin(),us.end()-k);
            }

        }else{
            bool flag = false;
            for(int i=0;i<min(k,(int)us.size());i++){
                if(us[i]==t[id-1]){
                    flag = true;
                }
            }
            if(flag){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}