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
    ll n,s;
    cin>>n>>s;
    vl a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    sort(all(a));

    ll sm = 0;
    for(int i =1; i<n;i++){
        sm+=a[i]-a[0];
    }

    if(sm>=s){
        cout<<a[0];
    }else{
        s -= sm;
        ll levels = (s+n-1) / n;
        if((a[0]-levels)<0){
            cout<<-1<<'\n';
        }else{
            cout<<a[0]-levels<<'\n';
        }
    }
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

