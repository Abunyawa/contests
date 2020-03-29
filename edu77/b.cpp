#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int a,b;
        
        cin>>a>>b;
        int x = 0;
        int mx = max(a,b);
        int mn = min(a,b);
        bool flag = true;
        int dif = mx - mn;

        a = mn - dif;
        b = mx - 2*dif;
        if(a==b && a%3==0 && a>=0 && b>=0){
            flag = true;
        }else{
            flag = false;
        }

        if(flag){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;

        }
    }

    return 0;
}