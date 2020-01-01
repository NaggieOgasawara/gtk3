#ifndef ENEMYLAYER_H
#define ENEMYLAYER_H

#include "enemytemplate.h"
#include <cairomm/context.h>
#include <gtkmm/drawingarea.h>
#include <gdkmm/pixbuf.h>

static const int ENEMY_NUM = 14;

class EnemyLayer : public Splite
{
public:
  Glib::RefPtr< Gdk::Pixbuf > m_image;
  Glib::RefPtr< Gdk::Pixbuf > m_enemychar[ 128 ];

  EnemyLayer();
  virtual ~EnemyLayer();
  void Draw( const Cairo::RefPtr<Cairo::Context>& cr );
  void Move();

private:
  EnemyTemplate * m_enemy[ ENEMY_NUM ];
};
#endif  //  ENEMYLAYER_H
