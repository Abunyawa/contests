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

char mb[] = {'(',')'};

int u,r,d,l;
int uf,rf,df,lf;

void check(){
    if(u==0){
        lf--;
        rf--;
    }

    if(r==0){
        uf--;
        df--;
    }

    if(d==0){
        lf--;
        rf--;
    }

    if(l==0){
        uf--;
        df--;
    }
}


void solve() {
    int n;
    cin>>n;
    cin>>u>>r>>d>>l;
    uf = n-2;
    rf = n-2;
    df = n-2;
    lf = n-2;
    int uk = u;
    int rk = r;
    int dk = d;
    int lk = l;
    vi seq;
    seq.pb(1);
    seq.pb(2);
    seq.pb(3);
    seq.pb(4);

    do{
        u = uk;
        d = dk;
        l = lk;
        r = rk;
        for(int i=0;i<4;i++){   
            if(seq[i]==1){
                if(u>0 && l>0){ 
                    u--;
                    l--;
                }
            }else if(seq[i]==2){
                if(u>0 && r>0 ){
                    u--;
                    r--;
                }
            }else if(seq[i]==3){
                if(d>0 && l>0 ){
                    d--;
                    l--;
                }
            }else{
                if(d>0 && r>0 ){
                    d--;
                    r--;
                }
            }
        }
        
        
        if(u>uf || d>df || r>rf || l>lf){
        }else{
            yes();
            return;
        }
    
    }while(next_permutation(all(seq)));

    no();


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

