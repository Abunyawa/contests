#include<iostream>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	int a[n],b[m];
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<m;i++)
		cin>>b[i];
	int ptrx(0),ptry(0),counter(0);
	while(ptrx<=n-1){
		int x,y;
		x=a[ptrx];
		y=b[ptry];
		if(x==y){
			counter++;
			ptrx++; ptry++;
			continue;
		}
		while(x!=y){
			if(x<y){
				ptrx++;
				x+=a[ptrx];
			}
			else{
				ptry++;
				y+=b[ptry];
			}
		}
		ptrx++;ptry++;
		counter++;
	}
	cout<<counter;
	return 0;
}
