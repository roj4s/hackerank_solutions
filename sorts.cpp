#include <stdio.h>

int merge(int A[],int i,int m,int f){

    int li = 0;
    int ri = 0;

    int k = i;

    int nL = m -i + 1;
    int L[nL];
    int nR = f - m;
    int R[nR];
    int Ai = i;

    for(int k=0; k < nL; k++)
        L[k] = A[k + i];

    for(int k=0; k< nR; k++)
        R[k] = A[k + m + 1];


    while(li < nL && ri < nR){

        if(L[li] <= R[ri]){
            A[k] = L[li];
            li ++;
        }
        else{
           A[k] = R[ri];
           ri ++;
        }

        k ++;

    }

    while(li < nL){
        A[k] = L[li];
        li ++;
        k ++;
    }

    while(ri < nR){
        A[k] = R[ri];
        ri ++;
        k ++;
    }
}

int merge_sort(int A[],int i, int f){

    if(i < f){
        int mid = i + (f - i)/2;
        merge_sort(A, i, mid);
        merge_sort(A, mid + 1, f);
        merge(A, i, mid, f);
    }

}

int partition(int A[],int lo,int hi){

    int p = A[lo + (hi - lo) / 2];
    int i = lo;
    for(int j=lo; j < hi; j++){

        if(A[j] < p){

            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i ++;

        }
    }

    int temp = A[hi];
    A[hi] = A[i];
    A[i] = temp;
    return i;

}

int quicksort(int A[],int lo,int hi){

    if(lo < hi){

        int p = partition(A, lo, hi);
        quicksort(A, lo, p - 1);
        quicksort(A, p + 1, hi);

    }

}


int main(){

    int n_inputs;
    scanf("%d", &n_inputs);

    for(int i=0; i < n_inputs; i++){

        int n;
        scanf("%d", &n);

        int nums[n];

        for(int j=0; j<n; j++)
            scanf("%d", &nums[j]);

        //quicksort(nums, 0, n - 1);
        merge_sort(nums, 0, n - 1);

        for(int j=0; j<n; j++)
            printf("%d ", nums[j]);

        printf("\n");

    }

}
