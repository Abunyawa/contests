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
ll n, ln, v;
double a[100100];

double f(ll sp){
    double V = sp;
    double ret = 0;

    for(int i=0;i<n;i++){
        double t = ln/(a[i]+V);
        double back = (t*V)/v;
        ret += (t+back)/(double)n;
    }

    return ret;

}


void solve() {
    cin>>n>>ln>>v;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    double l = 0;
    double r = v;
    
    while (r - l > 0.0000000001) {
        double m1 = l + (r - l) / 3,
            m2 = r - (r - l) / 3;
        if (f (m1) < f (m2))
            r = m2;
        else
            l = m1;
    }


    double mn = 10000000000;
    //cout<<l<<' '<<r<<endl;
    for(int i=l;i<=r;i++){
        mn = min(mn,f(i));
    }

    cout<<mn<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    
    while (tt--) {
        solve();
    }

    return 0;
}

