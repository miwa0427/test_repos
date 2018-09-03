#include "pch.h"

void winrt_sample( void )
{
    using namespace winrt;
    using namespace Windows::Foundation;

    init_apartment();
    Uri uri( L"http://aka.ms/cppwinrt" );
    printf( "Hello, %ls!\n", uri.AbsoluteUri().c_str() );
}
