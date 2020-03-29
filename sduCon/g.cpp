#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    long long prefix[n+1];
    long long suffix[n+1];
    prefix[0] = 0;
    for(int i =0;i<n;i++){
        cin>>a[i];
        prefix[i+1] = a[i]+prefix[i];
        //cout<<prefix[i+1]<<" ";
        
    }
    //cout<<endl;
    suffix[n] = 0;
    suffix[n-1] = a[n-1];
    for(int i =n-2;i>=0;i--){
        suffix[i] = suffix[i+1] +a[i];
    } 
    long long dp[n];
    dp[n-1] = suffix[n-1];
    for(int i= n-2;i>=0;i--){
        dp[i] = max(dp[i+1],suffix[i]-suffix[min(i+k,n)]);

    }
    
    long long max=0;
    int maxL1 = 0;
    for(int i = 1;i<=n;i++){
        //cout<<prefix[min(i+k-1,n)]-prefix[min(i-1,n)]+dp[min(i+k-1,n-1)]<<endl;
        if(prefix[min(i+k-1,n)]-prefix[min(i-1,n)]+dp[min(i+k-1,n-1)]>max){
            max=prefix[min(i+k-1,n)]-prefix[min(i-1,n)]+dp[min(i+k-1,n-1)];
            maxL1 = i;
            //cout<<prefix[min(i+k-1,n)]-prefix[min(i-1,n)]+dp[min(i+k-1,n-1)]<<endl;
        }
    }
    int maxL2 = min(maxL1+k-1,n-1);
    for(int i =0;i<n;i++){
        if(dp[min(maxL1+k,n-1)]==dp[i]){
            while(dp[min(maxL1+k-1,n-1)]==dp[i]){
                i++;
            }
            maxL2 = i-1;
            break;

        }
    }

    cout<<maxL1<<' '<<maxL1+k-1<<endl;
    cout<<maxL2+1<<' '<<min(maxL2+k,n)<<endl;
    return 0;
}

/*
5 2
5  7 1 3 4
13 8 4 7
*/