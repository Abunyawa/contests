#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    for(int i = 0;i<t;i++){
        string str;
        cin>>str;
        int n = str.length();
        for(int j=0;j<n;j++){
            if(j==n-1){
                if(str[j]=='?'){
                    if(str[j-1]!='a'){
                        str[j]='a';
                    }else if(str[j-1]!='b'){
                        str[j]='b';
                    }else if(str[j-1]!='c'){
                        str[j]='c';
                    }
                }
                break;
            }
            if(str[j]==str[j+1] && str[j]!='?'){
                str="-1";
                break;
                
            }
            if(str[j]=='?'){
                if(str[j-1]=='a'){
                    if(str[j+1]!='b'){
                        str[j]='b';
                    }else{
                        str[j]='c';
                    }
                   
                }else if(str[j-1]=='b'){
                    if(str[j+1]!='c'){
                        str[j]='c';
                    }else{
                        str[j]='a';
                    }
                }else if(str[j-1]=='c'){
                    if(str[j+1]!='b'){
                        str[j]='b';
                    }else{
                        str[j]='a';
                    }
                }else{
                    if(str[j+1]!='a'){
                        str[j]='a';
                    }else if(str[j+1]!='b'){
                        str[j]='b';
                    }else if(str[j+1]!='c'){
                        str[j]='c';
                    }
                
                }
            }
            
        }
        cout<<str<<endl;
    }

    return 0;
}