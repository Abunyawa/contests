#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define vi vector<int>
#define vl vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define abu ios_base::sync_with_stdio(0)
#define said cin.tie(0)
using namespace std;

void yes(){
    cout<<"YES"<<endl;
}

void no(){
    cout<<"NO"<<endl;
}
bool used[110][110];
int n,m;
char d[110][110];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

void dfs(int x,int y,int k){
    if(k%2==0){
        d[x][y] = 'B';
    }else{
        d[x][y] = 'W';
    }
    used[x][y] = true;
    for(int i=0;i<4;i++){
        int xto = x + dx[i];
        int yto = y + dy[i];
        if(xto<n && xto>=0 && yto<m && yto>=0 && !used[xto][yto] && d[xto][yto]!='-'){
            dfs(xto,yto,k+1);
        }
    }
}


void solve(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>d[i][j];
        }
    }    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!used[i][j] && d[i][j]!='-'){
                dfs(i,j,0);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<d[i][j];
        }
        cout<<endl;
    }
    
}

int main(){
    abu;
    said;
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}