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
ll ds[2000101];


void solve(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    for(int i=a;i<=b;i++){
        ds[i+b]++;
        ds[i+c+1]--;
    }
    for(int i=1;i<=2000100;i++){
        ds[i]+=ds[i-1];
    }
    for(int i=1;i<=2000100;i++){
        ds[i]+=ds[i-1];
    }
    ll ans = 0;
    for(int i=c;i<=d;i++){
        ans+=ds[2000100]-ds[i];
    }
    cout<<ans<<'\n';
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
