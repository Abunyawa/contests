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
    ll n;
    cin>>n;
    if(n%2!=0){
        cout<<-1<<'\n';
        return;
    }


    vi ans;
    int ctr = 1;
    ll num = 2;
    while(n!=0){
        while((num<<1)<=n){
            num<<=1;
            ctr++;
        }
        n-=num;
        num = 2;
        if(ctr==1){
            ans.pb(1);
            continue;
        }
        ans.pb(1);
        for(int i=0;i<ctr-2;i++){
            ans.pb(0);
        }
        ans.pb(1);
        
        ctr = 1;
    }
    if(ans.size()>2000){
        assert(0);
    }
    cout<<ans.size()<<'\n';
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<' ';
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

