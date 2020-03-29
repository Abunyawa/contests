#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int ans=n;
    while(n--){
        string str;
        cin>>str;
        int ctr = 0;
        for(int i =0;i<str.size();i++){
            if(str[i]=='4' || str[i]=='7'){
                ctr++;
            }
            if(ctr>k){
                ans--;
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}