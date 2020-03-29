#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;

    for(int i = 0;i<n;i++){
        int c,sm;
        cin>>c>>sm;
        if(sm<c){
            cout<<sm<<endl;
        }else{
            int perRad = sm/c;
            if(perRad * c == sm){
                cout<<perRad*perRad*c<<endl;
            }else{
                int ans =0;
                while(perRad*c!=sm){
                    c--;
                    sm-=perRad;
                    ans+=perRad*perRad;
                    perRad = sm/c;
                }
                ans+=perRad*perRad*c;
                cout<<ans<<endl;
            }
        }
    }

    return 0;
}