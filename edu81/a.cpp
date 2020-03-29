#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        string ans="";
        cin>>n;
        if(n%2==0){
            while(n!=0){
                n-=2;
                ans+='1';
            }
        }else if(n%2==1){
            n-=3;
            ans+='7';
            while(n!=0){
                n-=2;
                ans+='1';
            }
        }
        cout<<ans<<endl;
    }


    return 0;
}