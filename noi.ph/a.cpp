#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[4];
    int h;
    int sum = 0;
    for(int i=0;i<4;i++){
        cin>>a[i];
        sum+=a[i];
    }
    cin>>h;
    bool flag = false;
    for(int i=0;i<4;i++){
        if(sum-a[i]>=h){
            flag = true;
        }
    }
    if(flag){
        cout<<"WAW"<<endl;
    }else{
        cout<<"AWW"<<endl;
    }
    return 0;
}