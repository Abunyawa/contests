#include<bits/stdc++.h>
using namespace std;
#define line1 ios_base::sync_with_stdio(0)
#define line2 cin.tie(0);
long long mod = 1000000007;


long long powM(long long a, long long b){
    if(b==0){
        return 1;
    }else{
        if(b%2==0){
            return (powM(a,b/2)*powM(a,b/2))%mod;
        }else{
            return (powM(a,b-1)*a)%mod;
        }
    }
}

long long factorial (long long n, long long p) {
	long long res = 1;
	while (n > 1) {
		res = (res * ((n/p) % 2 ? p-1 : 1)) % p;
		for (long long i=2; i<=n%p; ++i)
			res = (res * i) % p;
		n /= p;
	}
	return res % p;
}

long long comb(long long n,long long m){
    cout<<"here"<<endl;
    return (factorial(m+n-1,mod)/(factorial(m-1,mod)*factorial(n,mod)))%mod;

}

int main(){
    line1;
    line2;
    int n,m;
    cin>>n>>m;
    long long ans = 0;
    for(int i = 1;i<=n;i++){
        ans+=(comb(i,m-1)*comb(n-i+1,m))%mod;
    }

    cout<<ans%mod<<endl;
    return 0;
}