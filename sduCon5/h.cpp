#include<bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
vector<pair<int,int>> g[100000];
int n;

int main(){
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(make_pair(a[x-1],y));
        g[y].push_back(make_pair(a[y-1],x));;
    }

    vector<int> d(n+1,INF);
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
    if(d[n]!=INF)
        cout<<d[n]<<endl;
    else
        cout<<-1<<endl;
    return 0;
}