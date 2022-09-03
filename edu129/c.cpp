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
    vi a(n);
    vi b(n);
    vi ag(n);
    vi bg(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
        ag[i] = a[i];
    }

    for(int i=0;i<n;i++){
        cin>>b[i];
        bg[i] = b[i];
    }

    sort(all(ag));
    sort(all(bg));

    vector<pii> ans;
    for(int i=0;i<n;i++){
        int needA = ag[i];
        int needB = bg[i];
        bool flag = false;


        for(int j = i;j<n;j++){
            if(a[j]==needA && b[j]==needB){
                flag = true;
                if(j!=i){
                    ans.pb({i,j});
                }

                swap(a[i],a[j]);
                swap(b[i],b[j]);
                break;
            }
        }

        if(!flag){
            cout<<-1<<'\n';
            return;
        }
    }

    cout<<ans.size()<<'\n';
    for(pii x: ans){
        cout<<x.fi+1<<' '<<x.se+1<<'\n';
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

