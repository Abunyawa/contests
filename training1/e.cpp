#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,k;
    cin>>n>>k;
    long long cur = 1+(k*2+1);
    if(cur>=n){
        cout<<0<<endl;
    }else{
        long long need = n-(cur-1);
        cout<<(need)/2<<endl;
    }
    return 0;
}