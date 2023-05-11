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
    int q;
    cin>>q;
    ll l=-1,h=-1;
    for(int i=0;i<q;i++){
        int t;
        cin>>t;

        if(t==1){
            ll a, b,n;
            cin>>a>>b>>n;
            if(l==-1){
                cout<<1<<' ';
                l = (n-1)*(a-b) + b +1;
                h = (n-1)*(a-b) + a;
                if(n==1){
                    l = 1;
                    h = a;
                }
            }else{
                ll locl = (n-1)*(a-b) + b + 1;
                ll loch = (n-1)*(a-b) + a;
                if(n==1){
                    locl = 1;
                    loch = a;
                }
                if(locl<=l && loch>=h){
                    cout<<1<<' ';
                }else if(locl>=l && loch<=h){
                    cout<<1<<' ';
                    l = locl;
                    h = loch;
                }else if(loch>=l && loch<=h){
                    cout<<1<<' ';
                    h = loch;
                }else if(locl>=l && locl<=h){
                    cout<<1<<' ';
                    l = locl;
                }else{
                    cout<<0<<' ';
                }
            }
        }else{
            ll a,b;
            cin>>a>>b;
            //cout<<"("<<l<<' '<<h<<")"<<' ';
            if(l==-1){
                cout<<-1<<' ';
            }else{
                ll daysToL = (max(0LL,l-b)+(a-b-1))/(a-b);
                if(l<=a){
                    daysToL = 1;
                }
                ll daysToH = (max(0LL,h-b)+(a-b-1))/(a-b);
                if(h<=a){
                    daysToH = 1;
                }
                
                if(daysToH!=daysToL){
                    cout<<-1<<' ';
                }else{
                    cout<<daysToH<<' ';
                }
            }
        }
    }

    cout<<'\n';
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

