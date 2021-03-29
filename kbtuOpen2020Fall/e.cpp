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
    cout<<"Yes"<<'\n';
}

void no(){
    cout<<"No"<<'\n';
}



void solve() {
    string s1;
    cin>>s1;
    string s2;
    cin>>s2;
    string ch1 = "";
    string ch2 = "";
    for(int i=0;i<s1.length();i++){
        if(s1[i]!='.'){
            ch1+=s1[i];
        }
    }
    for(int i=0;i<s1.length();i++){
        if(s2[i]!='.'){
            ch2+=s2[i];
        }
    }

    if(ch1!=ch2){
        no();
        return;
    }else{
        vi wh1;
        vi wh2;
        for(int i=0;i<s1.length();i++){
            if(s1[i]=='w'){
                wh1.pb(i);
            }
            if(s2[i]=='w'){
                wh2.pb(i);
            }
        }
        for(int i = 0;i<wh1.size();i++){
            if(wh2[i]>wh1[i]){
                no();
                debug('s');
                return;
            }
        }

        vi b1;
        vi b2;
        for(int i=s1.length()-1;i>=0;i--){
            if(s1[i]=='b'){
                b1.pb(i);
            }
            if(s2[i]=='b'){
                b2.pb(i);
            }
        }

        for(int i = b1.size()-1;i>=0;i--){
            if(b2[i]<b1[i]){
                no();
                return;
            }
        }
        yes();
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

