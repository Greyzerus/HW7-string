# HW7-string
Вариант 42 -> 5) sorted vector
использовать интерфейс map



#when you've no time and don't know how std::vector, std::map, std::string exactly works
/media/greyzerus/Files/gitfolder/HW7/main.cpp: In constructor ‘sorted_vector<T, Compare, Alloc>::sorted_vector(Compare&, Alloc&) [with T = int; Compare = std::less<int>; Alloc = std::allocator<int>]’:
/media/greyzerus/Files/gitfolder/HW7/main.cpp:13:24: error: invalid initialization of non-const reference of type ‘std::less<int>&’ from an rvalue of type ‘std::less<int>’
     sorted_vector<int> example;
                        ^
/media/greyzerus/Files/gitfolder/HW7/main.cpp: In function ‘int main()’:
/media/greyzerus/Files/gitfolder/HW7/main.cpp:13:24: error: invalid initialization of non-const reference of type ‘std::less<int>&’ from an rvalue of type ‘std::less<int>’
In file included from /media/greyzerus/Files/gitfolder/HW7/main.cpp:10:0:
/media/greyzerus/Files/gitfolder/HW7/sorted_vector.h:39:17: note: in passing argument 1 of ‘sorted_vector<T, Compare, Alloc>::sorted_vector(Compare&, Alloc&) [with T = int; Compare = std::less<int>; Alloc = std::allocator<int>]’
     /*explicit*/sorted_vector(Compare &comp = Compare(),
                 ^
/media/greyzerus/Files/gitfolder/HW7/main.cpp: In constructor ‘sorted_vector<T, Compare, Alloc>::sorted_vector(Compare&, Alloc&) [with T = int; Compare = std::less<int>; Alloc = std::allocator<int>]’:
/media/greyzerus/Files/gitfolder/HW7/main.cpp:13:24: error: invalid initialization of non-const reference of type ‘std::allocator<int>&’ from an rvalue of type ‘std::allocator<int>’
     sorted_vector<int> example;
                        ^
/media/greyzerus/Files/gitfolder/HW7/main.cpp: In function ‘int main()’:
/media/greyzerus/Files/gitfolder/HW7/main.cpp:13:24: error: invalid initialization of non-const reference of type ‘std::allocator<int>&’ from an rvalue of type ‘std::allocator<int>’
In file included from /media/greyzerus/Files/gitfolder/HW7/main.cpp:10:0:
/media/greyzerus/Files/gitfolder/HW7/sorted_vector.h:39:17: note: in passing argument 2 of ‘sorted_vector<T, Compare, Alloc>::sorted_vector(Compare&, Alloc&) [with T = int; Compare = std::less<int>; Alloc = std::allocator<int>]’
     /*explicit*/sorted_vector(Compare &comp = Compare(),
                 ^
/media/greyzerus/Files/gitfolder/HW7/sorted_vector.h: In instantiation of ‘void sorted_vector<T, Compare, Alloc>::insert(const T&) [with T = int; Compare = std::less<int>; Alloc = std::allocator<int>]’:
/media/greyzerus/Files/gitfolder/HW7/main.cpp:17:28:   required from here
/media/greyzerus/Files/gitfolder/HW7/sorted_vector.h:164:31: warning: invalid conversion from ‘void*’ to ‘int*’ [-fpermissive]
                 array = memcpy(new T[reserved_size *= reserved_size], temp, data_size);
                               ^
/media/greyzerus/Files/gitfolder/HW7/sorted_vector.h: In instantiation of ‘std::ostream& operator<<(std::ostream&, const sorted_vector<int>&)’:
/media/greyzerus/Files/gitfolder/HW7/main.cpp:20:18:   required from here
/media/greyzerus/Files/gitfolder/HW7/sorted_vector.h:311:9: warning: passing ‘const sorted_vector<int>’ as ‘this’ argument discards qualifiers [-fpermissive]
         for (auto iter: vector)
         ^
/media/greyzerus/Files/gitfolder/HW7/sorted_vector.h:133:8: note:   in call to ‘T* sorted_vector<T, Compare, Alloc>::begin() [with T = int; Compare = std::less<int>; Alloc = std::allocator<int>]’
     T* begin() { return array; };
        ^
/media/greyzerus/Files/gitfolder/HW7/sorted_vector.h:311:9: warning: passing ‘const sorted_vector<int>’ as ‘this’ argument discards qualifiers [-fpermissive]
         for (auto iter: vector)
         ^
/media/greyzerus/Files/gitfolder/HW7/sorted_vector.h:134:8: note:   in call to ‘T* sorted_vector<T, Compare, Alloc>::end() [with T = int; Compare = std::less<int>; Alloc = std::allocator<int>]’
     T* end() {return array+data_size; }
        ^
CMakeFiles/HW7.dir/build.make:62: ошибка выполнения рецепта для цели «CMakeFiles/HW7.dir/main.cpp.o»
make[3]: *** [CMakeFiles/HW7.dir/main.cpp.o] Ошибка 1
CMakeFiles/Makefile2:104: ошибка выполнения рецепта для цели «CMakeFiles/HW7.dir/all»
make[2]: *** [CMakeFiles/HW7.dir/all] Ошибка 2
CMakeFiles/Makefile2:116: ошибка выполнения рецепта для цели «CMakeFiles/HW7.dir/rule»
make[1]: *** [CMakeFiles/HW7.dir/rule] Ошибка 2
Makefile:131: ошибка выполнения рецепта для цели «HW7»
make: *** [HW7] Ошибка 2
