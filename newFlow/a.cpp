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

    vi a(n);
    vi b(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i] = a[i];
    }

    sort(all(b));
    map<int,int> m;
    map<int,int> ans;
    for(int i=0;i<n;i++){
        int cur = b[i];

        ans[cur] = 0;
        for(int j = 1;j<=sqrt(cur);j++){
            if(cur%j==0){
                if(cur/j==cur/(cur/j)){
                    ans[cur] += m[j];
                }else{
                    ans[cur] += m[j];
                    ans[cur] += m[cur/j];
                }
            }
        }
        //cout<<ans[cur]<<' ';
        m[cur]++;
    }
    //cout<<'\n';
    for(int i=0;i<n;i++){
        b[i] = ans[a[i]];
        //cout<<b[i]<<' ';
    }

    ll sm = 0;
    ll smb = 0;
    for(int i=0;i<k;i++){
        sm+=b[i];
    }
    smb = sm;
    for(int i=k;i<n;i++){
        sm+=b[i];
        sm-=b[i-k];

        smb = min(sm,smb);
    }


    cout<<smb<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    
    while (tt--) {
        solve();
    }

    return 0;
}

