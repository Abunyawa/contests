#include<bits/stdc++.h>
using namespace std;


void yes(){
    cout<<"YES"<<endl;
}

void no(){
    cout<<"YES"<<endl;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        long long x,y,a,b;
        cin>>x>>y>>a>>b;
        if((y-x)%(a+b)==0){
            cout<<(y-x)/(a+b)<<endl;
        }else{
            cout<<-1<<endl;
        }
    }

    return 0;
}