#include<bits/stdc++.h>
using namespace std;
 
 
int main(){
    int t;
    cin>>t;

    while(t--){
        vector<int> al[26];
        string a;
        cin>>a;
        int n = a.length();
        cout<<n;
        for(int i=0;i<n-1;i++){
            bool minFlag = true;
            for(int j=0;j<al[(int)(a[i]-'a')].size();j++){
                if(al[(int)(a[i]-'a')][j] == a[i+1]){
                    minFlag = false;
                    break;
                }
            }
            if(minFlag){
                al[(int)(a[i]-'a')].push_back(a[i+1]);
            }
            minFlag = true;
            for(int j=0;j<al[(int)(a[i+1]-'a')].size();j++){
                if(al[(int)(a[i+1]-'a')][j] == a[i]){
                    minFlag = false;
                    break;
                }
            }
            if(minFlag){
                al[(int)(a[i+1]-'a')].push_back(a[i]);
            }
        }
        cout<<"here";
        bool flag = false;
        char ind;
        int ctr = 0;
        for(int i = 0;i<26;i++){
            if(al[i].size()==1){
                ind = (char)(i+(int)'a');;
                flag = true;
                ctr++;
            }
            if(al[i].size()>2){
                flag = false;
                break;
            }
        }
        bool in[26];
        for(int i=0;i<26;i++){
            in[i] = 0;
        }
        if(ctr!=2){
            flag = false;
        }
        if(flag){
            string ans = "";
            while(true){
                ans+=ind;
                in[(int)(ind-'a')]=true;
                for(int i=0;i<al[(int)(ind-'a')].size();i++){
                    if(al[(int)(ind-'a')][i]==ind){
                        al[(int)(ind-'a')].erase(al[(int)(ind-'a')].begin()+i);
                    }
                }
                if(al[(int)(ind-'a')].size()!=0)
                    ind = al[(int)(ind-'a')][0];
                else{
                    break;
                }
            }
            for(char i ='a';i<='z';i++){
                if(!in[(int)(a[i]-'a')]){
                    ans+=i;
                }
            }
            cout<<"YES"<<endl;
            cout<<ans<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
/*
    0 0 0 0
1   1 
2     2
3       2
4   ------
5         1
6   ------
7   ---------
8 ------------
9              1
 */