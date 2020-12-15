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
    char d[n][n];
    char d2[n][n];
    char d3[n][n];
    int k = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>d[i][j];
            d2[i][j] = d[i][j];
            d3[i][j] = d[i][j];
            if(d[i][j]!='.'){
                k++;
            }
        }
    }
    int ctr=0;
    int ctr2=0;
    int ctr3=0;

    for(int i=0;i<n;i++){
        for(int j = 0;j<n;j++){
            if((i+j)%3==2){
                if(d[i][j]=='X'){
                    d[i][j] = 'O';
                    ctr++;
                }
            }
            if((i+j)%3==1){
                if(d2[i][j] == 'X'){
                    d2[i][j]='O';
                    ctr2++;
                }
            }
            if((i+j)%3==0){
                if(d3[i][j] == 'X'){
                    d3[i][j]='O';
                    ctr3++;
                }
            }
        }
    }
    
    if(ctr<=k/3){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<d[i][j];
            }
            cout<<'\n';
        }
        return;
    }

    if(ctr2<=k/3){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<d2[i][j];
            }
            cout<<'\n';
        }
        return;
    }

    if(ctr3<=k/3){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<d3[i][j];
            }
            cout<<'\n';
        }
        return;
    }

    assert(0);
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

