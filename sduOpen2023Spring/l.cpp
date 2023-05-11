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
    cin>>n>>m;

    vi a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    } 

    vi b(n);
    for(int i=0;i<m;i++){
        cin>>b[i];
    }

    map<int, array<int, 3>> mm;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                int sm = a[i]+a[j]+a[k];

                mm[sm] = {i,j,k};
            }
        }
    }

    int ans = -1;
    array<int,3> ansI;
    int tr;
    for(int i=0;i<m;i++){
        for(int cur = b[i]-1;cur>=3;cur--){
            if(mm.find(cur)!=mm.end()){
                if(ans==-1 || (b[i]-cur)<ans){
                    tr = i;
                    ans = b[i]-cur;
                    ansI = mm[cur];
                }
            }
        }   
    }

    if(ans==-1){
        cout<<ans<<'\n';
        return;
    }
    cout<<ansI[0]+1<<' '<<ansI[1]+1<<' '<<ansI[2]+1<<' '<<tr+1<<'\n';
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

