#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define pii pair<int, int>
using namespace std;

void yes(){
    cout<<"YES"<<endl;
}

void no(){
    cout<<"NO"<<endl;
}


int main(){
    int n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(all(a));
    bool flag = true;
    int l=0,r=n-1;
    int ptr=0;
    vector<ll> ans(n);

    while(l<=r){
        ans[l++] = a[ptr++];
        if(ptr>=n){
            break;
        }
        ans[r--] = a[ptr++];
    }
    for(int i=0;i<n;i++){
        if(ans[i]>=ans[(i-1+n)%n]+ans[(i+1)%n]){
            flag = false;
        }
    }
    if(flag){
        yes();
        for(auto e: ans){
            cout<<e<<' ';
        }
        cout<<endl;
    }else{
        no();
    }
    return 0;
}