#include <stdio.h>
#include <stdlib.h>

#define N 10000UL

void
find_zs(const int n){

    printf("在N之前的质数的是： ");
    printf("\t2\t");
    for(int i = 1; i <= N; i++)
    {
        for(int j = 2; j < i; j++)
        {
            if(i % j == 0)
            {
                break;
            }
            if(i - 1 == j)
            {
                printf("%d\t",i);
            }
        }
    }
    printf("\n");
    return;

}



int
main()
{
    find_zs(N);
    return 0;
}

