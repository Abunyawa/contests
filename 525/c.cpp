#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<long long> a;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a.push_back(x);
	}
	int div=n+1;
	vector<long long> tip;
	vector<long long> dok;
	vector<long long> skok;
	long long prib=0;
	int maxnum=div-1;
	for(int i=n-1;i>=0;i--){
		if((a[i]+prib)%div!=maxnum){
			tip.push_back(1);
			dok.push_back(i+1);
			skok.push_back(max(maxnum-(a[i]+prib)%div,maxnum+(div-(a[i]+prib)%div)));
			prib+=max(maxnum-(a[i]+prib)%div,maxnum+(div-(a[i]+prib)%div));
		}
		maxnum--;
	}

	tip.push_back(2);
	dok.push_back(n);
	skok.push_back(div);
	cout<<tip.size()<<endl;
	for(int i=0;i<tip.size();i++){
		cout<<tip[i]<<' '<<dok[i]<<' '<<skok[i]<<endl;
	}
	
	return 0;
}
