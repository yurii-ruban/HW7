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

void xstring::remove(const char c, size_t pos)
{
  if(m_buffer[pos] != c)
  {
    return;
  }

  char* newBuffer = new char[m_size - 1];
  for(auto i = 0, j = 0; i < m_size; ++i, ++j)
  {
    if(m_buffer[i] == c)
    {
      j--;
      continue;
    }
    newBuffer[j] = m_buffer[i];
  }
  m_size -= 1;
  delete[] m_buffer;
  m_buffer = newBuffer;
}

void xstring::remove(const char *str, size_t pos)
{
  auto occurence = findSubStr(str);
  if(pos != occurence)
  {
    return;
  }

  size_t tempSize = strlen(str);
  char* newBuffer = new char[m_size - strlen(str)];
  for(auto i = 0, j = 0; i < m_size; ++i, ++j)
  {
    if(i == pos)
    {
      while(tempSize--)
      {
        i++;
      }
      j -= 1;
      i-=1;
      continue;
    }
    newBuffer[j] = m_buffer[i];
  }
  m_size -= strlen(str);
  delete[] m_buffer;
  m_buffer = newBuffer;
}

void xstring::remove(const std::string& str, size_t pos)
{
  auto occurence = findSubStr(str.c_str());
  if(pos != occurence || occurence == -1)
  {
    return;
  }

  size_t tempSize = str.size();
  char* newBuffer = new char[m_size - str.size()];
  for(auto i = 0, j = 0; i < m_size; ++i, ++j)
  {
    if(i == pos)
    {
      while(tempSize--)
      {
        i++;
      }
      j -= 1;
      i-=1;
      continue;
    }
    newBuffer[j] = m_buffer[i];
  }
  m_size -= str.size();
  delete[] m_buffer;
  m_buffer = newBuffer;
}

void xstring::remove(const custom::xstring& str, size_t pos)
{
  auto occurence = findSubStr(str.m_buffer);
  if(pos != occurence || occurence == -1)
  {
    return;
  }

  size_t tempSize = str.m_size;
  char* newBuffer = new char[m_size - str.m_size];
  for(auto i = 0, j = 0; i < m_size; ++i, ++j)
  {
    if(i == pos)
    {
      while(tempSize--)
      {
        i++;
      }
      j-=1;
      i-=1;
      continue;
    }
    newBuffer[j] = m_buffer[i];
  }
  m_size -= str.m_size;
  delete[] m_buffer;
  m_buffer = newBuffer;
}


bool xstring::contains(const char c) const
{
  for(auto i = 0; i < m_size; ++i)
  {
    if(m_buffer[i] == c)
    {
      return true;
    }
  }
  return false;
}

bool xstring::contains(const char* str) const
{
  return findSubStr(str) >= 0;
}

bool xstring::contains(const std::string& str) const
{
  return findSubStr(str.c_str()) >= 0;
}

bool xstring::contains(const xstring& str) const
{
  return findSubStr(str.m_buffer) >= 0;
}

size_t xstring::length() const
{
  return m_size;
}

xstring xstring::reverse() const
{
  xstring temp(*this);

  for(auto i = 0; i < m_size/2; ++i)
  {
    swap(temp.m_buffer[i], temp.m_buffer[m_size-i-1]);
  }
  return temp;
}

std::string xstring::toStdString() const
{
  return std::string(m_buffer);
}

xstring& xstring::operator=(const char *rhs)
{
  delete [] m_buffer;
  m_size = strlen(rhs);
  m_buffer = new char[m_size];
  for(auto i = 0; i < m_size; ++i)
  {
    m_buffer[i] = rhs[i];
  }
  return *this;
}

xstring& xstring::operator=(const std::string& rhs)
{
  delete [] m_buffer;
  m_size = rhs.size();
  m_buffer = new char[m_size];
  for(auto i = 0; i < m_size; ++i)
  {
    m_buffer[i] = rhs[i];
  }
  return *this;
}

xstring& xstring::operator=(const xstring& rhs)
{
  if(this == &rhs)
  {
    return *this;
  }

  delete [] m_buffer;
  m_size = rhs.m_size;
  m_buffer = new char[m_size];
  for(auto i = 0; i < m_size; ++i)
  {
    m_buffer[i] = rhs.m_buffer[i];
  }
  return *this;
}

void xstring::prefix_function(const char *str, int *prefixes) const
{
  prefixes[0] = 0; //First prefix is the whole string

  for (size_t i = 1; i < strlen(str); ++i)
  {
    size_t j = prefixes[i-1];
    while ((j > 0) && (str[i] != str[j]))
    {
      j = prefixes[j-1];
    }

    if (str[i] == str[j])
    {
      ++j;
    }
    prefixes[i] = j;
  }
}

int xstring::findSubStr(const char* subStr) const
{
  if(strlen(subStr) > m_size || strlen(subStr) == 0)
  {
    return -1;
  }

  //Calculate prefix function for pattern
  int prefixes[m_size];
  prefix_function(subStr, prefixes);

  //Iterate through string to find the pattern;
  for(auto i = 0, j = 0; i < m_size; ++i)
  {
    while ((j > 0) && (m_buffer[i] != subStr[j]))
    {
      j = prefixes[j-1];
    }

    if (m_buffer[i] == subStr[j])
    {
      ++j;
    }

    if (j == strlen(subStr))
    {
      return i - j + 1;
    }
  }
  return -1;
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

bool operator == (const xstring& lhs, const xstring& rhs)
{
  if(lhs.m_size == rhs.m_size)
  {
    for(auto i = 0; i < lhs.m_size; ++i)
    {
      if(lhs.m_buffer[i] != rhs.m_buffer[i])
      {
        return false;
      }
    }
    return true;
  }
  return false;
}

bool operator == (const xstring& lhs, const std::string& rhs)
{
  if(lhs.m_size == rhs.size())
  {
    for(auto i = 0; i < lhs.m_size; ++i)
    {
      if(lhs.m_buffer[i] != rhs[i])
      {
        return false;
      }
    }
    return true;
  }
  return false;
}

bool operator == (const xstring& lhs, const char* rhs)
{
  if(lhs.m_size == strlen(rhs))
  {
    for(auto i = 0; i < lhs.m_size; ++i)
    {
      if(lhs.m_buffer[i] != rhs[i])
      {
        return false;
      }
    }
    return true;
  }
  return false;
}

xstring operator + (const xstring &lhs, const char c)
{
  size_t tempSize = lhs.m_size + 1;
  char* tmp = new char[tempSize + 1];
  for(auto i = 0; i < lhs.m_size; ++i)
  {
    tmp[i] = lhs.m_buffer[i];
  }
  tmp[lhs.m_size] = c;
  tmp[lhs.m_size + 1] = '\0';

  xstring res(tmp);
  delete[] tmp;

  return res;
}


xstring operator + (const xstring& lhs, const char* rhs)
{
  size_t tempSize = lhs.m_size + strlen(rhs);
  char* tmp = new char[tempSize + 1];
  for(auto i = 0, j = 0; i < tempSize; ++i)
  {
    if(i < lhs.m_size)
    {
      tmp[i] = lhs.m_buffer[i];
    }
    else
    {
      tmp[i] = rhs[j++];
    }
  }
  tmp[tempSize] = '\0';
  xstring res(tmp);
  delete[] tmp;

  return res;
}

xstring operator + (const xstring& lhs, const std::string& rhs)
{
  size_t tempSize = lhs.m_size + rhs.size();
  char* tmp = new char[tempSize + 1];
  for(auto i = 0, j = 0; i < tempSize; ++i)
  {
    if(i < lhs.m_size)
    {
      tmp[i] = lhs.m_buffer[i];
    }
    else
    {
      tmp[i] = rhs[j++];
    }
  }
  tmp[tempSize] = '\0';
  xstring res(tmp);
  delete[] tmp;

  return res;
}

xstring operator + (const xstring& lhs, const xstring& rhs)
{
  size_t tempSize = lhs.m_size + rhs.m_size;
  char* tmp = new char[tempSize + 1];

  for(auto i = 0, j = 0; i < tempSize; ++i)
  {
    if(i < lhs.m_size)
    {
      tmp[i] = lhs.m_buffer[i];
    }
    else
    {
      tmp[i] = rhs.m_buffer[j++];
    }
  }
  tmp[tempSize] = '\0';
  xstring res(tmp);
  delete[] tmp;

  return res;
}

void swap(char &a, char &b)
{
  char c = b;
  b = a;
  a = c;
}

}

