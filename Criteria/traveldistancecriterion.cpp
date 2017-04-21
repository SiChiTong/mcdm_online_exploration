/*
 * Copyright 2015 <copyright holder> <email>
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * 
 */

#include "Criteria/traveldistancecriterion.h"
#include "Criteria/criteriaName.h"
#include <iostream>
#include "PathFinding/astar.h"



TravelDistanceCriterion::TravelDistanceCriterion(double weight)
	: Criterion(TRAVEL_DISTANCE, weight,false)
{

}


TravelDistanceCriterion::~TravelDistanceCriterion()
{

}

double TravelDistanceCriterion::evaluate( Pose &p, dummy::Map &map)
{
    //cout << "travel " << endl;
    Astar astar;
    Pose robotPosition = map.getRobotPosition();
    //double distance = robotPosition.getDistance(p);
    string path = astar.pathFind(robotPosition.getX(),robotPosition.getY(),p.getX(),p.getY(),map);
    double distance = astar.lenghtPath(path);
    //cout << "alive after calling a*" << endl;
    Criterion::insertEvaluation(p, distance);
    
    return distance;
}

/*
void TravelDistanceCriterion::insertEvaluation(Pose& p, double value)
{
    cout << "alice" <<endl;
    insertEvaluation(p,value);
}
*/

