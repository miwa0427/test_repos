#include "pch.h"

#include <ctime>
#include <chrono>
#include <iomanip>

void lambda_sample( void )
{
    // 任意の変数値を表示する関数を定義する
    auto print_value = []( auto val, std::string prefix = "=== ", std::string suffix = " ===" ) noexcept {
        std::cout << prefix << val << suffix << std::endl;
    };
    print_value( 1 );
    print_value( "hello world", "<<< ", " >>>" );
}
