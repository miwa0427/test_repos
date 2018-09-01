#include "pch.h"

#include <string>
#include <iostream>
#include <algorithm>
#include <execution>

template < typename container_t , typename predicate >
bool check_container_contents( container_t const & container, predicate pred )
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

    auto less_than100 = []( auto x ) noexcept { return x < 100; };
    auto is_even_num = []( auto x ) noexcept { return ( ( x % 2 ) == 0 ); };
    auto is_odd_num = []( auto x ) noexcept { return ( ( x % 2 ) != 0 ); };
    auto bool2str = []( bool b ) noexcept {
        // HStringからstd::string変換を試す
        winrt::hstring hs = b ? L"true" : L"false";
        return winrt::to_string( hs );
    };

    std::cout << "コンテナ要素チェック" << std::endl;
    printf( u8"less_than100 -> %s\n", bool2str( check_container_contents( vec, less_than100 ) ).c_str() );
    printf( u8"is_even_num  -> %s\n", bool2str( check_container_contents( vec, is_even_num ) ).c_str() );
    printf( u8"is_odd_num   -> %s\n", bool2str( check_container_contents( vec, is_odd_num ) ).c_str() );

    // 詰め直す
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "コンテナ詰め直し" << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
    vec.clear();
    for( int i = 0; i < 100; i += 2 )
        vec.push_back( i );

    printf( u8"less_than100 -> %s\n", bool2str( check_container_contents( vec, less_than100 ) ).c_str() );
    printf( u8"is_even_num  -> %s\n", bool2str( check_container_contents( vec, is_even_num ) ).c_str() );
    printf( u8"is_odd_num   -> %s\n", bool2str( check_container_contents( vec, is_odd_num ) ).c_str() );
}

