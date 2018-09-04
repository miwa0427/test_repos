// main.cpp : Defines the entry point for the console application.
//

#include "pch.h"

#include <iostream>
#include <string>
#include "select_sample.h"

int main()
{
#ifdef PARA_SAMPLE
    std::wcout << L"\n\n\n=== Paralells sample ===" << std::endl;
    para_sample1();
    para_sample2();
#endif

#ifdef MAP_SAMPLE
    std::wcout << L"\n\n\n=== map sample ===" << std::endl;
    map_sample();
    map_sample2();
#endif

#ifdef TUPLE_SAMPLE
    std::wcout << L"\n\n\n=== tuple sample ===" << std::endl;
    tuple_sample();
#endif

#ifdef LAMBDA_SAMPLE
    std::wcout << L"\n\n\n=== lambda sample ===" << std::endl;
    lambda_sample();
#endif

#ifdef TIME_SAMPLE
    std::wcout << L"\n\n\n=== datetime sample ===" << std::endl;
    time_sample();
#endif

#ifdef UTIL_SAMPLE
    std::wcout << L"\n\n\n=== addressof sample ===" << std::endl;
    util_sample();

    std::wcout << L"\n\n\n=== fold expression sample ===" << std::endl;
    fold_sample();
#endif

#ifdef SMART_PTR_SAMPLE
    std::wcout << "\n\n\n=== custom deleter sample ===" << std::endl;
    smart_ptr_sample();
#endif

#ifdef LAMBDA_CAP_SAMPLE
    std::wcout << "\n\n\n=== lambda capture sample ===" << std::endl;
    lambda_capture_sample();
#endif

#ifdef FILESYTEM_SAMPLE
    std::wcout << L"\n\n\n=== FileSystem sample ===" << std::endl;
    filesystem_sample();
#endif

#ifdef BOOST_SAMPLE
#ifdef BOOST_LOG_SAMPLE
    std::wcout << L"\n\n\n=== [Boost] logging sample ===" << std::endl;
    boost_logging_sample();
#endif
#endif

#ifdef WIN_RT_SAMPLE
    std::wcout << L"\n\n\n=== [WinRT] sample ===" << std::endl;
    winrt_sample();
#endif
}
