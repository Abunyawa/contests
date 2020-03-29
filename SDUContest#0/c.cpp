#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int l, int r){
    int tmp = a[l];
    a[l] = a[r];
    a[r] = tmp;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        long long L,v,l,r;
        cin>>L>>v>>l>>r;
        long long ans = L/v;
        ans-=(r/v - (l-1)/v);
        cout<<ans<<endl;
    }

    return 0;
}

-----------------------------------L
      l                 r