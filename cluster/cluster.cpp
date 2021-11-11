#include "cluster.h"

centroid::centroid(point *coordinates)
{
    this->coordinates = coordinates;
}

void centroid::includePoint(point *pGiven)
{
    this->culsterPoints.push_back(pGiven);
}

void initCentroids(vector<centroid> &vecOfCentroids, int numOfClusters, vector<point> &vecOfPoints)
{
    std::random_device rd1;
    std::mt19937 gen1(rd1());
    std::uniform_int_distribution<int> uniDis(0, vecOfPoints.size());

    int numOfDimensions = vecOfPoints[0].pVector.size() - 1;
    int numOfLines = vecOfPoints.size();
    vecOfCentroids.push_back(centroid(&vecOfPoints[uniDis(gen1)]));

    for (int t = 1; t <= numOfClusters; t++)
    {
        vector<float> vecOfSums;
        vector<float> vecOfDistances;
        vector<float> vecOfProb;

        float min = MAXFLOAT;
        float max = -1;
        float dist;
        for (int i = 0; i < vecOfPoints.size(); i++)
        {
            point *curPoint = &vecOfPoints[i];

            for (int j = 0; j < t; j++)
            {
                point *centroidPoint = vecOfCentroids[j].coordinates;
                if (curPoint->pVector[0] != centroidPoint->pVector[0])
                {
                    dist = calculateDistance(curPoint, centroidPoint);
                    if (dist < min)
                    {
                        min = dist;
                    }
                    if (dist > max)
                    {
                        max = dist;
                    }
                }
            }
            vecOfDistances.push_back(min);
        }

        for (int i = 0; i < vecOfDistances.size(); i++)
        {
            vecOfDistances.at(i) = sqrt(vecOfDistances[i] / max);
        }
        int i;

        for (i = 0; i < vecOfDistances.size(); i++)
        {
            float sum = 0;
            for (int j = 0; j <= i; j++)
            {
                sum = sum + vecOfDistances[i];
            }
            vecOfSums.push_back(sum);
            if (sum != 0)
                vecOfProb.push_back(vecOfDistances[i] / sum);
            else
                vecOfProb.push_back(0);
        }
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<float> uniDis(0, vecOfSums.back());

        float cumulativeProbability = 0.0;
        for (int i = 0; i < vecOfDistances.size(); i++)
        {
            cumulativeProbability += vecOfProb[i];
            if (cumulativeProbability >= uniDis(gen))
            {
                vecOfCentroids.push_back(&vecOfPoints[i]);
                break;
            }
        }
    }
}

void lloyd(vector<centroid> &vecOfCentroids, vector<point> &vectorOfPoints)
{
}