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
    ll n;
    cin>>n;
    vl a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    unordered_map<ll,int> m;
    m[0] = 0;
    ll ans = n*(n+1)/2;
    ll cur_sm = 0;
    ll minL = 0;
    for(int i = 0;i<n;i++){
        cur_sm += a[i];
        if(m.find(cur_sm)!=m.end()){
            if(m[cur_sm]>=minL){
                ans -= 1+((m[cur_sm]-minL+1)*(n-i-1));
                minL = m[cur_sm];
            }
        }
        m[cur_sm] = i;
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
