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
    int n;
    ll k;
    cin>>n>>k;
    vl a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    sort(all(a));
    int mid = n/2;
    ll cur = a[mid];
    int went = 1;
    ll ans = 0;
    for(int i=mid+1;i<n;i++){
        if(went*a[i]-cur>k){
            ans = a[mid] + k/went;
            break;
        }else{
            a[mid] = a[i];
            k-=went*a[i]-cur;
            went++;
            cur=a[i]*went;
        }
    }
    ans = a[mid] + k/went;

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

