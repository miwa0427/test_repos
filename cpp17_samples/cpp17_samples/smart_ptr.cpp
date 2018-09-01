#include "pch.h"

#include <cstdio>
#include <iostream>
#include <memory>

void smart_ptr_sample()
{
    // ファイルオープン失敗は考慮しない
    auto custom_deleter = []( auto f ) noexcept{
        std::cout << "file close" << std::endl;
        if( f ) fclose( f );
    };
    std::shared_ptr< FILE > pf( fopen( "test_custom_deleter.txt", "wt" ), custom_deleter );
    fputs( "&*   でファイルポインタを引く\n", &*pf );
    fputs( "get()でファイルポインタを引く\n", pf.get() );
}
