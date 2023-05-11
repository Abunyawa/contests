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
    ll n;
    cin>>n;

    ll have = 1;

    if(n%2==0){
        cout<<-1<<'\n';
        return;
    }

    int cur = 0;
    vi ans;

    while(n!=1){
        if(((n-1)/2)%2==1){
            n = (n-1)/2;
            ans.pb(2);
        }else{
            n = (n+1)/2;
            ans.pb(1); 
        }
    }

    if(ans.size()>40){
        cout<<-1<<'\n';
    }else{
        cout<<ans.size()<<'\n';
        for(int i=ans.size()-1;i>=0;i--){
            cout<<ans[i]<<' ';
        }

        cout<<'\n';
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

