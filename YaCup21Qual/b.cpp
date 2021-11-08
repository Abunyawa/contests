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
    int n;
    cin>>n;
    map<array<char,4>, int> m;
    for(int i=0;i<n;i++){
        char c1, c2,c3,c4;
        cin>>c1>>c2>>c4>>c3;
        m[{c1,c2,c3,c4}]++;
        m[{c2,c3,c4,c1}]++;
        m[{c3,c4,c1,c2}]++;
        m[{c4,c1,c2,c3}]++;
    }
    int x,y;
    cin>>x>>y;
    char d[x][y];

    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            cin>>d[i][j];
        }
    }

    for(int i=0;i<x;i+=2){
        for(int j=0;j<y;j+=2){
            char c1 = d[i][j], c2 = d[i][j+1], c3 = d[i+1][j+1], c4=d[i+1][j];

            if(m[{c1,c2,c3,c4}]>0){
                m[{c1,c2,c3,c4}]--;
                m[{c2,c3,c4,c1}]--;
                m[{c3,c4,c1,c2}]--;
                m[{c4,c1,c2,c3}]--;
            }else{
                no();
                return;
            }
        }
    }
    
    yes();
    return;
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

