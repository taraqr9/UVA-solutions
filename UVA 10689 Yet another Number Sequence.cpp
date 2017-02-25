#include<bits/stdc++.h>
using namespace std;

//Keyword: Fibonacci number, finding cycle
//
//Algorithm:
//
//For this kind of problems, we usually have to find some cycle.
//If you don't know about pisano period, you may simulate the sequence and find out the length
//of the cycle.
//If you do, then just apply the period to this problem and you're home.
//The pisano period of the last few digits: one digit→60, two digits→300, three digits→1500,
//four digits→15000.

int main()
{
    int t, a,b, n, digit, pisano[] = { 0, 60, 300, 1500, 15000 };
    int pow10[] = { 1, 10, 100, 1000, 10000 };
    scanf( "%d", &t );

    while( t-- ){

        scanf( "%d %d %d %d", &a, &b, &n, &digit );

        n%= pisano[ digit ];
        a%= pow10[digit];
        b%= pow10[digit];

        int fibo[n];
        fibo[ 0 ] = a, fibo[ 1 ] = b;

        for( int i = 2; i < pisano[ digit ] && i <= n; ++i )
            fibo[ i ] = ( fibo[ i-1 ] + fibo[ i-2 ] ) % pow10[digit];

        printf( "%d\n", fibo[ n ] );
    }

    return 0;
}
