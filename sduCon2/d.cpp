#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string a;
    cin>>a;
    bool flag=0;
    for(int i=1;i<n/2;i++){
        for(int j=0;j<n;j++){
            if(a[j]=='*'){
                if(a[j+i]==a[j] && a[j+2*i]==a[j] && a[j+3*i]==a[j] && a[j+4*i]==a[j]){
                    flag = true;
                }
            }
        }
    }
    if(flag){
        cout<<"yes"<<endl;
    }else{
        cout<<"no"<<endl;
    }
    return 0;
}