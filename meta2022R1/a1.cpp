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

int g1[500100];
int g2[500100];


void solve() {
    int n;
    ll k;
    cin>>n>>k;

    vi a(n);
    vi b(n);

    for(int i=0;i<n;i++){
        cin>>a[i];   
    }

    for(int i=0;i<n;i++){
        cin>>b[i];   
    }

    for(int i=0;i<n;i++){
        g1[a[i]]=a[(i+1)%n];
        g2[b[i]]=b[(i+1)%n];  
    }

    for(int i=1;i<=n;i++){
        if(g1[i]!=g2[i]){
            no();
            return;
        }
    }

    if(n==2){
        if(a[0]==b[0]){
            if(k%2==0){
                yes();
            }else{
                no();
            }
        }else{
            if(k%2==1){
                yes();
            }else{
                no();
            }
        }
    }else{
        if(a[0]==b[0]){
            if(k==1){
                no();
            }else{
                yes();
            }
        }else{
            if(k>0){
                yes();
            }else{
                no();
            }
        }
    }

}   

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    cin>>tt;
    for(int i=1;i<=tt;i++){
        cout<<"Case #"<<i<<": ";
        solve();
    }

    return 0;
}

