#include<fstream>
#include<algorithm>
using namespace std;
int arr[1000100];
int main(){
	ifstream fin("INPUT.TXT");
	ofstream fout("OUTPUT.txt");
	int n;
	fin>>n;
	for(int i=0;i<n;i++){
		fin>>arr[i];
	}
	sort(arr[0],arr[n-1]);
	for(int i=0;i<n;i++){
		fout<<arr[i]<<' ';
	}
	return 0;
}
