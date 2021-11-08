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
    ll c;
    cin>>c;

    if(c==0){
        cout<<2<<'\n';
        cout<<"1 1\n";
        return;
    }
    vi a;
    while(c>0){
        a.pb(c%2);
        c/=2;
    }

    vi ans;
    for(int i=a.size()-1;i>=0;i--){
        if(a[i]==0){
            if(ans.size()%2==1){
                ans.pb(i);
            }
        }else{
            if(ans.size()%2==0){
                ans.pb(i);
            }
        }
    }
    cout<<ans.size()<<'\n';
    for(int i=0;i<ans.size();i++){
        cout<<(1LL<<(ans[i]+1))-1<<' ';
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

