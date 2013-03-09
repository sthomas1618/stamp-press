#include <iostream>
#include "stampstream.h"
#include "stampbuf.h"
using namespace std;

stampstream::stampstream(int c, int r) : ostream(new stampbuf(c,r))
{
}

stampstream::~stampstream()
{
  stampbuf* sb = dynamic_cast<stampbuf*>(rdbuf());
  delete sb;
}