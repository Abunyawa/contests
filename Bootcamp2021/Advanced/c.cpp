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
/*
a^2 + b^2 = c^2

a = x^2 - y^2
a^2 = x^4 - 2x^2y^2 + y^4

c = x^2 + y^2
c^2 = x^4 + 2x^2y^2 + y^4

b^2 = c^2-a^2 = 4x^2y^2
b = 2xy

*/
bool isPrime(int n){
    if(n==1){
        return true;
    }

    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}


int m[1000001];
void solve() {
    int n;
    cin>>n;
    vi a(n);
    for(int i=0;i<=1000000;i++){
        m[i]=0;
    }
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    vl b(n);
    int cur = 1;
    sort(all(a));
    for(int i=0;i<n;i++){
        while(m[cur]!=0){
            cur++;
        }

        if(m[cur]==0){
            b[i] = cur;
            
            for(int j = 0;j<n;j++){
                for(int k = j+1;k<n;k++){
                    m[cur + a[k] - a[j]]++;
                }
            }
            cur++;
        }
    }

    if(b.size()!=n){
        no();
        return;
    }else{
        yes();
        for(int i=0;i<n;i++){
            cout<<b[i]<<' ';
        }
        cout<<'\n';
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
 