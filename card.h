#include <string>
// Copyright(C) 2018 Sean Brennan

#ifndef __com_zettix_pixel_pusher_h__
#define __com_zettix_pixel_pusher_h__
class Card {
  public:
    int number;
    int cost;
    int px;
    int py;
    int victory;
    std::string name;
    std::string pixels;
    int card_type;

    Card(int number_, int cost_, int victory_, std::string name_, int ctyp_,
          std::string pxls_, int px_, int py_) : number(number_), cost(cost_),
          victory(victory_), name(name_), card_type(ctyp_), pixels(pxls_),
          px(px_), py(py_) {}
    void print();
};
    
#endif
