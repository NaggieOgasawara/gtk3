#pragma once
#include <iostream>
#include <vector>

class CPallet {
  public:
    CPallet();
    ~CPallet();
    unsigned long pickColor();
    void          createDefaultCLUT();
    int           setColor(unsigned long color);
    void          setCursor(int no);
  private:
    unsigned int  mCursorl;
    unsigned long mPallet[256];
};
