#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define pii pair<int, int>
using namespace std;

void yes(){
    cout<<"YES"<<endl;
}

void no(){
    cout<<"NO"<<endl;
}

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> g[n+1];
    vector<int> kt(k);
    set<int> kts;

    for(int i=0;i<k;i++){
        cin>>kt[i];
        kts.insert(kt[i]);
    }
    bool ok = false;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        if(kts.find(x)!=kts.end() && kts.find(y)!=kts.end()){
            ok = true;
        }
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int s = 1;
    queue<int> q;
    q.push (s);
    vector<bool> used (n+1);
    vector<int> d (n+1);
    used[s] = true;
    vector<int> sp;
    long long curM = 9999999999;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if(!ok){
            if(kts.find(v)!=kts.end()){
                if(sp.empty()){
                    sp.pb(v);
                }else{
                    queue<int> q;
                    q.push (v);
                    vector<bool> used1 (n+1);
                    vector<int> d1 (n+1);
                    used[s] = true;
                    vector<int> sp;
                    long long curM = 9999999999;
                    while (!q.empty()) {
                        int v = q.front();
                        q.pop();
                        if(!ok){
                            if(kts.find(v)!=kts.end()){
                                if(sp.empty()){
                                    sp.pb(v);
                                }else{
                                    
                                    sp.pb(v);
                                }
                            }
                        }
                        for (size_t i=0; i<g[v].size(); ++i) {
                            int to = g[v][i];
                            if (!used[to]) {
                                used[to] = true;
                                q.push (to);
                                d[to] = d[v] + 1;
                            }
                        }
                    }
                    sp.pb(v);
                }
            }
        }
        for (size_t i=0; i<g[v].size(); ++i) {
            int to = g[v][i];
            if (!used[to]) {
                used[to] = true;
                q.push (to);
                d[to] = d[v] + 1;
            }
        }
    }
    if(ok)
        cout<<d[n]<<endl;
    else{
        cout<<d[n]-curM+1<<endl;
    }
    return 0;
}