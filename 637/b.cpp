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
    int n,k;
    cin>>n>>k;
    vl a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vl pref(n+1);
    pref[0] = 0;
    pref[1] = 0;
    pref[2] = 0;
    for(int i=3;i<=n;i++){
        if(a[i-1]>a[i] && a[i-1]>a[i-2]){
            pref[i] = pref[i-1]+1;
        }else{
            pref[i] = pref[i-1];
        }
    }
    ll mx = -1;
    int ind = -1;
    for(int i=1;i+k-1<=n;i++){
        if(pref[i+k-1]-pref[i+1]>mx){
            mx = pref[i+k-1]-pref[i+1];
            ind = i;
        }
    }
    cout<<mx+1<<' '<<ind<<'\n';
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
