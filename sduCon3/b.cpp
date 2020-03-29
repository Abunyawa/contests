#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100000;

int t[4*MAXN],a[MAXN], t2[4*MAXN];


int main(){
    int n;
    cin>>n;
    long long sum1=0,sum2=0,sum3=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        sum1+=x;
    }

    for(int i=0;i<n-1;i++){
        int x;
        cin>>x;
        sum2+=x;
    }
    for(int i=0;i<n-2;i++){
        int x;
        cin>>x;
        sum3+=x;
    }
    cout<<sum1-sum2<<endl<<sum2-sum3<<endl;
    return 0;
}