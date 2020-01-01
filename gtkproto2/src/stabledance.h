#ifndef STABLEDANCE_H
#define STABLEDANCE_H

static const int centerX = 300;
static const int centerY = 100;
static const int ratioX = 20;
static const int ratioY = 10;

static const float stadan[][3] = {
  { centerX + 0.00 * ratioX, centerY + 0.00 * ratioY, 0 },     //  1
  { centerX + -0.02 * ratioX, centerY + 0.17 * ratioY, 0 },    //  2
  { centerX + -0.06 * ratioX, centerY + 0.34 * ratioY, 0 },    //  3
  { centerX + -0.13 * ratioX, centerY + 0.50 * ratioY, 0 },    //  4
  { centerX + -0.23 * ratioX, centerY + 0.64 * ratioY, 0 },    //  5
  { centerX + -0.36 * ratioX, centerY + 0.77 * ratioY, 0 },    //  6
  { centerX + -0.50 * ratioX, centerY + 0.87 * ratioY, 0 },    //  7
  { centerX + -0.66 * ratioX, centerY + 0.94 * ratioY, 0 },    //  8
  { centerX + -0.83 * ratioX, centerY + 0.98 * ratioY, 0 },    //  9
  { centerX + -1.00 * ratioX, centerY + 1.00 * ratioY, 0 },    //  10
  { centerX + -1.17 * ratioX, centerY + 0.98 * ratioY, 0 },    //  11
  { centerX + -1.34 * ratioX, centerY + 0.94 * ratioY, 0 },    //  12
  { centerX + -1.50 * ratioX, centerY + 0.87 * ratioY, 0 },    //  13
  { centerX + -1.64 * ratioX, centerY + 0.77 * ratioY, 0 },    //  14
  { centerX + -1.77 * ratioX, centerY + 0.64 * ratioY, 0 },    //  15
  { centerX + -1.87 * ratioX, centerY + 0.50 * ratioY, 0 },    //  16
  { centerX + -1.94 * ratioX, centerY + 0.34 * ratioY, 0 },    //  17
  { centerX + -1.98 * ratioX, centerY + 0.17 * ratioY, 0 },    //  18
  { centerX + -2.00 * ratioX, centerY + 0.00 * ratioY, 0 },    //  19
  { centerX + -1.98 * ratioX, centerY + -0.17 * ratioY, 0 },   //  20
  { centerX + -1.94 * ratioX, centerY + -0.34 * ratioY, 0 },   //  21
  { centerX + -1.87 * ratioX, centerY + -0.50 * ratioY, 0 },   //  22
  { centerX + -1.77 * ratioX, centerY + -0.64 * ratioY, 0 },   //  23
  { centerX + -1.64 * ratioX, centerY + -0.77 * ratioY, 0 },   //  24
  { centerX + -1.50 * ratioX, centerY + -0.87 * ratioY, 0 },   //  25
  { centerX + -1.34 * ratioX, centerY + -0.94 * ratioY, 0 },   //  26
  { centerX + -1.17 * ratioX, centerY + -0.98 * ratioY, 0 },   //  27
  { centerX + -1.00 * ratioX, centerY + -1.00 * ratioY, 0 },   //  28
  { centerX + -0.83 * ratioX, centerY + -0.98 * ratioY, 0 },   //  29
  { centerX + -0.66 * ratioX, centerY + -0.94 * ratioY, 0 },   //  30
  { centerX + -0.50 * ratioX, centerY + -0.87 * ratioY, 0 },   //  31
  { centerX + -0.36 * ratioX, centerY + -0.77 * ratioY, 0 },   //  32
  { centerX + -0.23 * ratioX, centerY + -0.64 * ratioY, 0 },   //  33
  { centerX + -0.13 * ratioX, centerY + -0.50 * ratioY, 0 },   //  34
  { centerX + -0.06 * ratioX, centerY + -0.34 * ratioY, 0 },   //  35
  { centerX + -0.02 * ratioX, centerY + -0.17 * ratioY, 0 },   //  36
  { centerX + 0.00 * ratioX, centerY + 0.00 * ratioY, 0 },     //  37
  { centerX + 0.02 * ratioX, centerY + 0.17 * ratioY, 0 },     //  38
  { centerX + 0.06 * ratioX, centerY + 0.34 * ratioY, 0 },     //  39
  { centerX + 0.13 * ratioX, centerY + 0.50 * ratioY, 0 },     //  40
  { centerX + 0.23 * ratioX, centerY + 0.64 * ratioY, 0 },     //  41
  { centerX + 0.36 * ratioX, centerY + 0.77 * ratioY, 0 },     //  42
  { centerX + 0.50 * ratioX, centerY + 0.87 * ratioY, 0 },     //  43
  { centerX + 0.66 * ratioX, centerY + 0.94 * ratioY, 0 },     //  44
  { centerX + 0.83 * ratioX, centerY + 0.98 * ratioY, 0 },     //  45
  { centerX + 1.00 * ratioX, centerY + 1.00 * ratioY, 0 },     //  46
  { centerX + 1.34 * ratioX, centerY + 0.94 * ratioY, 0 },     //  47
  { centerX + 1.17 * ratioX, centerY + 0.98 * ratioY, 0 },     //  48
  { centerX + 1.50 * ratioX, centerY + 0.87 * ratioY, 0 },     //  49
  { centerX + 1.64 * ratioX, centerY + 0.77 * ratioY, 0 },     //  50
  { centerX + 1.77 * ratioX, centerY + 0.64 * ratioY, 0 },     //  51
  { centerX + 1.87 * ratioX, centerY + 0.50 * ratioY, 0 },     //  52
  { centerX + 1.98 * ratioX, centerY + 0.17 * ratioY, 0 },     //  53
  { centerX + 1.94 * ratioX, centerY + 0.34 * ratioY, 0 },     //  54
  { centerX + 2.00 * ratioX, centerY + 0.00 * ratioY, 0 },     //  55
  { centerX + 1.98 * ratioX, centerY + -0.17 * ratioY, 0 },    //  56
  { centerX + 1.94 * ratioX, centerY + -0.34 * ratioY, 0 },    //  57
  { centerX + 1.87 * ratioX, centerY + -0.50 * ratioY, 0 },    //  58
  { centerX + 1.77 * ratioX, centerY + -0.64 * ratioY, 0 },    //  59
  { centerX + 1.64 * ratioX, centerY + -0.77 * ratioY, 0 },    //  60
  { centerX + 1.50 * ratioX, centerY + -0.87 * ratioY, 0 },    //  61
  { centerX + 1.34 * ratioX, centerY + -0.94 * ratioY, 0 },    //  62
  { centerX + 1.17 * ratioX, centerY + -0.98 * ratioY, 0 },    //  63
  { centerX + 1.00 * ratioX, centerY + -1.00 * ratioY, 0 },    //  64
  { centerX + 0.83 * ratioX, centerY + -0.98 * ratioY, 0 },    //  65
  { centerX + 0.66 * ratioX, centerY + -0.94 * ratioY, 0 },    //  66
  { centerX + 0.50 * ratioX, centerY + -0.87 * ratioY, 0 },    //  67
  { centerX + 0.36 * ratioX, centerY + -0.77 * ratioY, 0 },    //  68
  { centerX + 0.23 * ratioX, centerY + -0.64 * ratioY, 0 },    //  69
  { centerX + 0.13 * ratioX, centerY + -0.50 * ratioY, 0 },    //  70
  { centerX + 0.06 * ratioX, centerY + -0.34 * ratioY, 0 },    //  71
  { centerX + 0.02 * ratioX, centerY + -0.17 * ratioY, 0 }     //  72
  };

  static const int sta1[][2] = {
    {    0,  0 },
    { -100,  0 },
    {  -50,  0 },
    {   50,  0 },
    {  100,  0 },
    { -175, 40 },
    { -125, 40 },
    {  -75, 40 },
    {  -25, 40 },
    {   25, 40 },
    {   75, 40 },
    {  125, 40 },
    {  175, 40 },
    { -225, 80 }
  };

  static const int sta[][2] = {
    { 300, 50 },
    {200,50},
    {250,50},
    {350,50},
    {400,50},
    {125,90},
    {175,90},
    {225,90},
    {275,90},
    {325,90},
    {375,90},
    {425,90},
    {475,90},
    {75,130}
  };

#endif  // STABLEDANCE_H
