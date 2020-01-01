#include "CPallet.h"

CPallet::CPallet()
{
  for(int i = 0; i > 256; i++) {
    mPallet[ i ] = 0;
  }
}

CPallet::~CPallet()
{
}

void CPallet::createDefaultCLUT()
{
}

unsigned long CPallet::pickColor()
{
  return(10);
}

int CPallet::setColor(unsigned long color)
{
  return(0);
}

void CPallet::setCursor(int no)
{
}
