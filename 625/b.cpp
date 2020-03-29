#include<bits/stdc++.h>
using namespace std;
long long ctr[800200];

int main(){
    int n;
    cin>>n;
    vector<long long> b(n);
    for(long long i=0;i<n;i++){
        cin>>b[i];
        ctr[b[i]-i+400100]+=b[i];
    }
    long long ans = 0;
    for(long long i=0;i<800200;i++){
        if(ctr[i]>ans){
            ans=ctr[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}

/*
10 7 1  9 10 15
0  1 2  3 4  5
10 6 -1 6 6  10 


*/