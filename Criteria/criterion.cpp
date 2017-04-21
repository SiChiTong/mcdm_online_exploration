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

#include "Criteria/criterion.h"
#include "evaluationrecords.h"


Criterion::Criterion()
{

}

Criterion:: Criterion(string name, double weight, bool highGood):
    name(name), weight(weight),highGood(highGood)
{

}

Criterion::~Criterion()
{

}

void Criterion::insertEvaluation( Pose &p, double value)
{
//    if(evaluation.contains(point))
//        lprint << "#repeated frontier!!!" << endl;
    
   // string pose = getEncodedKey(p);
    EvaluationRecords *record = new EvaluationRecords();
    string pose = record->getEncodedKey(p);
    evaluation.emplace(pose, value);
    
    if(value >= maxValue)
	maxValue = value;
    if(value <= minValue)
        minValue = value;
    
    delete record;
    //pose.clear();
}

void Criterion::clean()
{
//    for(QHash<SLAM::Geometry::Frontier *, double>::iterator it = evaluation.begin(); it!=evaluation.end(); it++){
//        delete it.key();
//    }
    evaluation.clear();
}

void Criterion::normalize()
{
    if(highGood)
	normalizeHighGood();
    else
	normalizeLowGood();
}

void Criterion::normalizeHighGood()
{
    unordered_map<string, double> temp;
    for (unordered_map<string,double>::iterator it = evaluation.begin(); it != evaluation.end(); it++){
	pair<string,double> p =  *it;
	double value =p.second;
        value = (value-minValue)/(maxValue-minValue);
        temp.emplace(p.first, value);
   }
    evaluation = temp;
}

void Criterion::normalizeLowGood()
{
    unordered_map<string, double> temp;
    for (unordered_map<string,double>::iterator it = evaluation.begin(); it != evaluation.end(); it++){
	pair<string,double> p =  *it;
        double value =p.second;
        value = (maxValue-value)/(maxValue-minValue);
        temp.emplace(p.first, value);
    }
    evaluation = temp;
}


double Criterion::getEvaluation(Pose &p) const
{
   
    //string pose = getEncodedKey(p);
    EvaluationRecords *record = new EvaluationRecords();
    string pose = record->getEncodedKey(p);
    double value = evaluation.at(pose);
    delete record;
    return value;
    
}

string Criterion::getName() 
{
    return name;
}

double Criterion::getWeight()
{
    return weight;
}

void Criterion::setName( string name)
{
    this->name = name;
}

void Criterion::setWeight(double weight)
{
    this->weight = weight;
}

string Criterion::getEncodedKey(Pose &p)
{
 
    
   
    string key =  to_string(p.getX()) + "/" + to_string( p.getY()) + "/" + to_string( p.getOrientation()) + "/" + to_string(p.getRange()) +"/" + to_string(p.getFOV());
    
    /*
    string key =  to_string(p.getX());
    key.append( "/");
    key.append( to_string( p.getY()));
    key.append( "/");
    key.append( to_string(p.getOrientation())) ;
    key.append( "/");
    key.append(to_string(p.getRange()));
    key.append( "/"); 
    key.append(to_string(p.getFOV()));
    */

    
    return key;
}


