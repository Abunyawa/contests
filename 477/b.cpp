#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
	int n,a,b;
	cin>>n>>a>>b;
	vector<int> s;
	int s1;
	ll sum(0);
	int S;
	cin>>S;
	sum=sum+S;
	for(int i=1;i<n;i++){
		cin>>s1;
		s.push_back(s1);
		sum+=s1;
	}
	sort(s.begin(),s.end());
	int k(0),j(s.size()-1);
	while((S*a/sum)<b){
		k++;
		sum=sum-s[j];
		j--;
	}
	cout<<k;
	return 0;
}
