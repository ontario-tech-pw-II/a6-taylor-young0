// str.cpp

#include "str.h"
#include <cstring>
#include <iostream>

str::str()
{
  _buf = nullptr;
  _n = 0;
}

str::str(char ch)
{
   _n = 1;
  _buf = new char[_n];
  _buf[0] = ch;
}

str::str(const char* c_str)
{
  _n = strlen(c_str);
  _buf = new char[_n];
  for (int i = 0; i < _n; ++i)
    _buf[i] = c_str[i];
}
str::str(const str &s)
{
  _n = s._n;
  _buf = new char[_n];
  for (int i = 0; i < _n; ++i)
    _buf[i] = s._buf[i];
}

str::~str()
{
  if (_buf)
    delete [] _buf;
  _n = 0;
  _buf = nullptr;
}

str & str::operator=(const str &s2) {
  _n = s2.length();
  _buf = new char(_n);

  // Copy in the underlying string
  for (int i = 0; i < _n; i++) {
    _buf[i] = s2._buf[i];
  }

  return *this;
}

str str::operator+(const str &s2) {
  str s3;

  // Get the size of our combined string
  s3._n = this->_n + s2._n;
  // Create a new string to hold the combined strings
  s3._buf = new char[s3._n];

  // Add the two strings together
  for (int i = 0, j = 0; i < s3._n; i++) {
    // if we are at an index where we add the first string
    if (i < this->_n) {
      s3._buf[i] = this->_buf[i];
    } else {
      // We start adding at index 0 from second string, but add to ith index
      s3._buf[i] = s2._buf[j];
      j++;
    }
  }

  return s3;
}

void str::print()
{
  for (int i = 0; i < _n; ++i)
    cout << _buf[i];
  cout << endl;
}

void str::clear()
{
  if (_buf)
    delete [] _buf;

  _buf = nullptr;
  _n = 0;
}

void str::append(const str & s)
{
  char *p = new char[_n + s._n];

  int i;

  for (i = 0; i < _n; ++i)
    p[i] = _buf[i];

  for (int j = 0; j < s._n; ++i,++j)
    p[i] = s._buf[j];

  if (_buf)
    delete [] _buf;

  _buf = p;
  _n = _n + s._n;
}

void swap(str& x, str& y)
{
  char *tmp;
  int ntmp;

  tmp = x._buf;
  x._buf = y._buf;
  y._buf = tmp;

  ntmp = x._n;
  x._n = y._n;
  y._n = ntmp;

}

istream & operator>>(istream & in, str & s1) {
  // Create a new string
  char *c = new char[200];
  cout << "Enter string: ";
  in >> c;

  s1 = str(c);
  delete [] c;
  return in;
}

ostream & operator<<(ostream & out, str & s1) {
  out << s1._buf;
  return out;
}
