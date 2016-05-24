/*Quick Sort
Written by Chaitya Shah
*/
#include<iostream>
#include<stdlib.h> /* for malloc and calloc */
#include<ctime>  /*for execution time */
using namespace std;
int start_watch;
typedef long long datatype;  //replace long long with desired datatype

inline int swap_(datatype *A,datatype a, datatype b){     // just for swapping
    datatype temp = A[a];
    A[a] = A[b];
    A[b] = temp;
    return 0;
}


datatype partition_(datatype *A,datatype lo,datatype hi){    //partitioning read about quick sort for more details
    datatype i = lo;
    datatype j = hi+1;
    datatype temp;
    while(true){
        while(A[++i]<A[lo]) if(i==hi) break;

        while(A[--j]>A[lo]) if(j==lo) break;

        if(i>=j) break;
        swap_(A,i,j);
    }
    swap_(A,lo,j);
    return j;
}
int sort_(datatype *A,datatype lo,datatype hi){     //recursive partitioning the halves
    if(hi<=lo) return 0;
    datatype j = partition_(A,lo,hi);
    sort_(A,lo,j-1);
    sort_(A,j+1,hi);
    return 0;
}
int quick_sort(datatype *A,datatype N){       //quick sort starts
    start_watch = clock();
    sort_(A,0,N-1);
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

    /*Quick Sort  */
    quick_sort(A,N);
    for(int i=0;i<N;i++) cout<<"\n"<<A[i]<<" ";
    free(A);
    float stop_watch = clock();
    cout<<"\n Execution time :   "<<(stop_watch-start_watch)/CLOCKS_PER_SEC<<" seconds"<<endl;
    //cin>>N;
    return 0;
}



