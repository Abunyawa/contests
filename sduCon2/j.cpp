#include<bits/stdc++.h>
using namespace std;
int d[1000000];
int ans = 0;


void bitsa(int* fiwk,int n, int cur){
    if(cur>=n){
        long long t1=0;
        int ctr=0;
        for(int i =0;i<n;i++){
            t1+=fiwk[i]*d[i];
        }
        if(t1==0 && ctr!=cur){
            ans++;
        }
    }else{
        
        for(int i = -1;i<2;i++){
            d[cur] = i;
            bitsa(fiwk,n,cur+1);
        }
    }
}


int main(){
    int n;
    cin>>n;
    int c[n];
    for(int i =0;i<n;i++){
        cin>>c[i];
    }

    bitsa(c,n,0);
    cout<<ans-1<<endl;
    return 0;
}