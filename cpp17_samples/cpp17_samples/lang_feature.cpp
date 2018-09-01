#include "pch.h"

#include <cstdio>
#include <ostream>

template < typename ... Types >
auto create_labeling_str( Types ... args )
{
    int i = 0;
    auto f = [ &ref_i = i ]( std::string s ){
        char str_buf[ 256 ];
        sprintf_s( str_buf, sizeof( str_buf ), "[%04d] %s\n", ref_i++, s.c_str() );
        return std::string( str_buf );
    };
    return ( f( args ) + ...  );
}

void fold_sample()
{
    std::cout << create_labeling_str( "hoge", "fuga" ) << std::endl;
    std::cout << create_labeling_str( "one", "two", "three" ) << std::endl;
}