#include "pch.h"

#include <thread>
#include <boost/lockfree/queue.hpp>
#include <boost/lockfree/stack.hpp>

const int CONTAINER_SIZE = 0x100;

template < typename T >
void lock_free_container_test( void )
{
    T container( CONTAINER_SIZE );
    std::thread push_fn( [ & ]() {
        for( int i = 0; i < CONTAINER_SIZE; ++i )
            while( !container.push( i ) ); // コンテナへデータを追加
    } );
    std::thread pop_fn( [ & ]() {
        for( int count = 0; count < CONTAINER_SIZE; count++ ) {
            int x = 0;
            if( container.pop( x ) ) // コンテナからデータを取り出し
                printf( "%3d ", x );
        }
    } ); 
    push_fn.join();
    pop_fn.join();
}

void boost_lock_free_container_sample( void )
{
    std::cout << "--- lock free queue test ---" << std::endl;
    lock_free_container_test< boost::lockfree::queue< int > >();
    std::cout << std::endl;

    std::cout << "--- lock free stack test ---" << std::endl;
    lock_free_container_test< boost::lockfree::stack< int > >();
    std::cout << std::endl;
}
