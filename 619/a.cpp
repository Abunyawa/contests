#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string a,b,c;
        cin>>a>>b>>c;
        int n = a.length();
        bool flag = true;
        for(int i=0;i<n;i++){
            if(c[i]!=b[i] && a[i]!=c[i]){
                flag = false;
            }
        }
        if(flag){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }


    return 0;
}