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



vector<int> ctr[200100];
void solve() {
    int n;
    cin>>n;
    vector<pii> a(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[i] = {x,i+1};
    }
    int ans = -1;

    sort(all(a));
    if(n==1){
        ans = 1;
    }else{
        if(a[0].fi!=a[1].fi){
            ans = a[0].se;
        }
    }
    if(ans==-1){
        for(int i=1;i<n-1;i++){
            if(a[i].fi!=a[i+1].fi && a[i].fi!=a[i-1].fi){
                ans = a[i].se;
                break;
            }
        }
        if(ans==-1){
            if(a[n-1].fi!=a[n-2].fi){
                ans = a[n-1].se;
            }
        }
    }
    cout<<ans<<'\n';
    

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

