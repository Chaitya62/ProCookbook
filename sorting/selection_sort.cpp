/*Selection Sort
Written by Chaitya Shah
*/
#include<iostream>
#include<stdlib.h> /* for malloc and calloc */
#include<ctime>  /*for execution time */
using namespace std;
int start_watch;
typedef long long datatype;  //replace long long with desired datatype
int selection_sort(datatype *A,datatype N){
    start_watch = clock();
    datatype min,temp;
    for(datatype i = 0;i<N;i++){
            min = i;
        for(datatype j = i;j<N;j++){
            if(A[min]>A[j]){
                min = j;
            }
        }
        if(min!=A[i]){
            temp = A[i];
            A[i] = A[min];
            A[min] = temp;
        }
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

    /*Selection Sort  */
    selection_sort(A,N);
    for(int i=0;i<N;i++) cout<<"\n"<<A[i]<<" ";
    free(A);
    float stop_watch = clock();
    cout<<"\n Execution time :   "<<(stop_watch-start_watch)/CLOCKS_PER_SEC<<" seconds"<<endl;
    return 0;
}



