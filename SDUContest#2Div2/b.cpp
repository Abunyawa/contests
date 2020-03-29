#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    int left=0,right=0;
    int ctr = 0;
    for(int i = 0;i<n;i++){
        int x,y;
        cin>>x>>y;
        left+=x;
        right+=y;
        if(x%2!=y%2){
            ctr++;
        }
    }
    if(left%2==0 && right%2==0){
        cout<<0<<endl;
    }else if(left%2!=right%2){
        cout<<-1<<endl;
    }else{
        if(ctr!=0){
            cout<<1<<endl;
        }else{
            cout<<-1<<endl;
        }
    }
    
}