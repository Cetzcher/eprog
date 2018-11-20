#include <stdio.h>
#include <limits.h>

int length = 0;

void minMaxMean(int x[length], double* min, double* max, double* mean ) {
    int i;
    *min = INT_MAX, *max = INT_MIN, *mean = 0;
    for( i = 0; i < length; ++i) {
        int cur = x[i];
        if(cur < *min)
            *min = cur;
        if(cur > *max)
            *max = cur;
        *mean += cur;
    }
    *mean /= (double) length;
}


int main(){

    printf("Länge des Arrays: ");
    scanf("%d", &length);

    int x[length];
    int i;
    double min, max, mean;
    
    for(i = 0; i < length; ++i)  {
        printf("x array [%d] = ", i);
        scanf("%d", &x[i]);
    }

    minMaxMean(x, &min, &max, &mean);
    printf("Min=%lf\nMax=%lf\nMean=%lf", min, max, mean);

    return 0;
}

