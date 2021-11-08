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
    ll n, a, b;
    cin>>n>>a>>b;

    vl x;
    ll ctr=0;
    ll fix = n;
    ll ctr2=0;
    for(int i=2;i<=sqrt(fix);i++){
        while(n%i==0){
            if(i%2==0){
                ctr++;
            }else{
                ctr2++;
            }
            n/=i;
        }
    }

    if(n!=1){
        if(n%2==0){
            ctr++;
        }else{
            ctr2++;
        }
    }

    ll ans = 0;
    if(ctr>0){
        if(a<0 && b<0){
            ans+=a;
        }else if(a<0){
            ans+=a;

            ans+=ctr2*b;
        }else if(b<0){
            ans+=a*ctr;
        }else{
            ans+=a*ctr;
            ans+=ctr2*b;
        }
    }else{
        if(b>0){
            ans+=ctr2*b;
        }else{
            ans+=b;
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

