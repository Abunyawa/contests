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
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a<=b){
        cout<<b<<'\n';
    }else{
        if(c-d<=0){
            cout<<-1<<'\n';
        }else{
            ll ans = (a-b+(c-d)-1)/(c-d);
            cout<<b+ans*c<<'\n'; 
        }
    }
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
