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
typedef pair<ll, ll> pll;
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
    vl a(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int ind = -1;
    for(int i=n-1;i>=0;i--){
        if(a[i]!=0){
            ind = i;
            break;
        }
    }

    if(ind==-1){
        yes();
        return;
    }
    ll went = 0;
    for(int i=ind;i>=0;i--){
        a[i]-=went;
        if(a[i]>0){
            no();
            return;
        }
        if(i!=0 && a[i]==0){
            no();
            return;
        }
        went = -a[i];
    }

    if(went!=0){
        no();
    }else{
        yes();
    }
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

