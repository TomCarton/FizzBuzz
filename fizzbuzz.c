// Fizzbuzz
// 
// written by Thomas CARTON
//

#include <stdio.h>


#if 'ABCD' == 0x41424344
    static const unsigned int kFizzFourCC = 'zziF';
    static const unsigned int kBuzzFourCC = 'zzuB';
#else
    static const unsigned int kFizzFourCC = 'Fizz';
    static const unsigned int kBuzzFourCC = 'Buzz';
#endif

char buffer[414];


// version 1: using tests and a temporary flag
void version_1()
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
}

// version 2: with only one branching
void version_2()
{
    char fizz[] = "Fizz\0zzz\0zzz\0";
    char buzz[] = "Buzz\0zzz\0zzz\0zzz\0zzz\0";
    char r[] = "??zz--zz";
    
    for (unsigned int i = 1; i <= 100; ++i)
    {
        sprintf(r, "%d", i);
        if (!(i % 3) || !(i % 5))
            sprintf(r, "%s%s", &fizz[4 * (i % 3)], &buzz[4 * (i % 5)]);
        printf("%s\n", r);
    }
}

// version 3: first attempt with no branching
void version_3()
{
    char zz[] = "FizzBuzz\0Fizz\0zzzzFizz\0zzzzFizz\0zzzzFizz\0zzzz"
                "Buzz\0zzzz\0zzzzzzzz\0zzzzzzzz\0zzzzzzzz\0zzzzzzzz"
                "Buzz\0zzzz\0zzzzzzzz\0zzzzzzzz\0zzzzzzzz\0zzzzzzzz";
                
    for (unsigned int i = 1; i <= 100; ++i)
    {        
        printf("%d %s\n", i, &zz[((i % 3) * 5 + i % 5) * 9]);
    }
}

// version 4: no branching at all ;)
void version_4()
{
    char *p = buffer;

    unsigned int i = 0;
    while (100 - i++)
    {
        unsigned int fizz = !(i % 3);
        unsigned int buzz = !(i % 5);

        unsigned int dec = i / 10;
        p[0] = '0' + dec;
        p[!!dec] = '0' + i % 10;
        p += (!!dec + 1) * !(fizz | buzz);

        *(unsigned int *)p = kFizzFourCC;
        p += 4 * fizz;
        
        *(unsigned int *)p = kBuzzFourCC;
        p += 4 * buzz;

        *p++ = '\n';
    }

    *p = 0;

    printf("%s", buffer);
}

int main(int argc, const char *argv[])
{
    printf("\n\nVersion 1\n---------\n\n"); version_1();
    printf("\n\nVersion 2\n---------\n\n"); version_2();
    printf("\n\nVersion 3\n---------\n\n"); version_3();
    printf("\n\nVersion 4\n---------\n\n"); version_4();

    return 0;
}
