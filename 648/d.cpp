#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second
#define vi vector<int>
#define vl vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define abu ios_base::sync_with_stdio(0)
#define said cin.tie(0)
using namespace std;
ll const MOD = 998244353;

void yes(){
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}

ll fact(int n){
    ll ans = 1;
    for(int i=2;i<=n;i++){
        ans = (ans*i)%MOD;
    }

    return ans;
}

ll powM(int n, int x){
    if(x==0){
        return 1;
    }
    if(x==1){
        return n%MOD;
    }

    if(x%2==0){
        ll a = powM(n,x/2);
        return (a*a)%MOD;
    }else{
        return (n*powM(n,x-1))%MOD;
    }
}

ll C(int n, int k){
    return (fact(n) * powM((fact(k)*fact(n-k))%MOD,MOD-2))%MOD;
}

ll A(int n, int k){
    return (fact(n) * powM(fact(n-k)%MOD,MOD-2))%MOD;
}

void add_self(int &a, int b){
    a += b;
    if(a>=MOD){
        a-=MOD;
    }
}

void sub_self(int &a, int b){
    a -= b;
    if(a<0){
        a+=MOD;
    }
}

char g[60][60];
bool used[60][60];
int good = 0;

int movx[] = {1,-1,0,0};
int movy[] = {0,0,-1,1};
int n,m;


void bfs(int x,int y){
    used[x][y] = true;
    queue<pair<int,int>> q;
    q.push({x,y});
    while(!q.empty()){
        int curx = q.front().F;
        int cury = q.front().S;
        q.pop();
        if(g[curx][cury]=='G') good++;
        for(int i=0;i<4;i++){
            int xto = curx+movx[i];
            int yto = cury+movy[i];
            if(xto>=0 && xto<n && yto>=0 && yto<m){
               if(!used[xto][yto] && g[xto][yto]!='#'){
                   q.push({xto,yto});
                   used[xto][yto]=true;
               }
            }
        }
    }
}   


void solve(){
   
    cin>>n>>m;
    good = 0;
    int go = 0;
    int b = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            used[i][j] = false;
            cin>>g[i][j];
            if(g[i][j]=='B') b++;
            if(g[i][j]=='G') go++;
        }
    }
    if(g[n-1][m-1]=='B'){
        no();
        return;
    }

    if(go==0){
        yes();
        return;
    }
  

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]=='B'){
                for(int k=0;k<4;k++){
                    int xto = i+movx[k];
                    int yto = j+movy[k];
                    if(xto>=0 && xto<n&& yto>=0 && yto<m){
                        if(g[xto][yto]=='G'){
                            no();
                            return;
                        }else{
                            if(g[xto][yto]=='.'){
                                g[xto][yto]='#';
                            }
                        }
                    }
                }
            }
        }
    }

    if(g[n-1][m-1]=='#'){
        no();
        return;
    }
    bfs(n-1,m-1);
    if(good!=go){
        no();
    }else{
        yes();
    }
}

int main(){
    abu;
    said;
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
