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
    vl a(3);
    cin>>a[0]>>a[1]>>a[2];

    sort(all(a));

    ll ans = 0;
    ans+=(a[2]-a[0])/5;
    a[0] += (a[2]-a[0])/5*5; 

    ans+=(a[2]-a[1])/5;
    a[1] += (a[2]-a[1])/5*5; 


    ll mn = a[2]-a[0] + a[2]-a[1];
    for(int i=0;i<2;i++){
        ll loc = 1;
        ll df = a[i]+5;
        for(int j=0;j<3;j++){
            if(i==j) continue;
            loc+=(df-a[j])/5;
            //cout<<df<<' '<<a[j]<<' '<<loc<<'\n';
            loc+=df-(a[j]+((df-a[j])/5*5));
            //cout<<loc<<'\n';
        }
        //cout<<i<<' '<<loc<<'\n';
        mn = min(mn,loc);
    }

    ans+=mn;

    cout<<ans<<'\n';
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

