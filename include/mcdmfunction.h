#ifndef MCDMFUNCTION_H
#define MCDMFUNCTION_H
#include "Criteria/criterion.h"
#include "Criteria/weightmatrix.h"
#include "evaluationrecords.h"
#include <utility>

/**
    * This class implements the MCDM evaluation function
    * to evaluate the utility of the frontiers.
    */
using namespace dummy;
class MCDMFunction 
{

public:
    MCDMFunction();
    ~MCDMFunction();
    double evaluateFrontier(Pose& p, Map& map);
    EvaluationRecords* evaluateFrontiers(const list< Pose >& frontiers, Map& map, double threshold);
    pair< Pose, double > selectNewPose(EvaluationRecords* evaluationRecords);
    string getEncodedKey(Pose& p, int value);
    EvaluationRecords* evaluateFrontiersVec(const std::vector< Pose >& frontiers,  Map& map,double threshold);
    
protected:

    Criterion * createCriterion(string name, double weight);        
    unordered_map<string, Criterion* > criteria;
    vector<Criterion* > activeCriteria;
    WeightMatrix * matrix ;
   //mutex myMutex;

};
#endif // MCDMFUNCTION_H
