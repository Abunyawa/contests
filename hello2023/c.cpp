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
    int n,m;
    cin>>n>>m;

    vl a(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==1){
        cout<<0<<'\n';
        return;
    }
    int ans = 0;
    if(a[m-1]>0 && m!=1){
        ans++;
        a[m-1] = -a[m-1];
    }

    ll sm = 0;
    vector<ll> p(m);
    p[0] = 1e17;
    for(int i=0;i<m-1;i++){
        sm += a[i];
        p[i] = min(p[i], sm);
        p[i+1] = p[i];
    }
    sm+=a[m-1];
    ll cur = sm-a[m-1];
    priority_queue<ll> q;
    for(int i=m-2;i>=0;i--){
        if(a[i]>0){
            q.push(a[i]);
        }
        while(cur-a[i]<sm){
            ll mx = q.top();
            q.pop();
            sm-=mx;
            //cout<<i<<' ';
            ans++;
            sm+=-mx;
        }

        cur-=a[i];
        
    }


    ll lm = sm;
    for(int i= m;i<n;i++){
        if(sm+a[i]<lm){
            //cout<<i<<' ';
            a[i] = -a[i];
            ans++;
        }

        sm+=a[i];
    }
    //cout<<'\n';
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

