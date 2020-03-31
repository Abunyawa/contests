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
int dp[510][510];

void solve(){
    int k;
    cin>>k;
    if(k==0){
        cout<<1<<' '<<1<<'\n';
        cout<<(1<<17)<<'\n';
    }else{
        cout<<2<<' '<<3<<'\n';        
        ll p = (1<<17);
        cout<<p+k<<' '<<k<<' '<<0<<'\n';
        cout<<p<<' '<<p+k<<' '<<k<<'\n';
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
