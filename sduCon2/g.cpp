#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    int c,d;
    cin>>c>>d;
    int dist = abs(b-d);
    int mx = dist;
    int ans = -1;
    for(int i = 0;i<=10000;i++){
        if(ans!=-1){
            break;
        }
        for(int j =0;j<=10000;j++){
            if(c*i-a*j==b-d){
                ans = c*i + d;
                break;
            }   
        }
    }
    cout<<ans;
    return 0;
}