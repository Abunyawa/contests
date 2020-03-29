#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;


int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	int counter(0);
	vector<int> ans;
	for(int i=0;i<s.size();i++){
		if(s[i]=='x'){
			counter++;
		}
		if(s[i+1]!='x'&&s[i]=='x'){
			ans.push_back(counter);
			counter=0;
		}
	}	
	int ans1(0);
	for(int i=0;i<ans.size();i++){
		if(ans[i]>2){
			ans1+=ans[i]-2;
		}
	}
	cout<<ans1;
	return 0;
}
