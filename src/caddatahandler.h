#ifndef __CADDATAHANDLER_H__
#define __CADDATAHANDLER_H__

#include <QtCore>
#include "layer.h"
#include "stackup.h"
#include "step.h"
#include "utils.h"

class CadDataHandler
{
public:
  virtual void run(QXmlStreamReader& xml, UnitsType units);
  void odbOutputMatrixAllLayers(QTextStream& out);
  void odbOutputLayerFeature(
      QTextStream &out, QString stepName, QString layerName);

  // getter
  QList<Layer>& layers() { return m_layers; }

private:
  void odbOutputLayer(QTextStream& out, int rowNum, QString context,
      QString type, QString name, QString polarity);
  void odbOutputSingleLayer(QTextStream& out, int rowNum, Layer& layer);

  QList<Layer> m_layers;
  Stackup *m_stackup;
  QList<Step> m_steps;
};

#endif
