#include<bits/stdc++.h>
using namespace std;

int main(){
    int s, n;
    cin>>s>>n;
    vector<pair<int,int>> dr(n);
    for(int i=0;i<n;i++){
        cin>>dr[i].first>>dr[i].second;
    }

    sort(dr.begin(),dr.end());

    for(int i=0;i<n;i++){
        if(s>dr[i].first){
            s+=dr[i].second;
        }else{
            cout<<"NO\n";
            return 0;
        }
    }

    cout<<"YES\n";


    return 0;
}