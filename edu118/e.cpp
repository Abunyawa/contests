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
    int n,m;
    
    cin>>n>>m;
    char d[n][m];
    bool used[n][m];
    int stx, sty;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>d[i][j];
            used[i][j] = false;
            if(d[i][j] == 'L'){
                stx = i;
                sty = j;
            }
        }
    }

    stack<pii> st;
    st.push({stx, sty});
    int xto[] = {1,0,0,-1};
    int yto[] = {0,1,-1,0};
    while(!st.empty()){
        int curX = st.top().fi;
        int curY = st.top().se;
        st.pop();

        used[curX][curY] = true;
        
        for(int i=0;i<4;i++){
            int tox = curX + xto[i];
            int toy = curY + yto[i];
            //cout<<"[[[[[[[[[[[["<<curX<<' '<<curY<<endl;
            if(tox>=0 && tox<n && toy>=0 && toy<m){
                if(d[tox][toy] != '#' && !used[tox][toy]){
                    int bad = 0;
                    //cout<<"[[[[["<<tox<<' '<<toy<<endl;
                    for(int j=0;j<4;j++){
                        int tox2 = tox + xto[j];
                        int toy2 = toy + yto[j];
                        if(tox2>=0 && tox2<n && toy2>=0 && toy2<m){
                            if(d[tox2][toy2] != '#' && !used[tox2][toy2]){
                                bad++;
                                //cout<<tox2<<' '<<toy2<<endl;
                            }
                        }
                    }
                    //cout<<"--------------------\n";
                    //cout<<bad<<endl;
                    if(bad<=1){
                        st.push({tox,toy});
                    }
                }
            }
        }
    }   

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(d[i][j]!='.'){
                cout<<d[i][j];
            }else{
                if(used[i][j]){
                    cout<<"+";
                }else{
                    cout<<".";
                }
            }
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

