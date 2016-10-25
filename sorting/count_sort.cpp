/*Count Sort
Written by Chaitya Shah
*/
#include<iostream>
#include<stdlib.h> /* for malloc and calloc */
#include<ctime>  /*for execution time */
using namespace std;
int start_watch;
typedef long long datatype;  //replace long long with desired datatype
int count_sort(datatype *A,datatype N,datatype max_){
    start_watch = clock();
    datatype *B;
    B = new datatype[max_+1]();
    for(datatype i = 0;i<N;i++){
            B[A[i]]++;
    }
    datatype j = 0;
    for(datatype i = 0;i<max_+1;i++){
        while(B[i]!=0){
            A[j] = i;
            B[i]--;
            j++;
        }
    }
    delete [] B;
    return 0;

}

int main(){

    /* Taking input */
    datatype *A,N,max_=0;
    //cout<<"Enter the number of elements in the array: ";
    //cin>>N;
    N = 200000; //enter the numberOFTestCases here
    A = (datatype *) malloc(N*sizeof(datatype));//Can also use calloc()
    for(int i = 0;i<N;i++){

            cin>>A[i];
            if(A[i]>max_) max_ = A[i];
    }

    /*Bubble Sort  */
    count_sort(A,N,max_);
    for(int i=0;i<N;i++) cout<<"\n"<<A[i]<<" ";
    free(A);
    float stop_watch = clock();
    cout<<"\n Execution time :   "<<(stop_watch-start_watch)/CLOCKS_PER_SEC<<" seconds"<<endl;
    //cin>>N;
    return 0;
}



