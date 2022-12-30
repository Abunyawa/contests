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
    vi d(n);
    vi used(n,0);
    vector<int> a;
    vector<pii> ans;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        d[i] = x;
        if(x!=0){
            a.pb(i);
        }
    }

    if(a.size()%2==1){
        cout<<-1<<'\n';
        return;
    }

    
    for(int i=0;i<a.size();i+=2){
        if(d[a[i]]==d[a[i+1]]){
            if(a[i]+1==a[i+1]){
                ans.pb({a[i]+1, a[i+1]+1});
            }else{
                ans.pb({a[i]+1, a[i]+1});
                ans.pb({a[i+1], a[i+1]+1});
                used[a[i+1]-1] = 1;
                //cout<<"---"<<used[a[i+1]]<<' '<<a[i+1]<<'\n';
            }
        }else{
            ans.pb({a[i]+1, a[i]+1});

            ans.pb({a[i+1]+1, a[i+1]+1});
        }
    }

    for(int i=0;i<n;i++){
        if(d[i]==0 && used[i]==0){
            //cout<<d[i]<<' '<<i<<' '<<used[i]<<'\n';
            ans.pb({i+1,i+1});
        }
    }

    sort(all(ans));
    cout<<ans.size()<<'\n';
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].fi<<' '<<ans[i].se<<'\n';
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

