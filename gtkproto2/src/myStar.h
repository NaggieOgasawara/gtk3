#ifndef GTKMM_EXAMPLE_MYSTAR_H
#define GTKMM_EXAMPLE_MYSTAR_H

#include "splite.h"
#include <random>
#include <gtkmm/drawingarea.h>

class MyStar : public Splite
{
public:
  MyStar();
  virtual ~MyStar();
  void Draw(const Cairo::RefPtr<Cairo::Context>& cr);
  void Move();

protected:
  int m_x;
  int m_y;
  int m_size;
  int m_color;
  int m_speed;

};

#endif // GTKMM_EXAMPLE_MYSTAR_H
