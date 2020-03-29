#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=8;
    bool flag = true;
    for(int i =0;i<n;i++){
        string a;
        cin>>a;
        for(int j=1;j<n;j++){
            if(a[j]==a[j-1]){
                flag = false;
            }
            if(j==7){
                if(a[j]==a[0]){
                    flag = false;
                }
            }
        }
    }
    if(flag){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}