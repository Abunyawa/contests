#include<bits/stdc++.h>
using namespace std;

int is[1010];

int main(){
    int n;
    cin>>n;
    int bota[n],botb[n];
    for(int i=0;i<n;i++){
        cin>>bota[i]>>botb[i];
        is[botb[i]]++;
    }
    int ctr = 0;
    for(int i=0;i<n;i++){
        if(bota[i]==botb[i]){
            if(is[botb[i]]<=1){
                ctr++;
            }
        }else if(is[bota[i]]==0) ctr++;
    }
    cout<<ctr<<endl;

}