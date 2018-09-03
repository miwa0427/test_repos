#include "pch.h"

#include <cstdio>
#include <ostream>
#include <iomanip>

void lambda_capture_sample()
{
    int i = 0;
    // コピーキャプチャ([=])変数はデフォルトでconst扱いなので、
    // キャプチャ環境で変更する場合はmutable指定が必要
    auto print_increased_i = [=]() mutable {
        i++; // mutable指定しないとコンパイルエラー
        std::wcout << L"[capture]   i is " << i << std::endl;
    };
    print_increased_i(); // i is 1

    // コピーキャプチャは呼び元の変数に影響を及ぼさない
    std::wcout << L"[outer env] i is " << i << std::endl; // i is 0

    // 参照キャプチャー([&])はiへの参照を扱うので、呼び元のiに対して変更が行える
    auto modify_i = [ & ](){
        i = 12345678;
    };
    modify_i();
    std::wcout << std::setbase( 10 ) << L"[modified]  i is " << i << std::endl; // i is 12345678

    // 複数変数のコピーキャプチャ
    int x = 100;
    int y = 200;
    int z = 300;
    auto copy_capture = [ copy_x = x, copy_y = y, copy_z = z ] {
        printf( "[copy_cap] %d %d %d\n" ,copy_x, copy_y, copy_z );
    };
    copy_capture(); // -> 100 200 300

    // 複数変数の参照キャプチャ(初期化ラムダキャプチャーはC++14の機能)
    // 参照なので呼び元の変数を変更する
    auto ref_capture = [ &ref_x = x, &ref_y = y, &ref_z = z ] {
        // キャプチャ元変数の参照なので、int x,y,zの値を変更する
        ref_x *= 2;
        ref_y *= 2;
        ref_z *= 2;
        printf( "[ref_cap]  %d %d %d\n", ref_x, ref_y, ref_z );
    };
    ref_capture(); // -> 200 400 600

    // 参照キャプチャで変更されているので、呼び元のx,y,zも変更されている
    printf( "[out env]  %d %d %d\n", x, y, z ); // -> 200 400 600

    // 再度コピーキャプチャを呼び出すも、ラムダキャプチャは
    // 定義時点でのx,y,zのコピーを保持するので、変更前の値が表示される
    copy_capture(); // -> 100 200 300
}

template < typename ... Types >
auto strcat_plus( Types ... args )
{
    auto to_str = []( auto p ){
        return std::wstring( p );
    };
    return ( ... + to_str( args ) );
}

void fold_sample()
{
    // 任意個数の文字列を結合するstrcat()
    std::wcout << strcat_plus( L"only one" ) << std::endl;
    std::wcout << strcat_plus( L"Hello ", L"world." ) << std::endl;
    std::wcout << strcat_plus( L"one ", L"two ", L"three" ) << std::endl;
    std::wcout << strcat_plus( L"The ", L"quick ", L"brown ", L"fox ",
                               L"jumps ", L"over ", L"the ", L"lazy ",
                               L"dog " ) << std::endl;
}