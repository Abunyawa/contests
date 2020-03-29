#include<iostream>
using namespace std;

int main(){
	int x;
	cin>>x;
	for(int i=1;i<=x;i++){
		for(int j=1;j<=x;j++){
			if(j%i==0 && j*i>x && j/i<x){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	
	cout<<-1;
	return 0;
}
