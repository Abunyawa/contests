#include<bits/stdc++.h>
using namespace std;


int main(){
    int q;
    cin>>q;

    while(q--){
        vector<long long> a(3);
        for(int i=0;i<3;i++){
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        
        long long ans = 0;
        ans = 2 * max(0ll,(a[2]-a[0]-2));
        cout<<ans<<endl;
    }

    return 0;
}