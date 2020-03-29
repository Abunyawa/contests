#include<fstream>
#include<iostream>
using namespace std;
int main(){
	ifstream fin("INPUT.TXT");
	ofstream fout("OUTPUT.TXT");
	int n;
	fin>>n;
	int arr[n];
	
	char op[4];
	
	for(int i=0;i<4;i++){
		fin>>op[i];
	}
	int ptr=0;

	if(op[3]=='1'){
		arr[ptr]=1;
		arr[ptr+1]=1;
		ptr++;	
		
	}else if(op[1]=='1'){
		arr[ptr]=1;
		arr[ptr+1]=0;
		ptr++;	
		
	}else if(op[0]=='1'){
		arr[ptr]=0;
		arr[ptr+1]=1;
		ptr++;	
		
	}else if(op[2]=='1'){
		arr[ptr]=0;
		arr[ptr+1]=0;
		ptr++;	
		
	}
	
	if(ptr==0){
		fout<<"No solution";
		return 0;
	}
	
	for(int i=1;i<n;i++){
		int cnst=ptr;
		if(op[3]==(char)(arr[ptr]+48)){
			arr[ptr]=1;
			arr[ptr+1]=1;
			ptr++;	
		
		}else if(op[1]==(char)(arr[ptr]+48)){
			arr[ptr]=1;
			arr[ptr+1]=0;
			ptr++;	
			
		}else if(op[0]==(char)(arr[ptr]+48)){
			arr[ptr]=0;
			arr[ptr+1]=1;
			ptr++;	
			
		}else if(op[2]==(char)(arr[ptr]+48)){
			arr[ptr]=0;
			arr[ptr+1]=0;
			ptr++;	
			
		}
		if(ptr==cnst){
			fout<<"No solution";
			return 0;
		}
	}
	
	for(int i=n-1;i>=0;i--){
		fout<<arr[i];
	}
	return 0;
}
