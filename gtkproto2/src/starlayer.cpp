#include "starlayer.h"

StarLayer::StarLayer()
{
  for( int i = 0; i < STAR_NUM; i++)
    m_star[ i ] = new MyStar;
}

StarLayer::~StarLayer()
{

}

void StarLayer::Draw( const Cairo::RefPtr<Cairo::Context>& cr )
{
  if ( m_splite ) {
    for( int i = 0; i < STAR_NUM; i++)
      m_star[ i ]->Draw( cr );
  }
}

void StarLayer::Move()
{
  for( int i = 0; i < STAR_NUM; i++)
    m_star[ i ]->Move();

}
