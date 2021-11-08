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
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<array<ll,3>> ans;
    for(int i=0;i<n;i++){
        int ind = i;
        for(int j=i;j<n;j++){
            if(a[j]<a[ind]){
                ind = j;
            }
        }
        ll tmp=a[i];
        for(int j=i+1;j<=ind;j++){
            ll tmpl = a[j];
            a[j] = tmp;
            tmp = tmpl;
        }
        a[i] = tmp;
        if(ind !=i){
            ans.pb({i+1,ind+1,ind-i});
        }
    }

    cout<<ans.size()<<'\n';

    for(int i=0;i<ans.size();i++){
        cout<<ans[i][0]<<' '<<ans[i][1]<<' '<<ans[i][2]<<'\n';
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

