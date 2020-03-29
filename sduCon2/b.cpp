#include<bits/stdc++.h>
using namespace std;
vector<int> ans1;
int c[4];
bool isOk(int r1, int r2, int c1, int c2, int d1, int d2, int x){
    if(x>3){
        if(r1==c[0]+c[1] && r2==c[2]+c[3] && c1 == c[0]+c[2] && c2 == c[1]+c[3] && d1==c[0]+c[3] && d2==c[1]+c[2]){
            ans1.push_back(c[0]);
            ans1.push_back(c[1]);
            ans1.push_back(c[2]);
            ans1.push_back(c[3]);
            return true;

        }else{
            return false;
        }
    }else{
        bool ans = false;
        for(int i = 1;i<=9;i++){
            bool fl =true;
            for(int j=0;j<x;j++){
                if(c[j]==i){
                    fl = false;
                }
            }
            if(fl){
                c[x] = i;
                ans=ans|isOk(r1,r2,c1,c2,d1,d2,x+1);
            }
        }
        return ans;
    }
}


int main(){
    int r1, r2, c1, c2, d1, d2;
    cin>>r1>>r2>>c1>>c2>>d1>>d2;
    isOk(r1,r2,c1,c2,d1,d2,0);
    if(ans1.size()!=0){
        cout<<ans1[0]<<" "<<ans1[1]<<endl;
        cout<<ans1[2]<<" "<<ans1[3]<<endl;

    }else{
        cout<<-1<<endl;
    }
 
    return 0;
}