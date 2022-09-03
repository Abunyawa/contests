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
    int n,m,k;
    cin>>n>>m>>k;
    string a,b;
    cin>>a;
    cin>>b;

    int ptr1 = 0;
    int ptr2 = 0;

    int last = 0;
    int ctr = 0;
    string c="";
    sort(all(a));
    sort(all(b));

    while(true){
        if(ptr1==a.length() || ptr2==b.length()){
            break;
        }

        if(a[ptr1]<b[ptr2]){
            if(last == 0){
                if(ctr<k){
                    c+=a[ptr1++];
                    ctr++;
                }else{
                    c+=b[ptr2++];
                    last = 1;
                    ctr = 1;
                }
            }else{
                c+=a[ptr1++];
                ctr=1;
                last = 0;
            }
        }else{
            if(last == 1){
                if(ctr<k){
                    c+=b[ptr2++];
                    ctr++;
                }else{
                    c+=a[ptr1++];
                    last = 0;
                    ctr = 1;
                }
            }else{
                c+=b[ptr2++];
                ctr=1;
                last = 1;
            }
        }
    }

    cout<<c<<'\n';
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

