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
    int n,k;
    cin>>n>>k;
    vector<pii> a(n);
    for(int i = 0;i<n;i++){
        cin>>a[i].fi>>a[i].se;
    }
    vi in(n,0);
    for(int i=0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(abs(a[i].fi-a[j].fi)+abs(a[i].se-a[j].se)<=k){
                in[i]++;
                in[j]++;
            }
        }
    }

   for(int i=0;i<n;i++){
       if(in[i]==n-1){
           cout<<1<<'\n';
           return;
       }
   }

   cout<<-1<<'\n';
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

