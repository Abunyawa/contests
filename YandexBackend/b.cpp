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
ll const N = 1000100;
string s[N],ans[N];

void yes(){
    cout<<"Yes"<<endl;
}

void no(){
    cout<<"No"<<endl;
}

void solve(){
    int n;
    cin>>n;
    ll mn =0;
    ll mx = 0;
    vector<pll> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].F>>a[i].S;
        if(min(a[i].F,a[i].S)>mn){
            mn = min(a[i].F,a[i].S);
        }
        if(max(a[i].F,a[i].S)>mn){
            mx = max(a[i].F,a[i].S);
        }
    }
    int ctr = 0;
    for(int i=0;i<n;i++){
        cin>>a[i].F>>a[i].S;
        if(min(a[i].F,a[i].S)>mn){
            mn = min(a[i].F,a[i].S);
        }
        if(max(a[i].F,a[i].S)>mn){
            mx = max(a[i].F,a[i].S);
        }
    }
}

int main(){
    abu;
    said;
    cout.tie(0);
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
