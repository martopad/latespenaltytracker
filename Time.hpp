#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>

class Time : std::tm
{
    int tm_usecs; // [0, 999999] micros after the sec

    Time( const int year, const int month, const int mday, const int hour,
        const int min, const int sec, const int usecs, const int isDST = -1)
        : tm_usecs{usecs}
    {
        tm_year = year - 1900; // [0, 60] since 1900
        tm_mon = month - 1;    // [0, 11] since Jan
        tm_mday = mday;        // [1, 31]
        tm_hour = hour;        // [0, 23] since midnight
        tm_min = min;          // [0, 59] after the hour
        tm_sec = sec;          // [0, 60] after the min
                            //         allows for 1 positive leap second
        tm_isdst = isDST;      // [-1...] -1 for unknown, 0 for not DST,
    }

    template <typename Clock_t = std::chrono::high_resolution_clock,
            typename MicroSecond_t = std::chrono::microseconds>
    auto to_time_point() -> typename Clock_t::time_point {
    auto time_c = mktime(this);

    return Clock_t::from_time_t(time_c) + MicroSecond_t{tm_usecs};
  }
}