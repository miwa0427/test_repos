// main.cpp : Defines the entry point for the console application.
//

#include "pch.h"

#include <iostream>
#include <algorithm>
#include <execution>

template < typename T, typename T2 >
bool check_container_contents( T const & container, T2 pred )
{
    return std::all_of( std::execution::par,
                        std::begin( container ), std::end( container ),
                        pred );
}

int main()
{
    std::vector< int > vec;
    for( int i = 0; i < 100; i++ )
        vec.push_back( i );

    auto less_than100 = []( auto x ){ return x < 100; };
    auto is_even_num = []( auto x ){ return ( ( x % 2 ) == 0 ) ; };
    auto is_odd_num = []( auto x ){ return ( ( x % 2 ) != 0 ); };

    printf( "コンテナの全要素は100より小さい？ -> %s\n", check_container_contents( vec, less_than100 ) ? "真" : "偽" );
    printf( "コンテナの全要素は偶数？          -> %s\n", check_container_contents( vec, is_even_num ) ? "真" : "偽" );
    printf( "コンテナの全要素は奇数？          -> %s\n", check_container_contents( vec, is_odd_num ) ? "真" : "偽" );

    // 詰め直す
    printf( "-----------------------------------------\n"
            "コンテナ詰め直し\n"
            "-----------------------------------------\n");
    vec.clear();
    for( int i = 0; i < 100; i += 2 )
        vec.push_back( i );

    printf( "コンテナの全要素は100より小さい？ -> %s\n", check_container_contents( vec, less_than100 ) ? "真" : "偽" );
    printf( "コンテナの全要素は偶数？          -> %s\n", check_container_contents( vec, is_even_num ) ? "真" : "偽" );
    printf( "コンテナの全要素は奇数？          -> %s\n", check_container_contents( vec, is_odd_num ) ? "真" : "偽" );
}
