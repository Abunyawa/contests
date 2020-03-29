#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        string str;
        unordered_map<int ,int> f;
        cin>>str;
        int cnt = 0;
        for(int i=0;i<str.size();i++){
            if(str[i]=='0'){
                cnt++;
            }else{
                cnt--;
            }
            f[cnt] = f[cnt]+1;

        }
        if(cnt==x){
            cout<<-1<<endl;
        }else{
            int ans= 0;
            if(x==0){
                ans++;
            }
            if((cnt>0 && x>0) || (cnt<0 && x<0)){
                ans+=f[x%cnt];
                ans+=f[(cnt-x%cnt)];
                ans+=f[cnt-x];
                ans+=f[x];
            }else{
                ans+=f[cnt-x];
                ans+=f[x];
            }

            cout<<ans<<endl;
        }

    }


    return 0;
}