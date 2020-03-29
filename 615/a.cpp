#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        long long a,b,c,n;
        cin>>a>>b>>c>>n;
        long long sum = a+b+c+n;
        if(sum%3!=0){
            cout<<"NO"<<endl;
        }else{
            if(a>sum/3 || b>sum/3 || c>sum/3){
                cout<<"NO"<<endl;
            }else{
                cout<<"YES"<<endl;
            }

        }
    }

    return 0;
}