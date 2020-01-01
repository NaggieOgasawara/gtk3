#ifndef PLAYER_H
#define PLAYER_H

#include <gtkmm/drawingarea.h>

class Player
{
public:
  Player();
  virtual ~Player();
  void Draw(const Cairo::RefPtr<Cairo::Context>& cr);
  void Move();

protected:

private:
};

#endif // PLAYER_H
