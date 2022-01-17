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
    vi a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==1){
        yes();
        return;
    }

    bool flag = true;
    int tar1;
    int tar2;
    for(int i=0;i<n;i++){
        if(a[i]!=a[n-i-1]){
            flag = false;
            tar1=a[i];
            tar2=a[n-i-1];
            break;
        }
    }

    if(flag){
        yes();
        return;
    }


    vi a1;
    vi a2;

    for(int i=0;i<n;i++){
        if(a[i]!=tar1){
            a1.pb(a[i]);
        }
        if(a[i]!=tar2){
            a2.pb(a[i]);
        }
    }
    bool flag1 = true;
    bool flag2 = true;
    for(int i=0;i<a1.size();i++){
        if(a1[i]!=a1[a1.size()-i-1]){
            flag1 = false;
            break;
        }
    }

    for(int i=0;i<a2.size();i++){
        if(a2[i]!=a2[a2.size()-i-1]){
            flag2 = false;
            break;
        }
    }

    if(flag1 || flag2){
        yes();
    }else{
        no();
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

