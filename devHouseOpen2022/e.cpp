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
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

void yes(){
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}

int axis[7000000];

void solve() {
    int n;
    cin>>n;

    vl a(n-1);

    for(int i=0;i<n-1;i++){
        cin>>a[i];
    }

    vl x(n);

    for(int i=0;i<n;i++){
        cin>>x[i];
    }

    vector<pll> t1;
    vector<pll> t2;

    set<ll> st;


    ll cur = 0;
    for(int i=0;i<n;i++){
        st.insert(cur);
        st.insert(cur+x[i]);
        st.insert(cur+x[i]+1);
        t1.pb({cur,cur+x[i]});
        cur+=x[i];
        cur+=a[i];
    }

    cur = 0;

    for(int i=n-1;i>=0;i--){
        st.insert(cur);
        st.insert(cur+x[i]);
        st.insert(cur+x[i]+1);
        t2.pb({cur, cur+x[i]});
        cur+=x[i];
        cur+=a[i-1];
    }
    map<ll,ll> m;
    map<ll,ll> m1;
    int ctr = 0;
    for(ll x: st){
        cout<<x<<' '<<ctr<<'\n';
        m[x] = ctr;
        m1[ctr] = x;
        ctr++;
    }

    for(int i=0;i<n;i++){
        axis[m[t1[i].fi]]++;
        axis[m[t1[i].se]+1]--;
        axis[m[t2[i].fi]]++;
        axis[m[t2[i].se]+1]--;
    }
    
    cur = 0;
    for(int i=0;i<7000000;i++){
        cur+=axis[i];
        axis[i] = cur;
    }


    int s = 0;
    ll ans = 0;
    for(int i=1;i<7000000;i++){
        if(i<10){
            cout<<axis[i]<<' ';
        }
        
        if(axis[i]==2){
            if(axis[i-1]!=2){
                s = i;
            }
        }else{
            if(axis[i-1]==2){
                ans += m1[i-1]-m1[s]+1;
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
    
    while (tt--) {
        solve();
    }

    return 0;
}

