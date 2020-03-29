#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,k;
    cin>>n>>k;
    
    for(int i=0;i<n;i++){
        int pos[3];
        cin>>pos[0]>>pos[1]>>pos[2];
        int q;
        cin>>q;
        if(q==1){
            pos[1]-=k;
        }else if(q==2){
            pos[0]+=k;
        }else if(q==3){
            pos[1]+=k;
        }else if(q==4){
            pos[0]-=k;
        }else if(q==5){
            pos[2]-=k;
        }else{
            pos[2]+=k;
        }
        cout<<pos[0]<<" "<<pos[1]<<' '<<pos[2]<<endl;
    }
    
    return 0;
}