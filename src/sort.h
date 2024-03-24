#include <algorithm>
#include <vector>

template <class T>
void sortByPrice(std::vector<T> & a){

    std::sort(a.begin(),a.end(),[](T b, T c){
                                
                                return b -> price() < c -> price();
                                }
    );
}

template <class T>
void sortByPrice(std::vector<T>& items, bool (*cmp)(const T&, const T&)) {
    std::sort(items.begin(),items.end(),cmp);
}

template <class T,class Compare>
void sortByPrice(std::vector<T>& items, Compare comp) {
    std::sort(items.begin(), items.end(), comp);
}


    


    