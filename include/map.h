#ifndef MAP_H
#define MAP_H

#include <fstream> // ifstream
#include <sstream> // stringstream
#include <vector>
#include <string>
#include <iostream>
#include "pose.h"
#include <unordered_map>

using namespace std;
namespace dummy{

class Map
{

public:
  
  Map(std::ifstream& infile, double resolution, double imgresolution);	//constructor, takes in binary map file .pgm
	//Map(nav_msgs::OccupancyGrid ros_msg);
 // ~Map();					//destructor
  Map();
  void setGridValue(int value, long i, long j);	//setter for value in position ij of the grid
  int getGridValue(long i, long j) const;		//getter for value in position ij of the grid
  int getGridValue(long i) const;			//getter for value in position i of the grid vector
  int getMapValue(long i, long j);		//getter for value in position ij of the map
  long getNumGridRows() const;
  long getNumGridCols() const;
  long getNumRows();
  long getNumCols();
  void findFreeEdges(int cX, int cY);
  void addEdgePoint(int x, int y);
  //std::vector<int> getMap();
  //std::vector<int> getGrid();
  std::vector<vector<long> > getMap2D();
  std::vector<long> grid;			//vector containing the map as grid of cells sized 1 square metre
  std::vector<int> pathPlanningGrid;
  std::vector<int> envGrid;
  int getEnvGridValue(long i, long j) const;
  long numGridRows;
  long numGridCols;
  Pose getRobotPosition();
  long getTotalFreeCells();
  void setCurrentPose(Pose &p);
  void drawVisitedCells(unordered_map<string,int> &visitedCells,int resolution);
  void printVisitedCells(vector<string> &history);
  int getPathPlanningGridValue(long i,long j) const;
  void setPathPlanningGridValue(int value, int i, int j);
  int getPathPlanningNumCols() const;
  int getPathPlanningNumRows() const;
  int getGridToPathGridScale() const;
  int gridToPathGridScale;
  void updatePathPlanningGrid(int x, int y, int rangeInMeters);
  
	//nav_msgs::OccupancyGrid toROSMsg();
protected:
  std::vector<long> map;				//vector containing the original map as binary matrix (0 -> free, 1 -> obstacle)
  void createMap(std::ifstream& infile);
  void createGrid(double resolution);
  void createPathPlanningGrid(double resolution);
  void createNewMap();
  int numPathPlanningGridRows;
  int numPathPlanningGridCols;
  long numRows;
  long numCols;
  std::vector<std::pair<int, int> > edgePoints;
  long totalFreeCells;
  void decreaseFreeCells();
  Pose currentPose;
  
};
}

#endif
