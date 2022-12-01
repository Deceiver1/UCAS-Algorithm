#include <stdio.h>
#include <stdlib.h>
typedef int BOOL;
#define TRUE 1
#define FALSE 0

int isPrime(int a);

int main()
{

    int i, n;
    int *s;
    scanf("%d", &n);
    s = (int *)malloc(sizeof(int) * n);
    BOOL result;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &s[i]);
    }


    
    for (i = 0; i < n; i++)
    {
        result = isPrime(s[i]);

        if (result == TRUE)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}

BOOL isPrime(int n)
{
    if (n <= 1)
        return FALSE;

    if (n == 2 || n == 3)
        return TRUE;

    if (n % 6 != 1 && n % 6 != 5)
        return FALSE;
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return FALSE;
    }
    return TRUE;
}
