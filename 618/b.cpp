#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(2*n);
        for(int i = 0;i<2*n;i++){
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        cout<<abs(a[n-1]-a[n])<<endl;

    }


    return 0;
}