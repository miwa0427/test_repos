#include "pch.h"

#include <string>
#include <iostream>
#include <algorithm>
#include <execution>

std::string
to_bool_str( bool b )
{
    // HStringからstd::string変換を試す
    winrt::hstring hs = b ? L"true" : L"false";
    return winrt::to_string( hs );
}

template < typename T, typename T2 >
bool check_container_contents( T const & container, T2 pred )
{
    return std::all_of( std::execution::par,
                        std::begin( container ), std::end( container ),
                        pred );
}

void para_sample1( void )
{
    std::cout << __func__ << std::endl;

    std::vector< int > vec;
    for( int i = 0; i < 100; i++ )
        vec.push_back( i );

    auto less_than100 = []( auto x ){ return x < 100; };
    auto is_even_num = []( auto x ){ return ( ( x % 2 ) == 0 ); };
    auto is_odd_num = []( auto x ){ return ( ( x % 2 ) != 0 ); };

    std::cout << "コンテナ要素チェック" << std::endl;
    printf( "less_than100 -> %s\n", to_bool_str( check_container_contents( vec, less_than100 ) ).c_str() );
    printf( "is_even_num  -> %s\n", to_bool_str( check_container_contents( vec, is_even_num ) ).c_str() );
    printf( "is_odd_num   -> %s\n", to_bool_str( check_container_contents( vec, is_odd_num ) ).c_str() );

    // 詰め直す
    printf( "-----------------------------------------\n"
            "コンテナ詰め直し\n"
            "-----------------------------------------\n" );
    vec.clear();
    for( int i = 0; i < 100; i += 2 )
        vec.push_back( i );

    printf( "less_than100 -> %s\n", to_bool_str( check_container_contents( vec, less_than100 ) ).c_str() );
    printf( "is_even_num  -> %s\n", to_bool_str( check_container_contents( vec, is_even_num ) ).c_str() );
    printf( "is_odd_num   -> %s\n", to_bool_str( check_container_contents( vec, is_odd_num ) ).c_str() );
}

