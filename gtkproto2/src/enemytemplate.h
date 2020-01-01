#ifndef ENEMYTEMPLATE_H
#define ENEMYTEMPLATE_H

#include "splite.h"
#include <random>
#include <gtkmm/drawingarea.h>
#include <gdkmm/pixbuf.h>
#include "stabledance.h"
enum E_status { E_INIT = 0, E_STABLE = 1, E_ATACK1 = 2, E_ATACK2 = 3 };

static const int r1[24][2] = {
    {138,598},
    {172,594},
    {203,581},
    {230,560},
    {251,533},
    {264,502},
    {268,468},
    {264,434},
    {251,403},
    {230,376},
    {203,355},
    {172,342},
    {138,338},
    {104,342},
    {73,355},
    {46,376},
    {25,403},
    {12,434},
    {8,468},
    {12,502},
    {25,533},
    {46,560},
    {73,581},
    {104,594}
  };

class EnemyTemplate : public Splite
{
//  Cairo::RefPtr<Cairo::Context> m_gc;
//  Glib::RefPtr< Gdk::GC > m_gc;
  Glib::RefPtr< Gdk::Pixbuf > m_image;

public:
  EnemyTemplate();
  EnemyTemplate(int no, int status = 1);
  virtual ~EnemyTemplate();
  void setNo(int no);
  void Draw(const Cairo::RefPtr<Cairo::Context>& cr);
  void Move();

protected:

private:
  void ChangeStatus();

  int m_no;
  bool m_live;
  int m_x;
  int m_y;
  int m_status;
  //  0:  Intro
  //  1:  Stable
  //  2:  Attack1
  //  3:  Attack2
  int m_index;
};

#endif // ENEMYTEMPLATE_H
