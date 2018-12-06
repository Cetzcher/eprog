#include <stdio.h>

int main()
{
    int vec[5] = {1, 3, 5, 7, 9};
    int i = 0;
    for (i = 0; i < 5; i++)
    {
        printf("0) %p: %d\n", vec[i], (vec + i));   // vec[i]: Addresse des arrays an der stelle arrayStart +  i
        printf("1) %p: %d\n", (vec + i), vec[i]);   // das gleiche wie oben aber mit anderer Schreibweise.
        printf("2) %p: %d\n", &vec[i], *(vec + i)); // &vec[i] addresse des Elements von vec an der stelle i: dem Wert an der Stelle i.
        printf("3) %p: %d\n\n", &vec[i], *vec + i); // *vec = 1 damit 1 + i
    }
}