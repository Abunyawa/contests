#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define pii pair<int, int>
using namespace std;

void yes(){
    cout<<"YES"<<endl;
}

void no(){
    cout<<"NO"<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
    cin>>n;
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int c[]={-1,0,1};
    bool glFlag = false;
    ll fans = 9999999999;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            ll gap = a[1]+c[i]-(a[2]+c[j]);
            ll ans = abs(c[i])+abs(c[j]);
            int prev = c[j];
            bool flag = true;
            for(int k=3;k<=n;k++){
                prev = (a[k-1]+prev-gap)-a[k];
                if(abs(prev)>1){
                    flag = false;
                     break;
                }else{
                    ans+=abs(prev);
                }
            }
            if(flag){
                if(ans<fans){
                    glFlag = true;
                    fans = ans;
                }
            }
        }   
    }
    if(glFlag)
        cout<<fans<<endl;
    else
        cout<<-1<<endl;
    return 0;
}