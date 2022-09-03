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


int foo(vi a, int mid, int k){
    int n = a.size();
    int mx = -1;
    int mn = -1;

    for(int j=0;j<n;j++){
        int need = a[j]/mid;

        need = min(need, k);

        if(need==0){
            need = 1;
        }

        int have = a[j]/need;

        if(mx==-1){
            mx = have;
        }else{
            mx = max(mx,have);
        }

        if(mn==-1){
            mn = have;
        }else{
            mn = min(mn,have);
        }
    }

    return mx-mn;
}


void solve() {
    int n,k;
    cin>>n>>k;

    vi a(n);
    set<int> st;
    for(int i=0;i<n;i++){
        cin>>a[i];

        for(int j=1;j<=sqrt(a[i]);j++){
            if(a[i]%j==0){
                st.insert(j);
                st.insert(a[i]/j);
            }
        }
    }

    int ans = -1;
    
    for(int x: st){
        if(ans==-1){
            ans = foo(a,x,k);
        }else{
            ans = min(ans,foo(a,x,k));
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

