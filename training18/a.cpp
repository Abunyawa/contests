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


void solve(){
    int y,w;
    cin>>y>>w;
    int ans = 6-max(y,w)+1;
    if(ans%6==0){
        cout<<ans/6<<'/'<<1<<'\n';
    }else if(ans%2==0){
        cout<<ans/2<<'/'<<3<<'\n';
    }else if(ans%3==0){
        cout<<ans/3<<'/'<<2<<'\n';
    }else{
        cout<<ans<<'/'<<6<<'\n';
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
