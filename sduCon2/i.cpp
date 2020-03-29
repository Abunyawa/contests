#include<bits/stdc++.h>
using namespace std;

struct P{
    int x;
    int y;
};


bool isIn(vector<P> p, P p1){
    for(auto e: p){
        if(e.x==p1.x && e.y == p1.y){
            return true;
        }
    }
    return false;
}
double dist(P p1, P p2){
    return sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));
}
 


int main(){
    int n,m;

    cin>>n>>m;
    vector<P> points;
    for(int i = 0; i<=min(n,4);i++){
        for(int j=0;j<=min(m,4);j++){
            P p;
            p.x = i;
            p.y = j;
            if(!isIn(points, p))
                points.push_back(p);
        }
        for(int j = max(0,m-3);j<=m;j++){
            P p;
            p.x = i;
            p.y = j;
            if(!isIn(points, p))
                points.push_back(p);
        }
    }    
    for(int i = max(0,n-3); i<=n;i++){
        for(int j=0;j<=min(m,4);j++){
            P p;
            p.x = i;
            p.y = j;
            if(!isIn(points, p))
                points.push_back(p);
        }
        for(int j = max(0,m-3);j<=m;j++){
            P p;
            p.x = i;
            p.y = j;
            if(!isIn(points, p))
                points.push_back(p);
        }
    }    
    double curMaxDis = 0;
    vector<P> ans;

    for(int i=0;i<points.size();i++){
        for(int j=0;j<points.size();j++){
            for(int k=0;j<points.size();j++){
                for(int r=0;r<points.size();r++){
                    if(i!=j && i!=k && i!=r && j!=k && j!=r && k!= r){
                        double dis = dist(points[i],points[j])+dist(points[k],points[j])+dist(points[k],points[r]);
                        if(dis>curMaxDis){
                            curMaxDis = dis;
                            ans.clear();
                            ans.push_back(points[i]);
                            ans.push_back(points[j]);
                            ans.push_back(points[k]);
                            ans.push_back(points[r]);
                        }
                    }
                }
            }
        }
    }

    for(auto e: ans){
        cout<<e.x<<' '<<e.y<<endl;
    }
    return 0;
}