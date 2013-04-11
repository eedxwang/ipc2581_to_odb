#include "hexagon.h"

void
Hexagon::initialize(QXmlStreamReader& xml, UnitsType units)
{
  m_length = Length(
      getNonNegativeDoubleAttribute(xml, "Hexagon", "length"), units);
}

void
Hexagon::odbOutputLayerFeature(
    OdbFeatureFile& file, QString polarity,
    QPointF location, Xform *xform)
{
  QString symbol = QString("hex_s%1x%2x%3")
                           .arg(m_length.lengthMil() * 0.5 * qSqrt(3))
                           .arg(m_length.lengthMil())
                           .arg(m_length.lengthMil() * 0.25);
  int symNum = odbInsertSymbol(symbol, file.symbolsTable());
  QPointF newLocation = calcTransformedLocation(location, xform);
  int orient = odbDecideOrient(xform);
  file.featuresList().append(QString("P %1 %2 %3 %4 0 %5\n")
                              .arg(newLocation.x())
                              .arg(newLocation.y())
                              .arg(symNum)
                              .arg(polarity)
                              .arg(orient));
}
