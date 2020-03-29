#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
ll a[200100],asum[200100];
ll b[200100];
int main(){
	int n,m;
	cin>>n>>m;
	
	asum[0]=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i==0){
			asum[i]=a[i];
		}else{
			asum[i]=asum[i-1]+a[i];
		}
	}
	
	for(int i=0;i<m;i++){
		cin>>b[i];
	}
	int ptr=0;
	vector< pair<int,ll> > ans;
	for(int i=0;i<m;i++){
		while(b[i]>asum[ptr])
			ptr++;
		if(ptr!=0)
			ans.push_back(make_pair(ptr+1,b[i]-asum[ptr-1]));
		else
			ans.push_back(make_pair(ptr+1,b[i]));
	}
	for(int i=0;i<ans.size();i++){
		cout<<ans[i].first<<' '<<ans[i].second<<endl;
	}
	return 0;
}
