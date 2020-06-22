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

    /* Insert value in certain position.
     * Add the value to the end of the string
     * if position is bigger than size */
    void insert(const char c, size_t pos);
    void insert(const char* str, size_t pos);
    void insert(const std::string str, size_t pos);
    void insert(const xstring str, size_t pos);

    /* Add value in the end of the string.*/
    void append(const char c);
    void append(const char* str);
    void append(const std::string& str);
    void append(const xstring& str);

    /* Remove value from certain position.
     * Do nothing when the value wasn't found at the position */
    void remove(const char c, size_t pos);
    void remove(const char* str, size_t pos);
    void remove(const std::string& str, size_t pos);
    void remove(const xstring& str, size_t pos);

    /* Check value is contained in string */
    bool contains(const char c) const;
    bool contains(const char* str) const;
    bool contains(const std::string& str) const;
    bool contains(const xstring& str) const;

    /* Return size of the string */
    size_t length() const;

    /* Revert the string */
    xstring reverse() const;

    /* Converts xstring to std::string */
    std::string toStdString() const;

    xstring& operator=(const char* rhs);
    xstring& operator=(const std::string& rhs);
    xstring& operator=(const xstring& rhs);

    friend bool operator == (const xstring& lhs, const char* rhs);
    friend bool operator == (const xstring& lhs, const std::string& rhs);
    friend bool operator == (const xstring& lhs, const xstring& rhs);
    friend xstring operator + (const xstring& lhs, const char c);
    friend xstring operator + (const xstring& lhs, const char* rhs);
    friend xstring operator + (const xstring& lhs, const std::string& rhs);
    friend xstring operator + (const xstring& lhs, const xstring& rhs);
    friend std::ostream& operator << (std::ostream& out, const xstring& str);
    friend std::istream& operator >> (std::istream& in, const xstring& str);

   private:
    size_t m_size;
    char* m_buffer;

    void prefix_function(const char* str, int* prefixes) const;
    int findSubStr(const char* subStr) const;
  };

  void swap(char& a, char& b);
}

#endif
