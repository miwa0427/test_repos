#include "pch.h"

#include <string>
#include <iostream>
#include <ctime>
#include <chrono>
#include <iomanip>

#pragma warning( push )
#pragma warning( disable : 4996 ) 
void lambda_sample()
{
    auto print_value = []( auto val, std::string prefix = "=== ", std::string suffix = " ===" ) noexcept {
        std::cout << prefix << val << suffix << std::endl;
    };

    print_value( 1 );
    print_value( "hello world", "<<< ", " >>>" );

    // 時間変換のサンプル
    using std::chrono::system_clock;
    // 現在時刻を取得
    auto cur_time_time_point   = system_clock::now();
    // std::chrono::system_clock::time_point -> std::time_t
    auto cur_time_time_t       = system_clock::to_time_t( cur_time_time_point );
    // std::time_t -> const tm*
    auto cur_time_const_tm_ptr = std::localtime( &cur_time_time_t );
    print_value( std::put_time( cur_time_const_tm_ptr, "%c" ), "只今の時間は", "です" );
}
#pragma warning( pop )