#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long s;
        cin>>s;
        long long ans = 0;
        while(s!=0){
            ans+=s/10*10;
            s = s%10 + s/10;
            if(s<10){
                ans+=s;
                break;
            }
        }
        cout<<ans<<endl;

    }


    return 0;
}