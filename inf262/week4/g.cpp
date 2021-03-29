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
vi cnt(10,0);
ll b;
bool check(ll a){

    for(int num = 0;num<10;num++){
        int tr = cnt[num];
        while(tr--){
            a = a*10+num;
        }
    }

    return a<=b;
    
}

void solve() {
    string a;   
    cin>>a>>b;

    for(int i=0;i<a.length();i++){
        cnt[a[i]-'0']++;
    }
    ll cur = 0;

    for(int i=0;i<a.length();i++){
        for(int num = 9;num>=0;num--){
            if(cnt[num]>0){
                cnt[num]--;
                if(check(cur*10+num)){
                    cur = cur*10+num;
                    break;
                }else{
                    cnt[num]++;
                }
            }
        }
    }

    cout<<cur<<'\n';
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

