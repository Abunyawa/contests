#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100000;

int t[4*MAXN],a[MAXN], t2[4*MAXN];


int main(){
    int n;
    cin>>n;
    int a[n+10];
    int prefS[n+10];
    prefS[0] = 0;
    vector<int> zeros;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x==0){
            a[i]=1;
            zeros.push_back(i);
            
        }else{
            a[i] = 0;
        }
        prefS[i] = a[i] + prefS[i-1];
    }
    int m;
        
    cin>>m;
    for(int j =0;j<m;j++){
        int l,r,k;
        cin>>l>>r>>k;
        if(prefS[r]-prefS[l-1]>=k){
            cout<<zeros[prefS[l-1]+k-1]<<endl;
        }else{
            cout<<-1<<endl;
        }
    }
    return 0;
}