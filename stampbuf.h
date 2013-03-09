// Stephen Thomas
// Project 3
// CSCI 511

#ifndef STAMPBUF_H
#define STAMPBUF_H

#include <streambuf>
using namespace std;

class stampbuf : public streambuf {
  public:
    stampbuf(int c, int r);
    void set_col(int c);
    void set_row(int r);
    int  get_row();
    void flush_buffer();  
    ~stampbuf();

  private:
    int max_row;
    int max_col;
    int cur_row;
    int cur_col;
    char* buffer;
    virtual int overflow(int ch);
    void flush_buffer(int ch);  
    void write_to_press(char ch);
};

#endif