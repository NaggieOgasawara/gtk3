#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "splite.h"
#include <gtkmm/drawingarea.h>
#include <gdkmm/pixbuf.h>
#include <string>

class BackGround : public Splite
{
  Glib::RefPtr< Gdk::Pixbuf > m_image;
  Glib::RefPtr< Gdk::Pixbuf > m_char[ 128 ];

public:
  BackGround();
  virtual ~BackGround();
  void Draw(const Cairo::RefPtr<Cairo::Context>& cr);

protected:

private:
//  void PutString( int x, int y, std::string * str );
  void PutString( const Cairo::RefPtr<Cairo::Context>& cr, int x, int y, std::string * str );
  void PutLetter( const Cairo::RefPtr<Cairo::Context>& cr, int x, int y, int code );
  int m_score;
  int m_highscore;
};

#endif // BACKGROUND_H
