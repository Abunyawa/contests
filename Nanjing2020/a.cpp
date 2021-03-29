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
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    int x1s = x1,y1s = y1,x2s = x2,y2s=y2;


    
    int v = 8;
    int e = 8;
    int k =2;
    bool flag = false;
    int ctr = 0;

    cout<<"asd"<<check(2,3,2,1,2,4)<<'\n';
    /*
    for(int i=0;i<4;i++){
        for(int j = 0;j<4;j++){
            if((edg1[i].xf==edg2[j].xf && edg1[i].yf==edg2[j].yf) || (edg1[i].xf==edg2[j].xs && edg1[i].yf==edg2[j].ys) || 
            (edg1[i].xs==edg2[j].xf && edg1[i].ys==edg2[j].yf) || (edg1[i].xs==edg2[j].xs && edg1[i].ys==edg2[j].ys)){
                v--;
                continue;
            }else{

                if(intersect({edg1[i].xs,edg1[i].ys},{edg1[i].xf,edg1[i].yf}, {edg2[j].xs,edg2[j].ys},{edg2[j].xf,edg2[j].yf})){
                    if(check(edg1[i].xs,edg1[i].ys, edg2[j].xs,edg2[j].ys,edg2[j].xf,edg2[j].yf)||
                        check(edg1[i].xf,edg1[i].yf, edg2[j].xs,edg2[j].ys,edg2[j].xf,edg2[j].yf)||
                        check(edg2[j].xs,edg2[j].ys, edg1[i].xs,edg1[i].ys,edg1[i].xf,edg1[i].yf)||
                        check(edg2[j].xf,edg2[j].yf, edg1[i].xs,edg1[i].ys,edg1[i].xf,edg1[i].yf)
                    ){
                        ctr++;
                        e++;
                    }else{
                        ctr++;
                        v++;
                        e+=2;
                    }
                   
                    if(!flag){
                        k--;
                        flag = true;
                    }
                }
            }
        }
    }
    if(x1==x1s && x2==x2s && y1==y1s && y2==y2s){
        cout<<2<<'\n';
        return;
    }
    debug(ctr);
    debug(v);
    debug(e);

    cout<<k+1-v+e<<'\n';
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

