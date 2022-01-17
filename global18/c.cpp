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
    string s1, s2;
    cin>>s1>>s2;


    vi a(n);
    vi ctr(4,0);
    for(int i=0;i<n;i++){
        a[i] = (s1[i]-'0') * 2 + (s2[i]-'0'); 
        ctr[a[i]]++;
    }


    if(ctr[3]-1 != ctr[0] && ctr[2]!=ctr[1]){
        cout<<-1<<'\n';
    }else if(ctr[3]-1 == ctr[0] && ctr[2]==ctr[1]){
        cout<<min(ctr[3]+ctr[0], ctr[2]+ctr[1])<<'\n';
    }else if(ctr[3]-1 == ctr[0]){
        cout<<ctr[3]+ctr[0]<<'\n';
    }else{
        cout<<ctr[2]+ctr[1]<<'\n';
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

