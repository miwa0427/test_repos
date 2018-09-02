#include "pch.h"

#include <vector>
#include <map>

void map_sample( void )
{
    std::wcout << __func__ << std::endl;

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
    std::wcout << __func__ << std::endl;

    struct tbl_t{
        int num = 0;
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
    std::wcout << __func__ << std::endl;

    std::vector< elem3container< int, int, int > > vec;
    vec.push_back( {   1, 0b0000'0001, 0x01 } );
    vec.push_back( {  10, 0b0000'1010, 0x0a } );
    vec.push_back( { 100, 0b0110'0100, 0x64 } );
    for( auto[ dec, bin, hex ] : vec )
        printf( "%8d %8d %04x\n", dec, bin, hex );

    std::vector< elem3container< int, winrt::hstring, double > > vec2;
    vec2.push_back( { 1, L"pi     ", 3.14159 } );
    vec2.push_back( { 2, L"Napier ", 2.71828 } );
    vec2.push_back( { 3, L"sqrt(2)", 1.41421 } );
    for( auto[ idx, str, value ] : vec2 )
        printf( "[%d] %s : %f\n", idx, winrt::to_string( str ).c_str(), value );
}