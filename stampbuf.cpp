include <streambuf>
#include "stampbuf.h"
#include "stamp.h"
#include <stdexcept>
using namespace stamping_press;

stampbuf::stampbuf(int c, int r) : max_row(r), max_col(c), cur_row(0), cur_col(0),
                                   buffer(new char[10])

{
  insert_plate(max_col, max_row);
  setp(buffer, buffer + 10);
}

void stampbuf::set_col(int c)
{
  cur_col = c;
}

void stampbuf::set_row(int r)
{
  cur_row = r;
}

int stampbuf::get_row()
{
  return cur_row;
}

stampbuf::~stampbuf()
{
  flush_buffer();
  eject_plate();
  delete buffer;
}

int stampbuf::overflow(int ch)
{
  if((char)ch != EOF)
  {
    flush_buffer(ch);
  }

  return ch;
}

void stampbuf::flush_buffer()
{
  for(char* i = pbase(); i != epptr(); ++i)
  {
    write_to_press(*i);
    *i = NULL;
  }
  setp(buffer, buffer + 10);
}

void stampbuf::flush_buffer(int ch)
{
  for(char* i = pbase(); i != epptr(); ++i)
  {
    write_to_press(*i);
    *i = NULL;
  }
  write_to_press((char)ch);
  setp(buffer, buffer + 10);
}

void stampbuf::write_to_press(char ch)
{
  if(cur_col < max_col)
    {
      if(ch == ' ')
      {
        cur_col++;
      }
      else if (ch == get_die())
      {
        stamp(cur_col, cur_row);
        cur_col++;
      }
      else
      {
        try
        {
          set_die(ch);
          stamp(cur_col, cur_row);
        }
        catch(std::invalid_argument) {}
        cur_col++;
      }
    }
}
