#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    int k;
    cin>>n>>k;
    for(int i=0;i<k;i++){
        if(n%10==0){
            n/=10;
        }else{
            n--;
        }
    }
    cout<<n<<endl;

    return 0;
}