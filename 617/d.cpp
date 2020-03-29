#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,a,b,k;
    cin>>n>>a>>b>>k;
    vector<long long> pts;
    long long locK = 0;
    for(int i=0;i<n;i++){
        long long h;
        cin>>h;
        long long ost = h%(a+b);
        if(ost == 0){
            ost = a+b;
        }
        if(ost>a){
            long long p = ((ost-a)+a-1)/a;
            pts.push_back(p);
            locK += p;
        }else{
            pts.push_back(0);
        }
    }
    long long ans = n;
    sort(pts.begin(),pts.end());
    long long ptr = pts.size()-1;
    while(locK>k){
        ans--;
        locK-=pts[ptr--];
    }
    cout<<ans<<endl;

    return 0;
}