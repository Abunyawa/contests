#include<fstream>
#include<vector>
#include<cmath>
using namespace std;
ifstream fin("INPUT.txt");
ofstream fout("OUTPUT.txt");

int main(){
	int n,m,k;
	fin>>n>>m>>k;
	if(k<3){
		fout<<0;
		return 0;
	}
	int ans=n/(k-2);
	int rest=n%(k-2);
	m-=ans*2;
	rest+=m/k;
	m=m%k;
	if(rest!=0){
		if(m<2){
			fout<<0;
			return 0;
		}else{
			ans++;
			m-=2;
		}
		if(m!=0){
			ans++;
		}
	}else if(m!=0){	
		ans++;
	}
	fout<<ans;
	
	return 0;
}
