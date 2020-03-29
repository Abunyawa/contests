#include<iostream>
#include<cmath>
#include<set>
using namespace std;


int main(){
	int n,k,A,B;
	cin>>n>>k>>A>>B;
	set<int> nums;
	for(int  i =0;i<k;i++){
		int x;
		cin>>x;
		nums.insert(x);
	}
	long long ans(0);
	ans+=A*(pow(2,n)-nums.size());
	ans+=B*(k);
	cout<<ans;
	
	return 0;
}
