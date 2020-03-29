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
ll ctr[200100];
void solve(){
    ll n;
    cin>>n;
    vl a(n);
    for(int i=0;i<=n;i++){
        ctr[i] = 0;
    }
    for(int i=0;i<n;i++){
        cin>>a[i];
        ctr[a[i]]++;
    }
    ll tot = 0;
    for(int i=1;i<=n;i++){
        tot += ctr[i]*(ctr[i]-1)/2;
    }
    for(int i=0;i<n;i++){
        cout<<tot-(ctr[a[i]]-1)<<endl;
    }
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
