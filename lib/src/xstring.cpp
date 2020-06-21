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

void xstring::insert(const char c, size_t pos)
{
  if(pos > m_size)
  {
    pos = m_size;
  }
  m_size += 1;
  char* newBuffer = new char[m_size];
  for(auto i = 0; i < m_size; ++i)
  {
    if(i < pos)
    {
      newBuffer[i] = m_buffer[i];
    }
    else if(i == pos)
    {
      newBuffer[i] = c;
    }
    else
    {
      newBuffer[i] = m_buffer[i-1];
    }
  }
  delete[] m_buffer;
  m_buffer = newBuffer;
}

void xstring::insert(const char* str, size_t pos)
{
  size_t sizeDelta = strlen(str);

  if(pos > m_size)
  {
    pos = m_size;
  }
  m_size += sizeDelta;
  char* newBuffer = new char[m_size];

  for(auto i = 0, j = 0; i < m_size; ++i)
  {
    if(i < pos)
    {
      newBuffer[i] = m_buffer[i];
    }
    else if(i == pos)
    {
      while(j < sizeDelta)
      {
        newBuffer[i++] = str[j++];
      }
      i--;
    }
    else
    {
      newBuffer[i] = m_buffer[i-j];
    }
  }
  delete[] m_buffer;
  m_buffer = newBuffer;
}

void xstring::insert(const std::string str, size_t pos)
{
  size_t sizeDelta = str.size();

  if(pos > m_size)
  {
    pos = m_size;
  }
  m_size += sizeDelta;
  char* newBuffer = new char[m_size];

  for(auto i = 0, j = 0; i < m_size; ++i)
  {
    if(i < pos)
    {
      newBuffer[i] = m_buffer[i];
    }
    else if(i == pos)
    {
      while(j < sizeDelta)
      {
        newBuffer[i++] = str[j++];
      }
      i--;
    }
    else
    {
      newBuffer[i] = m_buffer[i-j];
    }
  }
  delete[] m_buffer;
  m_buffer = newBuffer;
}

void xstring::insert(const xstring str, size_t pos)
{
  size_t sizeDelta = str.length();

  if(pos > m_size)
  {
    pos = m_size;
  }
  m_size += sizeDelta;
  char* newBuffer = new char[m_size];

  for(auto i = 0, j = 0; i < m_size; ++i)
  {
    if(i < pos)
    {
      newBuffer[i] = m_buffer[i];
    }
    else if(i == pos)
    {
      while(j < sizeDelta)
      {
        newBuffer[i++] = str.m_buffer[j++];
      }
      i--;
    }
    else
    {
      newBuffer[i] = m_buffer[i-j];
    }
  }
  delete[] m_buffer;
  m_buffer = newBuffer;
}

void xstring::append(const char c)
{
  char* newBuffer = new char[m_size+1];
  for(auto i = 0; i < m_size; ++i)
  {
    newBuffer[i] = m_buffer[i];
  }
  newBuffer[m_size++] = c;
  delete [] m_buffer;
  m_buffer = newBuffer;
}

void xstring::append(const char* str)
{
  size_t deltaSize = strlen(str);
  char* newBuffer = new char[m_size + deltaSize];
  for(auto i = 0, j = 0; i < m_size + deltaSize; ++i)
  {
    if(i == m_size)
    {
      while(j < deltaSize)
      {
        newBuffer[i++] = str[j++];
      }
      break;
    }
    else
    {
      newBuffer[i] = m_buffer[i];
    }
  }
  m_size += deltaSize;
  delete [] m_buffer;
  m_buffer = newBuffer;
}

void xstring::append(const std::string& str)
{
  size_t deltaSize = str.size();
  char* newBuffer = new char[m_size + deltaSize];
  for(auto i = 0, j = 0; i < m_size + deltaSize; ++i)
  {
    if(i == m_size)
    {
      while(j < deltaSize)
      {
        newBuffer[i++] = str[j++];
      }
      break;
    }
    else
    {
      newBuffer[i] = m_buffer[i];
    }
  }
  m_size += deltaSize;
  delete [] m_buffer;
  m_buffer = newBuffer;
}

void xstring::append(const xstring& str)
{
  size_t deltaSize = str.m_size;
  char* newBuffer = new char[m_size + deltaSize];
  for(auto i = 0, j = 0; i < m_size + deltaSize; ++i)
  {
    if(i == m_size)
    {
      while(j < deltaSize)
      {
        newBuffer[i++] = str.m_buffer[j++];
      }
      break;
    }
    else
    {
      newBuffer[i] = m_buffer[i];
    }
  }
  m_size += deltaSize;
  delete [] m_buffer;
  m_buffer = newBuffer;
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

std::istream& operator >> (std::istream& in, const xstring& str)
{
  for(auto i  = 0; i < str.m_size; ++i)
  {
    in >> str.m_buffer[i];
  }
  return in;
}
}

