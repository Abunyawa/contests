#include<bits/stdc++.h>
using namespace std;
int a[510][510];
int movx[] ={1,-1,0,0};
int movy[] = {0,0,-1,1};
int ans=0;
const int INF = 100000;
vector<int> steps(1000000, INF);
int used[510][510];
 
vector<pair<int,int>> ones;

int n,m;
void bfs(vector<pair<int,int> > &p){
    queue<pair<int,int> > q;
    for(auto e: p){
        used[e.first][e.second]=true;
        q.push(make_pair(e.first,e.second));
    }
    while(!q.empty()){
        pair<int,int> pos = q.front();
        q.pop();
        int xcur = pos.first;
        int ycur = pos.second;
        for(int i = 0;i<4;i++){
            int xto = xcur+movx[i];
            int yto = ycur+movy[i];
            if(xto>=0 && yto>=0 && xto<n && yto<m){
                if(!used[xto][yto]){
                    used[xto][yto] = true;
                    q.push(make_pair(xto,yto));
                    a[xto][yto] = a[xcur][ycur]+1;
                }
            }
        }
        
    }
 
}
 
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            if(a[i][j]==1){
                ones.push_back(make_pair(i,j));
                a[i][j]=0;
                used[i][j] = true;
            }
        }
    }
   
    bfs(ones);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }
 
    return 0;
}