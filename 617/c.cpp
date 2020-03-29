#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        map< pair<long long, long long>,long long>  pos;
        long long x = 0, y = 0;
        long long ansInd = -1, dist = 999999999;
        pos[make_pair(x,y)] = 0;
        for(int i = 1;i<=n;i++){
            char d;
            cin>>d;
            if(d=='R'){
                x++;
            }else if(d == 'L'){
                x--;
            }else if(d == 'U'){
                y++;
            }else{
                y--;
            }
            if(pos.find(make_pair(x,y)) == pos.end()){
                
                pos[make_pair(x,y)] = i;
            }else{
                if(i-pos[make_pair(x,y)]-1 <= dist){
                    dist = i-pos[make_pair(x,y)]-1;
                    ansInd = 1+pos[make_pair(x,y)];
                    pos[make_pair(x,y)] = i;
                }else{
                    pos[make_pair(x,y)] = i;
                }
            }
        }
        if(ansInd!=-1)
            cout<<ansInd<<' '<<ansInd+dist<<endl;
        else{
            cout<<-1<<endl;
        }
    }


    return 0;
}