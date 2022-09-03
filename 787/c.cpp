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
    string s;
    cin>>s;
    int o = -1;
    int z = -1;

    for(int i=0;i<s.length();i++){
        if(s[i]=='1'){
            o = i;
        }

        if(s[i]=='0'){
            if(z==-1){
                z = i;
            }
        }
    }

    if(z==-1 && o==-1){
        cout<<s.length()<<'\n';
    }else if(z==-1){
        cout<<s.length()-o<<'\n';
    }else if(o==-1){
        cout<<z+1<<'\n';
    }else{
        if(z<o){
            cout<<1<<'\n';
        }else{
            cout<<z-o+1<<'\n';
        }
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

