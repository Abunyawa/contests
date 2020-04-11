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
bool cmp(ll a, ll b){
    return a>b;
}
void solve(){
    int n;
    ll x;
    cin>>n>>x;
    vl a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(all(a),cmp);
    double cur = a[0];
    int ind = 1;
    if(cur<x){
        cout<<0<<'\n';
        return;
    }
    while(cur/(double)ind>=x && ind<n){
        cur+=a[ind++];
    }
    if(cur/(double)ind>=x)
        cout<<ind<<'\n';
    else
        cout<<ind-1<<'\n';

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
