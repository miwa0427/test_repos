#include "pch.h"

#include <ctime>
#include <chrono>
#include <iomanip>

void time_sample( void )
{
    // 時間変換のサンプル
    using std::chrono::system_clock;
    // 現在時刻を取得
    auto cur_time_point = system_clock::now();
    // std::chrono::system_clock::time_point -> std::time_t
    auto cur_time_t = system_clock::to_time_t( cur_time_point );
    // std::time_t -> const tm*
    auto cur_const_tm_ptr = std::localtime( &cur_time_t );

    std::cout << "只今の時間は" << std::put_time( cur_const_tm_ptr, "%c" ) << "です" << std::endl;
}
