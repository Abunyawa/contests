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
ll anss[]
void solve(){
    int n,m,t;
    cin>>n>>m>>t;
    vi az;
    vi bz;
    vi a(n);
    vi b(m);
    ll ctr =0
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==0){
            az.pb(ctr);
            ctr = 0;
        }else{
            ctr++;
        }
        
    }
    ctr = 0;
    for(int i=0;i<m;i++){
        cin>>b[i];
        if(b[i]==0){
            bz.pb(ctr);
            ctr = 0;
        }else{
            ctr++;
        }
    }
    vl aa;
    vl bb;
    for(int i=0;i<az.size();i++){
        
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