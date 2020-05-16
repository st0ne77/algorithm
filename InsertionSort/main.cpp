#include <iostream>
#include <vector>
using namespace std;

template<typename T>
void printList(const std::vector<T>& lst){
    for(auto it = lst.begin(); it != lst.end(); ++it){
        std::cout << *it << ",";
    }
    std::cout << std::endl;
}

template<typename T>
void InsertionSort(std::vector<T>& array){
    if(array.size() < 2)
        return ;
    for(unsigned int i = 1; i < array.size(); ++i){
        std::cout << "   --" << i << "--" << std::endl;
        int count = 0;
        for(int j = i; j > 0 && array[j-1] > array[j]; --j){
            T tmp = array[j];
            array[j] = array[j-1];
            array[j-1] = tmp;
            std::cout << "      --" << ++count << "--";
            printList(array);
        }
    }
    return ;
}

int main(){

    std::vector<int> src{98, 58, 56, 32, 22, 10, 1};
    cout << "src:";
    printList(src);
    InsertionSort(src);
    cout << "dest:";
    printList(src);
    return 0;
}
