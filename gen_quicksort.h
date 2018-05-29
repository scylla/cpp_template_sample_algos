template <typename T, typename ListIt, typename F>
// requires F to be comparator func for List elements, ListIt randomaccessiterator
class QuickSort {
private:
    ListIt list_first;
    ListIt list_end;
    F is_less;
private:
    void swap(ListIt first, ListIt second);
    void sort_util(ListIt first, ListIt end);
    ListIt partition(ListIt first, ListIt end);
public:
    QuickSort(ListIt list_f, ListIt list_e, F functor_p) : list_first(list_f), list_end(list_e), is_less(functor_p) {}
    void sort();
};

template <typename T, typename ListIt, typename F>
void QuickSort<T, ListIt, F>::swap(ListIt first, ListIt second) {
    T temp = *first;
    *first = *second;
    *second = temp;
}

template <typename T, typename ListIt, typename F>
ListIt QuickSort<T, ListIt, F>::partition(ListIt first, ListIt end) {
    if(first == end) return first;
    ListIt pivot = first;
    for(ListIt it = first + 1; it != end; ++it) {
        if(is_less(*it, *pivot)) {
            first += 1;
            swap(it, first);
        } 
    }
    swap(pivot, first);
    return first;
}

template <typename T, typename ListIt, typename F>
void QuickSort<T, ListIt, F>::sort_util(ListIt first, ListIt end) {
    if(first == end) return;
    ListIt partitionIt = partition(first, end);
    sort_util(first, partitionIt);
    sort_util(partitionIt+1, end);
}

template <typename T, typename ListIt, typename F>
void QuickSort<T, ListIt, F>::sort() {
    if(list_first == list_end || list_first + 1 == list_end) return;
    sort_util(list_first, list_end);
}
