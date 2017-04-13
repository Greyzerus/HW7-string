//
// Created by greyzerus on 11.04.17.
//

#include "MyString.hpp"
#include "nstrlen.h"
#include <iomanip>



/*MyString::MyString(const char *string/ * =nullptr* /): string (nullptr), size (0) {
    if (string)
    {
        size = strlen(string)+1;
        try{
            this->string = new char[size];
        }
        catch (std::bad_alloc& ex) {
            std::cerr << ex.what() << std::endl;
            throw;
        }
        strncpy(this->string, string, size-1);
        this->string[size-1]='/0';
    }
}*/

MyString::MyString(const char *cstring /* =nullptr*/, size_t cstring_size /* =0*/)
        : string (nullptr)
        , size (cstring_size)
{
    if (cstring)
    {
        if (size == 0) {
            size = strlen(string) + 1;
            if (size == 0)
                return;
        }
        else size = nstrlen (cstring, size)+1;
        try{
            string = new char[size];
        } catch (std::bad_alloc& ex) {
            std::cerr << ex.what() << std::endl;
            throw;
        }
        strncpy(string, cstring, size-1);
        string[size-1]= (char) '\0';
    }
    else if (cstring_size)
        size = 0;
}

MyString::MyString(const MyString& other): string (nullptr), size (0) {
    if (other.string){
        size = other.size;
        try{
            string = new char[size];
        } catch (std::bad_alloc& ex) {
            std::cerr << ex.what() << std::endl;
            throw;
        }
        strncpy(this->string, string, size);
    }
}

MyString& MyString::operator=(const MyString& other) {
    if (string == other.string)
        return *this;
    size = other.size;
    if (!other.string || !size) {
        delete[] string;
        this->string = nullptr;
        return *this;
    }
    try {
        char *tmp = string;
        string = new char[size];
        delete[] tmp;
    }    catch (std::bad_alloc &ex) {
            std::cerr << ex.what() << std::endl;
            throw;
    }
    strncpy (string, other.string, size);
    return *this;
    }


MyString::~MyString() {
    if (string)
    {
        delete[] string;
    }
}

char *MyString::getStringCopy() const {
    if ( ! string)
        return nullptr;
    else {
        char *cpy;
        try {
            cpy = new char[size];
        } catch (std::bad_alloc &ex) {
            std::cerr << ex.what() << std::endl;
            throw;
        }
        strncpy(cpy, string, size);
        return cpy;
    }
}

size_t MyString::getSize() const {
    return size;
}

const MyString& MyString::operator+(const MyString& other) {
    size_t res_size = this->size + other.size;
    if (res_size == 0) {
        return * (new MyString());
    }
    if (this->size && other.size)
        res_size--; /* '/0' terminated this->string */
    char* result;
    try {
        result = new char[res_size];
    } catch (std::bad_alloc &ex) {
        std::cerr << ex.what() << std::endl;
        throw;
    }
    if (size)
        strncpy (result, string, size);
    if (other.size)
        strncpy (&result[size-1], other.string, other.size);
    return * (new MyString(result, res_size));
}

const MyString& MyString::operator+=(const MyString& other){
    char* temp = string;
    try {
        string = new char[size+other.size-1];
    } catch (std::bad_alloc &ex) {
        std::cerr << ex.what() << std::endl;
        string = temp;
        throw;
    }
    strncpy (string, temp, size);
    strncat (string, other.string, other.size);
    size += other.size - 1;
    delete[] temp;
    return *this;
}

MyString& MyString::concatenate_with (MyString &other) {
    try {
        *this += other;
    } catch (std::bad_alloc &ex) {
        std::cerr << ex.what() << std::endl;
        throw;
    }
    return *this;
}
/*
std::ostream &operator<<(std::ostream &os, const MyString &string) {
    os << string.string;
    return os;
}*/


std::istream& operator>> (std::istream& is, MyString& string ) {
    is.clear();
    try {
        char *buf = new char[CSTRING_BUF_SIZE];
        is >> std::setw(CSTRING_BUF_SIZE) >> buf;
        string = MyString(buf, CSTRING_BUF_SIZE);
        if (is && nstrlen (buf, (const size_t) CSTRING_BUF_SIZE) == (CSTRING_BUF_SIZE-1))  {
            MyString add_string;
            is >> add_string;
            string += add_string;
        }
        delete[] buf;
    } catch (std::bad_alloc &ex) {
        std::cerr << ex.what() << std::endl;
        throw;
    }
    return is;

}

std::ostream &operator<<(std::ostream &os, const MyString &string) {
    for (size_t i = 0; i < string.getSize(); i++)
        os << string.string[i];
    return os;
}