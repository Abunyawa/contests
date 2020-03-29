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
    cout<<"YES"<<endl;
}

void no(){
    cout<<"NO"<<endl;
}
/*
13213
2112
101
11
0
*/
void solve(){
    int n,m;
    cin>>n>>m;
    vi a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(all(a));
    ll ans = 0;
    int ind = 0;
    while(ind<m && a[ind]<0){
        ans-=a[ind++];
    }
    cout<<ans<<endl;
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
