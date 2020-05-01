#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define vi vector<int>
#define vl vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define abu ios_base::sync_with_stdio(0)
#define said cin.tie(0)
using namespace std;

void yes(){
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}
ll pow2[64];

void solve(){
    int n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<ll> ans;
    ll mn = -10e9-1;
    ll mx = -10e9-1;
    for(int i=0;i<n;){
        while(i<n && a[i]<0){
            if(a[i]>mn){
                mn = a[i];
            }
            i++;
        }
        if(mn!=-10e9-1)
            ans.pb(mn);
        mn = -10e9-1;
        while(i<n && a[i]>0){
            if(a[i]>mx){
                mx = a[i];
            }
            i++;
        }
        if(mx!=-10e9-1)
            ans.pb(mx);
        mx = -10e9-1;
    }
    ll sm =0;
    for(auto e: ans){
        sm+=e;
    }
    cout<<sm<<'\n';
}

int main(){
    abu;
    said;
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
