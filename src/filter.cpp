#include "filter.hpp"

Filter::Filter(int value):
    value(value)
{}

void Filter::func() {
    hwlib::cout << "Filter: " << value << hwlib::endl;
}