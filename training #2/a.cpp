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
    ll n;
    cin>>n;
    int p;
    vector<int> a(n);
    ll sm = 0;
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    sort(all(a));
    for(ll i=0;i<n;i++){
        sm+=a[i]*(n-i-1);
    }
    cout<<sm<<endl;
    return 0;
}