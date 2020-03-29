#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> arr;
	for(int i = 0;i<n;i++){
		int x;
		cin>>x;
		arr.push_back(x);
	}
	sort(arr.begin(),arr.end());
	int ar[n];
	int ptrl = n/2-1;
	int ptrr = n/2+1;
	ar[n/2]=arr.back();
	arr.pop_back();
	while(true){
		if(!arr.empty()){
			if(ptrl>=0)
				ar[ptrl--]=arr.back();
				arr.pop_back();
		}else{
			break;
		}
		if(!arr.empty()){
			if(ptrr<n)
				ar[ptrr++]=arr.back();
				arr.pop_back();
		}else{
			break;
		}
		
	}
	for(int i=0;i<n;i++){
		cout<<ar[i]<<' ';
	}
}
