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
    vector<char> a(n);
    int ctr=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]=='0'){
            ctr++;
        }
    }

    vi ans;

    for(int i=0;i<n-ctr;i++){
        if(a[n-i-1]=='0'){
            ans.pb(n-i);
        }
    }

    for(int i=ctr-1;i>=0;i--){
        if(a[i]=='1'){
            ans.pb(i+1);
        }
    }

    if(ans.size()==0){
        cout<<0<<'\n';
        return;
    }else{
        cout<<1<<'\n';
    }

    reverse(all(ans));
    cout<<ans.size()<<' ';
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<' ';
    }


    cout<<'\n';

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

