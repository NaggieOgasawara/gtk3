#ifndef STARLAYER_H
#define STARLAYER_H

#include "myStar.h"
#include <cairomm/context.h>

static const int STAR_NUM = 250;

class StarLayer : public Splite
{
public:
  StarLayer();
  virtual ~StarLayer();
  void Draw( const Cairo::RefPtr<Cairo::Context>& cr );
  void Move();

private:
  MyStar * m_star[ STAR_NUM ];
};
#endif  //  STARLAYER_H
