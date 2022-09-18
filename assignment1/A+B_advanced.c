#include <stdio.h>
#include <string.h>
#define len 201
int ans[len];
int compare(int *num1, int *num2);
//比较两个数组形式数字大小
int compare(int *num1, int *num2)
{
    int i, j;
    for (i = len; num1[i] == 0; i--)
        ;
    for (j = len; num2[j] == 0; j--)
        ;
    if (i < j)
        return -1;
    else if (i > j)
        return 1;
    else
    {
        for (; i >= 0; i--)
        {
            if (num1[i] > num2[i])
                return 1;
            else if (num1[i] < num2[i])
                return -1;
        }
        return 0;
    }
}
void add(int *num1, int *num2);
void sub(int *num1, int *num2);
int array_length(int *a);
int array_length(int *a)
{
    int i;
    for (i = len - 1; i > 0; i--)
    {
        if (a[i] != 0)
            break;
    }
    return i + 1;
}

void add(int *add1, int *add2)
{
    int i;
    for (i = 0; i < len; i++)
    {
        ans[i] = ans[i] + add1[i] + add2[i];
        if (ans[i] >= 10)
        {
            ans[i] -= 10;
            ans[i + 1]++;
        }
    }
}

void sub(int *sub1, int *sub2)
{
    int i = 0;
    for (i = 0; i < len; i++)
    {
        if (sub1[i] < sub2[i])
        {
            for (int j = i + 1; j < len; j++)
            {
                if (sub1[j] == 0)
                {
                    sub1[j] = 9;
                }
                else
                {
                    sub1[j]--;
                    sub1[i] += 10;
                    break;
                }
            }
        }
        ans[i] = sub1[i] - sub2[i];
    }
}
int main()
{
    char a[len], b[len]; // 存的是你要输入的数字
    int s1 = 1;
    int s2 = 1; //符号位

    scanf("%s", &a);
    scanf("%s", &b);
    int num1[len];
    int num2[len];
    int i = 0;
    int j;
    for (int i = 0; i < len; i++)
    {
        num1[i] = 0;
        num2[i] = 0;
    }

    for (i = 0, j = strlen(a) - 1; j >= 0; i++, j--)
    {
        if (a[j] == '-')
        {
            s1 = -1;
            break;
        }
        num1[i] = a[j] - '0';
    }

    for (i = 0, j = strlen(b) - 1; j >= 0; i++, j--)
    {
        if (b[j] == '-')
        {
            s2 = -1;
            break;
        }
        num2[i] = b[j] - '0';
    }
    //低位数加减
    long long int x=0;
    long long int y=0;
    if(array_length(num1)<9&&array_length(num2)<9){
        for(int i=8;i>=0;i--){
            x+=num1[i];
            x*=10;
        }
        x/=10;
        x*=s1;
        for(int i=8;i>=0;i--){
            y+=num2[i];
            y*=10;
        }
        y/=10;
        y*=s2;
        // printf("%lld\n",x);
        // printf("%lld\n",y);
        printf("%lld",x+y);
    }
    //加法
    else if (s1 * s2 == 1)
    {
        add(num1, num2);
        if (s1 == -1)
            printf("-");
        for (i = 0, j = array_length(ans) - 1; j >= 0; i++, j--)
        {
            printf("%d", ans[j]);
        }
    }
    //减法
    else if (s1 * s2 == -1)
    {
        int h;
        int sign = 1;
        if ((h = compare(num1, num2)) == 1) //==1 num1>num2
        {
            sign = s1;
            sub(num1, num2);
            if (sign == -1)
                printf("-");
            for (i = 0, j = array_length(ans) - 1; j >= 0; i++, j--)
            {
                printf("%d", ans[j]);
            }
        }
        else if ((h = compare(num1, num2)) == -1)
        { //==-1 num1<num2
            sign = s2;
            sub(num2, num1);
            if (sign == -1)
                printf("-");
            for (i = 0, j = array_length(ans) - 1; j >= 0; i++, j--)
            {
                printf("%d", ans[j]);
            }
        }
        else{
            printf("0");
        }
    }
    return 0;
}
