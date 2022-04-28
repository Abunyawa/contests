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
    map<ll,int> m;
    vl a;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        if(m[x]==0){
            a.pb(x);
            m[x]++;
        }
    }
    if(m[1]==0){
        yes();
        return;
    }
    sort(all(a));
    bool flag = true;
    for(int i=0;i<a.size()-1;i++){
        if(a[i+1]-a[i]==1){
            flag = false;
        }
    }

    if(flag){
        yes();
    }else{
        no();
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

