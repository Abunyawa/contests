#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n1;
        cin>>n1;
       
        set<int> ans;
        int i=0;
        for(int i=2;i<sqrt(n1) && ans.size()<2;i++){
            if(n1%i==0){
                n1/=i;
                ans.insert(i);
            }
            
               
        }

        ans.insert(n1);
        if(ans.size()==3){
            cout<<"YES\n";
            for(auto j = ans.begin();j!=ans.end();j++){
                cout<<*j<<' ';
            }
            cout<<endl;
        }else{
            cout<<"NO\n";
        
        }
    }

    return 0;
}