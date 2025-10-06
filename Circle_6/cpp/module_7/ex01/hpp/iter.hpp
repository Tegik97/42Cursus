#ifndef ITER_HPP
# define ITER_HPP

template<typename T, typename U>
void    iter(T* arr, const int len, U f) {
    for (int i = 0; i < len; i++)
        f(arr[i]);
}

#endif