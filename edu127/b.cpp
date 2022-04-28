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
    vl a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ctr2 = 0;
    int ctr3 = 0;
    for(int i=1;i<n;i++){
        if(a[i]-a[i-1]>3){
            no();
            return;
        }else if(a[i]-a[i-1]==3){
            ctr3++;
        }else if(a[i]-a[i-1]==2){
            ctr2++;
        }
    }

    if(ctr3>1){
        no();
    }else if(ctr2>2){
        no();
    }else{
        if(ctr3>0 && ctr2>0){
            no();
        }else{
            yes();
        }
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

