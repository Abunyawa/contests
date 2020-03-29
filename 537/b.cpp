#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
double count(vector<double> a, double tot,int num,int k, int n){
	for(int i = 0; i<num;i++){
		double p;
		p = a.back();
		a.pop_back();
		tot+=p;
	}
	tot+=(n-num)*k;
	return tot/a.size();
}
int main(){
	double n,m,k;
	cin>>n>>k>>m;
	vector<double> a;
	double total(0);
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		total+=x;
		a.push_back(-x);
	}
	sort(a.begin(),a.end());
	vector<double> ans;
	int num=n-1;
	for(int i = n-1;i>=0;i--){
		if((n-i)*k<=(m-i)){
			num=i;
			vector<double> u = a;
			ans.push_back(count(u,total,i,k,n));
		}
	}
	double maxans(0);
	for(int i = 0; i < ans.size();i++){
		if(ans[i]>maxans){
			maxans=ans[i];
		}
	}	

	printf("%.20f",maxans);
	return 0;
}
