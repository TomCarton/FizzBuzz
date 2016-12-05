// Fizzbuzz
// 

#include <stdio.h>


int main(int argc, const char *argv[])
{
    for (unsigned int i = 1; i <= 100; ++i)
    {
        int fnd = 0;

        if (i % 3 == 0)
        {
            printf("Fizz");

            fnd = 1;
        }

        if (i % 5 == 0)
        {
            printf("Buzz");

            fnd = 1;
        }

        if (fnd == 0)
        {
            printf("%d", i);
        }

        printf("\n");
    }

    return 0;
}
