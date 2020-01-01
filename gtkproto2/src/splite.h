#ifndef SPLITE_H
#define SPLITE_H

class Splite
{
public:
  Splite();
  virtual ~Splite();
  virtual void splite_on();
  virtual void splite_off();

protected:
  bool  m_splite;

private:
};

#endif // SPLITE_H
