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
int n;
double a[110];
double b[110];

ll f(double m){

    vector<double> curA;
    vector<double> curB;
    curA.pb(a[0]);
    curB.pb(b[0]);
    for(int i=1;i<n;i++){
        bool d1 = true;
        bool d2 = true;
        for(int j = 0;j<curA.size();j++){
            if(curA[j]+a[i] > m || curB[j]+b[i] > m){
                d1 = false;
            }

            if(curA[j]+b[i] > m || curB[j]+a[i] > m){
                d2 = false;
            }
        }
        if(d1){
            curA.pb(a[i]);
            curB.pb(b[i]);
        }else if(d2){
            curA.pb(b[i]);
            curB.pb(a[i]);
        }else{
            return -1;
        }
    }

    ll ans = 0;

    for(int i=0;i<n;i++){
        for(int j = i+1;j<n;j++){
            ans += (curA[i]+curA[j])*(curA[i]+curA[j]);
            ans += (curB[i]+curB[j])*(curB[i]+curB[j]);
        }
    }

    return ans;
}

void solve() {
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    ll ans = 1e10;
    

    for(int k=0;k<n;k++){
        ll locA = 0;

        for(int i=0;i<n;i++){
            if(i==k){
                continue;
            }
            ll have = (a[i]+a[k])*(a[i]+a[k]) + (b[i]+b[k])*(b[i]+b[k]);
            ll can = (b[i]+a[k])*(b[i]+a[k]) + (a[i]+b[k])*(a[i]+b[k]);

            if(can < have){
                swap(a[i],b[i]);
            }
        }

        for(int i=0;i<n;i++){
            for(int j = i+1;j<n;j++){
                locA += (a[i]+a[j])*(a[i]+a[j]);
                locA += (b[i]+b[j])*(b[i]+b[j]);
            }
        }

        ans = min(ans,locA);
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

