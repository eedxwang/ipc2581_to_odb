#ifndef __OVAL_H__
#define __OVAL_H__

#include "standardprimitive.h"

class Oval : public StandardPrimitive
{
public:
  virtual void initialize(QXmlStreamReader& xml);
  virtual void odbOutputLayerFeature(
      QList<QString>& symbolsTable,
      QList<QString>& attributeTable,
      QList<QString>& attributeTexts,
      QList<QString>& featuresList,
      QString polarity,
      QPointF location, Xform *xform);

private:
  qreal m_width;
  qreal m_height;
};

#endif
