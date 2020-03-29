#include<bits/stdc++.h>
using namespace std;
long long ctr[800200];

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        char c;
        cin>>c;
        a[i] = (int)(c-'a');
    }
    int ans = 0;
    for(int i=0;i<a.size();i++){
        int ctr = 0;
        int cr = i;
        while(cr<n-1 && a[cr]+1==a[cr+1]){
            cr++;
        }
        if(cr<n && a[cr+1]<a[cr]){
            
        }
        
    }

    cout<<ans;
    return 0;
}

/*

bacabcab
21312312

bacabcdcc
213123433

*/