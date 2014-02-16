#include "f_helper.hpp"
/*
 * Algorithm taken and modified from
 * http://en.wikipedia.org/wiki/Bresenham's_line_algorithm
 */
std::vector<zf::Grid> getLine(const zf::Grid& start, const zf::Grid& end)
{
    std::vector<zf::Grid> grids;
    int deltax = std::abs(end.col - start.col);
    int deltay = std::abs(end.row - start.row);
    int signx = start.col < end.col ? 1 : -1;
    int signy = start.row < end.row ? 1 : -1;
    float error = deltax - deltay;

    int currX = start.col;
    int currY = start.row;
    
    while(true)
    {
        grids.push_back(zf::Grid(currY, currX));
        if(currX == end.col && currY == end.row)
        {
            break;
        }
        float error2 = 2 * error;
        if(error2 > -(deltay))
        {
            error = error - deltay;
            currX += signx;
        }
        if(currX == end.col && currY == end.row)
        {
            grids.push_back(zf::Grid(currY, currX));
            break;
        }
        if(error2 < deltax)
        {
            error += deltax;
            currY += signy;
        }
    } 
    return grids;
}

std::vector<zf::Grid> getSquareVisionBoundary(int range, const zf::Grid& source, const zf::Grid& maxSize)
{
    std::vector<zf::Grid> boundary;
    int colMin = source.col - range;
    colMin = colMin < 0 ? 0 : colMin;
    int colMax = source.col + range;
    colMax = colMax >= maxSize.col ? maxSize.col - 1 : colMax;
    int rowMin = source.row - range;
    rowMin = rowMin < 0 ? 0 : rowMin;
    int rowMax = source.row + range;
    rowMax = rowMax >= maxSize.row ? maxSize.row - 1 : rowMax;
    for(int r = rowMin ; r <= rowMax ; r++)
    {
        boundary.push_back(zf::Grid(r, colMin));
        boundary.push_back(zf::Grid(r, colMax));
    }
    for(int c = colMin ; c <= colMax ; c++)
    {
        boundary.push_back(zf::Grid(rowMin, c));
        boundary.push_back(zf::Grid(rowMax, c));
    }
    return boundary;
}

