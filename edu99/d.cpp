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

bool isSorted(vi a){
    int n = a.size();
    for(int i=1;i<n;i++){
        if(a[i]<a[i-1]){
            return false;
        }
    }
    return true;
}

void solve() {
    int n,x;
    cin>>n>>x;
    vi a(n);
    int ctr = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(isSorted(a)){
        cout<<0<<'\n';
        return;
    }else{
        for(int i=1;i<n;i++){
            if(a[i]<a[i-1]){
                for(int j = 0;j<=i-1;j++){
                    if(a[j]>x){
                        swap(a[j],x);
                        ctr++;
                    }
                }
                if(a[i]<a[i-1]){
                    cout<<-1<<'\n';
                    return;
                }
            }
        }
        cout<<ctr<<'\n';
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
 