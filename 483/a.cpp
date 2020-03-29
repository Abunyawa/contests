#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;

int main(){
	int n;
	cin>>n;
	int a;
	vector<int> arr;
	for(int i=0;i<n;i++){
		cin>>a;
		arr.push_back(a);
	}
	sort(arr.begin(),arr.end());
	cout<<arr[(n-1)/2];
	return 0;
}
