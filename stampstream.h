#ifndef STAMPSTREAM_H
#define STAMPSTREAM_H

#include <iostream>
using namespace std;

class stampstream : public ostream {
  public:
    stampstream(int c, int r);
    ~stampstream();
};

#endif