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

bool cmp(pii a, pii b){
    return a>b;
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<pii>l(m);
    int sm = 0;
    for(int i=0;i<m;i++){
        cin>>l[i].F;
        l[i].S = i;
        sm+=l[i].F;
    }
    sort(all(l));
    vi ans;
    ans.pb(1);
    for(int i=0;i<m;i++){
        ans.pb(ans[ans.size()-1]+l[i].F);
    }
    int shift = max(0,ans[ans.size()-2]-(n-l[m-1].F+1));
    for(int i=1;i<ans.size();i++){
        ans[i] -= min(shift,ans[i]-ans[i-1]-1);
    }
    for(int i=0;i<ans.size()-1;i++){
        if(ans[i]>n-l[i].F+1){
            cout<<-1<<'\n';
            return;
        }
    }
    if(ans[ans.size()-1]<n){
        cout<<-1<<'\n';
        return;
    }
    int fans[m+1];
    for(int i=0;i<ans.size()-1;i++){
        fans[l[i].S] = ans[i];
    }
    for(int i=0;i<m;i++){
        cout<<fans[i]<<' ';
    }
    cout<<'\n';
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
