#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;

ll Nod(ll a, ll b)
{
    while (a && b)
        if (a >= b)
           a %= b;
        else
           b %= a;
    return a | b;
}
int main(){
	int n;
	cin>>n;
	vector<int> ans;
	for(int i=0;i<n;i++){
		ll p,q,b;
		cin>>p>>q>>b;
		if(p==q){
			ans.push_back(1);
			continue;
		}
		ll del=Nod(p,q);
		q=q/del;
		ll sc;
		while((b=Nod(q,b))!=1){
			while(q%sc==0)q/=sc;
		}
		if(q==1){
			cout<<"Finite"<<endl;
		}else{
			cout<<"Infinite"<<endl;
		}
	}
	return 0;
}
