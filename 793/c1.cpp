// chrono::system_clock::now().time_since_epoch().count()
#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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
    vl a;
    map<ll,int> m;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        m[x]++;
    }

    for(auto p: m){
        if(p.second==1){
            a.pb(p.first);
        }else{
            a.pb(p.first);
            a.pb(p.first);
        }
    }
    n = a.size();
    if(n==1){
        cout<<1<<'\n';
        return;
    }

    int ans1 = 1;
    int ans2 = 1;
    for(int i=2;i<n;i+=2){
        if(a[i-2]<a[i]){
            ans1++;
        }
    }

    for(int i=3;i<n;i+=2){
        if(a[i-2]<a[i]){
            ans2++;
        }
    }


    if(n%2==0){
        if(a[n-1]>a[n-2]){
            ans1++;
        }
    }else{
        if(a[n-1]>a[n-2]){
            ans2++;
        }
    }

    int ans =min(ans1,ans2);

    sort(rall(a));
    ans1 = 1;
    ans2 = 1;
    for(int i=2;i<n;i+=2){
        if(a[i-2]>a[i]){
            ans1++;
        }
    }

    for(int i=3;i<n;i+=2){
        if(a[i-2]>a[i]){
            ans2++;
        }
    }

    if(n%2==0){
        if(a[n-1]<a[n-2]){
            ans1++;
        }
    }else{
        if(a[n-1]<a[n-2]){
            ans2++;
        }
    }
    
    ans = max(ans,min(ans1,ans2));
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

