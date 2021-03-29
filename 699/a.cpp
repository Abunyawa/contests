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
    int px,py;
    cin>>px>>py;
    string s;
    cin>>s;
    int x = 0;
    int y = 0;
    int num[4];
    num[0] = num[1] = num[2] = num[3] = 0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='U'){
            y++;
            num[0]++;
        }else if(s[i]=='D'){
            y--;
            num[1]++;
        }else if(s[i]=='L'){
            x--;
            num[2]++;
        }else{
            x++;
            num[3]++;

        }
    }
    int hor = px-x;
    int ver = py - y;
    if(hor>0){
        if(num[2] < hor) {
            no();
            return;
        }
    }else{
        if(num[3] < -hor){
            no();
            return;
        }
    }

    if(ver>0){
        if(num[1]<ver){
            no();
            return;
        }
    }else{
        if(num[0]<-ver){
            no();
            return;
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

