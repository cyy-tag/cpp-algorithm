#pragma once
template<typename T>
void Merge(const T *a, size_t a_len, const T *b, size_t b_len, T *c) {
    size_t i = 0, j = 0, k = 0;
    while(i < a_len && j < b_len)
    {
        if(b[j] < a[i]) {
            c[k++] = b[j++];
        } else {
            c[k++] = a[i++];
        }
    }
    while(i < a_len) c[k++] = a[i++];
    while(j < b_len) c[k++] = b[j++];
}

template<typename T>
void MergeSort(T *a, size_t l, size_t r) {
    if(r - l <= 1) return;
    size_t mid = l + ((r - l) >> 1);
    MergeSort(a, l, mid);
    MergeSort(a, mid, r);
    T tmp[1024] = {};
    Merge(a+l, mid-l, a +mid, r-mid, tmp+l);
    for(size_t i = l; i < r; ++i) a[i] = tmp[i];
}
