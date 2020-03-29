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
    cout<<"Yes"<<endl;
}

void no(){
    cout<<"No"<<endl;
}

void solve(){
    ll k,n;
    cin>>k>>n;
    vl a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll totDis = 0;
    ll mx = 0;
    for(int i=0;i<n-1;i++){
        totDis+=a[i+1]-a[i];
        if(a[i+1]-a[i]>mx){
            mx = a[i+1]-a[i];
        }
    }
    totDis+=a[0]+k - a[n-1];
    if(a[0]+k - a[n-1]>mx){
        mx = a[0]+k - a[n-1];
    }
    cout<<totDis-mx<<endl;
}

int main(){
    abu;
    said;
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
