#include <stdio.h>

int findBisection(int *x, int y, int start, int end)
{
    int mid = (start + end) / 2;
    int atMid = x[mid];
    if (atMid == y)
        return atMid;
    else if ( end - start == 1)
        return -1;

    if (atMid < y)
    {
        // y is to the right.
        start = mid;
    }
    else if (atMid > y)
    {
        // y is to the left
        end = mid;
    }
    return findBisection(x, y, start, end);
}

int main(int argc, char const *argv[])
{
    int n, y;
    printf("n=");
    scanf("%d", &n);
    printf("y=");
    scanf("%d", &y);
    int x[n];
    int i;
    for (i = 0; i < n; ++i)
    {
        x[i] = i;
    }
    for (i = 0; i < n; ++i)
    {
        int valAtI = x[i];
        printf("x[%d] = %d\n", i, valAtI);
    }

    int idx = findBisection(x, y, 0, n);
    printf("At index = %d", idx);

    return 0;
}
