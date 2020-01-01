#include "myArea.h"
#include <iostream>
#include <cairomm/context.h>
#include <ctime>
#include <cmath>
#include <glibmm/main.h>

MyArea::MyArea()
{
  Glib::signal_timeout().connect( sigc::mem_fun(*this, &MyArea::on_timeout), 25 );
}

MyArea::~MyArea()
{
}

bool MyArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
// draw All
  m_control.Draw(cr);

//  std::cout << "on_Draw" << std::endl;
  return true;
}

bool MyArea::on_timeout()
{
// move All
  m_control.Move();

  // force our program to redraw the entire clock.
  auto win = get_window();
  if (win)
  {
      Gdk::Rectangle r(0, 0, get_allocation().get_width(),
              get_allocation().get_height());
      win->invalidate_rect(r, false);
  }
  return true;
}

void MyArea::get_keyEvent(int key)
{
  std::cout << key << std::endl;
  m_key = key;
}
