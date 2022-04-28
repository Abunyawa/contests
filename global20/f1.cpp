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
    vector<queue<int>> ctr(n+1);
    for(int i=0;i<n;i++){
        cin>>a[i];
        ctr[a[i]].push(i);
    }
    vector<pii> good;
    for(int i=1;i<=n;i++){
        if(ctr[i].size()!=0){
            good.pb({ctr[i].size(),i});
        }
    }

    sort(all(good));

    int ptr = 0;
    while(ptr<good.size()){
        int last = -1;
        while(ptr<good.size() && ctr[good[ptr].se].empty()){
            ptr++;
        }
        for(int i=ptr;i<good.size();i++){
            if(last==-1){
                last = ctr[good[i].se].front();
                ctr[good[i].se].pop();
            }else{
                int cur = ctr[good[i].se].front();
                ctr[good[i].se].pop();
                int tmp = a[last];
                a[last] = a[cur];
                a[cur] = tmp;

                last = cur;
            }
            
        }
    }

    for(int i=0;i<n;i++){
        cout<<a[i]<<' ';
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

