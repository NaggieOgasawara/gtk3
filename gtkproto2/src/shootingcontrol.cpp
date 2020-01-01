#include "shootingcontrol.h"
#include <cairomm/context.h>


ShootingControl::ShootingControl()
{
  m_background = new BackGround;
  m_StarLayer = new StarLayer;
  m_EnemyLayer = new EnemyLayer;
/*
  m_enemy[ 0 ] = new EnemyTemplate( 0, 2 );
  for( int i = 1; i < ENEMY_NUM; i++ )
  {
    m_enemy[ i ] = new EnemyTemplate( i );
//    m_enemy[ i ]->setNo(i);
  }
  */
}

ShootingControl::~ShootingControl()
{

}

void ShootingControl::Draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
  // draw BackGround
  m_background->Draw( cr );

  // draw Star
  m_StarLayer->Draw( cr );

  // draw Enemy
  m_EnemyLayer->Draw( cr );
  /*
  for( int i = 0; i < ENEMY_NUM; i++)
    m_enemy[ i ]->Draw( cr );
  */
}

void ShootingControl::Move()
{
  //  星を動かす
  m_StarLayer->Move();

  m_EnemyLayer->Move();
  /*
  for( int i = 0; i < ENEMY_NUM; i++)
    m_enemy[ i ]->Move();
  */
}
