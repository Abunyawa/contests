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
    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    vl a(n1);
    vl b(n2);
    vl c(n3);
    ll ans = 0;
    for(int i=0;i<n1;i++){
        cin>>a[i];
        ans+=a[i];
    }
    for(int i=0;i<n2;i++){
        cin>>b[i];
        ans+=b[i];
    }
    for(int i=0;i<n3;i++){
        cin>>c[i];
        ans+=c[i];
    }

    sort(all(a));
    sort(all(b));
    sort(all(c));
    ll sm = ans;

    ll sm1 = sm;
    sm1-=2*a[0];
    ll loc = 0;
    for(int i=1;i<n1;i++){
        loc+=a[i];
    }
    if(loc>=min(b[0],c[0])){
        sm1-=2*min(b[0],c[0]);
    }else{
        sm1-=2*loc;
    }

    ll sm2 = sm;
    sm2-=2*b[0];
    loc = 0;
    for(int i=1;i<n2;i++){
        loc+=b[i];
    }
    if(loc>=min(a[0],c[0])){
        sm2-=2*min(a[0],c[0]);
    }else{
        sm2-=2*loc;
    }

    ll sm3 = sm;
    sm3-=2*c[0];
    loc = 0;
    for(int i=1;i<n3;i++){
        loc+=c[i];
    }
    if(loc>=min(a[0],b[0])){
        sm3-=2*min(a[0],b[0]);
    }else{
        sm3-=2*loc;
    }


    cout<<max(sm1,max(sm2,sm3))<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    //cin>>tt;

    while (tt--) {
        solve();
    }

    return 0;
}

