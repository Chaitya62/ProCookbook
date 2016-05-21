/*Bubble Sort
Written by Chaitya Shah
*/
#include<iostream>
#include<stdlib.h> /* for malloc and calloc */
#include<ctime>  /*for execution time */
using namespace std;
int start_watch;
typedef long long datatype;  //replace long long with desired datatype
int bubble_sort(datatype *A,datatype N){
    start_watch = clock();
    int swap = true;
    datatype c = 0;
    datatype temp; //fpr swapping
    while(swap){                                //if no swap array is sorted
        swap = false;
        for(datatype i=0;i<N-1-c;i++){
                if(A[i]>A[i+1]){
                temp = A[i];
                A[i] = A[i+1];
                A[i+1] = temp;
                swap = true;
                }

        }
        c++;   //after n loops nth largest element is at right place
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

    /*Bubble Sort  */
    bubble_sort(A,N);
    for(int i=0;i<N;i++) cout<<"\n"<<A[i]<<" ";
    free(A);
    float stop_watch = clock();
    cout<<"\n Execution time :   "<<(stop_watch-start_watch)/CLOCKS_PER_SEC<<" seconds"<<endl;
    return 0;
}



