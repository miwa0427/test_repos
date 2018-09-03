#include "pch.h"

#include <regex>
#include <ostream>
#include <filesystem>
#include <system_error>

void filesystem_sample( void )
{
    namespace fs = std::filesystem;
    using recurse_dir_iter = fs::recursive_directory_iterator;
    auto insert_separator = []{
        std::cout << "\n-------------------------------------------------\n";
    };

    std::wcout << "ディレクトリ情報表示( std::copy()版 )" << std::endl;
    std::copy( recurse_dir_iter( "." ), recurse_dir_iter(),
               std::ostream_iterator< fs::path >( std::cout, "\n" ) );
    insert_separator();

    std::wcout << "ディレクトリ情報表示( 範囲for文版 )" << std::endl;
    for( auto entry : recurse_dir_iter( "." ) )
        std::cout << entry.path() << std::endl;
    insert_separator();

    // パス文字列を表示する為、Raw文字列を試す
    std::wcout << R"***(ディレクトリ作成( .\test_dir\a\b\c ))***" << std::endl;
    auto util_create_dir = []( auto dirname ){
        fs::path dir_path( dirname );
        if( !fs::exists( dir_path ) )
            fs::create_directories( dir_path );
    };
    util_create_dir( R"(.\test_dir\a\b\c)" );
    insert_separator();

    std::wcout << "ファイルコピー動作" << std::endl;
    auto dir_backup = R"(.\test_dir\backup\)";
    util_create_dir( dir_backup );
    auto filtered_backup = [ dir_backup ]( fs::path base_path ) noexcept {
        // 最初の条件文はバックアップディレクトリを除外する為のもの
        if( !( std::regex_match( base_path.string(), std::regex( R"(.*test_dir.*)" ) ) ) && 
             ( base_path.extension().string() == ".cpp" ) )
        {
            std::cout << "[copy]" << base_path << " -> " << dir_backup << std::endl;
            std::error_code  fs_err;
            fs::copy( base_path, dir_backup, fs::copy_options::update_existing, fs_err );
            if( fs_err )
            {
                std::cout << fs_err.value() << " | " << fs_err.message()
                          << base_path << " -> " << dir_backup << std::endl;
            }
        }
    };

    std::for_each( recurse_dir_iter( "." ), recurse_dir_iter(), filtered_backup );
}