#ifndef INFORMATIONGAINCRITERION_H
#define INFORMATIONGAINCRITERION_H

#include "criterion.h"
#include "pose.h"
#include "map.h"
#include <vector>


class InformationGainCriterion : public Criterion
{
public:
    InformationGainCriterion(double weight);
    virtual ~InformationGainCriterion();
    double evaluate( Pose &p, Map &map);
private:
    void normalize(long minSensedX, int number);
    int* intersect(int p1x, int p1y, int p2x, int p2y, Pose &p);
};


#endif // INFORMATIONGAINCRITERION_H
