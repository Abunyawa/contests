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


bool askAdd(int num){
    cout<<"+ "<<num<<endl;
    cout.flush();
    string ans;
    cin>>ans;
    if(ans=="Incorrect"){
        assert(0);
    }
    return ans=="YES";
}

bool askRm(int num){
    cout<<"- "<<num<<endl;
    cout.flush();

    string ans;
    cin>>ans;
    if(ans=="Incorrect"){
        assert(0);
    }
    return ans=="YES";
}

bool askGuess(int num){
    cout<<"! "<<num<<endl;
    cout.flush();

    string ans;
    cin>>ans;
    if(ans=="Incorrect"){
        assert(0);
    }
    return ans=="Correct";
}

void solve() {
    for(int i=25;i<=500;i+=25){
        bool res = askAdd(i);
        if(res){
            bool ans = askGuess(i-25);
            return;
        }
    }

    for(int i=0;i<=24;i++){
        bool res = askAdd(i);
        if(res){
            for(int j = 25;j<=500;j+=25){
                int ans = askRm(j);
                if(!ans){
                    bool resAns = askGuess(j-i);
                    return;
                }
            }
        }else{
            askRm(i);
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

