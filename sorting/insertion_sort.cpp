/*Insertion Sort
Written by Chaitya Shah
*/
#include<iostream>
#include<stdlib.h> /* for malloc and calloc */
#include<ctime>  /*for execution time */
using namespace std;
int start_watch;
typedef long long datatype;  //replace long long with desired datatype
int insertion_sort(datatype *A,datatype N){
    start_watch = clock();
    datatype min,temp,pointer;
    for(datatype i=0;i<N;i++){
            pointer = i;     //index of the element it will insert in the correct place
            temp = A[i];
        while(temp<A[pointer-1] && pointer>0){
            A[pointer] = A[pointer-1];
            pointer--;
        }
        A[pointer] = temp;
    }
    return 0;

}

int main(){

    /* Taking input */
    datatype *A,N;
    //cout<<"Enter the number of elements in the array: ";
    //cin>>N;
    N = 200000; //enter the numberOFTestCases here
    A = (datatype *) malloc(N*sizeof(datatype));  //Can also use calloc()
    for(int i = 0;i<N;i++) cin>>A[i];

    /*Insertion Sort  */
    insertion_sort(A,N);
    for(int i=0;i<N;i++) cout<<"\n"<<A[i]<<" ";
    free(A);
    float stop_watch = clock();
    cout<<"\n Execution time :   "<<(stop_watch-start_watch)/CLOCKS_PER_SEC<<" seconds"<<endl;
    return 0;
}



