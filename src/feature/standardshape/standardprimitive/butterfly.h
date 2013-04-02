#ifndef __BUTTERFLY_H__
#define __BUTTERFLY_H__

#include "standardprimitive.h"


class Butterfly : public StandardPrimitive
{
public:
  virtual void initialize(QXmlStreamReader& xml, UnitsType units);
  enum ButterflyShape { ROUND, SQUARE };
  virtual void odbOutputLayerFeature(
      OdbFeatureFile& file,
      QString polarity,
      QPointF location, Xform *xform);

private:
  ButterflyShape m_shape;
  qreal m_diameter; // for ROUND butterfly
  qreal m_side; // for SQUARE butterfly
};

#endif
