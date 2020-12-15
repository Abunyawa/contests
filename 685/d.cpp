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

void yes(){
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}
/*
abc

bcd


*/


void solve() {
    ll d,k;
    cin>>d>>k;
    ll st = 0;
    ll x = 0;
    ll y = 0;
    while(x*x+y*y<=d*d){
        if(st%2==0){
            if((x+k)*(x+k) + y*y <= d*d){
                st++;
                x+=k;
            }else{
                break;
            }
        }else{
            if(x*x + (y+k)*(y+k) <= d*d){
                st++;
                y+=k;
            }else{
                break;
            }
        }
    }
    
    
    if(st%2==0){
        cout<<"Utkarsh\n";
    }else{
        cout<<"Ashish\n";
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

