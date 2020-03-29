#include<iostream>
using namespace std;

int main(){
	int hh,mm;
	cin>>hh>>mm;
	int h,d,n;
	double c;
	cin>>h>>d>>c>>n;
	double ans1,ans2;
	if(hh<20){
		ans1=((h+n-1)/n);
		ans1=(double)ans1*c;
	}else{
		ans1=((h+n-1)/n);
		ans1=(double)ans1*c;
		printf("%.4f", ans1*0.8);
		return 0;
	}
	ans2=((((20-hh)*60-mm)*d+h)+n-1)/n;
	ans2=(double)ans2*c;
	printf("%.4f", min(ans1,ans2*0.8));
	return 0;
}
