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

vector<pii> ai(4);

vector<pii> a(4);

ll ans = 1e9;

ll findD(int x, int d){
    ll ans = 0;
    for(int i = 0;i<4;i++){
        if(i<2) ans+=abs(a[i].fi-x);
        else ans+=abs(a[i].fi-(x+d));
    }
    return ans;
}

ll findD2(int x,int d){
    ll ans = 0;
    for(int i = 0;i<4;i++){
        if(i<2) ans+=abs(a[i].se-x);
        else ans+=abs(a[i].se-(x+d));
    }
    return ans;
}


ll build(ll d){
    ll l = 0;
    ll r = 1e9;
    ll ans = 0;
    while(r-l!=0){
        ll a = (l*2+r)/3;
        ll b = (l+r*2)/3;
        if(findD(a,d)<findD(b,d)){
            if(r==b) break;
            r = b;
        }else{
            if(l==a) break;
            l = a;
        }
    }
    ans+=min(findD(l,d),findD(r,d));
    r = 0;
    l = 1e9;
    while(r-l!=0){
        ll a = (l*2+r)/3;
        ll b = (l+r*2)/3;
        if(findD2(a,d)<findD2(b,d)){
            if(r==b) break;
            r = b;
        }else{
            if(l==a) break;
            l = a;
        }
    }
    ans+=min(findD2(l,d),findD2(r,d));

    return ans;

}

void check(){
    ll l = 0;
    ll r = 1e9;
    while(r-l!=0){
        ll a = (l*2+r)/3;
        ll b = (l+r*2)/3;
        if(build(a)<build(b)){
            if(r==b) break;
            r = b;
        }else{
            if(l==a) break;
            l = a;
        }
    }


    ans = min(ans,min(build(l),build(r)));
}


void solve() {
    for(int i=0;i<4;i++){
        cin>>ai[i].fi>>ai[i].se;
    }
    ans = 1e9;
    sort(all(ai));
    
    for(int i=0;i<4;i++){
        for(int j = 0;j<4;j++){
            for(int k = 0;k<4;k++){
                for(int y = 0;y<4;y++){
                    if(i!=j && i!=k && i!=y && j!=k && j!=y && k!=y){
                        a[0] = ai[i];
                        a[1] = ai[j];
                        a[2] = ai[k];
                        a[3] = ai[y];
                        check();
                    }
                }
            }
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
 