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

int dig(int x, int y){
    cout<<"DIG "<<x<<' '<<y<<endl;
    int a;
    cin>>a;
    return a;
}

int scan(int x, int y){
    cout<<"SCAN "<<x<<' '<<y<<endl;
    int a;
    cin>>a;
    return a;
}

void solve() {
    int n, m;
    cin>>n>>m;

    int a = scan(1,1); 
    int b = scan(1,m);

    int sx = (a+b+6-2*m)/2; // 2
    int sy = (a-b+2+2*m)/2; // 6

    int c = scan(sx/2, 1); // 3
    int d = scan(1,sy/2); // 1

    int dx = c - sy + 2; 
    int dy = d - sx + 2;


    int x1 = (sx-dx)/2;
    int x2 = (sx+dx)/2;
    int y1 = (sy-dy)/2;
    int y2 = (sy+dy)/2;

    if(dig(x1,y1)==0){
        dig(x1,y2);
        dig(x2,y1);
    }else{
        dig(x2,y2);
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

