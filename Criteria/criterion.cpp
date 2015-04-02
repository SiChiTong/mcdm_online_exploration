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

#include "criterion.h"

Criterion::Criterion()
{

}

Criterion:: Criterion(const String &name, double weight):
    name(name), weight(weight)
{

}

Criterion::~Criterion()
{

}


double Criterion::getEvaluation(Point p) const
{
    return evaluation[p];
}


const String& Criterion::getName() const
{
    return name;
}

double Criterion::getWeight() const
{
    return weight;
}

void Criterion::setName(const QString& name)
{
    this->name = name;
}

void Criterion::setWeight(double weight)
{
    this->weight = weight;
}
