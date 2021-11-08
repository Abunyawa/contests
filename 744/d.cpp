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
typedef pair<ll, ll> pll;
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
    vector<pll> a(n);
    
    for(int i=0;i<n;i++){
        cin>>a[i].fi;
        a[i].se = i;
    }

    vector<pll> ans;
    sort(all(a));
    ll sm = 0;
    for(int i=0;i<n-1;i++){
        sm+=a[i].fi;
    }
    if(sm<=a[n-1].fi){
        for(int i=0;i<n-1;i++){
            for(int j=0;j<a[i].fi;j++){
                ans.pb({a[i].se, a[n-1].se});
            }
        }   
    }else{
        if(sm==a[n-1].fi+1){
            for(int i=0;i<n-2;i++){
                for(int j=0;j<a[i].fi;j++){
                    ans.pb({a[i].se, a[n-1].se});
                }
            }
            for(int j=0;j<a[n-2].fi-1;j++){
                ans.pb({a[n-2].se, a[n-1].se});
            }
        }else{
            for(int i=0;i<n-2;i++){
                int fx = a[i].fi;
                for(int j=0;j<fx;j++){
                    if(sm-2>=a[n-1].fi){
                        ans.pb({a[i].se, a[i+1].se});
                        a[i].fi--;
                        a[i+1].fi--;
                        sm-=2;
                    }else{
                        break;
                    }
                }
            }
            if(sm<=a[n-1].fi){
                for(int i=0;i<n-1;i++){
                    for(int j=0;j<a[i].fi;j++){
                        ans.pb({a[i].se, a[n-1].se});
                    }
                }
            }else{
                for(int i=0;i<n-2;i++){
                    for(int j=0;j<a[i].fi;j++){
                        ans.pb({a[i].se, a[n-1].se});
                    }
                }
                for(int j=0;j<a[n-2].fi-1;j++){
                    ans.pb({a[n-2].se, a[n-1].se});
                }
            }
        }
    }


    cout<<ans.size()<<'\n';
    for(auto d: ans){
        cout<<d.fi+1<<' '<<d.se+1<<'\n';
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

