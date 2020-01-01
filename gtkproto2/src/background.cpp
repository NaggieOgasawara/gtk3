#include "background.h"
#include <cairomm/context.h>
#include <gdkmm/general.h> // set_source_pixbuf()
#include <glibmm/fileutils.h>
#include <iostream>

BackGround::BackGround()
{
  Glib::RefPtr< Gdk::Pixbuf > m_charmap;

  m_score = 0;
  m_highscore = 0;

  try
  {
    // The fractal image has been created by the XaoS program.
    // http://xaos.sourceforge.net
    m_image = Gdk::Pixbuf::create_from_file("./images/test_background.png");
  }
  catch(const Glib::FileError& ex)
  {
    std::cerr << "FileError: " << ex.what() << std::endl;
  }
  catch(const Gdk::PixbufError& ex)
  {
    std::cerr << "PixbufError: " << ex.what() << std::endl;
  }

//  文字の取り込み
  try
  {
    m_charmap = Gdk::Pixbuf::create_from_file("./images/24_24_ascii.png");
  }
  catch(const Glib::FileError& ex)
  {
    std::cerr << "FileError: " << ex.what() << std::endl;
  }
  catch(const Gdk::PixbufError& ex)
  {
    std::cerr << "PixbufError: " << ex.what() << std::endl;
  }

//  Gdk::Pixbuf::copy_area(0,0,36,36,&m_char[0],0,0);
//  m_char[ 0 ] = Gdk::Pixbuf::new(); パラメータが良くわからないので使えない。
int k = 0;
  for( int j = 0; j < 8; j++ ) {
    for( int i = 0; i < 16; i++ ) {
      m_char[ k ] = Gdk::Pixbuf::create_from_file("./images/24_24_dummy.png");
      m_charmap->copy_area( i * 24, j * 24, 24, 24, m_char[ k ], 0, 0 );
      k++;
    }
  }
}

BackGround::~BackGround()
{

}

void BackGround::Draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
  std::string s = "HELLO";
  PutString( cr, 5, 24, &s );
/*
  cr->rectangle(0,0,600,960);
  cr->fill();
*/
/*
  Gdk::Cairo::set_source_pixbuf( cr, m_image, 0, 0 );
  cr->paint();

  for( int j = 0; j < 8; j++ ){
    for( int i = 0; i < 16; i++ ) {
      PutLetter( cr, i * 24 + 5, j * 24 + 5, j * 16 + i );
//      Gdk::Cairo::set_source_pixbuf( cr, m_char[ j * 16 + i ], i * 24 + 5 ,j * 24 + 5 );
//      cr->paint();
    }
  }
*/
}

//void BackGround::PutString( int x, int y, std::string * str )
void BackGround::PutString( const Cairo::RefPtr<Cairo::Context>& cr, int x, int y, std::string * str )
{
  std::string::iterator ptr;
  for( ptr = str->begin(); ptr != str->end(); ptr++) {
//    PutLetter( cr, x, y, (int)str[ i ] );
    PutLetter( cr, x, y, *ptr );
    x = x + 24;
  }
}

void BackGround::PutLetter( const Cairo::RefPtr<Cairo::Context>& cr, int x, int y, int code )
{
  Gdk::Cairo::set_source_pixbuf( cr, m_char[ code ], x, y );
  cr->paint();
}
