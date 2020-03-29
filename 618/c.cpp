#include<bits/stdc++.h>
using namespace std;

bool cmp(int a, int b){
    return a>b;
}

int main(){
    int n;
    cin>>n;
    map<long long,long long> nums;
    vector<long long> a(n);
    int mx = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>mx){
            mx = a[i];
        }
    }
    long long ans = 0;
    for(long long i=1;i<mx;i*=2){
        vector<int> nm;
        int ctr = 0;
        for(int j=0;j<n;j++){
            if(a[j] & i){
                ctr++;
                nm.push_back(j);
            }
        }
        if(ctr == 1){
            ans = nm[0];
        } 
    }
    
    cout<<a[ans]<<' ';
    for(int i = 0;i<n;i++){
        if(i!=ans){
            cout<<a[i]<<' ';
        }
    }
    cout<<endl;

    return 0;
}