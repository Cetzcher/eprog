#include <stdio.h>
#include <stdlib.h>

double *merge(double *a, int n, double *b, int m)
{
    double *vec = malloc(sizeof(double) * (m + n));
    int curLength = 0, i = 0, j = 0;
    int garbage;
    while (curLength != n + m)
    {
        //if (j == m)
        //    for (; i < n; ++i)
        //    {
        //        vec[curLength] = a[i];
        //        curLength;
        //    }
        //else if (i == n)
        //{
        //    for (; j < m; ++j)
        //    {
        //        vec[curLength] = b[j];
        //        curLength;
        //    }
        //}
        printf("Current length: %d, i: %d j: %d, a[i]=%lf, b[j] =%lf\n", curLength, i, j, a[i], b[j]);
        for (garbage = 0; a[i] <= b[j] && i < n || j + 1  == m; ++i)
        {
            vec[curLength] = a[i];
            curLength++;
        }
        for (garbage = 0; b[j] <= a[i] && j < m || i + 1 == n; ++j)
        {
            vec[curLength] = b[j];
            curLength++;
        }
    }
    return vec;
}

int main()
{
    /* code */
    double a[] = {1, 2, 5};
    double b[] = {3, 4, 6};
    int i = 0;
    double *res = merge(b, 3, a, 3);
    for (i = 0; i < 6; ++i)
    {
        printf("A: [%d] => %lf\n", i, res[i]);
    }
    return 0;
}
