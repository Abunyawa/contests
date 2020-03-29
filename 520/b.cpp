#include<iostream>
#include<cmath>
using namespace std;
bool is_prime(int n){
	for(int i=2;i<sqrt(n);i++){
		if(n%i==0){
			return false;
		}
	return true;
	}
}
int main(){
	int n;
	cin>>n;
	int op=0;
	if(n==1){
		cout<<1<<' '<<0;
		return 0;
	}
	while((float)sqrt(n)*(float)sqrt(n)==n){
		n=sqrt(n);
		op++;
 	}
	if(is_prime(n)){
		cout<<n<<' '<<op;
		return 0;
	}
	for(int i=1;i<n;i++){
		if((i*i)%n==0){
			op+=1;
			n=i;
			i=1;
		}
	}
	if(op!=0){
		op++;
	}
	cout<<n<<' '<<op;
	
	
	return 0;
}
