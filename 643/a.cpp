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
ll next(ll x){
    ll nm = x;
    ll mn = 10;
    ll mx = -1;
    while(x!=0){
        if(x%10>mx){
            mx = x%10;
        }
        if(x%10<mn){
            mn = x%10;
        }
        x/=10;
    }
    return nm + mn*mx;
}


void solve(){
    ll a,k;
    cin>>a>>k;
    ll nw = next(a);
    k--;
    while(nw!=a && k>0){
        a = nw;
        nw = next(a);
        k--;
    }
    cout<<a<<'\n';
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
