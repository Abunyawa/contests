// chrono::system_clock::now().time_since_epoch().count()
#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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
    cin>>n;
    ll tn = n;
    map<ll,int> m;
    int mx = 0;
    ll num;
    for(int i=2;i<=sqrt(n);i++){
        while(n%i==0){
            m[i]++;
            if(m[i]>mx){
                mx = m[i];
                num = i;
            }
            n/=i;
        }
    }
    if(n!=1){
        m[n]++;
        if(m[n]>mx){
            mx = m[n];
            num = n;
        }
    }
    cout<<mx<<'\n';
    for(int i=0;i<mx-1;i++){
        cout<<num<<' ';
        tn/=num;
    }
    cout<<tn<<'\n';

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

