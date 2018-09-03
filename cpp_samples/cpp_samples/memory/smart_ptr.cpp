#include "pch.h"

#include <cstdio>
#include <memory>

void smart_ptr_sample()
{
    auto custom_deleter = []( auto f ) noexcept {
        std::wcout << "file close" << std::endl;
        if( f )
            fclose( f );
    };
    // ファイルオープン失敗は考慮しない
    std::shared_ptr< FILE > pf( fopen( "test_custom_deleter.txt", "wt" ), custom_deleter );
    fputs( "&*   でファイルポインタを引く\n", &*pf );
    fputs( "get()でファイルポインタを引く\n", pf.get() );
}
