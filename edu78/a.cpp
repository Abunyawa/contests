#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 0;
    cin>>n;
    for(int i = 0 ;i<n;i++){
        bool flag = true;
        string p;
        cin>>p;
        string h;
        cin>>h;
        int alph[26];
        int ptrL(0);
        int ptrR(h.length()-1);
        for(int j=0;j<26;j++){
            alph[j] = 0;
        }
        for(int j = 0;j<h.length();j++){
            alph[(int)(h[j]-'a')]++;
        }
        for(int j = 0;j<p.length();j++){
            alph[(int)(h[j]-'a')]--;
        }

        int cnt=0;
        for(int j=0;j<h.length()-1;j++){
            if(alph[(int)(h[j]-'a')]>0 && alph[(int)(h[j+1]-'a')]==0){
                cnt++;
            }
        }

        if(cnt==1 && alph[(int)(h[0]-'a')]>0){
            flag = false;
        }else if(cnt > 1){
            flag = false;
        }
        
        for(int j=0;j<26;j++){
            if(alph[j] < 0){
                flag = false;
            }
        }
        if(flag){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }


    return 0;
}