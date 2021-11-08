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
    string s1;
    cin>>s1;
    vi n1;
    for(int i=0;i<s1.length();){
        if(s1.substr(i,3)=="one"){
            n1.pb(1);
            i+=3;
        }else{
            n1.pb(0);
            i+=4;
        }
    }

    string s2;
    cin>>s2;
    vi n2;
    for(int i=0;i<s2.length();){
        if(s2.substr(i,3)=="one"){
            n2.pb(1);
            i+=3;
        }else{
            n2.pb(0);
            i+=4;
        }
    }

    if(n1.size()>n2.size()){
        cout<<">"<<'\n';
    }else if(n1.size()<n2.size()){
        cout<<"<"<<'\n';
    }else{
        for(int i=0;i<n1.size();i++){
            if(n1[i]>n2[i]){
                cout<<">"<<'\n';
                return;
            }else if(n1[i]<n2[i]){
                cout<<"<"<<'\n';
                return;
            }
        }

        cout<<"="<<'\n';
    }
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

