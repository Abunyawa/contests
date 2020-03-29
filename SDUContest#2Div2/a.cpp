#include<bits/stdc++.h>
using namespace std;
/*
ax+by+cz = n
(n-ax-by)/c = z
*/
int main(){
    int n,a,b,c;
    cin>>n>>a>>b>>c;
    int ans = 0;
    for(int i=0;i<=n/a;i++){
        for(int j=0;j<=n/b;j++){
            if((n-a*i-b*j)%c==0 && (n-a*i-b*j)>=0){
                if(i+j+(n-a*i-b*j)/c>ans){
                    ans = i+j+(n-a*i-b*j)/c;
                }
            }
        }
    }
    cout<<ans<<endl;
}