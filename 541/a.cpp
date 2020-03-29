#include<iostream>
using namespace std;

int main(){
	int w1,h1,w2,h2;
	cin>>w1>>h1>>w2>>h2;
	int ans = w1*2+4+(h1+h2)*2;
	cout<<ans;
}
