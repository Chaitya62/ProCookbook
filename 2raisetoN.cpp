/*
Written By 
Chaitya Shah
*/
#include<iostream>
using namespace std;
int main(){
	string s;
	int a[100];
	int pow;
	cin>>pow;
	a[0] = 0;
	a[1] = 2;
	a[2] = 4;
	a[3] = 6;
	a[4] = 8;
	a[5] = 0;
	a[6] = 2;
	a[7] = 4;
	a[8] = 6;
	a[9] = 8;
	s = "1";
	int len;
	for(int i =0;i<pow;i++){
		len = s.length();
		int carry = 0;
		for(int j = len-1;j>=0;j--){
			int x  = s[j] -'0';
			int n = a[s[j]-'0']+carry;
			//cout<<" "<<x<<endl;
			if(x>4)
			{ 
				carry = 1;
				if(j==0){
					s[j] = n +'0';
					s = '1'+s;
					//cout<<"here"<<endl;
					break;
				}
			}
			else carry = 0;
			s[j] = n + '0';
			//cout<<"in"<<endl;
		}
		//if(s[0]=='1') //cout<<"out"<<endl;
		
	}
	int sum = 0;
	for(int i = 0;i<s.length();i++){
		sum+= s[i]-'0';
	}
	cout<<len<<endl;
	cout<<s<<endl;
	cout<<sum<<endl;

	return 0;
}
