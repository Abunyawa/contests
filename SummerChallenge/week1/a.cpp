#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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

void solve(){
    
    int n;
    cin>>n;
    vl a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(all(a));
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        ll r;
        cin>>r;
        int pos = lower_bound(all(a),r)-a.begin();
        if(a[pos]==r){
            yes();
        }else{
            no();
        }
    }
}

int main(){

    freopen("collect.in","r",stdin);
    freopen("collect.out","w",stdout);
    abu;
    said;
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
