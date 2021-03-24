//Student ID: s1260032
// complete: headers ...
#include <iostream>
#include <vector>
#include <thread>
using namespace std;
// complete: write the function split that computes the lower/higher indices
// for which each thread will be responsible.
void split(size_t nele, size_t nthreads, vector<size_t> &lower, vector<size_t> &heigher)
{
    size_t thread_entry = nele / nthreads;
    for (size_t i = 0; i < nthreads; i++)
    {
        lower.push_back(i * thread_entry);
        heigher.push_back((i + 1) * thread_entry - 1);
    }
}

// complete: add dot_product and modify it such that there is no race condition.
void dot_product(const std::vector<double> &v1, const std::vector<double> &v2, double *result, std::size_t lower, std::size_t higher)
{
    double sum = 0;
    for (std::size_t i = lower; i < higher; ++i)
    {
        sum += v1[i] * v2[i];
    }

    *result += sum;
}

// complete: the main function
int main(void)
{
    std::size_t nele = 1000000; // you can modify this to experiment and this as well, it depends on the number of cores on your machine
    std::size_t nthreads = thread::hardware_concurrency();
    double result = 0;

    std::vector<double> v1(nele);
    // complete: fill v1 with random integers
    for (size_t i = 0; i < nele; ++i)
    {
        v1[i] = double(rand()) / double(RAND_MAX);
    }

    std::vector<double> v2(nele);
    for (size_t i = 0; i < nele; ++i)
    {
        v2[i] = double(rand()) / double(RAND_MAX);
    }

    // complete: split nele into nthreads part
    std::vector<std::size_t> lower;
    std::vector<std::size_t> higher;
    // lower[i] and higher[i] contains the lower and higher indices
    // for which a given thread will compute the dot product
    split(nele, nthreads, lower, higher);

    // complete: start nthreads threads
    // don't forget to pass explicitly a reference to the arrays v1 and v2
    std::vector<std::thread> threads;
    for (std::size_t i = 0; i < nthreads; ++i)
    {
        // start a thread that will compute the dot product between v1 and v2
        // for indices between lower[i] and higher[i]
        threads.push_back(thread(dot_product, v1, v2, &result, lower[i], higher[i]));
        threads[i].join();
    }

    // complete: join the threads with the main thread
    std::cout << "nele = " <<  nele << std::endl;
    std::cout << "concurrency = " <<  nthreads << std::endl;
    std::cout << "Result: " << result << std::endl;
    return 0;
}