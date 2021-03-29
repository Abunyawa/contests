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
    int a,b;
    cin>>a>>b;
    ll ans = 0;
    while(a!=0 && b!=0){
        int mn = min(a,b);
        int mx = max(a,b);
        mn+=(mx-1)/2;
        ans+=(mx-1)/2;
        if(mx%2==0){
            mx = 2;
        }else{
            mx = 1;
        }

        a = mx;
        b = mn;

        if(a<=2 && b<=2){
            
            if(a==2 || b==2){
                ans++;
            }
            break;
        }
    }
    cout<<ans<<'\n';

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    
    while (tt--) {
        solve();
    }

    return 0;
}

