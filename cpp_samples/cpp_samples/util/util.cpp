#include "pch.h"

#include <iomanip>

struct UnknownAddrType{
    auto operator&( void ){ return 0xdeadbeaf; }
};

template < typename T >
void print_addr( std::wstring prefix,T t )
{
    std::wcout << std::setbase( 16 ) << prefix << ( &t ) << std::endl;
}

template < typename T >
void print_addr2( std::wstring prefix, T t )
{
    std::wcout << std::setbase( 16 ) << prefix << std::addressof( t ) << std::endl;
}

void util_sample()
{
    int hoge = 0;
    UnknownAddrType hoge2;

    print_addr( L"int             hoge  addr is : ", hoge );
    print_addr( L"UnknownAddrType hoge2 addr is : ", hoge2 );

    print_addr2( L"int             hoge  addr is : ", hoge );
    print_addr2( L"UnknownAddrType hoge2 addr is : ", hoge2 );
}

