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

bool need[200100];
queue<int> pos[200100];
int fre[200100];

void solve() {
    int n,m;
    cin>>n>>m;
    char d[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>d[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                continue;
            }   

            if(d[i][j]==d[j][i]){
                yes();
                cout<<i+1<<' ';
                for(int k=0;k<m;k++){
                    if(k%2==0){
                        cout<<j+1<<' ';
                    }else{
                        cout<<i+1<<' ';
                    }
                }
                cout<<'\n';
                return;
            }
        }
    }
    if(m%2==1){
        yes();
        cout<<1<<' ';
        for(int i=0;i<m;i++){
            if(i%2==0){
                cout<<2<<' ';
            }else{
                cout<<1<<' ';
            }
        }
        cout<<'\n';
        return;
    }else{
        if(n==2){
            no();
        }else{
            int need = 0;
            int sec = 1;
            int third = 2;
            for(int i = 1;i<n;i++){
                for(int j =i+1;j<n;j++){
                    if(d[0][i]==d[0][j]){
                        
                        if(d[i][j]==d[0][i]){
                            need = i;
                            sec = j;
                            third = 0;
                        }else{
                            need = j;
                            sec = i;
                            third = 0;
                        }
                        
                    }
                }
            }

            if((m/2)%2==1){
                yes();
                cout<<third+1<<' ';
                for(int i=0;i<m/2;i++){
                    if(i%2==0){
                        cout<<need+1<<' ';
                    }else{
                        cout<<third+1<<' ';
                    }
                }
                for(int i=0;i<m/2;i++){
                    if(i%2==0){
                        cout<<sec+1<<' ';
                    }else{
                        cout<<need+1<<' ';
                    }
                }
                cout<<'\n';
            }else{
                yes();
                cout<<need+1<<' ';
                for(int i=0;i<m/2;i++){
                    if(i%2==1){
                        cout<<need+1<<' ';
                    }else{
                        cout<<third+1<<' ';
                    }
                }
                for(int i=0;i<m/2;i++){
                    if(i%2==0){
                        cout<<sec+1<<' ';
                    }else{
                        cout<<need+1<<' ';
                    }
                }
                cout<<'\n';
            }
        }
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

