#include<iostream>
#include<vector>
using namespace std;

int main(){
	vector<long long> fib;
	fib.push_back(1);
	fib.push_back(1);
	cout<<"How much numbers u wanna see???"<<endl;
	int n;
	cin>>n;
	int i=2;
	cout<<fib[0]<<' '<<fib[1]<<' ';
	while(i!=n){
		fib.push_back(fib[i-2]+fib[i-1]);
		cout<<fib[i]<<" ";
		i++;
	}
	return 0;
}
