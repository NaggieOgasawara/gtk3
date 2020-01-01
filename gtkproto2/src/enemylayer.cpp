#include "enemylayer.h"
#include <cairomm/context.h>
#include <gdkmm/general.h> // set_source_pixbuf()
#include <glibmm/fileutils.h>
#include <iostream>

EnemyLayer::EnemyLayer()
{
  Glib::RefPtr< Gdk::Pixbuf > m_charmap;

  m_enemy[ 0 ] = new EnemyTemplate( 0, 2 );
  for( int i = 1; i < ENEMY_NUM; i++ )
  {
    m_enemy[ i ] = new EnemyTemplate( i );
  }

  //  敵キャラクタの取り込み
  try
  {
    m_charmap = Gdk::Pixbuf::create_from_file("./images/24_24_ascii.png");
  }
  catch( const Glib::FileError& ex )
  {
    std::cerr << "FileError: " << ex.what() << std::endl;
  }
  catch(const Gdk::PixbufError& ex)
  {
    std::cerr << "PixbufError: " << ex.what() << std::endl;
  }

  int k = 0;
    for( int j = 0; j < 8; j++ ) {
      for( int i = 0; i < 16; i++ ) {
        m_enemychar[ k ] = Gdk::Pixbuf::create_from_file("./images/24_24_dummy.png");
        m_charmap->copy_area( i * 24, j * 24, 24, 24, m_enemychar[ k ], 0, 0 );
        k++;
      }
    }

}

EnemyLayer::~EnemyLayer()
{

}

void EnemyLayer::Draw( const Cairo::RefPtr<Cairo::Context>& cr )
{
  if ( m_splite ) {
    for( int i = 0; i < ENEMY_NUM; i++)
      m_enemy[ i ]->Draw( cr );
  }
}

void EnemyLayer::Move()
{
  for( int i = 0; i < ENEMY_NUM; i++)
    m_enemy[ i ]->Move();

}
