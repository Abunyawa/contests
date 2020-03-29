#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int> > > g(1000);

struct edge {
	int a, b, cost;
};
 
int n, m;
vector<edge> e;
const int INF = 1000000000;

vector<int> solve(int v,vector<int> d) {
    m = e.size();
	for (int i=0; i<n-1; ++i)
		for (int j=0; j<m; ++j)
			if (d[e[j].a] < INF)
				d[e[j].b] = min (d[e[j].b], d[e[j].a] + e[j].cost);
    return d;
}


int main(){
    cin>>n;
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            int x;
            cin>>x;
            edge eq;
            eq.a= i;
            eq.b = j;
            eq.cost = x;
            e.push_back(eq);
            
        }
    }
    vector<int> d (n, INF);
    d[0] =0;
    vector<int> d1 = solve(0,d);
    vector<int> d2 = solve(0,d1);
    
    int is = 0;
    for(int i=0;i<n;i++){
        if(d1[i]!=d2[i]){
            is = 1;
        }
    }

    cout<<is<<endl;
    return 0;
}