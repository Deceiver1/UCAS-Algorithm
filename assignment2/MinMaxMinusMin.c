#include <stdio.h>

int max(int a, int b);
int min(int a, int b);
int minest(int *a, int length);

int main()
{

    int n, k;
    int *s;
    int *result;
    int *f1, *f2, *g1, *g2;
    scanf("%d %d", &n, &k);

    s  = (int *)malloc(sizeof(int) * n);
    f1 = (int *)malloc(sizeof(int) * n);
    f2 = (int *)malloc(sizeof(int) * n);
    g1 = (int *)malloc(sizeof(int) * n);
    g2 = (int *)malloc(sizeof(int) * n);
    result = (int *)malloc(sizeof(int) * (n - k + 1));

    int temp;
    int i = 0;
    while (i < n)
    {
        scanf("%d", &temp);
        char c = getchar();
        s[i++] = temp;
    }

    f1[0] = s[0];
    f2[0] = s[0];
    g1[n - 1] = s[n - 1];
    g2[n - 1] = s[n - 1];

    for (i = 1; i < n; i++)
    {
        if (s[i] > f1[i - 1])
        {
            f1[i] = s[i];
        }
        else
        {
            f1[i] = f1[i - 1];
        }

        if (s[i] < f2[i - 1])
        {
            f2[i] = s[i];
        }
        else
        {
            f2[i] = f2[i - 1];
        }
    }

    for (i = n - 2; i >= 0; i--)
    {
        if (s[i] > g1[i + 1])
        {
            g1[i] = s[i];
        }
        else
        {
            g1[i] = g1[i + 1];
        }

        if (s[i] < g2[i + 1])
        {
            g2[i] = s[i];
        }
        else
        {
            g2[i] = g2[i + 1];
        }
    }

    // for(i=0;i<n;i++){
    //     printf("%d ",f1[i]);
    // }
    // printf("\n");
    // for(i=0;i<n;i++){
    //     printf("%d ",f2[i]);
    // }
    // printf("\n");
    // for(i=0;i<n;i++){
    //     printf("%d ",g1[i]);
    // }
    // printf("\n");
    // for(i=0;i<n;i++){
    //     printf("%d ",g2[i]);
    // }
    // printf("\n");

    for (i = 0; i < n - k + 1; i++)
    {
        if ((i > 0) && (i < n - k))
        {
            result[i] = max(f1[i - 1], g1[i + k]) - min(f2[i - 1], g2[i + k]);
        }
        else if (i == 0)
        {
            result[i] = g1[i + k] - g2[i + k];
        }
        else if (i == n - k)
        {
            result[i] = f1[i - 1] - f2[i - 1];
        }
    }

    int res = minest(result, n - k + 1);

    printf("%d", res);

    return 0;
}

int max(int a, int b)
{
    int c;
    if (a > b)
    {
        c = a;
    }
    else
    {
        c = b;
    }
    return c;
}

int min(int a, int b)
{
    int c;
    if (a < b)
    {
        c = a;
    }
    else
    {
        c = b;
    }
    return c;
}

int minest(int *a, int length)
{
    int x = 2147483646;
    for (int i = 0; i < length; i++)
    {
        if (a[i] < x)
        {
            x = a[i];
        }
    }
    return x;
}
