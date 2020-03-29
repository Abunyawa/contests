#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;


int main(){
	bool ch[1010];
	int n;
	cin>>n;
	int arr[60];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int i=1;i<=1000;i++){
		ch[i]=false;
	}
	vector<int> ans;
	int a;
	for(int i=n-1;i>=0;i--){
		if(ch[arr[i]]==false){
			ans.push_back(arr[i]);
			ch[arr[i]]=true;
		}
	}
	cout<<ans.size()<<endl;
	for(int i=ans.size()-1;i>=0;i--)
		cout<<ans[i]<<' ';
	return 0;
}
