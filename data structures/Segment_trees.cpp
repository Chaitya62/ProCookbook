/* 
Segment trees Implementation 
Written By lakshmanaram
*/
#include <bits/stdc++.h>
using namespace std;
class node{
public:
	long long val;
};
class segment_tree{
public:
	vector<node> tnodes;
	vector<node> arr;
	segment_tree(long n){
		arr.resize(n);
		for(long i=0;i<n;i++)
			cin>>arr[i].val;
	}
	void build_segment_tree(long index, long start, long end) {
		if(start == end){
			// leaf node
			if(tnodes.size() <= index)
				tnodes.resize(index+1);
			tnodes[index].val = arr[start].val;
		} else {
			long mid = (start+end)/2;
			build_segment_tree(2*index+1,start,mid);
			build_segment_tree(2*index+2,mid+1,end);
			tnodes[index].val = tnodes[2*index+1].val + tnodes[2*index+2].val;
		}
	}
	long long query_range(long index, long start, long end, long l, long r) {
		if(start > r || end < l)
			return 0;
		if(start >= l && end <= r)
			return tnodes[index].val;
		long mid = (start+end)/2;
		long long val1 = query_range(2*index+1,start,mid,l,r);
		long long val2 = query_range(2*index+2,mid+1,end,l,r);
		return val1+val2;
	}
	void update(long index, long start, long end, long updatepos, long long val) {
		// add val to updatepos indexed element
		if(start == end){
			arr[updatepos].val += val;
			tnodes[index].val += val;
		} else {
			long mid = (start+end)/2;
			if(start <= updatepos && mid >= updatepos)
				update(2*index+1,start,mid,updatepos,val);
			else
				update(2*index+2,mid+1,end,updatepos,val);
			tnodes[index].val = tnodes[2*index+1].val + tnodes[2*index+2].val;
		}
	}
	void update_range_naive(long start, long end, long l, long r, long long val) {
		// O(nlogn) algo to update range
		for(long i=l;i<=r;i++){
			update(0,start,end,i,val);
		}
	}
	void update_range_naive_lower_calls(long index, long start, long end, long l, long r, long long val) {
		// O(nlogn) algo to update range with leser function calls
		if(start > end || start > r || end < l)
			return;
		if(start == end){
			arr[start].val += val;
			tnodes[index].val += val;
		} else {
			long mid = (start+end)/2;
			update_range_naive_lower_calls(2*index+1,start,mid,l,r,val);
			update_range_naive_lower_calls(2*index+2,mid+1,end,l,r,val);
			tnodes[index].val = tnodes[2*index+1].val + tnodes[2*index+2].val;
		}
	}
	void update_query() {
		long pos,l,r;
		long long val;
		// update individual element
		cin>>pos;
		cin>>val;
		cout<<"update individual query"<<endl;
		update(0,0,arr.size()-1,pos,val);
		show_tnodes();
		show_arr();
		//update range
		cin>>l>>r;
		cin>>val;
		cout<<"update range query"<<endl;
		update_range_naive(0,arr.size()-1,l,r,val);
		show_tnodes();
		show_arr();
		//update range with lesser calls
		cin>>l>>r;
		cin>>val;
		update_range_naive_lower_calls(0,0,arr.size()-1,l,r,val);
		show_tnodes();
		show_arr();
	}
	void show_tnodes() {
		for(long i=0;i<tnodes.size();i++)
			cout<<tnodes[i].val<<" ";
		cout<<endl;
	}
	void show_arr() {
		for(long i=0;i<arr.size();i++)
			cout<<arr[i].val<<" ";
		cout<<endl;
	}
};
int main(){
	long n;
	cin>>n;
	segment_tree st(n);	
	st.build_segment_tree(0,0,st.arr.size()-1);
	st.show_arr();
	st.show_tnodes();
	st.update_query();
	while(1){
		long l,r;
		cin>>l>>r;
		cout<<st.query_range(0,0,st.arr.size()-1,l,r)<<endl;
	}

	return 0;
}