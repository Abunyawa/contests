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
    int n,c;
    cin>>n>>c;
    if(n*(n+1)/2-1<c || c<n-1){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    int need = c-n+1;
    vl ans(n);
    for(int i = 0;i<n;i++){
        ans[i] = i+1;
    }
    int l = 0;
    int r = n-1;
    bool reversed = false;
    while(need>0){
        int mx = r - l;
        if(mx <= need){
            reverse(ans.begin()+l,ans.begin()+r+1);
            need-=mx;
            if(!reversed){
                r--;
            }else{
                l++;
            }
            reversed^=1;
        }else{
            if(!reversed){
                reverse(ans.begin()+l,ans.begin()+l+need+1);
                need = 0;
            }else{
                reverse(ans.begin()+r-need,ans.begin()+r+1);
                need = 0;
            }
        }        
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
    for(int i=1;i<=tt;i++){
        cout<<"Case #"<<i<<": ";
        solve();
    }

    return 0;
}

