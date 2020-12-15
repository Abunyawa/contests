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

void yes(){
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}



void solve() {
    int n,k;
    cin>>n>>k;
    vi a(n);
    vi ag(n);
    for(int i = 0;i<n;i++){
        cin>>a[i];
        ag[i] = a[i];
    }
    int bestA = 999999999;
    for(int col=1;col<=100;col++){
        for(int i=0;i<n;i++){
            a[i] = ag[i];
        }
        int ans = 0;
        int l = 0;
        while(l<n){
            while(l<n && a[l]==col) l++;
            if(l>=n) break;
            for(int i = l;i<min(l+k,n);i++){
                a[i]=col;
            }
            ans++;
            l +=k;
        }
        bestA = min(bestA,ans);
    }

    cout<<bestA<<'\n';
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

