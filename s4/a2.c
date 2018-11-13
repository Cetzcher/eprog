#include <stdio.h>

#define N 10

double check(int toCheck[N], int y[3]) {

    int i;
    for (i = 0; i < (N - 2); ++i) {
        int cur, next, next2;
        cur = toCheck[i];
        next = toCheck[ i + 1];
        next2 = toCheck[i + 2];
        if(y[0] == cur && y[1] == next && y[2] == next2) {
            return 1;
        }
    }
    return 0;
}


int main(){
    int toCheck[N];
    int y[3];
    int i;
    
    for(i = 0; i < N; ++i)  {
        printf("toCheck array [%d] = ", i);
        scanf("%d", &toCheck[i]);
    }

    for(i = 0; i < 3; ++i) {
        printf("y array [%d] = ", i);
        scanf("%d", &y[i]);
    }

    int res = check(toCheck, y);
    if(res)
        printf("Die Suche war erfolgreich");
    else
        printf("Die Suche war NICHT erfolgreich");

    return 0;
}

