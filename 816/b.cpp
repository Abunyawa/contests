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
    ll k,b,s;
    cin>>n>>k>>b>>s;

    if(k*b>s){
        cout<<-1<<'\n';
        return;
    }

    if(k*b+(k-1)*n < s){
        cout<<-1<<'\n';
        return;
    }

    ll left = s - k*b;
    if(k==1){
        if(left!=0){
            cout<<-1<<'\n';
            return;
        }

        cout<<s<<' ';
        for(int i=1;i<n;i++){
            cout<<0<<' ';
        }

        cout<<'\n';
        return;
    }
    if((left + (k-1)-1)/(k-1)>n){
        cout<<-1<<'\n';
        return;
    }

    vl ans(n,0);
    ans[0] = k*b;

    int ptr = 0;

    while(left>0){
        ans[ptr] += min(left, k-1);
        left-=min(left,k-1);
        ptr++;
    }


    for(int i=0;i<n;i++){
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

