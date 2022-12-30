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

map<vi,int> g;

void solve() {
    g.clear();
    int n,k;
    cin>>n>>k;

    vector<vi> a(n, vi(k,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            cin>>a[i][j];
        }

        g[a[i]] = i+1;
    }

    set<array<int,3>> st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){

            vi lf(k,0);

            for(int p=0;p<k;p++){
                if(a[i][p]==a[j][p]){
                    lf[p]=a[i][p];
                }else{
                    for(int h=0;h<3;h++){
                        if(a[i][p]!=h && a[j][p]!=h){
                            lf[p] = h;
                            break;
                        }
                    }
                }
            }

            if(g[lf]==0){
                continue;
            }else{
                int pos = g[lf];
                pos--;

                if(pos!=i && pos!=j){
                    array<int,3> have = {pos,i,j};
                    sort(all(have));
                    st.insert(have);
                }
            }
        }
    }
    

    vi ctr(n,0);

    for(auto x: st){
        ctr[x[0]]++;
        ctr[x[1]]++;
        ctr[x[2]]++;
    }


    ll ans = 0;

    for(int i=0;i<n;i++){
        ans+=(ctr[i]*(ctr[i]-1))/2;
    }

    cout<<ans<<'\n';
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

