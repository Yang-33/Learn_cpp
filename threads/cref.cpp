#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <numeric>

std::mutex mtx;

void foo(const std::vector<int>& a, int i){
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << a[i] << '\n';
    std::cout<<"thread id: "<<std::this_thread::get_id()<< std::endl;
}

int main(){
    const int N = 8;
    std::vector<std::thread> ths(N);
    std::vector<int> nums(N);
    std::iota(nums.begin(),nums.end(), 0);

    for(int i = 0 ; i < N ; i++){
        ths[i] = std::thread(foo, std::cref(nums), i);
    }

    for(auto &th: ths){
        th.join();
    }
    for(int i = 0 ; i < N ; i++){
        std::cout<<nums[i]<< " \n"[i+1==N];
    }

    return 0;
}
