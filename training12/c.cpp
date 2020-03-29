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
/*
13213
2112
101
11
0
*/
void solve(){
    int n,v;
    cin>>n>>v;
    vi g(3010,0);
    vi g2(3010,0);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a]+=b;
        g2[a+1]+=b;
    }
    ll ans=0;
    for(int i=1;i<3010;i++){
        int cur = v;
        ans+=min(g2[i],cur);
        cur-=min(g2[i],cur);
        if(cur>0){
            ans+=min(g[i],cur);
            g2[i+1]-=min(g[i],cur);
        }
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
