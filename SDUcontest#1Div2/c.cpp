#include<bits/stdc++.h>
using namespace std;
int al[26][26];


int main(){
    int n,c;
    cin>>n>>c;
    int p[n],t[n];
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    for(int i=0;i<n;i++){
        cin>>t[i];
    }
    int lim = 0;
    int x = 0;
    for(int i=0;i<n;i++){
        x +=t[i];
        lim+=max(0,p[i]-c*x);
    }

    int rade = 0;
    x = 0;
    for(int i=n-1;i>=0;i--){
        x +=t[i];
        rade+=max(0,p[i]-c*x);
    }
    if(rade>lim){
        cout<<"Radewoosh"<<endl;
    }else if(lim>rade){
        cout<<"Limak"<<endl;
    }else{
        cout<<"Tie"<<endl;
    }
    return 0;
}