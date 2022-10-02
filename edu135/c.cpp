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


int f(ll x){
    int ctr = 0;
    while(x!=0){
        x/=10;
        ctr++;
    }

    return ctr;
}
void solve() {
    int n;
    cin>>n;
    map<ll,int> a;
    map<ll,int> b;

    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        a[x]++;
    }

    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        if(a[x]>0){
            a[x]--;
        }else{
            b[x]++;
        }
    }


    vl a0(10, 0);
    vl b0(10, 0);

    vl a1(10, 0);
    vl b1(10, 0);
    for(pair<ll,int> i: a){
        for(int k=0;k<i.se;k++){
            ll x = i.fi;
            
            if(x<10){
                a0[x]++;
            }else{
                a1[f(x)]++;
            }
        }
    }

    for(pair<ll,int> i: b){
        for(int k=0;k<i.se;k++){
            ll x = i.fi;
            
            if(x<10){
                b0[x]++;
            }else{
                b1[f(x)]++;
            }
        }
    }

    int ans = 0;

    for(int i=1;i<10;i++){
        int have = min(a0[i], b1[i]);
        ans+=have;
        a0[i]-=have;
        b1[i]-=have;

        have = min(a1[i], b0[i]);
        ans+=have;
        a1[i]-=have;
        b0[i]-=have;
    }

    for(int i=2;i<10;i++){
        int have = min(a1[i], b1[i]);
        ans+=have*2;
        a1[i]-=have;
        b1[i]-=have;

    }

    for(int i=2;i<10;i++){
        ans+=a0[i];
        ans+=b0[i];
        ans+=a1[i]*2;
        ans+=b1[i]*2;
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

