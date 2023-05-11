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
    ll c,d;
    cin>>n>>c>>d;

    vl a;
    ll ans =n*c+d;
    set<ll> st;
    ll fx = 0;
    for(int i=0;i<n;i++){
        ll x;
        int szs = st.size();
        cin>>x;
        st.insert(x);
        if(st.size()==szs){
            fx+=c;
        }else{
            a.pb(x);
        }
    }

    ll left = 0;
    ll right = a.size();
    sort(all(a));

    for(int i=0;i<a.size();i++){
        ll pr = (a[i]-1LL - left)*d + (a.size()-1LL-i)*c;

        //cout<<pr+fx<<"----\n";
        ans = min(ans, pr+fx);
        left++;
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

