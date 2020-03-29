
#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,s,k;
        cin>>n>>s>>k;
        set<long long> m;
 
        for(int i=0;i<k;i++){
            long long x;
            cin>>x;
            m.insert(x);
        }
        long long l=s,r=s;
        while(m.find(l)!=m.end() && l>=0){
            l--;
 
        }
        while(m.find(r)!=m.end() && r<n+1){
            r++;
        }
        long long ans = k+20;
        if(m.find(l)==m.end() && l!=0){
            ans = min(ans,abs(s-l));
        }
        if(m.find(r)==m.end() && r!=n+1){
            ans = min(ans,abs(r-s));
        }
        cout<<ans<<endl;
    }
 
    return 0;
}