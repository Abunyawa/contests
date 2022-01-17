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
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

void yes(){
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}

int pre[200100];
int foo(int lw, int mw, int hw){
    

    return pre[lw]+pre[mw]+pre[hw];
}

void solve() {
    int n;
    cin>>n;
    vi cnt(n+3,0);


    for(int i=0;i<n;i++){
        int x;
        cin>>x;

        cnt[x]++;        
    }

    for(int i=1;i<=cnt.size()-1;i++){
        cnt[i] += cnt[i-1];
    }
    n+=2;
    int l = 1;
    int r = n;
    
    int ans = 1e8;
    for(int i=1;i<n-1;i++){
        int x = i;


        int l = x+1;
        int r = n;

        while(l-r>3){
            int m1 = (l * 2 + r) / 3;
            int m2 = (l + r * 2) / 3;

            int lw = cnt[x-1]-cnt[0];
            int mw = cnt[m1-1] - cnt[x-1];
            int hw = cnt[n]-cnt[m1-1];

            int ans1 = foo(lw,mw,hw);


            lw = cnt[x-1]-cnt[0];
            mw = cnt[m2-1] - cnt[x-1];
            hw = cnt[n]-cnt[m2-1];

            int ans2 = foo(lw,mw,hw);

            if(ans1 < ans2){
                r = m1;
            }else{
                l = m2;
            }
        }

        int locA = 1e8;

        for(int y = l;y<=r;y++){
            int lw = cnt[x-1]-cnt[0];
            int mw = cnt[y-1]-cnt[x-1];
            int hw = cnt[n]-cnt[y-1];

            
            locA = min(locA,foo(lw,mw,hw));
        }

        ans = min(ans,locA);
    }

    cout<<ans<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int sz = 1;
    for(int i=0;i<200100;i++){
        if(i>sz){
            sz*=2;
        }

        pre[i] = sz - i;
    }
    int tt = 1;
    cin>>tt;
    while (tt--) {
        solve();
    }

    return 0;
}

