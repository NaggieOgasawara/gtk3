#ifndef SHOOTING_CONTROL_H
#define SHOOTING_CONTROL_H

#include "background.h"
#include "starlayer.h"
#include "enemylayer.h"
#include "player.h"
//#include "enemytemplate.h"
#include <gtkmm/drawingarea.h>

class ShootingControl
{
public:
  ShootingControl();
  virtual ~ShootingControl();
  void Draw(const Cairo::RefPtr<Cairo::Context>& cr);
  void Move();

protected:
  BackGround * m_background;
  StarLayer * m_StarLayer;
  EnemyLayer * m_EnemyLayer;
  Player * m_player;
//  EnemyTemplate * m_enemy[ENEMY_NUM];

private:
  int m_stage;
};

#endif // SHOOTING_CONTROL_H
