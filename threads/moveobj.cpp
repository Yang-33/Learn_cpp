#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <numeric>

class tapi {
private:
    /* data */
    int a_;
    std::vector<int>bs_;
public:
    tapi(int a, int bsize):a_(a), bs_(bsize) {}
    void chan(){
        std::cout<<a_<<std::endl;
        for(auto bs:bs_){
            std::cout<<bs<<" ";
        }std::cout<<std::endl;
    }
};

std::mutex mtx;

void foo(tapi ta, int i){
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << i << '\n';
    ta.chan();
    std::cout<<"thread id: "<<std::this_thread::get_id()<< std::endl;
}

int main(){
    const int N = 8;
    std::vector<std::thread> ths(N);
    std::vector<tapi> nums;{
        for(int i = 0 ; i < N ; i ++){
            nums.push_back(tapi(i,i+1));
        }
    }
    for(int i = 0 ; i < N ; i++){
        ths[i] = std::thread(foo, std::move(nums[i]), i);
    }

    for(auto &th: ths){
        th.join();
    }
    std::cout<<"!!!"<<std::endl;

    // No.
    for(int i = 0 ; i < N ; i++){
        nums[i].chan();
    }

    return 0;
}
