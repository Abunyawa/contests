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
    ll n,m;
    cin>>n>>m;

    vl a(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }


    ll ans = n*(n-1LL)/2LL+n;
    for(int i=0;i<n-1;i++){
        if(a[i]!=a[i+1]){
            ll left = i+1;

            ll right = n-1 - i;


            ans+= right*left;
        }
    }


    for(int k=0;k<m;k++){
        int ind;
        ll x;

        cin>>ind>>x;
        ind--;
        if(ind-1>=0){
            if(a[ind-1]!=a[ind]){
                ll left = ind;

                ll right = n-1 - ind +1;


                ans-= right*left;
            }
        }

        if(ind+1<n){
            if(a[ind]!=a[ind+1]){
                ll left = ind+1;

                ll right = n-1 - ind;


                ans-= right*left;
            }
        }

        a[ind] = x;

        if(ind-1>=0){
            if(a[ind-1]!=a[ind]){
                ll left = ind;

                ll right = n-1 - ind +1;


                ans+= right*left;
            }
        }

        if(ind+1<n){
            if(a[ind]!=a[ind+1]){
                ll left = ind+1;

                ll right = n-1 - ind;


                ans+= right*left;
            }
        }

        cout<<ans<<'\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    //cin>>tt;
    while (tt--) {
        solve();
    }

    return 0;
}

