#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        long long gap = 0;
        long long maxN(-1),minN(999999999);
        for(int i=0;i<n;i++){
            if(a[i]==-1){
                if(a[min(i+1,n-1)]!=-1){
                    maxN = max(maxN,a[i+1]);
                    minN = min(minN,a[i+1]);
                }
                if(a[max(i-1,0)]!=-1){
                    maxN = max(maxN,a[i-1]);
                    minN = min(minN,a[i-1]);
                }
            }else{
                if(a[min(i+1,n-1)]!=-1){
                    gap = max(gap,abs(a[i]-a[min(i+1,n-1)]));
                }
                if(a[max(i-1,0)]!=-1){
                    gap = max(gap,abs(a[i]-a[max(i-1,0)]));
                }
            }
        }
        if(maxN!=-1){
            long long k = (maxN+minN)/2;
            cout<<max(gap,max(abs(minN-k),abs(maxN-k)))<<' '<<k<<endl;
        }else{
            cout<<0<<' '<<0<<endl;
        }
    }

    return 0;
}



