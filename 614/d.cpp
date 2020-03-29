#include<bits/stdc++.h>
using namespace std;
long long x,y,ax,ay,bx,by;
set<pair<int,int> > a;
int mx[] = {1, 0, 0, -1};
int my[] = {0, 1, -1, 0};
long long answer = 0;



int main(){
    int x,y,ax,ay,bx,by;
    cin>>x>>y>>ax>>ay>>bx>>by;
    int posx,posy,k;
    cin>>posx>>posy>>k;
    long long curx =x;
    long long cury =y;

    while(curx<=posx+k && cury<=posy+k){
        a.insert(make_pair(curx,cury));
        curx = ax*curx + bx;
        cury = ay*cury + by;

    }
    dfs(posx,posy,k,0);

    cout<<answer<<endl;

    return 0;
}
