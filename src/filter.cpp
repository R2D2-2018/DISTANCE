#include "filter.hpp"

//TODO: Change to use C++ array
int Filter::getMedian(int list[], int length)
{    
    int i = 1;	
    //TODO: Change to use for loop instead of while
    while ( i < length ) {
		for (int j = i; list[j - 1] > list[j]; j-- ) {
			int temp = list[j];
			list[j] = list[j - 1];
			list[j - 1] = temp;
		}
		i++;
	}

    return length % 2 ? list[length / 2] : (list[length / 2 - 1] + list[length / 2]) / 2;
}