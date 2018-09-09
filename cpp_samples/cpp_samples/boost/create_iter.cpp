#include "pch.h"

#include <ostream>
#include <algorithm>
#include <boost/iterator_adaptors.hpp>

class my_container_t{
    int arr_[ 128 ];
    int size_;

public:
    struct iterator : public boost::iterator_adaptor< iterator, int* >
    {
        iterator( int *p )
            : iterator::iterator_adaptor_( p )
        {}
    };

    my_container_t()
        : size_( sizeof( arr_ ) )
    {
        for( int i = 0; i < size_ - 1; ++i )
            arr_[ i ] = i;
    }

    iterator begin()
    {
        return iterator( arr_ );
    }

    iterator end()
    {
        return iterator( arr_ + size_ );
    }
};

void boost_create_iter_sample()
{
    my_container_t c;
    auto print_fn = []( auto x ){
        std::cout << x << std::endl;
    };
    std::for_each( c.begin(), c.end(), print_fn );
}