#include<bits/stdc++.h>
using namespace std;
vector<int> q[100100];



int main(){

    int n;
    cin>>n;
    vector<int> count(n,0);
    vector<bool> vis(n,false);

    for(int i=0;i<n-2;i++){
        int x1,y1,z1;
        cin>>x1>>y1>>z1;
        x1--;
        y1--;
        z1--;
        count[x1]++;
        count[y1]++;
        count[z1]++;
        q[x1].push_back(y1);
        q[x1].push_back(z1);
        q[y1].push_back(x1);
        q[y1].push_back(z1);
        q[z1].push_back(y1);
        q[z1].push_back(x1);

    }
    int x,y,z;
    for(int i=0;i<n;i++){
        if(count[i]==1){
            x = i;
        }
    }
    
    for(int i=0;i<q[x].size();i++){
        if(count[q[x][i]]==2){
            y=q[x][i];
        }
    }
    vis[x]=true;
    vis[y]=true;
    cout<<x+1<<' '<<y+1<<' ';
    for(int i = 0;i<n-2;i++){
        for(int j = 0;j<q[x].size();j++){
            if(!vis[q[x][j]]) z = q[x][j];
        }
        vis[z] = true;
        cout<<z+1<<' ';
        x=y;
        y=z;

    }
    return 0;
}