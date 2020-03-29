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
    cout<<"Yes"<<endl;
}

void no(){
    cout<<"No"<<endl;
}

ll dp[2010];
void solve(){
    int x,y,a,b,c;
    cin>>x>>y>>a>>b>>c;
    vl p(a);
    for(int i=0;i<a;i++){
        cin>>p[i];
    }
    vl q(b);
    for(int i=0;i<b;i++){
        cin>>q[i];
    }
    vl r(c);
    for(int i=0;i<c;i++){
        cin>>r[i];
    }
    sort(all(p));
    for(int i=a-1;i>=a-x;i--){
        r.pb(p[i]);
    }
    sort(all(q));
    for(int i=b-1;i>=b-y;i--){
        r.pb(q[i]);
    }
    sort(all(r));
    ll ans=0;
    for(int i=r.size()-1;i>=r.size()-x-y;i--){
        ans+=r[i];
    }
    cout<<ans<<endl;
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
