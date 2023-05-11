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

    vl a(n);
    vl b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i] = a[i];
    }

    sort(all(b));
    int mex = 0;
    for(int i=0;i<n;i++){
        if(b[i]==mex){
            mex++;
        }
    }

    int target = mex+1;
    int l = -1;
    int r = -1;

    for(int i=0;i<n;i++){
        if(a[i]==target){
            if(l==-1){
                l = i;
            }
            r = i;
        }
    }

    vl vals;
    for(int i=0;i<l;i++){
        vals.pb(a[i]);
    }
    for(int i=r+1;i<n;i++){
        vals.pb(a[i]);
    }

    sort(all(vals));
    int nmex = 0;
    for(int i=0;i<vals.size();i++){
        if(nmex==vals[i]){
            nmex++;
        }
    }


    if(nmex==mex){
        if(l!=-1){
            yes();
            return;
        }else{
            bool can = false;
            for(int i=0;i<n;i++){
                if(b[i]>target){
                    can = true;
                }

                if(i-1>=0 && b[i]==b[i-1]){
                    can = true;
                }
            }
            if(can){
                yes();
            }else{
                no();
            }
        }
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

