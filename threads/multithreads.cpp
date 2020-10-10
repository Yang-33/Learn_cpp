#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

std::mutex mtx;

void foo(int a){
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << a << '\n';
    std::cout<<"thread id: "<<std::this_thread::get_id()<< std::endl;
}

int main(){
    int N; std::cin >>N;
    // const int N = 20;
    std::vector<std::thread> ths(N);
    for(int i = 0 ; i < N ; i++){
        ths[i] = std::thread(foo, i);
    }

    for(auto &th: ths){
        th.join();
    }

    return 0;
}
