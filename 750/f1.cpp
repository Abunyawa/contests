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



bool used[10010];

void solve() {
    int n;
    cin>>n;
    vl a(n);
    vl uni;
    used[0] = true;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(!used[a[i]]){
            used[a[i]]=true;
            uni.pb(a[i]);
        }
    }

    for(int i=0;i<uni.size();i++){
        for(int j=0;j<i;j++){
            if(uni[j]<uni[i]){
                ll res = uni[i]^uni[j];
                if(res == 9){
                    cout<<uni[i]<<' '<<uni[j]<<endl;
                }
                if(!used[res]){
                    used[res] = true;
                }
            }
        }
    }


    sort(all(uni));
    for(int i=0;i<501;i++){
        if(used[i]) cout<<i<<' ';
    }

    cout<<'\n';
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

