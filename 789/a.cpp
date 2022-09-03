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
int hasLeft[5010][5010];
int hasRight[5010][5010];

/*
6
hasLeft
   5 3 6 1 4 2
1: 0 0 0 1 1 1
2: 0 0 0 0 0 1
3: 0 1 1 1 1 1
4: 0 0 0 0 1 1
5: 1 1 1 1 1 1
6: 0 0 1 1 1 1 

hasLeft
   5 3 6 1 4 2
1: 0 0 0 1 1 1
2: 0 0 0 1 1 2
3: 0 1 1 2 2 3
4: 0 1 1 2 3 4
5: 1 2 2 3 4 5
6: 1 2 3 4 5 6


hasRight
   5 3 6 1 4 2
1: 1 1 1 1 0 0
2: 1 1 1 1 1 1
3: 1 1 0 0 0 0
4: 1 1 1 1 1 0
5: 1 0 0 0 0 0
6: 1 1 1 0 0 0 
*/


void solve() {
    int n;
    cin>>n;
    vi a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=n+1;j++){
            hasLeft[i][j] = 0;
            hasRight[i][j] = 0;
        }
    }


    for(int i=1;i<=n;i++){
        

        for(int j=1;j<=n;j++){
            hasLeft[i][j] = hasLeft[i-1][j];
        }
        hasLeft[i][a[i]]++;
    }


    for(int i=n;i>=1;i--){
        

        for(int j=1;j<=n;j++){
            hasRight[i][j] = hasRight[i+1][j];
        }
        hasRight[i][a[i]]++;
    }



    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            hasLeft[i][j] = hasLeft[i][j-1]+hasLeft[i][j];
            hasRight[i][j] = hasRight[i][j-1]+hasRight[i][j];

            //cout<<prefLeft[i][j]<<' ';
        }
        //cout<<'\n';
    }
    ll ans = 0;
    for(int i=2;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            ll left = hasLeft[i-1][a[j]-1];
            ll right = hasRight[j+1][a[i]-1];

            //cout<<i<<' '<<j<<' '<<left<<' '<<right<<'\n';
            
            ans+=left*right;
        }
    }


    cout<<ans<<'\n';
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

