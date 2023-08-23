# ParallelizedCounter
Optimizing a serial counter for speed by utilizing omp library for parallelization. This code demonstrates counting to 1 Billion both with/without parallelization, and demonstrates the time difference between the two.

# Compile the code by running the following commmand:
g++ -fopenmp counter.cpp -o counter.o

# Run the code by running the following command:
./counter.o
