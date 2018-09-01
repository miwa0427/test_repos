// main.cpp : Defines the entry point for the console application.
//

#include "pch.h"

#include <iostream>
#include <string>

void para_sample1( void );
void map_sample( void );
void map_sample2( void );
void tuple_sample( void );
void lambda_sample( void );
void util_sample( void );
void smart_ptr_sample( void );
void fold_sample( void );
void lambda_capture_sample();

int main()
{
    std::cout << "\n\n\n=== Paralells sample ===" << std::endl;
    para_sample1();

    std::cout << "\n\n\n=== map sample ===" << std::endl;
    map_sample();
    map_sample2();

    std::cout << "\n\n\n=== tuple sample ===" << std::endl;
    tuple_sample();

    std::cout << "\n\n\n=== lambda sample ===" << std::endl;
    lambda_sample();

    std::cout << "\n\n\n=== addressof sample ===" << std::endl;
    util_sample();

    std::cout << "\n\n\n=== custom deleter sample ===" << std::endl;
    smart_ptr_sample();

    std::cout << "\n\n\n=== fold expression sample ===" << std::endl;
    fold_sample();

    std::cout << "\n\n\n=== lambda capture sample ===" << std::endl;
    lambda_capture_sample();
}
