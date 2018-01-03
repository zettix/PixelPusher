// cards.cpp Pixel Pusher cards.
// (C) 2018 Sean Brennan

#include <vector>
#include <string>
#include <sstream>
#include <iostream>

#include "card.h"

// return string of some char len times.
std::string dashout(int len) {
  std::stringstream ss;
  for (int i = 0; i < len; i++) {
    ss << " ";
  }
  return ss.str();
}
 
// print a card to std::cout
// 
// looks like this:
/*
   /.........\
   | #     # |   cost, victory points
   |   abc   |     card name
   |         |
   |   OXO   |    pixels/text
   |   txt   |
   \--------#/    card serial number

*/
void Card::print() {
  std::stringstream ss;
  ss << "/" << dashout(18) << "\\" << "\n";  // top row.
  ss << "|" << dashout(1);  // cost / victory line begin.
  if (cost < 10) {
    ss << dashout(1);
  }
  ss << cost << dashout(12);
  if (victory < 10) {
    ss << dashout(1);
  }
  if (victory > 0) {
    ss << victory << dashout(1) << "|" << "\n";
  } else {
    ss << dashout(2) << "|" << "\n";
  }  // cost / victory line end.

  int namelen = name.size();
  int prefix = namelen / 2;

  ss << "|" << dashout(18) << "|\n";
  // name begin.
  ss << "|" << dashout(9 - prefix) << name << dashout(9 - namelen + prefix) << "|\n";
  // name end.
  ss << "|" << dashout(18) << "|\n";
  ss << "|" << dashout(18) << "|\n";

  int linecount = 0;
  // pixels:
  if (card_type == 1) {
    for (int y = 0; y < py; y++) {
      ss << "|" << dashout(9 - px / 2);
      for (int x = 0; x < px; x++) {
        char c = pixels[y * px + x];
        if (c == ' ') {
           c = 'O';
        }
        ss << c;
      }
      ss <<  dashout(9 - px + px / 2) << "|\n";
    }
  } else {
    // limit line length to 18, find spaces in words, paginate.
    bool done = false;
    int ptr = 18;
    int prevp = 0;
    int pixelsize = pixels.size();
    std::stringstream sec2;
    while (! done) {
      bool diddit = false;
      if (ptr >= pixelsize || pixels[ptr] == ' ') {  // search back for a space.
        // space/end found, emit buffer.
        for (int i = prevp; i < ptr; i++) {
          sec2 << pixels[i];
        }
        prevp = ptr + 1;
        ptr = prevp + 18;
        diddit = true;
      }
      ptr--;
      if (ptr <= prevp) {  // couldn't find a space, for words longer than 18 chars.
        ptr = prevp + 18;
        for (int i = prevp; i < ptr; i++) {
          sec2 << pixels[i];
          diddit = true;
        }
        prevp = ptr + 1;
        ptr = prevp + 18;
      }
      if (diddit) {  // if buffer emitted, append to card stringstream, centered, increment line count.
          std::string sec2str = sec2.str();
          int ss2slen = sec2str.length();
          ss << "|" << dashout(9 - ss2slen / 2) << sec2str << dashout(9 - ss2slen + ss2slen / 2) << "|\n";
          linecount++;
          sec2.clear();
          sec2.str(std::string());
      }

      if (ptr >= pixelsize) {  // normal exit, we're searching for a space beyond end of text.
          std::stringstream sec3;
          for (int i = prevp; i < pixels.size(); i++) {
            sec3 << pixels[i];
          }
          std::string sec2str = sec3.str();
          int ss2slen = sec2str.length();
          ss << "|" << dashout(9 - ss2slen / 2) << sec2str << dashout(9 - ss2slen + ss2slen / 2) << "|\n";
          done = true;
      }
    } // while
  } // card type

  if (linecount == 0) {
    linecount = py;
  }

  for (int y = 6 - linecount; y > 0 ; y--)  {
    ss << "|" << dashout(18) << "|\n";
  }
     
  ss << "\\" << dashout(16);
  if (number < 10) {
    ss << dashout(1);
  }
  ss << number << "/" << "\n";
  std::cout << ss.str();
} 

int main(int argc, char **argv) {
  // 3x3 victory cards
  char r33[][10] = {
  // 1
  "X X"
  "   "
  "XXX",
  // 2
  "XXX"
  "X X"
  "XXX",
  // 3
  "XXX"
  " X "
  " X ",
  // 4
  " X "
  "XXX"
  "  X",
  // 5
  " X "
  "XXX"
  "X  ",
  // 6
  "XX "
  "X X"
  "XX "
  };

  // 4x4 victory cards
  char r44 [][17] = {
  // 7
  "X  X"
  "    "
  "X  X"
  "XXXX",
  // 8
  "   X"
  "  XX"
  " X X"
  "XXXX",
  // 9
  "XXXX"
  "  XX"
  " X X"
  "X  X",
  // 10
  "XX  "
  "XX  "
  "  XX"
  "  XX",
  // 11
  "XX  "
  "  XX"
  "XX  "
  "  XX",
  // 12
  "  XX"
  "XX  "
  "  XX"
  "XX  ",
  // 13
  " XX "
  "X  X"
  "X  X"
  " XX ",
  // 14
  "X  X"
  " XX "
  " XX "
  "X  X",
  // 15
  "XXXX"
  "  X "
  " X  "
  "XXXX",
  // 16
  "XXXX"
  " X  "
  "  X "
  "XXXX",
  // 17
  "XXXX"
  "X  X"
  "X  X"
  "XXXX",
  // 18
  "X  X"
  "  X "
  " X  "
  "X  X",
  // 19
  " X  "
  "XXX "
  " XXX"
  "  X ",
  // 20
  "X  X"
  "    "
  "XXXX"
  "X  X",
  // 21
  "X  X"
  "    "
  "    "
  "XXXX",
  // 22
  "X XX"
  "  XX"
  "X   "
  "XXXX",
  // 23
  "XX X"
  "XX  "
  "   X"
  "XXXX"
  };

  // 5x4 victory cards
  char r54 [][21] = {
  // 24
  " X X " 
  "     " 
  "X   X" 
  "XXXXX",
  // 25
  "XXXXX" 
  "X   X" 
  "X   X" 
  "XXXXX",
  // 26
  "  XXX" 
  " X  X" 
  "X  X " 
  "XXX  ",
  // 27
  "XXX  "
  "X  X " 
  " X  X" 
  "  XXX", 
  // 28
  "X X X" 
  "XXXXX" 
  " X X " 
  " X X ",
  // 29
  "  X  " 
  " X X " 
  "X   X" 
  " XXX ",
  // 30
  "X    " 
  "XXX  " 
  "XXXXX" 
  "X    ",
  // 31
  " X  X" 
  "X XXX" 
  "XXX X" 
  "X  X "
  };

  // 4x3 victory cards
  char r43[][13] = {
  // 32
  " XX "
  "X  X"
  " XX ",
  // 33
  "X  X"
  " XX "
  "X  X",
  // 34
  "X  X"
  "    "
  "XXXX",
  // 35
  "X XX"
  "X X "
  "XXX ",
  // 36
  "XX X"
  " X X"
  " XXX",
  // 37
  "   X"
  "XX X"
  " XXX",
  // 38
  "X   "
  "X XX"
  "XXX "
  };

  
  std::vector<Card *> cards;
  //    Card(int number_, int cost_, int victory_, string name_, int card_type,
  //          string pxls_) : number(number_), cost(cost_), victory(victory_),
  //                       #, $, V, name, type, pixels
  cards.push_back(new Card( 1, 3, 1, "Meh", 1, r33[0], 3, 3));
  cards.push_back(new Card( 2, 3, 1, "Box 3x3", 1, r33[1], 3, 3));
  cards.push_back(new Card( 3, 3, 1, "Mr. Tee", 1, r33[2], 3, 3));
  cards.push_back(new Card( 4, 3, 1, "Life Kite", 1, r33[3], 3, 3));
  cards.push_back(new Card( 5, 3, 1, "Ghost face", 1, r33[4], 3, 3));
  cards.push_back(new Card( 6, 3, 1, "D minor", 1, r33[5], 3, 3));

  cards.push_back(new Card( 7, 7, 3, "Happy", 1, r44[0], 4, 4));
  cards.push_back(new Card( 8, 7, 3, "Triangle", 1, r44[1], 4, 4));
  cards.push_back(new Card( 9, 7, 3, "Arrow", 1, r44[2], 4, 4));
  cards.push_back(new Card(10, 7, 3, "Checkers", 1, r44[3], 4, 4));
  cards.push_back(new Card(11, 7, 3, "Left dog leg", 1, r44[4], 4, 4));
  cards.push_back(new Card(12, 7, 3, "Right dog leg", 1, r44[5], 4, 4));
  cards.push_back(new Card(13, 7, 3, "Soft Box", 1, r44[6], 4, 4));
  cards.push_back(new Card(14, 7, 3, "Bomb", 1, r44[7], 4, 4));
  cards.push_back(new Card(15, 7, 3, "Zee", 1, r44[8], 4, 4));
  cards.push_back(new Card(16, 7, 3, "Ess", 1, r44[9], 4, 4));
  cards.push_back(new Card(17, 7, 3, "4 by 4", 1, r44[10], 4, 4));
  cards.push_back(new Card(18, 7, 3, "Divide", 1, r44[11], 4, 4));
  cards.push_back(new Card(19, 7, 3, "Spax", 1, r44[12], 4, 4));
  cards.push_back(new Card(20, 7, 3, "Mad", 1, r44[13], 4, 4));
  cards.push_back(new Card(21, 7, 3, "Indifferent", 1, r44[14], 4, 4));
  cards.push_back(new Card(22, 7, 3, "Crazy here", 1, r44[15], 4, 4));
  cards.push_back(new Card(23, 7, 3, "Crazy there", 1, r44[16], 4, 4));

  cards.push_back(new Card(24, 9, 5, "Exstatic", 1, r54[0], 5, 4));
  cards.push_back(new Card(25, 9, 5, "Long box", 1, r54[1], 5, 4));
  cards.push_back(new Card(26, 9, 5, "Red Pill", 1, r54[2], 5, 4));
  cards.push_back(new Card(27, 9, 5, "Blue Pill", 1, r54[3], 5, 4));
  cards.push_back(new Card(28, 9, 5, "Castle", 1, r54[4], 5, 4));
  cards.push_back(new Card(29, 9, 5, "Kiss", 1, r54[5], 5, 4));
  cards.push_back(new Card(30, 9, 5, "Jet", 1, r54[6], 5, 4));
  cards.push_back(new Card(31, 9, 5, "Art Piece 9", 1, r54[7], 5, 4));

  cards.push_back(new Card(32, 5, 2, "Soft dash", 1, r43[0], 4, 3));
  cards.push_back(new Card(33, 5, 2, "Candy", 1, r43[1], 4, 3));
  cards.push_back(new Card(34, 5, 2, "Smug", 1, r43[2], 4, 3));
  cards.push_back(new Card(35, 5, 2, "Snake comes", 1, r43[3], 4, 3));
  cards.push_back(new Card(36, 5, 2, "Snake goes", 1, r43[4], 4, 3));
  cards.push_back(new Card(37, 5, 2, "Crook", 1, r43[5], 4, 3));
  cards.push_back(new Card(38, 5, 2, "Sickel", 1, r43[6], 4, 3));

  char sprites33[][10] = {
    // 39 - slash
    "  X"
    " X "
    "X  ",
    // 40 - pipe
    " X "
    " X "
    " X ",
    // 41 - two to one
    "X  "
    "  X"
    "  X"};

  cards.push_back(new Card(39, 4, 0, "Slash Sprite", 1, sprites33[0], 3, 3));
  cards.push_back(new Card(40, 4, 0, "Slash Sprite", 1, sprites33[0], 3, 3));
  cards.push_back(new Card(41, 4, 0, "Slash Sprite", 1, sprites33[0], 3, 3));

  cards.push_back(new Card(42, 4, 0, "Pipe Sprite", 1, sprites33[1], 3, 3));
  cards.push_back(new Card(43, 4, 0, "Pipe Sprite", 1, sprites33[1], 3, 3));
  cards.push_back(new Card(44, 4, 0, "Pipe Sprite", 1, sprites33[1], 3, 3));

  cards.push_back(new Card(45, 4, 0, "Two to One Sprite", 1, sprites33[2], 3, 3));
  cards.push_back(new Card(46, 4, 0, "Two to One Sprite", 1, sprites33[2], 3, 3));

  std::vector<std::string> specials;
  specials.push_back("Allow a mirror image of a pattern to match.");  // Mirror
  specials.push_back("Allow a pattern to match with one pixel wrong. "
                     "The victory points are reduced by one."); // Off by one.
  specials.push_back("When placing pixels, if a pixel is already present on"
                     " the board, place your pixel on top of the existing"
                     " pixel."); // burn-in
  // I changed my mind.
  specials.push_back("Dicard this and any other card in your hand.");
  specials.push_back("Treat a sprite card like an eraser."); // Erase

  cards.push_back(new Card(47, 1, 0, "Mirror", 2, specials[0], 0, 0));
  cards.push_back(new Card(48, 1, 0, "Mirror", 2, specials[0], 0, 0));
  cards.push_back(new Card(49, 3, 0, "Off by One", 2, specials[1], 0, 0));
  cards.push_back(new Card(50, 3, 0, "Off by One", 2, specials[1], 0, 0));
  cards.push_back(new Card(51, 3, 0, "Burn In", 2, specials[2], 0, 0));
  cards.push_back(new Card(52, 3, 0, "Burn In", 2, specials[2], 0, 0));
  cards.push_back(new Card(53, 3, 0, "I changed my mind", 2, specials[3], 0, 0));
  cards.push_back(new Card(54, 3, 0, "I changed my mind", 2, specials[3], 0, 0));
  cards.push_back(new Card(55, 3, 0, "Erase", 2, specials[4], 0, 0));
  cards.push_back(new Card(56, 3, 0, "Erase", 2, specials[4], 0, 0));

  for (int i = 0; i < cards.size(); i++) {
    if (i % 4 == 0 && i != 0) { std::cout << "" << std::endl; }
    else {
     std::cout << "\n"; };
    Card *c = cards[i];
    c->print();
  }
  // cleanup
  for (int i = 0; i < cards.size(); i++) {
    delete cards[i];
  }
}
