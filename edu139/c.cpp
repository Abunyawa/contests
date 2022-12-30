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
int tox[] = {0,0,1,-1};
int toy[] = {1,-1,0,0};



void solve() {
    int n;
    cin>>n;
    char d[2][n];
    for(int i=0;i<n;i++){
        cin>>d[0][i];
    }
    for(int i=0;i<n;i++){
        cin>>d[1][i];
    }
    int cur = 0;
    if(d[0][0]=='B' && d[1][0]=='B'){
        cur = 2;
    }else if(d[0][0]=='B'){
        cur = 0;
    }else{
        cur = 1;
    }

    for(int i=1;i<n;i++){
        if(d[0][i]=='B' && d[1][i]=='B'){
            if(cur==0){
                cur = 1;
            }else if(cur==1){
                cur = 0;
            }
        }else if(d[0][i]=='B'){
            if(cur==1){
                no();
                return;
            }else if(cur==2){
                cur=0;
            }
        }else{
            if(cur==0){
                no();
                return;
            }else if(cur==2){
                cur=1;
            }
        }
    }


    yes();

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

