//
// Created by greyzerus on 13.04.17.
//

#ifndef HW7_SORTED_VECTOR_H
#define HW7_SORTED_VECTOR_H

#include <cstdlib>
#include <cstring> //memcpy
#include <iostream>
#include <algorithm>
#include <iterator>



template <class T>
void swap (T* lhs, T* rhs)
{
    T temp = *lhs;
    *lhs = *rhs;
    *rhs = temp;
    delete temp;
}


/* difference_type	is undefined
 * always taken as:
 * iterator_traits<iterator>::difference_type
 * size_type is undefined
 * always taken as:
 * size_t
 */
template <typename T, class Compare = std::less<T>, class Alloc = std::allocator<T>>
class sorted_vector /*<class T, class Compare, class Alloc>*/ {
public:
    /*cplusplus.com*/
    /*empty(1)*/
    /*explicit*/sorted_vector(Compare comp = Compare(),
                           Alloc alloc = Alloc())
            : alloc (alloc), comp (comp), data_size (0), reserved_size (0),
                                                    array (nullptr){};
    /*range(2)*/
    sorted_vector(T* first, T* last,
                  Compare comp = Compare(),
                  Alloc alloc = Alloc())
            : alloc (alloc), comp (comp) {
        data_size = last-first;
        reserved_size = data_size * data_size;
        try {
            array = new T[reserved_size];
        } catch (std::bad_alloc &ex) {throw;}
        for (uint iter = 0; iter < data_size; iter++) {
            array[iter] = *(first + iter);
        }
        sort();
    };
    /* copy(3)* /TROUBLES

     sorted_vector (const sorted_vector / *<T, Compare, Alloc>* / &other
            , Compare &comp = Compare(), Alloc &alloc = Alloc())* /
            : comp (other.comp), alloc (alloc)
    {
        data_size = other.data_size;
        reserved_size = other.reserved_size;
        try {
            array = new T[reserved_size];
        } catch (std::bad_alloc &ex) {throw;}
        for (uint iter = 0; iter < data_size; iter++) {
            array[iter] = *(other.array + iter);
        }
    };*/
    /*sorted_vector& sorted_vector (const sorted_vector &other,
                                  const Alloc &alloc)
            : alloc (alloc), comp (Compare()) {
        data_size = other.data_size;
        reserved_size = other.reserved_size;
        try {
            array = new T[reserved_size];
        } catch (std::bad_alloc &ex) {throw;}
        for (uint iter = 0; iter < data_size; iter++) {
            array[iter] = *(other.array + iter);
        }

    }; */
    /*move(4)* /
    sorted_vector& sorted_vector (sorted_vector&& other)
            : alloc (Alloc()), comp (Compare()), array (other.array)
             , data_size (other.data_size), reserved_size (other.reserved_size)
    {
        data_size = 0;
        reserved_size = 0;
        array = nullptr;
    }*/

    /*sorted_vector& sorted_vector (sorted_vector&& other, const Alloc &alloc);*/


    ~sorted_vector() {
        delete[] array;
    }

    /*copy op=(1)*/
    sorted_vector& operator= (const sorted_vector& other)    {
        if (&other == this)
            return *this;
        /*alloc = other.alloc;
        comp = other.comp;*/
        data_size = other.data_size;
        reserved_size = other.reserved_size;
        delete[] array;
        try {
            array = new T[reserved_size];
        } catch (std::bad_alloc &ex) {throw;}

        memcpy(array, other.array, reserved_size*sizeof(T));
        return *this;
    }
    /*move op=(2)* /
    sorted_vector& operator= (sorted_vector&& other)
            :alloc (other.alloc), comp (other.comp),
    data_size (other.data_size), reserved_size (other.reserved_size),
    array (other.array)
    {
        data_size = 0;
        reserved_size = 0;
        array = nullptr;
        return *this;
    }
*/

    /*cIterators - pointers?*/
    T* begin() { return array; };
    T* end() {return array+data_size; }
    T* rbegin() { return end(); };
    T* rend() {return array; };
    const T* cbegin() { return array; };
    const T* cend() { return end(); };
    const T* crbegin() { return cend(); };
    const T* crend() { return cbegin(); }

    /*capacity*/
    bool empty () { return this->data_size == 0; };
    const size_t size () {    return data_size; };
    const size_t max_size () {    return reserved_size; };

    /*Element access*/
    T&operator[] (const size_t key) {
        if (key<data_size)
            return array[key];
        else {
            std::out_of_range ex("");
            throw (ex);
        }
    };
    T& at (const size_t key) {
        return (*this)[key];
    };

    void insert (const T& val) {
        if (data_size +1 == reserved_size) {
            try {
                T* temp = array;
                array = memcpy(new T[reserved_size *= reserved_size], temp, data_size);
                delete[] temp;
            } catch (std::bad_alloc) {throw;}
        }
        memcpy(&array[data_size++], &val, sizeof(val));
        array[data_size++] = val;
        sort();
    };
    void insert (const T* const val, size_t num) {
        if (data_size + num > reserved_size) {
            while (data_size + num > reserved_size)
                reserved_size *= reserved_size;
            try {
                T* temp = array;
                array = memcpy(new T[reserved_size *= reserved_size], temp, data_size);
                delete[] temp;
            } catch (std::bad_alloc) {throw;}
        }
        for (size_t iter = 0; iter<num; iter++)
        {
            array[data_size + iter] = val[iter];
        }
        sort();
    }
    void erase (size_t position)
    {
        if (position>=data_size) {
            std::out_of_range ex;
            throw ex;
        }
        std::swap(array[data_size-1], array[position]);
        delete array[data_size-1];
        sort();
    };
    void erase (const T* value) {
        for (auto iter: *this) {
            if (iter == value) {
                std::swap (*iter, *end());
                delete end;
                data_size--;
            }
        }
        sort();
    };
    void erase (T* first, T* last) {
        if (first < begin() || first > end || last > end() || last < begin) {
            std::out_of_range ex;
            throw ex;
        }
        for (last; last>=first; last-- ) {
            std::swap (*last, *end());
            delete end;
            data_size--;
        }
        sort();
    };
    sorted_vector<T>& swap_data (sorted_vector<T>& other)
    {
        T* temp=array;
        array = other.array;
        other.array = temp;
        temp = nullptr;
        size_t temp_s = data_size;
        data_size = other.data_size;
        other.data_size = temp_s;
        temp_s = reserved_size;
        reserved_size = other.reserved_size;
        other.reserved_size = temp_s;
        sort();
        other.sort();
        return *this;
    };
    void clear() {
        delete[] array;
        data_size = 0;
        reserved_size = 0;
    }
    void sort() {
        std::sort(begin(), end(), comp);
    }
    T* find (const T& value) {
        T* iter = begin();
        while (*iter!=value && iter <= end())
        {
            iter++;
        }
        return iter;
    }
    size_t count (const T& value) {
        size_t  count = 0;
        for (T* iter : *this) {
            if (*iter == value)
                count++;
        }
        return count;
    };
    T* lower_bound(const T& value) {
        T* iter = begin();
        while (*iter < value && iter <= end())
        {
            iter++;
        }
        if (iter > end()) {
            std::out_of_range ex;
            throw ex;
        }
        return iter;
    };//Returns an iterator pointing
    // to the first element in the container whose key is not considered
    // to go before k (i.e., either it is equivalent or goes after).
    T* upper_bound(const T& value) {
        T* iter = end();
        while (*iter > value && iter >= begin()) {
            iter--;
        }
        if (iter < begin) {
            std::out_of_range ex;
            throw ex;
        }
        return iter++;
    };//Returns an iterator pointing
    // to the first element in the container whose key is considered
    // to go after k.
    std::pair<T*, T*> equal_range (const T& value) {
        T* first = begin(), last = begin;
        while (*first != value && first <= end()) {
            first++;
        }
        if (first > end) {
            std::out_of_range ex;
            throw ex;
        }
        last = first;
        while (*last == value && last < end())
            last++;
        return std::pair<T*, T*>(first, last);
    };

private:
    /*DATA*/
    Alloc alloc;
    Compare comp;
    size_t data_size;
    size_t reserved_size;
    T *array;
public:
    friend std::ostream &operator<<(std::ostream &os, const sorted_vector<T> &vector) {
        for (auto iter: vector)
            os <<  iter << " ";
        return os;
    }
};

/*sorted_vector<T, Compare, Alloc>::sorted_vector
        (Compare &comp, Alloc &alloc)
        : alloc (alloc), comp (comp), data_size (0), reserved_size (0),
        array (nullptr){};*/
#endif //HW7_SORTED_VECTOR_H
