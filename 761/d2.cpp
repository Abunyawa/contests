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

int ask(int a, int b, int c){
    cout<<"? "<<a<<' '<<b<<' '<<c<<endl;
    int x;
    cin>>x;

    return x;
}

void solve() {
    int n;
    cin>>n;
    int prev = -1;
    int md = -1;
    for(int i=1;i+2<=n;i++){
        int cur = ask(i,i+1,i+2);

        if(prev==-1){
            prev = cur;
        }else{
            if(prev!=cur){
                md = i;
                break;
            }
        }
    }

    vector<int> ansG;
    vector<int> ansB;

    for(int i=1;i<=n;i++){
        if(i==md || i==md+1) continue;
        int cur = ask(md,md+1,i);
        if(cur==1){
            ansG.pb(i);
        }else{
            ansB.pb(i);
        }
    }

    int askMd = ask(ansG[0],ansB[0], md);
    if(askMd==1){
        ansG.pb(md);
    }else{
        ansB.pb(md);
    }

    askMd = ask(ansG[0],ansB[0], md+1);
    if(askMd==1){
        ansG.pb(md+1);
    }else{
        ansB.pb(md+1);
    }


    cout<<"! "<<ansB.size()<<" ";
    for(int x: ansB){
        cout<<x<<' ';
    }

    cout<<endl;
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

