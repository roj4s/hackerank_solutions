#include <stdio.h>


int main(){

    int n_inputs;
    scanf("%d", &n_inputs);

    for(int i=0; i < n_inputs; i++){

        int n;
        scanf("%d", &n);

        int nums[n];
        for(int k=0; k<n; k++)
            scanf("%d", &nums[k]);

        if(n == 1){
            printf("%d\n", 1);
            continue;
        }

        int sums[n];
        sums[0] = nums[0];

        for(int k=1; k<n; k++)
            sums[k] = sums[k-1] + nums[k];

        bool found = false;
        for(int k=1; k < n-1; k++){
            int prevsum = sums[k-1];
            int nextsum = sums[n-1] - sums[k];
            if(prevsum == nextsum){
                found = true;
                printf("%d\n", k+1);
                break;
            }

        }

        if(not found)
            printf("%d\n", -1);
    }

}
