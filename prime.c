#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

// If bool not present (pre C98). 
// Warning: causes issue with memset as default enum size is int.
// typedef enum
// {
//     false,
//     true = !false
// } bool;
bool isPrime(int n);
void sieve_of_eratoshenes(int n);

int main()
{
    int MAX = 10;
    printf("Primes upto %d using 6k+1/6k-1 method:\n", MAX);
    for (int i = 0; i <= MAX; i++)
    {
        if (isPrime(i))
            printf("%d\n", i);
    }
    printf("Primes upto %d using sieve of eratosthenes method:\n", MAX);
    sieve_of_eratoshenes(MAX);
}

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    int i = 5;
    while (i * i <= n)
    {
        assert(i < n);
        // because we started from 5
        // so its 5,7, 11, 13 ...
        // note: 6k+1/6k-1 method is not inverse, all primes are of this type but
        // inverse is not true. e.g. 35,25
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return false;
        }
        i += 6;
    }
}

void sieve_of_eratoshenes(int n)
{
    if (n <= 1)
        return;
    bool prime[n + 1];
    // be careful with it. For anything else than byte it gives burn (1-> 16843009)
    memset(prime, true, sizeof(prime));

    for (int i = 2; i * i <= n; i++)
    {
        if (prime[i] == true)
        {
            for (int j = 2*i; j <= n; j += i)
            {
                prime[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (prime[i])
            printf("%d\n", i);
    }
}
