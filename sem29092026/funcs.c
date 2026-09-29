#include <time.h>

// void _hello(int k)
// {
//     for (int i = 0; i < k; i++)
//     {
//         printf("hello, world!");
//     }

// }
int _max(int x, int y)
{
    if (x > y)
        return x;
    return y;
}

int main()
{
    printf("Enter 2 num: ");
    int a = 0, b = 0;
    // int n = 0;
    scanf('%d%d', &a, &b);
    // _hello(n);
    int c = _max(a, b);
    printf("MAX = %d", &c);
    return 0;
}