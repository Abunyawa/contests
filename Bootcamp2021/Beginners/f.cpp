#include<bits/stdc++.h>
using namespace std;


int main(){
    string mainC;
    cin>>mainC;
    bool flag = false;

    for(int i=0;i<5;i++){
        string loc;
        cin>>loc;

        if(loc[0]==mainC[0] || loc[1] == mainC[1]){
            flag = true;
        }
    }

    if(flag){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
    return 0;
}