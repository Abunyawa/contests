// chrono::system_clock::now().time_since_epoch().count()
#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

void yes(){
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}



void solve() {
    int n,q;
    cin>>n>>q;

    vi a(n+1,1e9);

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    sort(rall(a));

    vi pref(n+1,0);

    for(int i=1;i<=n;i++){
        pref[i] = pref[i-1]+a[i];
    }

    for(int i=0;i<q;i++){
        int x;
        cin>>x;

        if(pref[n]<x){
            cout<<-1<<'\n';
            continue;
        }

        int l = 1;
        int r = n;

        while(l<r-1){
            int m = (l+r)/2;

            if(pref[m]>=x){
                r = m;
            }else{
                l = m+1;
            }
        }
        //cout<<pref[l]<<'\n';
        if(pref[l]>=x){
            cout<<l<<'\n';
        }else{
            cout<<r<<'\n';
        }
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    cin>>tt;

    while (tt--) {
        solve();
    }

    return 0;
}

