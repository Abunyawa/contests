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
/*
13213
2112
101
11
0
*/
int x[] = {1,-1,0,0};
int y[] = {0,0,1,-1};
char d[510][510];
bool used[510][510];
int ctr = 0;
int k;
bool dfs(int ix,int iy,int px,int py,int n,int m){
    used[ix][iy] = true;
    stack<pair<int,int> > st;
    for(int i=0;i<4;i++){
        int xto = ix+x[i];
        int yto = iy+y[i];
        if(xto<n && xto>=0 && yto<m && yto>=0 && d[xto][yto]=='.' && !used[xto][yto]){
            used[xto][yto] = true;
            st.push(mp(xto,yto));
        }
    }  
    if(st.size()==0){
        if(ctr<k){
            ctr++;
            d[ix][iy] = 'X';
            return true;
        }
    }else{
        int need = st.size();
        int have = 0;
        while(!st.empty()){
            int cx = st.top().F;
            int cy = st.top().S;
            st.pop();
            if(dfs(cx,cy,ix,iy,n,m)){
                have++;
            }
        }
        if(have==need && ctr<k){
            ctr++;
            d[ix][iy] = 'X';
            return true;
        }
    }
    return false;
}
void solve(){
    int n,m;
    cin>>n>>m>>k;
    int c = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>d[i][j];
            if(d[i][j]=='.')
                c++;
        }
    }
    for(int i=0;i<n && ctr<k;i++){
        for(int j=0;j<m && ctr<k;j++){
            if(d[i][j]=='.'){
                dfs(i,j,-1,-1,n,m);
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
