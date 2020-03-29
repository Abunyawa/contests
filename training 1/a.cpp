#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,a,b;
    cin>>n>>a>>b;
    bool flag = true;
    int l = 0;
    int r = n-1;
    int c[n];
    for(int i = 0;i<n;i++){
        cin>>c[i];
    }
    int ans = 0;
    while(l<=r){
        if(l==r){
            if(c[l]==2){
                ans+=min(a,b);
            }
            l++;
            r--;
            continue;
        }
        if(c[l]==c[r]){
            if(c[l]==2){
                ans+=2*min(a,b);
            }
            l++;
            r--;
            
        }else{
            if(c[l]!=2 && c[r]!=2){
                flag = false;
                break;
            }else{
                if(min(c[l],c[r])==1){
                    ans+=b;
                }else{
                    ans+=a;
                }
            }
            l++;
            r--;
        }
    }

    if(flag){
        cout<<ans<<endl;
    }else{
        cout<<-1<<endl;
    }

    return 0;
}