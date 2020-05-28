#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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
    int n,m;
    cin>>n>>m;
    vl a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<pll> d(m);
    for(int i=0;i<m;i++){
        cin>>d[i].F>>d[i].S;
    }
    sort(all(d));
    vl pref(m);
    vl b(m);
    pref[0] = d[0].S;
    b[0] = d[0].S;
    for(int i=1;i<m;i++){
        b[i] = d[i].F;
        pref[i] = pref[i-1]+d[i].S;
    }

    for(int i=0;i<n;i++){
        int pos = lower_bound(all(b),a[i])-b.begin();
        if(pos>0)
            cout<<pref[min(pos-1,m-1)]<<' ';
        else
            cout<<0<<' ';

    }
    cout<<'\n';

}

int main(){
    /*
    freopen("trains.in","r",stdin);
    freopen("trains.out","w",stdout);
    */
    abu;
    said;
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
