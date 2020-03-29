#include<bits/stdc++.h>
using namespace std;
int f(int *x,int l, int r){
    int a = 0;
    for(int i=l;i<=r;i++){
        a = a|x[i];
    }
    return a;
}   
int main(){
    int n;
    cin>>n;

    int a[n+10],b[n+10];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    int ans=f(a,0,n-1)+f(a,0,n-1);
    
    cout<<ans;
    return 0;
}