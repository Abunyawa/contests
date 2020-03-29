#include<bits/stdc++.h>
using namespace std;
 
int main(){
    long long n;
    cin>>n;
    long long a=1,d=1;
    int k=0;
    while(a+d<=n){
        if(k%2==0){
            k++;
            a+=d;
            d*=2;
        }else{
            d*=2;
            k++;
        }
    }    
    cout<<a<<endl;
    return 0;
}