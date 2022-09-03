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
    string s;
    cin>>s;
    int n = s.length();


    vi sufO(n+1,0);
    vi sufZ(n+1,0);
    int ctr = 0;
    for(int i=n-1;i>=0;i--){
        sufO[i] = sufO[i+1];
        sufZ[i] = sufZ[i+1];

        if(s[i]=='1'){
            sufO[i]++;
        }else{
            ctr++;
            sufZ[i]++;
        }
    }

    int z = 0;
    int o = 0;
    int ans = n;
    for(int i=0;i<n;i++){
        int  l = i;
        int r = n;

        while(l<r-4){
            int m = (l+r)/2;

            int segZ = ctr - z - sufZ[m];
            int segO = o + sufO[m];

            if(segO>segZ){
                l = m;
            }else{
                r = m;
            }
        }
        //cout<<i<<' '<<l<<' '<<r<<'\n';
        for(int j = l;j<=r;j++){
            int segZ = ctr - z - sufZ[j];
            int segO = o + sufO[j];

            ans = min(ans, max(segZ, segO));
        }
        if(s[i]=='1'){
            o++;
        }else{
            z++;
        }
    }

    cout<<ans<<'\n';

/*
    int st = n;
    int fn = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            st = min(i,st);
            fn = max(i,fn);
        }
    }

    if(st==n){
        cout<<0<<'\n';
        return;
    }


    vi bl;
    int cur = 0;
    int curZ = 0;
    int ctr = 0;
    for(int i=st;i<=fn;i++){
        if(s[i]=='1'){
            cur++;
        }else{
            ctr++;
            if(cur!=0){
                bl.pb(cur);
                cur = 0;
            }
        }

        if(s[i]=='0'){
            curZ++;
        }else{
            if(curZ!=0){
                bl.pb(curZ);
                curZ = 0;
            }
        }
    }

    if(cur!=0){
        bl.pb(cur);
        cur = 0;
    }



    if(bl.size()==1){
        cout<<0<<'\n';
        return;
    }

    vector<pii> left(bl.size(),{0,0});\
    vector<pii> right(bl.size(),{0,0});

    int cP = bl[0];
    int cN = bl[1];
    
    for(int i=2;i<bl.size();i+=2){
        left[i] = left[i-2];

        if(cP <= max(cN-left[i].se, left[i].fi)){
            left[i] = {cP, cN};
        }
        cP+=bl[i];
        cN+=bl[i+1];
    }

    cP = bl[bl.size()-1];
    cN = bl[bl.size()-2];

    for(int i=bl.size()-3;i>=0;i-=2){
        right[i] = right[i+2];

        if(cP <= max(cN-right[i].se, right[i].fi)){
            right[i] = {cP, cN};
        }

        cP+=bl[i];
        cN+=bl[i-1];
    }

    int ans = ctr;
    for(int i=0;i<bl.size();i+=2){
        cout<<left[i].fi<<' '<<left[i].se<<' '<<right[i].fi<<' '<<right[i].se<<'\n';
        int locA = max(ctr-left[i].se-right[i].se, left[i].fi+right[i].fi);
        
        ans = min(ans, locA);
    }
    cout<<'\n';

    cout<<ans<<'\n';
 */   
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

