/*
Author: Deepak Ahire
Email: ahiredeepak20@gmail.com
ORCID: https://orcid.org/0000-0002-9174-0797
*/

//Code to demonstrate sequential execution of 2 parallel regions created using OpenMP API

//Expected Output: Both 100 and 200 should always be printed before 10000, 20000, 30000, and 40000.

#include <omp.h>
#include <stdio.h>

int main(){
    
    int tid;
    
    #pragma omp parallel num_threads(2) default( shared ) private ( tid ) 
    {
        tid = omp_get_thread_num();
        
        printf("%d\n", (tid+1)*100);
    }
    
    #pragma omp parallel num_threads(4) default( shared ) private ( tid ) 
    {
        tid = omp_get_thread_num();
        
        printf("%d\n", (tid+1)*10000);
    }
    
    return 0;
}

