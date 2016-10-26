/*Merge Sort
Written by Chaitya Shah
*/
#include<iostream>
#include<stdlib.h> /* for malloc and calloc */
#include<ctime>  /*for execution time */
using namespace std;
int start_watch;
typedef long long datatype;  //replace long long with desired datatype

/* Merging the sorted arrays */

int merge_(datatype *A,datatype *B,datatype lo,datatype mid,datatype hi){
    datatype j,i;

    for(datatype i = lo;i<hi+1;i++) B[i] = A[i];  //copying the array to B

    j = mid+1;        //pointer of second half
    i = lo;          //pointer of first half

    for(datatype k=lo;k<hi+1;k++){

        if(i>mid)           A[k] = B[j++];       //if first half is exhausted
        else if (j>hi)      A[k] = B[i++];      //if first half is exhausted
        else if (B[j]>B[i]) A[k] = B[i++];
        else                A[k] = B[j++];

    }
    return 0;

}

/*Recursive sorting (Divide and Conquer)*/

int sort_(datatype *A,datatype *B,datatype lo,datatype hi){
        if(lo==hi) return 0;            //only one element in the sub-array

        datatype mid = lo + ((hi-lo)/2);
        sort_(A,B,lo,mid);       //sorting the first half
        sort_(A,B,mid+1,hi);    //sorting the second half
        merge_(A,B,lo,mid,hi); //merging the sorted halves
        return 0;


}


int merge_sort(datatype *A,datatype N){
    start_watch = clock();
    datatype *B;      //Helping array
    B = (datatype *) malloc(N*sizeof(datatype));
    sort_(A,B,0,N-1);
    free(B);
    return 0;
}

int main(){

    /* Taking input */
    datatype *A,N;

    //cout<<"Enter the number of elements in the array: ";
    //cin>>N;

    N = 200000; //enter the numberOFTestCases here
    A = (datatype *) calloc(N,sizeof(datatype));      //can also use malloc
    for(datatype i = 0;i<N;i++) cin>>A[i];


    /*Merge Sort  */
    merge_sort(A,N);
    for(datatype i=0;i<N;i++) cout<<"\n"<<A[i]<<" ";
    free(A);

    float stop_watch = clock();
    cout<<"\n Execution time :   "<<(stop_watch-start_watch)/CLOCKS_PER_SEC<<" seconds"<<endl;
    return 0;
}



