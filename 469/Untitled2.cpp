#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
	string str;
	cin>>str;
	queue<int> nul,ed;
	int len=str.length();
	for(int i=0;i<len;i++){
		if(str[i]=='0')
			nul.push_back(i+1);
		else
			ed.push_back(i+1);
	}
	vector<vector<int>> ans;
	vector<int> ans1;
	while(!nul.empty()){
		int x,y;
		x=nul.front();
		nul.pop();
		ans1.push_back(x);
		if(!ed.empty()){
			y=ed.front();
			while(y<x){
				ed.pop();
				y=ed.front();
			}
			ed.pop();
			if(x<y&&nul.empty!=true)
				ans1.push_back(y);	
			x=nul.front();
			nul.pop();
			if(x>y){
				ans1.push_back(x);
			}else{
				ans1.clear
			}
		}
		
			
				
	}
}
