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
    vector<pair<ll,int>> a(n);

    for(int i=0;i<n;i++){
        cin>>a[i].fi;
        a[i].se = i;
    }

    sort(all(a));
    int cur = 1;

    vi ans(n,-1);
    for(int i=1;i<n;i++){
        if(a[i].fi==a[i-1].fi){
            cur++;
        }else{
            if(cur==1){
                cout<<-1<<'\n';
                return;
            }

            int st = i-cur;
            int fn  = i - 1;
            ans[a[fn].se] = a[st].se;
            for(int k=st;k<fn;k++){
                ans[a[k].se] = a[k+1].se;
            }
            cur = 1;
        }
    }

    if(cur==1){
        cout<<-1<<'\n';
        return;
    }

    int st = n-cur;
    int fn  = n - 1;
    ans[a[fn].se] = a[st].se;
    for(int k=st;k<fn;k++){
        ans[a[k].se] = a[k+1].se;
    }


    for(int i=0;i<n;i++){
        cout<<ans[i]+1<<' ';
    }

    cout<<'\n';


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

