#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        int sum = 0;
        int zero = 0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum += a[i];
            if(a[i] == 0){
                zero++;
            }
        }
        int ans = zero;
        sum+=zero;
        if(sum==0){
            ans++;
        }
        
        cout<<ans<<endl;

    }


    return 0;
}