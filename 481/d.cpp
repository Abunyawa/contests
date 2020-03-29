#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
ll b[100100];
ll sum(vector<ll> &a){
	ll sum(0);
	for(int i=0;i<a.size();i++){
		sum+=a[i];
	}
	return sum;
}
ll check(vector<ll> &a){
	if(sum(a)%a.size()!=0){
		return -1;
	}else{
		ll counter(0);
		counter=0;
		ll piv=sum(a)/a.size();
		for(int i=0;i<a.size()-1;i++){
			ll past;
			past=a[i]-piv;
			if(past*past>1)
				return -1;
			if(past==-1){
				a[i]+=1;
				a[i+1]-=1;
				counter++;
			}else if(past==1){
				a[i]-=1;
				a[i+1]+=1;
				counter++;
			}else if(past==0)
				continue;
		}
		if(a[a.size()-1]==piv)
			return counter;
		else
			return -1;
	}
	
}
int main(){
	int n;
	ll razn;
	vector<ll> c;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>b[i];
		if(i>0){
			if(b[1]<b[0]){
				razn=b[i-1]-b[i];
				c.push_back(razn);
			}else{
				razn=b[i]-b[i-1];
				c.push_back(razn);
			}
		}
	}
	ll ans[9];
	for(int i=0;i<9;i++){
		ans[i]=0;
	}
	vector<ll> a=c;
	ans[0]=check(a);
	a[a.size()-1]-=1;
	ans[1]=check(a);
	a=c;
	a[a.size()-1]+=1;
	ans[2]=check(a);
	a=c;
	a[0]+=1;
	ans[3]=check(a);
	a=c;
	a[0]+=1;
	a[a.size()-1]-=1;
	ans[4]=check(a);
	a=c;
	a[0]+=1;
	a[a.size()-1]+=1;
	ans[5]=check(a);
	a=c;
	a[0]-=1;
	ans[6]=check(a);
	a=c;
	a[0]-=1;
	a[a.size()-1]-=1;
	ans[7]=check(a);
	a=c;
	a[0]-=1;
	a[a.size()-1]+=1;
	ans[8]=check(a);
	a=c;
	for(int i=0;i<9;i++){
		if(ans[i]!=-1){
			if(i==1)
				ans[i]+=1;
			if(i==2)
				ans[i]+=1;
			if(i==3)
				ans[i]+=1;
			if(i==4)
				ans[i]+=2;
			if(i==5)
				ans[i]+=2;
			if(i==6)
				ans[i]+=1;
			if(i==7)
				ans[i]+=2;
			if(i==8)
				ans[i]+=2;
		}	
	}
	ll ans1(99999999);
	for(int i=0;i<9;i++)
		if(ans[i]<ans1&&ans[i]>-1){
			ans1=ans[i];
		}
	if(ans1==99999999)
		cout<<-1;
	else
		cout<<ans1;
	return 0;
}
