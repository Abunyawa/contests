#include<bits/stdc++.h>
using namespace std;
 
 
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,g,b;
        cin>>n>>g>>b;
        if(g>=b){
            cout<<n<<endl;
        }else{
            long long ans = n/(g*2);
            long long lastD = n%(g*2);
            ans *= (g+b);

            if(lastD == 0){
                lastD = b+g;
                ans -= lastD;
            }

            int pp = ans/(g+b);
            pp*=b-g;
            cout<<pp<<endl;
            cout<<lastD-g<<endl;
            long long left = max(0ll,max(lastD-g,0ll) - pp);
            ans+=left;
            
 
            cout<<ans<<endl;
        }
    }
    return 0;
}
/*
    0 0 0 0
1   1 
2     2
3       2
4   ------
5         1
6   ------
7   ---------
8 ------------
9              1
 */