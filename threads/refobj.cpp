#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <numeric>

std::mutex mtx;

class tapi {
private:
    /* data */
    int a_;
    std::vector<int>bs_;
public:
    tapi(int a, int bsize):a_(a), bs_(bsize) {
        std::iota(bs_.begin(),bs_.end(), 0);
    }
    void chan(int i){
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << i << '\n';
        std::cout<<a_<<std::endl;
        a_ =  10*i;
        for(auto &bs:bs_){
            std::cout<<bs<<" ";
            bs*=10;
        }std::cout<<std::endl;
        std::cout<<"thread id: "<<std::this_thread::get_id()<< std::endl;
    }
};

int main(){
    const int N = 8;
    std::vector<std::thread> ths(N);
    std::vector<tapi> nums;{
        for(int i = 0 ; i < N ; i ++){
            nums.push_back(tapi(i,i+1));
        }
    }
    for(int i = 0 ; i < N ; i++){
        ths[i] = std::thread(&tapi::chan, std::ref(nums[i]), i);
    }

    for(auto &th: ths){
        th.join();
    }
    std::cout<<"!!!"<<std::endl;
    for(int i = 0 ; i < N ; i++){
        nums[i].chan(i);
    }

    return 0;
}
