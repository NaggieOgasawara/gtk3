#ifndef GTKMM_EXAMPLE_MYAREA_H
#define GTKMM_EXAMPLE_MYAREA_H

#include "shootingcontrol.h"
#include <gtkmm/drawingarea.h>

//static const int STAR_NUM = 50;

class MyArea : public Gtk::DrawingArea
{
public:
  MyArea();
  virtual ~MyArea();
  void get_keyEvent(int key);

protected:
  //Override default signal handler:
  bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;

  bool on_timeout();

//  MyStar mystar[STAR_NUM];

private:
  ShootingControl m_control;
  int m_key;

};

#endif // GTKMM_EXAMPLE_MYAREA_H
