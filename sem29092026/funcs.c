#include <time.h>

void _hello(int k)
{
    for (int i = 0; i < k; i++)
    {
        printf("hello, world!");
    }

}

int main()
{
    printf("");
    int n = 0;
    scanf('%d', &n);
    _hello(n);
    return 0;
}