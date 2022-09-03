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
    ll k;

    cin>>n>>k;

    string s;
    cin>>s;
    ll cur = 0;
    vl d;
    for(int i=n-1;i>=0;i--){
        if(s[i]=='1'){
            d.pb(cur);
        }

        cur++;
    }

    int ans = 0;

    for(int i=0;i<n-1;i++){
        if(s[i]=='1' && s[i+1]=='1'){
            ans+=11;
        }else if(s[i]=='1' && s[i+1]=='0'){
            ans+=10;
        }else if(s[i]=='0' && s[i+1]=='1'){
            ans+=1;
        }
    }
    
    if(d.size()==0){
        cout<<ans<<'\n';
        return;
    }

    if(d.size()==1){
        
        if(d[0]==0){
            cout<<ans<<'\n';
            return;
        }

        if(d[0]<=k){
            ans-=10;
            if(d[0]==n-1){
                ans++;
            }
            cout<<ans<<'\n';
            return;
        }

        if(d[0]==n-1){
            cout<<ans<<'\n';
            return;
        }

        if(n-1-d[0]<=k){
            ans--;
            cout<<ans<<'\n';
            return;
        }

        cout<<ans<<'\n';
        return;
    }

    if(d.size()>1){
        if(d[0]<=k && d[0]!=0){
            ans-=10;
            k-=d[0];
        }

        if(n-1-d[d.size()-1]<=k && d[d.size()-1]!=n-1){
            ans--;
        }

        cout<<ans<<'\n';
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

