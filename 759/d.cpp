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
    vector<pii> a(n);
    set<int> s;
    for(int i=0;i<n;i++){
        cin>>a[i].fi;
        a[i].se = i;
        s.insert(a[i].fi);
    }
    if(s.size()!=n){
        yes();
        return;
    }
    sort(all(a));

    vector<bool> used(n,false);

    ll ans = 0;
    for(int i=0;i<n;i++){
        if(used[i]){
            continue;
        }

        int cur = i;
        int cyc = 0;
        while(!used[cur]){
            used[cur] = true;
            cyc++;
            cur = a[cur].se;
            //cout<<a[cur].fi<<' '<<a[cur].se<<'\n';
        }

        ans+=cyc-1;
    }
    //cout<<ans<<endl;
    if(ans%2==0){
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

