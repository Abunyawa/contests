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
    double h1,w1,h2,w2;
    cin>>h1>>w1>>h2>>w2;
    double area = 0;
    area+=h1*w1+h2*w2;
    double dop1;
    double dop2;
    double dop3;
    double dop4;
    if(h1<h2){
        dop1 = (h2-h1)*w1/2.0;
    }else{
        dop1 = (h1-h2)*w2/2.0;
    }


    if(w1<w2){
        dop2 = (w2-w1)*h1/2.0;
    }else{
        dop2 = (w1-w2)*h2/2.0;
    }

    if(w1<h2){
        dop3 = (h2-w1) * h1/2.0;
    }else{
        dop3 = (w1-h2)*w2/2.0;
    }

    if(w2<h1){
        dop4 = (h1-w2)*h2/2.0;
    }else{
        dop4 = (w2-h1)*w1/2.0;
    }

    area+=min(min(dop1,dop2),min(dop3,dop4));


    printf("%.10f\n",area);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    cin>>tt;
    for(int i=1;i<=tt;i++){
        printf("Case %d: ", i);
        solve();
    }

    return 0;
}

