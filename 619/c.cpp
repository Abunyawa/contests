#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,m;
        cin>>n>>m;
        long long ans;
        if(m==0){
            ans = 0;
        }else{
            long long p = (n+1)/2;
            if(m%2==1){
                ans = p*(n+1-p);
                m--;
                long long l = m/2;
                long long r = m-l;
                ans+= ((p-l)+(p-1))*l/2;
                ans += ((n-p-1)+(n-p-1-r))*r/2;      
            }else{
                if(n%2==0){
                    ans = (p)*(n-p+1);
                    ans += (n-p);
                    m-=2;
                    long long l = m/2;
                    long long r = m-l;
                    ans += ((p-1-l)+(p-2))*l/2;
                    ans += ((n-p)+(n-p-r))*r/2;    
                }else{
                    ans = (p-1)*(n-p+2);
                    ans += (2)*(n-p);  
                    m-=2;
                    long long l = m/2;
                    long long r = m-l;
                    ans += ((p-1-l)+(p-2))*l/2;
                    ans += ((n-p)+(n-p-r))*r/2; 
                }    
            }      
        }
        cout<<ans<<endl;
    }

    return 0;
}



