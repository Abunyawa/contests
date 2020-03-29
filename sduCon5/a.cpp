#include<bits/stdc++.h>
using namespace std;
 
int ans=0;
int m;
const int INF = 100000;
vector<int> steps(1000000, INF);
int used[1000000];
 
void bfs(int a){
    queue<int> q;
    q.push(a);
    used[a] = true;
    steps[a] = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(cur-1>=0 && !used[cur-1]){
            q.push(cur-1);
            steps[cur-1] = steps[cur]+1;

            used[cur-1] = true;
        }
 
        if(cur*2<2*m && !used[cur*2]){
            q.push(cur*2);
            steps[cur*2] = steps[cur]+1;

            used[cur*2] = true;
        }
 
    }
 
}
 
int main(){
    int n;
    cin>>n>>m;
    int ctr(0);
    bfs(n);
    cout<<steps[m]<<endl;
 
    return 0;
}