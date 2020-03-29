#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    double dp[n+1];
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1]+(double)(1)/i;

    }
    cout.precision(5);
    cout.setf(std::ios::fixed);
    cout<<dp[n]<<endl;
    return 0;
}
/*

1 2    3       4 5 6
1 1.5  1.6667  

*/