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

int q = 0;

ll ask(int i, int j, int k){
    
    cout<<"? "<<i<<' '<<j<<' '<<k<<endl;
    fflush(stdout);

    ll x;
    cin>>x;
    if(x==-1){
        assert(0);
    }
    q++;
    return x;
}

void guess(int i, int j){
    cout<<"! "<<i<<' '<<j<<endl;
    fflush(stdout);

    
}

void solve() {
    int n;
    cin>>n;
    q = 0;

    vector<pair<ll,int>> a;

    for(int i=3;i<=n;i++){
        if(q>2*n-2){
            assert(0);
        }
        ll d = ask(1,2,i);
        a.pb({d,i});
    }

    sort(all(a));

    ll mx = a[a.size()-1].fi;
    int ind = a[a.size()-1].se;

    
    mx = -1;
    vl ans;
    vector<pii> inds;
    for(int i=1;i<=n;i++){
        int f = i;
        int s = i+1;
        if(s>n){
            s = 1;
        }
        if(f==ind){
            continue;
        }
        if(s==ind){
            s++;
            if(s>n){
                s = 1;
            }
        }
        if(q>2*n-2){
            assert(0);
        }
        ll asd = ask(ind,f,s);
        ans.pb(asd);
        mx = max(mx,asd);
        inds.pb({f,s});
    }

    int check = -1;
    for(int i=0;i<ans.size();i++){
        if(ans[i]==ans[(i+1)%ans.size()] && ans[i]==mx){
            check = i;
        }
    }

    int ind2=1;
    if(check == -1){
        guess(1,2);
        fflush(stdout);
        return;
    }
    if(inds[check].fi==inds[(check+1)%ans.size()].fi){
        ind2 = inds[check].fi;
    }else if(inds[check].fi==inds[(check+1)%ans.size()].se){
        ind2 = inds[check].fi;
    }else{
        ind2 = inds[check].se;
    }

    guess(ind,ind2);

    fflush(stdout);
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








