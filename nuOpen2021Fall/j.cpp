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
    int n,m;
    cin>>n;
    vl a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cin>>m;
    vl b(m);
    for(int i=0;i<m;i++){
        cin>>b[i];
    }

    ll cur = 0;
    int ptr = 0;
    int ctr = 0;
    vi vals;
    for(int i=0;i<n;i++){
        cur+=a[i];
        ctr++;
        if(cur<b[ptr]){
            continue;
        }else{
            if(cur==b[ptr]){
                vals.pb(ctr);
                ctr = 0;
                cur = 0;
                ptr++;
            }else{
                cout<<0<<'\n';
                return;
            }
        }
    }

    if(ptr!=m){
        cout<<0<<'\n';
        return;
    }

    sort(all(vals));

    if(vals.size()==0){
        cout<<0<<'\n';
        return;
    }else{
        bool flag = true;
        int nzr = 0;
        for(int i=0;i<vals.size();i++){
            if(vals[i]>1){
                flag = false;
                nzr++;
            }
        }
        vi m(n+1,0);
        if(flag){
            cout<<n<<'\n';
            for(int i=0;i<n;i++){
                cout<<i+1<<'\n';
            }
        }else{
            for(int i=0;i<vals.size();i++){
                ll cur = vals[i]-1;
                if(cur==0){
                    continue;
                }
                for(int j = 1;j<=sqrt(cur);j++){
                    if(cur%j==0){
                        if(cur/j!=j){
                            m[j]++;
                            m[cur/j]++;
                        }else{
                            m[j]++;
                        }
                    }
                }
            }

            int ans = 0;
            vi p;
            for(int i=0;i<n;i++){
                if(m[i]==nzr){
                    ans++;
                    p.pb(i+1);
                }
            }

            cout<<ans<<'\n';
            for(int i=0;i<ans;i++){
                cout<<p[i]<<' ';
            }
            cout<<'\n';
        }
    }
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

