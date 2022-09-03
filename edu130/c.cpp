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
    int n;
    cin>>n;

    string s,t;
    cin>>s>>t;

    string s1,t1;
    s1 = s;
    t1 = t;

    sort(all(s1));
    sort(all(t1));

    if(s1!=t1){
        no();
        return;
    }
    queue<int> q[3];

    for(int i=0;i<n;i++){
        q[s[i]-'a'].push(i);
    }

    for(int i=0;i<n;i++){
        if(t[i]=='a'){
            if((q[1].empty() || q[0].front()<q[1].front()) && (q[2].empty() || q[0].front()<q[2].front())){
                q[0].pop();
            }else{
                no();
                return;
            }
        }else if(t[i]=='b'){
            if(q[2].empty() || q[1].front()<q[2].front()){
                q[1].pop();
            }else{
                no();
                return;
            }
        }else{
            if(q[0].empty() || q[2].front()<q[0].front()){
                q[2].pop();
            }else{
                no();
                return;
            }
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

