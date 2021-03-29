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

int primes[] = {4,9,16,25,36,49,64,81,100,121,144,169,196,225,256,289,324,361,400};


void solve() {
    int n,k;
    cin>>n>>k;
    vl a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        for(int j=2;j*j<=a[i];j++){
            while(a[i]%(j*j)==0){
                a[i]/=j*j;
            }
        }
    }
    /*
    for(int i=0;i<n;i++){
        cout<<a[i]<<' ';
    }
    cout<<'\n';
    */
    set<int> st;
    int ans = 1;
    int ctr = 0;
    for(int i=0;i<n;i++){
        int prev = st.size();
        st.insert(a[i]);
        if(st.size()==prev){
            if(k>0){
                k--;
                st.insert(primes[ctr++]);
            }else{
                st.erase(all(st));
                ans++;
                st.insert(a[i]);
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

