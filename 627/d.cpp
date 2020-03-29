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
using namespace std;

void yes(){
    cout<<"YES"<<endl;
}

void no(){
    cout<<"NO"<<endl;
}
/*
4 8 2  6  2
4 5 4  1  3
0 3 -2 5 -1
-2 -1 0 3 5
\                
*/

void solve(){
    int n;
    cin>>n;
    vl a(n);
    vl b(n);
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    for(int i = 0;i<n;i++){
        cin>>b[i];
        a[i] -=b[i];
    }
    sort(all(a));
    int l = 0;
    int r = n-1;
    ll ans = 0;
    while(l<r){
        while(a[l]+a[r]>0 && r>l){
            ans+=(r-l);
            r--;
        }
        while(a[l]+a[r]<=0 && l<r){
            l++;
        }
    }
    cout<<ans<<endl;
}

int main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}