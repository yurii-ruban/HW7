#ifndef _XSTRING_H
#define _XSTRING_H

#include <string>
#include <iostream>
#include <cstring>

namespace custom
{
  class xstring
  {
   public:
    xstring();
    xstring(const char* str);
    xstring(const std::string& str);
    xstring(const xstring& other);
    xstring(xstring&& other);
    ~xstring();

    /* Inserts value in certain position.
     * Adds the value to the end of the string
     * if position is bigger than size */
    void insert(const char c, size_t pos);
    void insert(const char* str, size_t pos);
    void insert(const std::string str, size_t pos);
    void insert(const xstring str, size_t pos);

    void append(const char c);
    void append(const char* str);
    void append(const std::string str);
    void append(const xstring& str);

    void remove(size_t start, size_t end, const char c);
    void remove(size_t start, size_t end, const char* str);
    void remove(size_t start, size_t end, const std::string str);
    void remove(size_t start, size_t end, const xstring& str);

    bool contains(const char c) const;
    bool contains(const char* str) const;
    bool contains(const std::string str) const;
    bool contains(const xstring& str) const;

    size_t length() const;
    xstring reverse() const;
    std::string toStdString() const;

    xstring& operator=(const char* rhs);
    xstring& operator=(const std::string& rhs);
    xstring& operator=(const xstring& rhs);

    friend bool operator == (const xstring& lhs, const char* rhs);
    friend bool operator == (const xstring& lhs, const std::string& rhs);
    friend bool operator == (const xstring& lhs, const xstring& rhs);
    friend xstring operator + (const xstring& lhs, const char* rhs);
    friend xstring operator + (const xstring& lhs, const std::string& rhs);
    friend xstring operator + (const xstring& lhs, const xstring& rhs);
    friend std::ostream& operator << (std::ostream& out, const xstring& str);
    friend std::istream& operator >> (std::istream& in, const xstring& str);

   private:
    size_t m_size;
    char* m_buffer;
  };
}

#endif
