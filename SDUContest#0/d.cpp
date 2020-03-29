#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long a,b;
        cin>>a>>b;
        long long dif = abs(a-b);
        long long ans = 0;
        ans+=dif/5;
        dif%=5;
        ans+=dif/2;
        dif%=2;
        ans+=dif;
        cout<<ans<<endl;

    }

    return 0;
}