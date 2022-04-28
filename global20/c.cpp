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
    vl a(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    vector<pii> sm;

    int cur = 1;

    for(int i=1;i<n;i++){
        if(a[i]==a[i-1]){
            cur++;
        }else{
            if(cur>1){
                sm.pb({i-cur,cur});
            }
            cur=1;
        }
    }
    if(cur>1){
        sm.pb({n-cur,cur});
    }

    ll ans = 0;
  
    
    ll mn = 0;

    if(sm.size()>1){
        int s = sm[0].fi;
        int f = sm[sm.size()-1].fi + sm[sm.size()-1].se - 1;
        //cout<<s<<' '<<f<<'\n';
        mn = f-s-2;
    }else{
        if(sm.size()==1){
            if(sm[0].se>2){
                mn = max(1,sm[0].se-3);
            }
        }else{
            mn = 0;
        }
    }
    /*
    int sms = sm.size();
    for(int i=1;i<(sms-1);i++){
        int l = sm[i].fi;
        int r = sm[i].fi+sm[i].se-1;

        ll tot1 = 3;
        ll tot2 = 3;
        ll dl = sm[0].fi+sm[0].se-1;
        tot1+=l-dl-1;
        tot2+=r-1-dl-1;
        ll dr = sm[sm.size()-1].fi;
        tot1 +=dr-(l+1)-1;
        tot2 += dr-r-1;

        mn = min(mn, min(tot1,tot2));
    }
    
    if(sm.size()>1){
        int rs = sm[0].fi+sm[0].se-1;
        int lf = sm[sm.size()-1].fi;

        ll tot = 1;
        tot+=lf-rs-1;

        mn = min(mn, tot);
    }else{
        mn = 0;
    }
    */
    ans+=mn;


    cout<<ans<<endl;

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

