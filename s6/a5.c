#include <stdio.h>
#include <stdlib.h>

double *merge(double *a, int n, double *b, int m)
{
    double *vec = malloc(sizeof(double) * (m + n));
    int curLength = 0, i = 0, j = 0;
    for (curLength = 0; curLength < m + n; ++curLength)
    {
        if (i >= n || j >= m) // wenn eines der arrays volkommen übertragen wurde brich ab
            break;

        if (a[i] < b[j]) // x = a[i++]; ist das gleiche wie:  x = a[i]; i++;
            vec[curLength] = a[i++];
        else
            vec[curLength] = b[j++];
    }

    // die beiden loops schreiben das verbleibende restliche array (also a oder b) in vec
    while (i < n)
        vec[curLength++] = a[i++];
    while (j < m)
        vec[curLength++] = b[j++];

    return vec;
}

int main()
{
    /* code */
    int alen, blen, i;
    printf("Länge von A:");
    scanf("%d", &alen);
    printf("Länge von B:");
    scanf("%d", &blen);

    double a[alen], b[blen];
    for (i = 0; i < alen; ++i)
    {
        printf("A[%d] = ", i);
        scanf("%lf", &a[i]);
    }
    for (i = 0; i < blen; ++i)
    {
        printf("B[%d] = ", i);
        scanf("%lf", &b[i]);
    }
    double *res = merge(a, alen, b, blen);
    for (i = 0; i < alen + blen; ++i)
    {
        printf("Merged[%d] = %lf\n", i, res[i]);
    }
    return 0;
}
