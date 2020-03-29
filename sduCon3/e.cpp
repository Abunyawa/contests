#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100000;

int t[4*MAXN],a[MAXN], t2[4*MAXN];


int main(){
    int n;
    int a[n];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int l,r,k;
        cin>>l>>r>>k;
        int ctr = 0;
        for(int j=l-1;j<r;j++){
            if(a[j]==0){
                ctr++;
            }
            if(ctr==k){
                cout<<j+1<<endl;
                break;
            }
        }
        if(ctr<k){
            cout<<-1<<endl;
        }
    }
    return 0;
}