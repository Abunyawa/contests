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
    cin>>n;
    vector<pair<ll,ll>> a(n);

    for(int i=0;i<n;i++){
        cin>>a[i].fi;
        a[i].se = i+1;
    }
    sort(all(a));

    ll ptr1 = 1;
    ll ptr2 = -1;

    vl ans(n+1);

    ans[0] = 0;

    ll ansT = 0;
    for(int i=n-1;i>=0;i--){
        if(ptr1==-ptr2){
            ansT += (2LL * abs(ptr1))*a[i].fi;
            ans[a[i].se] = ptr1;
            ptr1++;

        }else if(ptr1>-ptr2){
            ansT += (2LL * abs(ptr2))*a[i].fi;
            ans[a[i].se] = ptr2;
            ptr2--;
        }else{
            ansT += (2LL * abs(ptr1))*a[i].fi;
            ans[a[i].se] = ptr1;
            ptr1++;
        }
    }

    cout<<ansT<<'\n';

    for(int i=0;i<=n;i++){
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
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

