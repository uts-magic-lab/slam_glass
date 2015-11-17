#ifndef SMMAP_H
#define SMMAP_H
#include <grid/map.h>
#include <grid/harray2d.h>
#include <utils/point.h>
#include <stdio.h>
#include <vector>
#define SIGHT_INC 1
// Change value to int to include glass case Jack Wang 21/10/2013
// true = 1, false = 0, glass =-1
namespace GMapping {

struct PointAccumulator
{
  typedef point<float> FloatPoint;
  FloatPoint acc;
  int n, visits;
  bool glassDetected;
  static PointAccumulator* unknown_ptr;

  /* before
  PointAccumulator(int i=-1): acc(0,0), n(0), visits(0){assert(i==-1);}
  */
  /*after begin*/
  PointAccumulator(): acc(0,0), n(0), visits(0), glassDetected( false ) {}
  PointAccumulator(int i): acc(0,0), n(0), visits(0), glassDetected(false) { assert(i==-1);}
  /*after end*/
  Point mean() const { return 1./n*Point(acc.x, acc.y); }

  operator double() const;

  static const PointAccumulator& Unknown();
  void add(const PointAccumulator& p);
  void update( int value, const Point& p = Point(0,0) );
  void updateGlass() { glassDetected = true; }; // this is only invoked while we are producing the final map
  bool isGlassDetected() { return glassDetected; }
  double entropy() const;
};

struct GlassInfo
{
  OrientedPoint pose; // uncorrected robot pose
  double radius; // detected glass point's polar coordinate
  double phi;
  double timestamp;
};

typedef std::vector<GlassInfo> GlassDetectionCache;

typedef Map<PointAccumulator,HierarchicalArray2D<PointAccumulator> > ScanMatcherMap;

};

#endif 
