#include "pch.h"

#include <string>
#include <iostream>
#include <iomanip>

struct UnknownAddrType{
    auto operator&( void ){ return 0xdeadbeaf; }
};

template < typename T >
void print_addr( std::string prefix,T t )
{
    std::cout << std::setbase( 16 ) << prefix << ( &t ) << std::endl;
}

template < typename T >
void print_addr2( std::string prefix, T t )
{
    std::cout << std::setbase( 16 ) << prefix << std::addressof( t ) << std::endl;
}

void util_sample()
{
    int hoge = 0;
    UnknownAddrType hoge2;

    print_addr( "int             hoge  addr is : ", hoge );
    print_addr( "UnknownAddrType hoge2 addr is : ", hoge2 );

    print_addr2( "int             hoge  addr is : ", hoge );
    print_addr2( "UnknownAddrType hoge2 addr is : ", hoge2 );
}

