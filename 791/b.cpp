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
    int n,q;
    cin>>n>>q;

    vector<pair<ll,int>> a(n);


    int last = -1;
    ll ch;
    ll sm =0;
    for(int i=0;i<n;i++){
        cin>>a[i].fi;
        a[i].se = 0;
        sm+=a[i].fi;
    }

    for(int i=1;i<=q;i++){
        int t;
        cin>>t;
        if(t==1){
            int ind;
            ll x;
            cin>>ind>>x;

            if(last<a[ind-1].se){
                sm-=a[ind-1].fi;
                sm+=x;
                a[ind-1] = {x,i};
            }else{
                sm-=ch;
                sm+=x;
                a[ind-1] = {x,i};
            }

        }else{
            ll x;
            cin>>x;
            last = i;
            ch = x;

            sm = ch*n;
        }

        cout<<sm<<'\n';

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

