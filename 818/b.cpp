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
    int n,k,r,c;
    cin>>n>>k>>r>>c;

    vector<vi> a(n,vi(n,0));

    queue<pii> q;

    q.push({r-1,c-1});
    while(!q.empty()){
        pii cur = q.front();

        q.pop();

        a[cur.fi][cur.se] = 1;

        
        for(int i = cur.fi+k;a[i%n][cur.se]!=1;i+=k){
            a[i%n][cur.se] = 1;
        }

        pii next = {(cur.fi+1)%n, (cur.se+1)%n};

        if(a[next.fi][next.se]!=1){
            q.push(next);
        }
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==1){
                cout<<'X';
            }else{
                cout<<'.';
            }
        }

        cout<<'\n';
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

