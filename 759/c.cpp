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
    int n, k;
    cin>>n>>k;

    vl a(n);
    vl pos;
    vl neg;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>0){
            pos.pb(a[i]);
        }else if(a[i]<0){
            neg.pb(a[i]);
        }
    }

    sort(all(pos));
    sort(all(neg));
    sort(all(a));
    ll ansPos = 0;
    for(int i=pos.size()-1;i>=0;i-=k){
        ansPos += 2*pos[i];
    }

    ll ansNeg = 0;
    for(int i=0;i<neg.size();i+=k){
        ansNeg += 2*abs(neg[i]);
    }

    
    cout<<ansPos+ansNeg - max(abs(a[0]),abs(a[n-1]))<<'\n';
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

