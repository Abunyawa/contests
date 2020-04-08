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

void solve(){
    int n;
    cin>>n;
    vl a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ll hs;
    if(n>1){
        hs = a[2]-a[1];
    }else{
        hs = a[1];
    }
    for(int i=3;i<=n;i++){
        hs = a[i] - hs;
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        ll l,r,v;
        cin>>l>>r>>v;
        if((r-l+1)%2==0){
            cout<<hs<<'\n';
        }else{
            hs+=(v)*pow(-1,(n-r)%2);
            cout<<hs<<'\n';
        }
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
