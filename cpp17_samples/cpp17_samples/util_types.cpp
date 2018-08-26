#include "pch.h"

#include <iostream>
#include <vector>
#include <map>

void map_sample( void )
{
    std::cout << __func__ << std::endl;

    std::map< int, std::string > tbl
    {
        { 1, "one" },
        { 2, "two" },
        { 3, "three" },
    };
    for( auto[ num, s ] : tbl )
        printf( "%2d : %s\n", num, s.c_str() );
}

void map_sample2( void )
{
    std::cout << __func__ << std::endl;

    struct tbl_t{
        int num;
        std::string s;
    };

    tbl_t tbl[ 3 ];
    tbl[ 0 ] = { 1, "one" };
    tbl[ 1 ] = { 2, "two" };
    tbl[ 2 ] = { 3, "three" };
    for( auto[ num, s ] : tbl )
        printf( "%2d : %s\n", num, s.c_str() );
}

template < typename X, typename Y, typename Z >
struct elem3container{
    X x;
    Y y;
    Z z;
};

void tuple_sample( void )
{
    std::cout << __func__ << std::endl;

    std::vector< elem3container< int, int, int > > vec;
    vec.push_back( { 1, 2, 3 } );
    for( auto[ x, y, z ] : vec )
        printf( "%d %d %d\n", x, y, z );

    std::vector< elem3container< int, double, winrt::hstring > > vec2;
    vec2.push_back( { 1, 3.14, L"hoge" } );
    for( auto[ x, y, z ] : vec2 )
        printf( "%d %f %s\n", x, y, winrt::to_string( z ).c_str() );
}