// chrono::system_clock::now().time_since_epoch().count()
#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
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
    ll w,h;
    cin>>w>>h;
    int n;
    cin>>n;

    vi horD;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        horD.pb(x);
    }

    cin>>n;

    vi horU;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        horU.pb(x);
    }

    cin>>n;
    vi verL;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        verL.pb(x);
    }


    cin>>n;
    vi verR;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        verR.pb(x);
    }

    ll mx = (horD[horD.size()-1] - horD[0])*h;

    mx = max(mx,  (horU[horU.size()-1] - horU[0])*h);

    mx = max(mx,  (verL[verL.size()-1] - verL[0])*w);

    mx = max(mx,  (verR[verR.size()-1] - verR[0])*w);

    cout<<mx<<'\n';
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

