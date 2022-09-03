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
    int n;
    cin>>n;

    vl a(n);
    vi pos;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>0){
            pos.pb(i);
        }
    }



    if(pos.size()<2){
        yes();
        return;
    }

    ll mx = 1e10;
    for(int i=0;i<pos.size()-1;i++){

        if(a[pos[i]]>mx){
            no();
            return;
        }
        ll r = 0;

        for(int j=pos[i];j!=pos[i+1];j++){
            r+=a[j];
        }

        if(r>0){
            mx = min(mx, a[pos[i]]);
        }

    }
    
    if(a[pos[pos.size()-1]]>mx){
        no();
        return;
    }
    mx = 1e10;
    for(int i=pos.size()-1;i>0;i--){

        if(a[pos[i]]>mx){
            no();
            return;
        }
        ll l = 0;

        for(int j=pos[i];j!=pos[i-1];j--){
            l+=a[j];
        }

        if(l>0){
            mx = min(mx, a[pos[i]]);
        }

    }
    
    if(a[pos[0]]>mx){
        no();
        return;
    }

    yes();
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

