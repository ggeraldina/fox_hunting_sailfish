#include "TableAny.h"

TableAny::TableAny(QObject *parent) : QObject(parent) {

}

void TableAny::calculateIndexesCellsAroundRadius(int indexesCellsAround[],
                                                 int countCells,
                                                 int currentIndex,
                                                 int radius) {
   int baseFieldSize = static_cast<int>(sqrt(countCells));
   bool isNearLeftEdge = (currentIndex % baseFieldSize < radius) ? true : false;
   bool isNearTopEdge = (currentIndex < baseFieldSize * radius) ? true : false;
   bool isNearRightEdge = (currentIndex % baseFieldSize >= baseFieldSize - radius) ? true : false;
   bool isNearBottomEdge = (currentIndex >= baseFieldSize * (baseFieldSize - radius)) ? true : false;
   indexesCellsAround[0] = (isNearLeftEdge) ? -1 : currentIndex - radius;
   indexesCellsAround[1] = (isNearLeftEdge || isNearTopEdge) ? -1 : currentIndex - (baseFieldSize + 1) * radius;
   indexesCellsAround[2] = (isNearTopEdge) ? -1 : currentIndex - baseFieldSize * radius;
   indexesCellsAround[3] = (isNearTopEdge || isNearRightEdge) ? -1 : currentIndex - (baseFieldSize - 1) * radius;
   indexesCellsAround[4] = (isNearRightEdge) ? -1 : currentIndex + radius;
   indexesCellsAround[5] = (isNearRightEdge || isNearBottomEdge) ? -1 :
                                                                   currentIndex + (baseFieldSize + 1) * radius;
   indexesCellsAround[6] = (isNearBottomEdge) ? -1 : currentIndex + baseFieldSize * radius;
   indexesCellsAround[7] = (isNearBottomEdge || isNearLeftEdge) ? -1 :
                                                                  currentIndex + (baseFieldSize - 1) * radius;
}

int TableAny::calculateIndexesShapeSnowflake(bool cellsShapeSnowflake[], int sizeArray, int currentIndex) {
    for(int i = 0; i < sizeArray; i++) {
        cellsShapeSnowflake[i] = false;
    }
    cellsShapeSnowflake[currentIndex] = true;
    int countGroupTrue = 1;
    int indexesCellsAround[8];
    int baseFieldSize = static_cast<int>(sqrt(sizeArray));
    for(int i = 1; i < baseFieldSize; i++) {
        calculateIndexesCellsAroundRadius(indexesCellsAround, sizeArray, currentIndex, i);
        for (int indexCell : indexesCellsAround) {
            if(indexCell >= 0) {
                cellsShapeSnowflake[indexCell] = true;
                countGroupTrue++;
            }
        }
    }
    return countGroupTrue;
}




