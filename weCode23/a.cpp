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
b2 = a2 + x

x = b2-a2
1 2 3 4  5  6
  3 8 15 24 35
    5 12 21 32
      7  16
         9
*/
void solve() {
    ll n;
    cin>>n;

    ll l = 3, r = 1e11;

    while(l<r-1){
        //debug(l);
        //debug(r);
        ll m = (l+r)/2LL;
        ll count1 = 0;
        if(m>=3){
            count1 += (m-1)/2;
        }
        vi ws;
        for(ll i=3;(i*i-1)<=m;i+=2){
            bool was = false;
            for(int k=0;k<ws.size();k++){
                if(((i-1)*2)%ws[k]==0){
                    was = true;
                }
            }
            if(!was){
                count1 += (m-(i*i-1)+1 + (i-1)*2-1)/((i-1)*2);
                ws.pb((i-1)*2);
            }
        }

        if(count1<n){
            l = m+1;
        }else if(count1>=n){
            r = m;
        }
    }
    if(l==r){
        cout<<l<<'\n';
    }else{
        ll count1 = 0;
        if(l>=3){
            count1 += (l-1)/2;
        }
        vi ws;
        for(ll i=3;(i*i-1)<=l;i+=2){
            bool was = false;
            for(int k=0;k<ws.size();k++){
                if(((i-1)*2)%ws[k]==0){
                    was = true;
                }
            }
            if(!was){
                count1 += (l-(i*i-1)+1 + (i-1)*2-1)/((i-1)*2);
                ws.pb((i-1)*2);
            }
        }
        if(count1>=n){
            cout<<l<<'\n';
            return;
        }else{
            cout<<r<<'\n';
        }
    }
    //cout<<(l+r)/2<<'\n';
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

