#ifndef CLUSTER
#define CLUSTER
#include "hashtable.h"

class centroid
{
public:
    point *coordinates;
    vector<point *> culsterPoints;
    centroid(point *);
    void includePoint(point *);
};

void initCentroids(vector<centroid> &vecOfCentroids, int numOfClusters, vector<point> &vectorOfPoints);
void lloyd(vector<centroid> &vecOfCentroids, vector<point> &vectorOfPoints);
#endif