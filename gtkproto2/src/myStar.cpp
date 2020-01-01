#include "myStar.h"
#include  <iostream>

MyStar::MyStar()
{
  std::random_device rnd;
  std::mt19937 mt(rnd());
  std::uniform_int_distribution<> rand960(0,960);
  m_y = rand960(mt);
  std::uniform_int_distribution<> rand600(0,600);
  m_x = rand600(mt);
  std::uniform_int_distribution<> rand7(0,7);
  m_color = rand7(mt);
  std::uniform_int_distribution<> rand2(0,2);
  m_speed = rand2(mt) + 1;
}

MyStar::~MyStar()
{
}

void MyStar::Draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
  switch( m_color ){
    case 0:
      cr->set_source_rgb( 0.0, 0.0, 1.0);
      break;
    case 1:
      cr->set_source_rgb( 0.0, 1.0, 0.0);
      break;
    case 2:
      cr->set_source_rgb( 0.0, 1.0, 1.0);
      break;
    case 3:
      cr->set_source_rgb( 1.0, 0.0, 0.0);
      break;
    case 4:
      cr->set_source_rgb( 1.0, 0.0, 1.0);
      break;
    case 5:
      cr->set_source_rgb( 1.0, 1.0, 0.0);
      break;
    default:
      cr->set_source_rgb( 1.0, 1.0, 1.0);
      break;
  }
  cr->rectangle( m_x, m_y, m_speed, m_speed );
  cr->fill();
}

void MyStar::Move()
{
  m_y = m_y + m_speed;
  if ( m_y > 960 ) {
    m_y = 0;
    std::random_device rnd;
    std::mt19937 mt(rnd());
    std::uniform_int_distribution<> rand600(0,600);
    m_x = rand600(mt);
    std::uniform_int_distribution<> rand7(0,7);
    m_color = rand7(mt);
    std::uniform_int_distribution<> rand2(0,2);
    m_speed = rand2(mt) + 1;
  }
}
