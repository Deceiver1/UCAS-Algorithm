#include <stdio.h>

int order_sub(int *s, int n);

int main()
{

    int n, *s;
    scanf("%d", &n);
    s = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &s[i]);
    }

    printf("%d", order_sub(s, n));

    return 0;
}

int order_sub(int *s, int n)
{
    if (n <= 0)
        return n;
    int stack[n], i = 0, top = 0, j;
    int low, high, mid;

    stack[top++] = s[0];

    for (i = 1; i < n; i++)
    {
        if (s[i] > stack[top - 1])
            stack[top++] = s[i];
        else
        {
            low = 0;
            high = top - 1;
            while (high >= low)
            {
                mid = (low + high) / 2;
                if (stack[mid] >= s[i])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            stack[high + 1] = s[i];
        }
    }
    return top;
}
