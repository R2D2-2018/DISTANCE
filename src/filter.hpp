#ifndef filter_hpp
#define filter_hpp
#include "wrap-hwlib.hpp"

class Filter {
    private:
        int value;
    public:
        Filter(int value);

        void func();
};

#endif //x