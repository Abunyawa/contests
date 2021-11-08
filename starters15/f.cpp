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


ll foo(ll a, ll b){
    int ctr = 0;

    ll cur = 1;
    while(cur<=a){
        cur*=10;
        ctr++;
    }

    return b*cur+a;
}


void solve() {
    ll n, L, R;
    cin>>n>>L>>R;

    vector<ll> a(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    sort(all(a));
    ll ans =0;

/*
    for(int i=0;i<n;i++){
        cout<<a[i]<<' ';
    }

    cout<<'\n';
*/
    for(int i=0;i<n;i++){
        int limR;
        int limL;
        int l = 0;
        int r = n-1;

        while(l<r){
            int m = (l+r)/2;

            ll res = foo(a[m],a[i]);
            //cout<<res<<'\n';
            if(res<=R){
                if(l==m){
                    break;
                }
                l = m;
                
            }else{
                r = m-1;
            }
        }
        if(foo(a[r],a[i])<=R){
            limR = r;
        }else if(foo(a[l],a[i])<=R){
            limR = l;
        }else{
            continue;
        }

        l = 0;
        r = limR;
        while(l<r){
            int m = (l+r)/2;

            ll res = foo(a[m],a[i]);
            if(res>=L){
                if(r==m){
                    break;
                }
                r = m;
            }else{
                l = m+1;
            }
        }

        if(foo(a[l],a[i])>=L){
            limL = l;
        }else if(foo(a[r],a[i])>=L){
            limL = r;
        }else{
            continue;
        }

        //cout<<i<<' '<<limL<<' '<<limR<<'\n';
        if(limL<=limR){
            ans += limR-limL+1;
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

