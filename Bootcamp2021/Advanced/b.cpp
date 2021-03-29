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
    if(n==1){
        cout<<1<<'\n';
        return;
    }
    ll d[n][n];
    vl row(n,0);
    vl col(n,0);
    vl rowZ(n,0);
    vl colZ(n,0);

    ll diagM = 0;
    ll diagS = 0;
    ll diagMU = 0;
    ll diagSU = 0;

    for(int i=0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>d[i][j];
            row[i]+=d[i][j];
            col[j]+=d[i][j];
            if(i==j){
                diagM+=d[i][j];
            }
            if(i+j==n-1){
                diagS+=d[i][j];
            }
            if(d[i][j]==0){
                rowZ[i]=1;
                colZ[j]=1;
                if(i==j){
                    diagMU = 1;
                }
                if(i+j==n-1){
                    diagSU = 1;
                }
            }
        }
    }
    ll nwNum = -1;
    ll needS = 0;
    if(rowZ[0]!=1){
        needS = row[0];
    }else{
        needS = row[1];
    }
    for(int i=0;i<n;i++){
        if(rowZ[i]!=1){
            if(row[i]!=needS){
                cout<<-1<<'\n';
                return;
            }
        }else{
            if(row[i]>=needS){
                cout<<-1<<'\n';
                return;
            }else{
                if(nwNum==-1){
                    nwNum = needS-row[i];
                }

                if(needS-row[i]!=nwNum){
                    cout<<-1<<'\n';
                    return;
                }
            }
        }
        if(colZ[i]!=1){
            if(col[i]!=needS){
                cout<<-1<<'\n';
                return;
            }
        }else{
            if(col[i]>=needS){
                cout<<-1<<'\n';
                return;
            }else{
                if(nwNum==-1){
                    nwNum = needS-col[i];
                }

                if(needS-col[i]!=nwNum){
                    cout<<-1<<'\n';
                    return;
                }
            }
        }
    }
    if(diagMU!=1){
        if(diagM!=needS){
            cout<<-1<<'\n';
                return;
        }
    }else{
        if(diagM>=needS){
            cout<<-1<<'\n';
            return;
        }else{
            if(nwNum==-1){
                nwNum = needS-diagM;
            }

            if(needS-diagM!=nwNum){
                cout<<-1<<'\n';
                return;
            }
        }
    }
    if(diagSU!=1){
        if(diagS!=needS){
            cout<<-1<<'\n';
                return;
        }
    }else{
        if(diagS>=needS){
            cout<<-1<<'\n';
            return;
        }else{
            if(nwNum==-1){
                nwNum = needS-diagS;
            }

            if(needS-diagS!=nwNum){
                cout<<-1<<'\n';
                return;
            }
        }
    }

    cout<<nwNum<<'\n';
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

