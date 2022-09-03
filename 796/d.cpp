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


/*
5 6 1 2 3   1
6 7 1 3 4   7
7 1 2 4 5   7
1 2 3 5 6   2
2 1 4 6 7   4
3 2 1 7 8   7
4 3 2 1 9   9


5 6 1 2 3
    
0 1 2 3 4
      2
    4
  6   

*/
void solve() {
    int n;
    ll k;
    cin>>n>>k;

    vl a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    if(k>=n){
        ll sm = 0;

        for(int i=0;i<n;i++){
            sm+=a[i];
        }

        for(int i=0;i<n;i++){
            sm+=(k-1-i);
        }
        cout<<sm<<'\n';
    }else{
        ll cur = 0;
        for(int i=0;i<k;i++){
            cur+=a[i];
        }

        ll mx = cur;

        for(int i=1;i+k<=n;i++){
            cur-=a[i-1];
            cur+=a[i+k-1];

            mx = max(mx,cur);
        }

        for(int i=0;i<k;i++){
            mx+=i;
        }

        cout<<mx<<'\n';
    }
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

