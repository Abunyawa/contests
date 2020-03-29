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
int ctr[5001];

int main(){
    int n;
    cin>>n;
    bool flag = true;
    vector<ll> h1(n);
    ll w,h;
    cin>>w>>h;
    h1[0] = max(w,h);
    for(int i=1;i<n;i++){
        cin>>w>>h;
        if(w<=h1[i-1] && h<=h1[i-1]){
            h1[i] = max(w,h);
        }else if(w>h1[i-1] && h>h1[i-1]){
            flag = false;
        }else{
            h1[i] = min(w,h);
        }
    }
    if(flag){
        yes();
    }else{
        no();
    }
    return 0;
}