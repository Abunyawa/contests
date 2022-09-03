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
    ll n;
    cin>>n;
    if(n%2==1){
        cout<<-1<<'\n';
        return;
    }


    ll bl = n/2;
    
    ll x;

    if(bl%3==0){
        x = bl/3;
    }else if(bl%3==1){
        if(bl/3>0){
            x = bl/3+1;
        }else{
            cout<<-1<<'\n';
            return;
        }
    }else{
        x = bl/3+1;
    }
    

    if(x==0){
        cout<<-1<<'\n';
        return;
    }


    ll y;

    if(bl%2==0){
        y = bl/2;
    }else{
        if(bl/2>0){
            y = bl/2;
        }else{
            cout<<-1<<'\n';
            return;
        }
    }

    if(y==0){
        cout<<-1<<'\n';
        return;
    }
    cout<<x<<' '<<y<<'\n';
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

