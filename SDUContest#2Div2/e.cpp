#include<bits/stdc++.h>
using namespace std;

int is[1010];

int main(){
    long long r,g,b;
    cin>>r>>g>>b;
    long long ans = r/3+g/3+b/3;
    for(int i=0;i<min(3ll,min(r,min(g,b)));i++){
        long long locAns = i + ((r-i)/3+(g-i)/3+(b-i)/3);
        if(locAns>ans){
            ans = locAns;
        }
    }
    cout<<ans<<endl;
    return 0;
}