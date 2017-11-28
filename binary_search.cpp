#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int binary_search(vector<int> v, int start, int end, int find){
	
	sort(v.begin(), v.end());
	int mid;	
	while(start < end){
		mid = (start+end) / 2;
		if(v[mid] == find) return mid;
		else if(v[mid] > find){
			end = mid;	
		}else{
			start = mid;
		}
	}

	return -1;

}


int main(){
	vector<int> a;
	a.push_back(10);
	a.push_back(11);
	a.push_back(12);
	a.push_back(13);
	a.push_back(14);
	cout<<binary_search(a, 0, a.size()-1, 3)<<endl;


}
