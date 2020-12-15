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

void yes(){
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}

int n;
double d;
double a1[1000100];

double f(){
    double mx = -1e16;
    double mn = 1e16;
    for(int i=0;i<n;i++){
        mx = max(mx,a1[i]+d*i);
        mn = min(mn,a1[i]+d*i);
    }
    return (mx-mn)/2;
}

double f1(){
    double mx = -1e16;
    double mn = 1e16;
    for(int i=0;i<n;i++){
        mx = max(mx,a1[i]-d*i);
        mn = min(mn,a1[i]-d*i);
    }
    return (mx-mn)/2;
}

void solve() {
    scanf("%d%lf",&n,&d);

    for(int i=0;i<n;i++){
        scanf("%lf",a1+i);
    }
    
    for(int i = 0;i<n;i++){

    }
    
    printf("%.10f\n",min(f(),f1()));

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