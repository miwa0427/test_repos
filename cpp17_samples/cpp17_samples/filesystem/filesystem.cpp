#include "pch.h"

#include <regex>
#include <ostream>
#include <filesystem>
#include <system_error>

void filesystem_sample( void )
{
    namespace fs = std::filesystem;
    using recurse_dir_iter = fs::recursive_directory_iterator;
    auto insert_separator = []{ std::cout << "\n-------------------------------------------------\n"; };

    std::wcout << "ディレクトリ情報表示( std::copy()版 )" << std::endl;
    std::copy( recurse_dir_iter( "." ), recurse_dir_iter(),
               std::ostream_iterator< fs::path >( std::cout, "\n" ) );
    insert_separator();

    std::wcout << "ディレクトリ情報表示( recursive_directory_iterator版 )" << std::endl;
    for( auto entry : recurse_dir_iter( "." ) )
        std::cout << entry.path() << std::endl;
    insert_separator();

    std::wcout << "ディレクトリ作成( ./test_dir/a/b/c )" << std::endl;
    fs::path dir_name( "./test_dir/a/b/c" );
    if( !fs::exists( dir_name ) )
        fs::create_directories( dir_name );
    insert_separator();

    std::wcout << "ファイルコピー動作" << std::endl;
    auto backup_dirname = "./test_dir/backup";
    fs::path dir_backup( backup_dirname );
    if( !fs::exists( dir_backup ) )
        fs::create_directory( dir_backup );
    fs::directory_iterator cur_start( "." ), cur_end;
    auto filter = [ dir_backup ]( fs::path base_path ) noexcept {
        // 正規表現での拡張子マッチはこんな感じ
        // if( std::regex_match( path.string(), std::regex( ".*cpp$" ) ) )
        if( base_path.extension().string() == ".cpp" )
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
    std::for_each( cur_start, cur_end, filter );
}