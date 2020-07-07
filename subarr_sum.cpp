#include <cstdio>

int main(){

    int n_inputs;
    scanf("%d", &n_inputs);

    for(int i=0; i< n_inputs; i++){

        int n, s;
        char space;
        scanf("%d %d", &n, &s);
        int nums [n];
        for(int j=0; j <n;j++)
            scanf("%d", &nums[j]);

        int i1 = -1;
        int i2 = 0;

        for(int j=0; j<n; j++){
            int sum = 0;
            for(int r=j; r<n; r++){
                sum += nums[r];
                if(sum == s){
                   i1 = j+1;
                   i2 = r+1;
                   break;
                }
                if(sum > s){
                    break;
                }
            }
            if(i1 != -1)
                break;
        }

        if(i1 != -1)
                printf("%d %d\n",i1, i2);
        else
            printf("%d\n", -1);

    }
    return 0;
}
