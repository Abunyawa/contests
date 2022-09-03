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
    int n,k;
    cin>>n>>k;

    map<ll, int> m;

    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        m[x]++;
    }
    
    vector<ll> a;
    for(auto p: m){
        if(p.second>=k){
            a.pb(p.first);
        }
    }

    //sort(all(a));


    

    if(a.size()==0){
        cout<<-1<<'\n';
        return;
    }


    int l = 0;
    int r = 0;

    int cur = 1;

    for(int i=1;i<a.size();i++){
        if(a[i]-a[i-1]==1){
            cur++;
        }else{
            int locr = a[i-1];
            int locl = a[i-1]-cur+1;

            if(locr-locl >= r-l){
                r = locr;
                l = locl;
            }
            
            cur = 1;
        }
    }

    int locr = a[a.size()-1];
    int locl = a[a.size()-1]-cur+1;

    if(locr-locl >= r-l){
        r = locr;
        l = locl;
    }


    cout<<l<<' '<<r<<'\n';
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

