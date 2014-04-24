#include "smmap.h"

namespace GMapping {

PointAccumulator* PointAccumulator::unknown_ptr = NULL;

const PointAccumulator& PointAccumulator::Unknown()
{
	if (!unknown_ptr) {
		unknown_ptr = new PointAccumulator;
	}
	return *unknown_ptr;
}

void PointAccumulator::update(int value, const Point& p)
{
  if (value == 1) {
    acc.x+= static_cast<float>(p.x);
    acc.y+= static_cast<float>(p.y);
    n++;
  }
  visits += SIGHT_INC;
}

double PointAccumulator::entropy() const
{
  if (!visits)
    return -log(.5);

  if (n==visits || n<1)
    return 0;

  double x = (double)n*SIGHT_INC/(double)visits;
  return -( x*log(x)+ (1-x)*log(1-x) );
}

void PointAccumulator::add(const PointAccumulator& p)
{
  acc=acc+p.acc; n+=p.n; visits+=p.visits;
}

PointAccumulator::operator double() const
{
  return visits?(double)n*SIGHT_INC/(double)visits:-1;
}

};


