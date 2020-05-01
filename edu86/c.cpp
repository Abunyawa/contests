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
    int a,b,q;
    cin>>a>>b>>q;
    vector<int> pref(a*b+1);
    pref[0] = 0;
    for(int i=1;i<=a*b;i++){
        pref[i] = pref[i-1];
        if((i%a)%b != (i%b)%a) pref[i]++;
    }
    while(q--){
        ll l,r;
        cin>>l>>r;
        ll left = (l-1)/(a*b) * 1ll * pref[a*b] + pref[(l-1)%(a*b)];
        ll right = r/(a*b) * 1ll * pref[a*b] + pref[r%(a*b)];
        cout<<right-left<<' ';
    }
    cout<<'\n';
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
