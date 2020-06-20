#include "xstring.h"

namespace custom
{
  xstring::xstring() : m_size(0), m_buffer(nullptr){}

  xstring::xstring(const char* str) : m_size(strlen(str)), m_buffer(new char[m_size])
  {
    for(auto i = 0; i < m_size; ++i)
    {
      m_buffer[i] = str[i];
    }
  }

  xstring::xstring(const std::string& str) : m_size(str.size()), m_buffer(new char[m_size])
  {
    for(auto i = 0; i < m_size; ++i)
    {
      m_buffer[i] = str.c_str()[i];
    }
  }

  xstring::xstring(const xstring& other) : m_size(other.m_size), m_buffer(new char[m_size])
  {
    for(auto i = 0; i < m_size; ++i)
    {
      m_buffer[i] = other.m_buffer[i];
    }
  }

  xstring::xstring(xstring&& other) : m_size(other.m_size), m_buffer(other.m_buffer)
  {
    other.m_size = 0;
    other.m_buffer = nullptr;
  }

  xstring::~xstring()
  {
    delete[] m_buffer;
  }

  size_t xstring::length() const
  {
    return m_size;
  }

  std::ostream& operator << (std::ostream& out, const xstring& str)
  {
    for(auto i  = 0; i < str.m_size; ++i)
    {
      out << str.m_buffer[i];
    }
    return out;
  }
}

