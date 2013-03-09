// Stephen Thomas
// Project 3
// CSCI 511

#include <iostream>
#include "stampbuf.h"
using namespace std;

class row {
  public:
    row(int r) : _r(r) {}
    int  get_row() const { return _r; }
  private:
    int  _r;
};

ostream& operator<<(ostream& os, const row& r)
{
  stampbuf* sb = dynamic_cast<stampbuf*>(os.rdbuf());
  sb->flush_buffer();
  sb->set_col(0);
  sb->set_row(r.get_row());

  return os;
}

ostream &endrow(ostream& os)
{
  stampbuf* sb = dynamic_cast<stampbuf*>(os.rdbuf());
  sb->flush_buffer();
  sb->set_col(0);
  int cur_row = sb->get_row();
  sb->set_row(cur_row + 1);

  return os;
}