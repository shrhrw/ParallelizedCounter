#include <stdio.h>
#include <chrono>
#include <iostream>
#include <omp.h>

// Compile using g++ -fopenmp counter.cpp -o counter.a

/* Original slow serial counter */
double serial_counter() {
    size_t counter = 0;
    size_t nb_iter = 1000000000;
    auto serial_start_time = std::chrono::high_resolution_clock::now();
    for( int i = 0; i < nb_iter; ++i )
    {
        counter ++;
    }
    auto serial_end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> serial_duration = serial_end_time - serial_start_time;
    printf( "Serial Loop: counter: %ld / %ld\n", counter, nb_iter );
    std::cout << "Serial Loop: Time elapsed: " << serial_duration.count() << std::endl;
    return serial_duration.count();
}

/* Utilizing omp library to parallelize the process, on a newer multi-core CPU */
double parallel_counter() {
    size_t counter = 0;
    size_t nb_iter = 1000000000;
    auto parallel_start_time = std::chrono::high_resolution_clock::now();
#pragma omp parallel for reduction(+:counter)
    for( int i = 0; i < nb_iter; ++i )
    {
        counter ++;
    }
    auto parallel_end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> parallel_duration = parallel_end_time - parallel_start_time;
    printf( "Parallel Loop: counter: %ld / %ld\n", counter, nb_iter );
    std::cout << "Parallel Loop: Time elapsed: " << parallel_duration.count() << std::endl;
    return parallel_duration.count();
}

int main( int argc, char** argv )
{
    double serial_duration = serial_counter();
    double parallel_duration = parallel_counter();
    std::cout << "Parallel Processing speedup: " << serial_duration / parallel_duration << std::endl;
    return 0;
}
