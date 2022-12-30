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
    cout<<"Yes"<<'\n';
}

void no(){
    cout<<"No"<<'\n';
}



void solve() {
    int n,k;
    cin>>n>>k;

    if((n*n)%k!=0){
        no();
        return;
    }

    if(k==1){
        if(n!=1){
            no();
            return;
        }
    }

    if((n*n)/k%n!=0){
        yes();
        int st = 1;
        for(int i=0;i<n;i++){
            for(int j = 0;j<n;j++){
                cout<<st++<<' ';
                if(st>k){
                    st=1;
                }
            }
            cout<<'\n';
            
        }

        return;
    }
    yes();
    int d[n][n];
    int st = 0;
    for(int i=0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout<<(st+j)%k+1<<' ';
        }
        cout<<'\n';
        st++;
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

