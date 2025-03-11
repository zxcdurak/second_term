#include <iostream>
#include <cstdlib>
#include <ctime>  
#include <algorithm>

#define length_array 1000

int* createRandomArray(int length) {
    int* arr = new int[length];

    std::srand(std::time(0));

    for (int i = 0; i < length; i++) {
        arr[i] = std::rand() % 18;
    }
    std::sort(arr, arr + length);
    return arr;
}

int* pack_array(int* array, int length) {
    int* packed_array = new int[18]();
    
    for (int i = 0; i < length; i++) {
        packed_array[array[i]]++;
    }

    return packed_array;
}

int* unpack_array(int* array) {
    int size = 0;
    
    for (short i = 0; i < 18; i++) size += array[i];
    int* unpacked_array = new int[size];
    short i = 0;
    int j;
    int curr = 0;
    while (i < 18) {
        j = array[i];
        while (j > 0) {
            j--;
            unpacked_array[curr] = i;
            curr++;
        }
        i++;
    }
    return unpacked_array;
}


int main()
{
    int* arr = createRandomArray(length_array);
    int* packed_arr = pack_array(arr, length_array);
    int* unpacked_arr = unpack_array(packed_arr);
    for (int i = 0; i < 1000; i++) std::cout << arr[i] << "  " << unpacked_arr[i] << "\n";
    delete[] arr;
    delete[] packed_arr;
    delete[] unpacked_arr;
    
    return 0;
}
