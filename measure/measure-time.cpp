#include <iostream>
#include <vector>
#include <chrono>

template<typename TimeT = std::chrono::milliseconds>
struct measure
{
    template<typename F, typename ...Args>
    static typename TimeT::rep execution(F&& func, Args&&... args)
    {
        auto start = std::chrono::steady_clock::now();
        std::forward<decltype(func)>(func)(std::forward<Args>(args)...);
        auto duration = std::chrono::duration_cast< TimeT>
                            (std::chrono::steady_clock::now() - start);
        return duration.count();
    }
};

#define MEASURE(args...) \
  { \
   auto start = std::chrono::steady_clock::now(); \
   args; \
   auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>  (std::chrono::steady_clock::now() - start); \
   std::cerr<<__FILE__<<":"; \
   std::cerr<<__LINE__<<": "; \
   std::cerr<<#args<<" took "; \
   std::cerr<< duration.count() <<" nanoseconds (10^(-9) second)"<< std::endl; \
  }

int fun(int a,int b){
    int c= a+b;
    return c;
}



int main(){
    // std::cout<< 1 << std::endl;
    std::cout << measure<std::chrono::nanoseconds>::execution(fun,1,2) << std::endl;
    // std::cout << measure<std::chrono::microseconds>::execution(fun,1,2) << std::endl;
    std::cout << measure<std::chrono::nanoseconds>::execution([](){std::cout<<"!!!"<<std::endl;}) << std::endl;
    MEASURE(fun(1,2));
    MEASURE([](){ std::cout<<"!!!"<<std::endl; }());
}
