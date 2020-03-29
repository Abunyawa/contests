#include<bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
vector<pair<int,int>> g[100000];
int n;
int movx[] = {1, 0, 0, -1};
int movy[] = {0, 1, -1, 0};
int main(){
    int n,m;
    cin>>n>>m;
    int x;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>x;
            //cout<<m*(i-1)+j<<endl;

            for(int k=0;k<4;k++){
                int xto = j+movx[k];
                int yto = i+movy[k];
                //cout<<i*(j-1)+i<<' '<<x<<endl;
                if(j+movx[k] > 0 && j+movx[k] <=m && i+movy[k] > 0 && i+movy[k] <=n){
                    g[m*(i-1)+j].push_back(make_pair(x,m*(yto-1)+xto));
                    
                }
            }

        }
    }


    vector<int> d(n*m+1,INF);
    d[1] = 0;
    set<pair<int,int> > q;
    q.insert(make_pair(d[1],1));
    while(!q.empty()){
        int v = (*q.begin()).second;
        q.erase(q.begin());
        for(int j=0;j<g[v].size();j++){
            int to = g[v][j].second;
            int cst = g[v][j].first;
            if(d[v]+cst<d[to]){
                q.erase(make_pair(d[to],to));
                d[to] =  d[v]+cst;
                q.insert(make_pair(d[to],to));

            }
        }
    }
    cout<<d[n*m]+x<<endl;   

    return 0;
}