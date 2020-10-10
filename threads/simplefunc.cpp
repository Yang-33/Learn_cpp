#include <iostream>
#include <thread>

void foo(int a)
{
    std::cout << a << '\n';
    std::cout<<"thread id: "<<std::this_thread::get_id()<< std::endl;
}

int main()
{
    unsigned num_cpus = std::thread::hardware_concurrency();
    std::cout << "Launching " << num_cpus << " threads\n";
    // Create and execute the thread
    std::thread thread(foo, 10); // foo is the function to execute, 10 is the
                                 // argument to pass to it

    // Keep going; the thread is executed separately

    // Wait for the thread to finish; we stay here until it is done
    thread.join();

    return 0;
}
