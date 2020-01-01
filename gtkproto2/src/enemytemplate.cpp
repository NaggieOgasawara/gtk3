#include "enemytemplate.h"
#include <cairomm/context.h>
#include <gdkmm/general.h> // set_source_pixbuf()
#include <glibmm/fileutils.h>
#include <iostream>

EnemyTemplate::EnemyTemplate()
{
  m_splite = true;
  m_live = true;
  m_status = 1;
  m_index = 0;
  m_x = r1[m_index][0];
  m_y = r1[m_index][1];

  try
  {
    m_image = Gdk::Pixbuf::create_from_file("./images/bee.png");
  }
  catch(const Glib::FileError& ex)
  {
    std::cerr << "FileError: " << ex.what() << std::endl;
  }
  catch(const Gdk::PixbufError& ex)
  {
    std::cerr << "PixbufError: " << ex.what() << std::endl;
  }
}

EnemyTemplate::EnemyTemplate(int no, int status )
{
  m_splite = true;
  m_no = no;
  m_live = true;
  m_status = status;
  m_index = 0;

  m_x = r1[m_index][0];
  m_y = r1[m_index][1];

  try
  {
    m_image = Gdk::Pixbuf::create_from_file("./images/bee.png");
  }
  catch(const Glib::FileError& ex)
  {
    std::cerr << "FileError: " << ex.what() << std::endl;
  }
  catch(const Gdk::PixbufError& ex)
  {
    std::cerr << "PixbufError: " << ex.what() << std::endl;
  }
}

EnemyTemplate::~EnemyTemplate()
{

}

void EnemyTemplate::setNo(int no)
{
  m_no = no;
}

void EnemyTemplate::Draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
  if ( m_live ) {
    Gdk::Cairo::set_source_pixbuf(cr, m_image,m_x,m_y);
    cr->paint();
  }
}

void EnemyTemplate::Move()
{
  if ( m_live )
  {
    // m_status の値で動作を決める。
    switch( m_status ){
      case E_INIT:
        //  画面に入ってくるステータス
        break;
      case E_STABLE:
        m_index++;
        if( m_index > 71 )
          m_index = 0;
        m_x = sta1[m_no][0] + stadan[m_index][0];
        m_y = sta1[m_no][1] + stadan[m_index][1];
        //
        // m_x = sta[m_no][0];
        // m_y = sta[m_no][1];
        break;
      case E_ATACK1:
        m_index++;
        if ( m_index > 24 )
          m_index = 0;
        m_x = r1[m_index][0];
        m_y = r1[m_index][1];
        break;
      }
    }
}

void EnemyTemplate::ChangeStatus()
{
  std::random_device rnd;
  std::mt19937 mt(rnd());
  std::uniform_int_distribution<> rand9(0,9);
  m_status = rand9(mt);

}
