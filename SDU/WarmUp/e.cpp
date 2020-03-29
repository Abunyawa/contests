#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#define ll long long
const ll INF=100000000000000;
using namespace std;
struct edge{
	ll a,b,cost;
};
 

vector<ll> dj(int s,vector<pair<int,int> > *g){
	vector<ll> d(100000,INF);
	d[s]=0;
	set <pair<int, int> > q;
	q.insert(make_pair(d[s],s));
	while(!q.empty()){
		int v= q.begin()->second;
		q.erase(q.begin());
		for(size_t j=0;j<g[v].size();j++){
			int to=g[v][j].second;
			int len=g[v][j].first;
			if(d[v]+len<d[to]){
				q.erase(make_pair(d[to],to));
				d[to]=d[v]+len;
				q.insert(make_pair(d[to],to));
			}
		}
	}
	return d;
}

int main(){
	int n,m;
	scanf("%i%i",&n,&m);
	vector<pair<int,int> > g[n];
	for(int i=0;i<m;i++){
		int v,u,cost;
		scanf("%i%i%i",&v,&u,&cost);
		v--;
		u--;
		g[v].push_back(make_pair(cost,u));
		g[u].push_back(make_pair(cost,v));
	}
	int q;
	cin>>q;
	vector<pair<int,int> > ans;
	for(int i=0;i<q;i++){
		int s,f;
		scanf("%i%i",&s,&f);
		s--;
		f--;
		ans.push_back(make_pair(s,f));
	}
	for(int i=0;i<ans.size();i++){
		vector<ll> d=dj(ans[i].first,g);
		while(ans[i+1].first==ans[i].first){
			cout<<d[ans[i].second]<<endl;
			i++;
		}
		cout<<d[ans[i].second]<<endl;
	}
	return 0;
}
