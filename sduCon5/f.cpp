#include<bits/stdc++.h>
using namespace std;
int n,s,t;
const int INF = 10000000;
vector<vector<pair<int,int> > > g(1000);


int main(){
    cin>>n>>s>>t;
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            int x;
            cin>>x;
            if(x!=-1 && x!=0)
                g[i].push_back(make_pair(x,j));
        }
    }
    s--;
    t--;

    vector<int> d(n,INF);
    d[s] = 0;
    set<pair<int,int> > q;
    q.insert(make_pair(d[s],s));
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

    if(d[t]!=INF)
        cout<<d[t]<<endl;
    else{
        cout<<-1<<endl;
    }
    return 0;
}