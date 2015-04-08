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

#include "sensingtimecriterion.h"
#include "criteriaName.h"


SensingTimeCriterion::SensingTimeCriterion(double weight):
    Criterion(SENSING_TIME, weight, true)
{

}


SensingTimeCriterion::~SensingTimeCriterion()
{

}

double SensingTimeCriterion::SensingTimeCriterion::evaluate(Pose &p, Map &map)
{
    double sensingTime;
    float phi = p.getPhi();
    if (phi <= 30){
	sensingTime = 0.2;
    }else if (phi >30 & phi <= 60){
	sensingTime = 0.4;
    }else if (phi > 60 & phi <=90){
	sensingTime = 0.6;
    }else if (phi > 90 & phi <= 120){
	sensingTime = 0.8;
    }else {
	sensingTime = 1;
    }
    insertEvaluation(p,sensingTime);
}
