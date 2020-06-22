# Homework task 7 (6th lecture)
This project contains a binary and shared library with implemented of custom string class `xstring`.

Here is implementation of the next public methods:

- `void insert(const char c, size_t pos)`
- `void insert(const char* str, size_t pos)`
- `void insert(const std::string str, size_t pos)`
- `void insert(const xstring str, size_t pos)`

- `void append(const char c)`
- `void append(const char* str)`
- `void append(const std::string& str)`
- `void append(const xstring& str)`

- `void remove(const char c, size_t pos)`
- `void remove(const char* str, size_t pos)`
- `void remove(const std::string& str, size_t pos)`
- `void remove(const xstring& str, size_t pos)`

- `bool contains(const char c) const`
- `bool contains(const char* str) const`
- `bool contains(const std::string& str) const`
- `bool contains(const xstring& str) const`

- `size_t length() const`
- `xstring reverse() const`
- `std::string toStdString() const`

- `xstring& operator=(const char* rhs)`
- `xstring& operator=(const std::string& rhs)`
- `xstring& operator=(const xstring& rhs)`

- `friend bool operator == (const xstring& lhs, const char* rhs)`
- `friend bool operator == (const xstring& lhs, const std::string& rhs)`
- `friend bool operator == (const xstring& lhs, const xstring& rhs)`
- `friend xstring operator + (const xstring& lhs, const char c)`
- `friend xstring operator + (const xstring& lhs, const char* rhs)`
- `friend xstring operator + (const xstring& lhs, const std::string& rhs)`
- `friend xstring operator + (const xstring& lhs, const xstring& rhs)`
- `friend std::ostream& operator << (std::ostream& out, const xstring& str)`
- `friend std::istream& operator >> (std::istream& in, const xstring& str)`

## How to check
To run the program cd to root of the repository and create build folder. Then:

1. `cmake -H. -Bbuild`
2. `cmake --build build`
3. `./build/testapp`