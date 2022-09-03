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

    vi a(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    if(n>2*k){
        no();
        return;
    }

    map<int,int> ctr;

    for(int i=0;i<n;i++){
        ctr[a[i]]++;

        if(ctr[a[i]]>2){
            no();
            return;
        }
    }

    yes();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    cin>>tt;

    for(int i=1;i<=tt;i++){
        cout<<"Case #"<<i<<": ";
        solve();
    } 
   

    return 0;
}

