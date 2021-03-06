#ifndef __SET_H__
#define __SET_H__

#include <QtCore>
#include "attribute.h"
#include "pad.h"
#include "fiducial.h"
#include "hole.h"
#include "slot.h"
#include "featuresgroup.h"
#include "colorgroup.h"
#include "linedescgroup.h"
#include "standardprimitive.h"
#include "userprimitive.h"
#include "odbfeaturefile.h"
#include "utils.h"

class Set
{
public:
  void initialize(QXmlStreamReader& xml, UnitsType units);
  enum PolarityType { POSITIVE, NEGATIVE };
  enum PadUsageType { TERMINATION, VIA, PLANE, TOOLING_HOLE, MASK, NONE };
  void odbOutputLayerFeature(OdbFeatureFile& file);

private:
  // attributes
  QString *m_net;
  PolarityType m_polarity;
  PadUsageType m_padUsage;
  bool m_testPoint;
  QString *m_geometry;
  bool m_plate;
  QString *m_toolIdRef;

  // nested elements
  QList<Attribute*> m_attributes;
  QList<Pad> m_pads;
  QList<Fiducial*> m_fiducials;
  QList<Hole> m_holes;
  QList<Slot> m_slots;
  QList<Features> m_featureses;
  QList<ColorGroup*> m_colorGroups;
  QList<LineDescGroup*> m_lineDescGroups;
};

#endif
