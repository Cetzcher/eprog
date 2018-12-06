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

void mergesort(double *array, int length)
{
    if (length == 2)
    {
        if (array[0] > array[1])
        {
            printf("swapping [0] %lf and [1] %lf\n", array[0], array[1]);
            double tmp = array[0];
            array[0] = array[1];
            array[1] = tmp;
        }
        return;
    } else if (length < 2) {
        return;
    }
    // wenn lenght = 6, dann 6/2 = 3 und 6 - 3 = 3
    // aber wenn length = 5 dann 5/2 = 2 (int div rundet ab) und 5 - 2 = 3
    int leftsize = length / 2;
    int rightsize = length - leftsize;
    double left[leftsize], right[rightsize];
    int i;
    for (i = 0; i < leftsize; ++i)
        left[i] = array[i];
    for (i = 0; i < length - leftsize; ++i)
        right[i] = array[leftsize + i];

    // linke seite sortieren
    mergesort(left, leftsize);
    // rechte seite sortieren
    mergesort(right, rightsize);

    // zusammenfügen der beiden sortierten listen.
    double* mergedArray = merge(left, leftsize, right, rightsize);
    for(i = 0; i < leftsize + rightsize; ++i) {
        array[i] = mergedArray[i];
    }
    // free macht den verbrauchten speicher wieder frei.
    free(mergedArray);
}

int main()
{
    int n, i;
    printf("länge =");
    scanf("%d", &n);
    double arr[n];
    for(i = 0; i < n; ++i) {
        printf("x[%d] = ", i);
        scanf("%lf", &arr[i]);
    }
    mergesort(arr, n);
    printf("Sortiert\n");
    for(i = 0; i < n; ++i) {
        printf("x[%d] = %lf\n", i, arr[i]);
    }
}