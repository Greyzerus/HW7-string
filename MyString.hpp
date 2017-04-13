//
// Created by greyzerus on 11.04.17.
//

#ifndef HW7_MYSTRING_HPP
#define HW7_MYSTRING_HPP

#ifndef CSTRING_BUF_SIZE
#define CSTRING_BUF_SIZE 4096 //Buffer size for cstring reading
#endif //CSTRING_BUF_SIZE

#include <iostream>
#include <cstring>




class MyString {
    public:
    /*MyString(const char *string = nullptr);*/
    MyString(const char *string = nullptr, size_t size = 0);
    MyString(const MyString& other);
    MyString& operator=(const MyString& other);
    ~MyString();

    char *getStringCopy() const;

    size_t getSize() const;

    const MyString& operator+(const MyString& other);
    const MyString& operator+=(const MyString& other);

    MyString& concatenate_with (MyString& other);

    friend std::ostream &operator<<(std::ostream &os, const MyString &string);
    friend std::istream &operator>>(std::istream &is, MyString &string);
private:
        char* string;
        size_t size;
};

#endif //HW7_MYSTRING_HPP
