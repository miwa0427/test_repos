#include "pch.h"

#include <boost/log/trivial.hpp>
#include <boost/log/core.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/expressions.hpp>

void boost_logging_sample()
{
    // サンプルコードはboost.orgのものを拝借
    using namespace boost::log;

    // ロギングファイル設定
    add_file_log( R"*(./test_dir/boost_log.txt)*" );

    // ロギングレベル(warning)以上のものをロギング対象に設定
    core::get()->set_filter( trivial::severity >= trivial::warning );

    BOOST_LOG_TRIVIAL( trace ) << "A trace severity message";
    BOOST_LOG_TRIVIAL( debug ) << "A debug severity message";
    BOOST_LOG_TRIVIAL( info ) << "An informational severity message";
    BOOST_LOG_TRIVIAL( warning ) << "A warning severity message";
    BOOST_LOG_TRIVIAL( error ) << "An error severity message";
    BOOST_LOG_TRIVIAL( fatal ) << "A fatal severity message";
}