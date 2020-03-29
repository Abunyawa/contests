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
    int n,m,k;
    cin>>n>>m>>k;
    pair<ll,ll> h[n];
    pair<ll,ll> v[m];
    for(int i=0;i<n;i++){
        h[i] = {0,-1};
    }
    for(int i=0;i<m;i++){
        v[i] = {0,-1};
    }
    for(int i=0;i<k;i++){
        int t;
        cin>>t;
        if(t==1){
            int r,a;
            cin>>r>>a;
            h[r-1] = {a,i};
        }else{
            int c,a;
            cin>>c>>a;
            v[c-1] = {a,i};
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(h[i]==mp(0ll,-1ll) && v[j]==mp(0ll,-1ll)){
                cout<<0<<' ';
            }else{
                if(h[i]!=mp(0ll,-1ll) && v[j]!=mp(0ll,-1ll)){
                    if(h[i].S>v[j].S){
                        cout<<h[i].F<<' ';
                    }else{
                        cout<<v[j].F<<' ';
                    }
                }else{
                    if(h[i]!=mp(0ll,-1ll)){
                        cout<<h[i].F<<' ';
                    }else{
                        cout<<v[j].F<<' ';
                    }
                }
            }
        }
        cout<<endl;
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
