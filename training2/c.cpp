#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    vector<int> s(m);
    vector<int> f(m);
    for(int i = 0;i<m;i++){
        scanf("%d",&s[i]);
    }
    for(int i = 0;i<m;i++){
        scanf("%d",&f[i]);
    }
    for(int i=0;i<q;i++){
        int ctr = 0;
        int x;
        scanf("%d",&x);
        for(int i=0;i<m;i++){
            if(f[i]-s[i]<abs(s[i]-x)+abs(f[i]-n-1)){
                ctr++;
            }
        }
        printf("%d ",m-ctr);
    }
    printf("\n");
    return 0;
}