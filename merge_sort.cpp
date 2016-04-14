/*Merge Sort (Divide & Conquer) */
#include<iostream>
#include<stdlib.h>  /* malloc, free, rand */
using namespace std;
int A[]= {1,123,121,5432,22,221,13423,21,13,21,21,2134}; //here you place your array
int merge_(int ,int );  //
int merge_sort(int first ,int last){
    if(first==last) return 0 ;
    cout<<"First = "<<first<<"last = "<<last;
    int mid;
    if((last-first)<2) merge_(first,last);
    mid = first + (last-first)/2;
    merge_sort(first,mid);
    merge_sort(mid+1,last);
    merge_(first,last);

    return 0;
}
int merge_(int c,int b){   //This guy merges the sub-arrays
    int s = c+b;
    int j=0,k=0,temp;
    for(int i=0;i<s;i++){
        cout<<"j = "<<j<<"k= "<<k<<endl;
        if(j==c || k==b) break;
        if(A[j]>A[c+k]){
            temp = A[j];
            A[j] = A[c+k];
            A[c+k] = temp;
            k++;
        }
        else j++;

    }
    return 0;
}
int main(){
         /*For taking an input
    int N;
    cin>>N;
    A = (int*) malloc(N);
    for(int i=0;i<N;i++){
        cin>>*(A+i);
    }
    */
    int n = sizeof(A)/sizeof(int);
    cout<<n<<endl;
    merge_sort(0,n-1);
    for(int i=0;i<n;i++){
        cout<<*(A+i)<<" ";
    }
    int a;
    cin>>a;

    return 0;
}
