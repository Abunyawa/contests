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

    vector<double> a(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    vl t(n);
    for(int i=0;i<n;i++){
        cin>>t[i];
    }

    double l = 0;
    double r = 1e8;

    while(r-l>0.0000001){
        double m1 = (l*2.0+r)/3.0;
        double m2 = (l+r*2.0)/3.0;

        double ans1 = 0;
        double ans2 = 0;
        for(int i=0;i<n;i++){
            ans1 = max(abs(a[i]-m1)+t[i], ans1);
            ans2 = max(abs(a[i]-m2)+t[i], ans2);
        }
        //cout<<l<<' '<<r<<endl;
        if(ans1<ans2){
            r = m2;
        }else{
            l = m1;
        }
    }
    float ans = (l+r)/2.0;

    printf("%.6f\n", ans);
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

