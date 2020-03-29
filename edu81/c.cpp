#include<bits/stdc++.h>
using namespace std;



int main(){
    int t;
    cin>>t;
    while(t--){
        queue<int> alph[26];
        
        string s,t;
        bool flag = true;
        cin>>s>>t; 
        for(int i=0;i<s.size();i++){
            alph[s[i]-'a'].push(i);
            
        }
        int cur=-1;
        int ans = 1;
        for(int i=0;i<t.size();i++){
            if(alph[t[i]-'a'].size()==0){
                flag = false;
                break;
            }
            if(alph[t[i]-'a'].front()>cur){
                cur = alph[t[i]-'a'].front();
                alph[t[i]-'a'].pop();
            }else{
                ans++;
                cur = alph[t[i]-'a'].front();
                alph[t[i]-'a'].pop();
            }
        }
        if(flag){
            cout<<ans<<endl;
        }else{
            cout<<-1<<endl;
        }

    }


    return 0;
}