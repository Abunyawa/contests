#include<bits/stdc++.h>
using namespace std;
bool used[25][25];
int dist[25][25];
int n;
int movx[] = {1,1,2,2,-1,-1,-2,-2};
int movy[] = {2, -2, 1, -1 , 2,-2,1,-1};
void bfs(int x, int y){
    used[x][y] = true;
    dist[x][y] = 0;
    queue<pair<int,int> > q;
    q.push(make_pair(x,y));
    while(!q.empty()){
        pair<int,int> pos = q.front();
        q.pop();
        int xcur = pos.first;
        int ycur = pos.second;
        for(int i = 0;i<8;i++){
            int xto = xcur+movx[i];
            int yto = ycur+movy[i];
            if(xto>0 && yto>0 && xto<=n && yto<=n){
                if(!used[xto][yto]){
                    used[xto][yto] = true;
                    q.push(make_pair(xto,yto));
                    dist[xto][yto] = dist[xcur][ycur]+1;
                }
            }
        }
        
    }

}

int main(){
    int xs,ys,xf,yf;
    cin>>n>>xs>>ys>>xf>>yf;

    
    bfs(xs,ys);
    cout<<dist[xf][yf]<<endl;
 
    return 0;
}