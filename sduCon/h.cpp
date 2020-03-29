#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> g;
    int x;
    for(int i=0;i<m;i++){
        cin>>x;
        g.push_back(x);
    }
    sort(g.begin(),g.end());

    double ans = 0;
    vector<double> dp;
    double l=0,r=g[0];

    double rad = r-l;
    double ansLoc = pow(rad,2)+7*rad+5;
    if(ansLoc>ans){
        ans=ansLoc;
    }
    l=r;
    for(int i =0;i<m;i++){
        r = g[i];
        double rad = (r-l)/2;
        double ansLoc = pow(rad,2)+7*rad+5;
        if(ansLoc>ans){
            ans=ansLoc;
        }
        l=r;
    }
    r=n;
    rad = r-l;
    ansLoc = pow(rad,2)+7*rad+5;
    if(ansLoc>ans){
        ans=ansLoc;
    }
    
    printf("%0.6f\n",ans);



    return 0;
}

/*
0 1 2 3 4 5 6 7 8 9
      k     k     k
r = 3
9+21+5      
*/