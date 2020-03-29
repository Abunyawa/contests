#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include <ctime>
#include<iterator>
using namespace std;

set<int> Y;
bool find_num(int *arr,int n, int a, int ex){
	for(int i=0;i<n;i++){
		if(arr[i]==a and i!=ex){
			return true;
		}
	}
	return false;
}
bool find_num(vector<int> &arr, int a){
	for(int i=0;i<arr.size();i++){
		if(arr[i]==a){
			return true;
		}
	}
	return false;
}
void findind(int *arr,int a,int n){
	for(int i=0;i<n;i++){
		if(arr[i]==a){
			Y.insert(i+1);
		}
	}
}
int main(){
	int n;
	scanf("%i",&n);
	int arr[n];
	long sum(0);
	for(int i=0;i<n;i++){
		scanf("%i",&arr[i]);
		sum+=arr[i];
	}
	
	for(int i=0;i<n;i++){
		int sumn=sum;
		sumn-=arr[i];
		if(sumn%2==0 && find_num(arr,n,sumn/2,i)){
			findind(arr,arr[i],n);		
		}
	}
    printf("%i",Y.size());
    cout<<endl;
	ostream_iterator<int> out(cout, " ");
	copy(Y.begin(),Y.end(), out); cout << endl;
	return 0;
}
