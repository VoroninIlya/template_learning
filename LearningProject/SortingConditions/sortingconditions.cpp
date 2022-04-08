#include "sortingconditions.h"

#include <string.h>

using namespace std;

bool AlphaBethSorting(char *preNodeData,
                      char *currNodeData){
    bool result = false;

    int preDataLength = (int)(strlen(preNodeData));
    int currDataLength = (int)(strlen(currNodeData));

    int index = preDataLength < currDataLength ?
                preDataLength : currDataLength;

    for(int i = 0; i < index; i++){
        if ((preNodeData[i] != 0)&&(currNodeData[i] != 0)&&
             (preNodeData[i] > currNodeData[i])){
            return true;
        }else if ((preNodeData[i] != 0)&&(currNodeData[i] != 0)&&
                  (preNodeData[i] == currNodeData[i])){

        }else if ((preNodeData[i] != 0)&&(currNodeData[i] != 0)&&
                  (preNodeData[i] < currNodeData[i])){
            return false;
        }
    }
    return result;
}

bool iAlphaBethSorting(char* preNodeData,
                      char* currNodeData){
    bool result = false;

    int preDataLength = (int)(strlen(preNodeData));
    int currDataLength = (int)(strlen(currNodeData));

    int index = preDataLength < currDataLength ?
                preDataLength : currDataLength;

    for(int i = 0; i < index; i++){
        if ((preNodeData[i] != 0)&&(currNodeData[i] != 0)&&
             (preNodeData[i] < currNodeData[i])){
            return true;
        }else if ((preNodeData[i] != 0)&&(currNodeData[i] != 0)&&
                  (preNodeData[i] == currNodeData[i])){

        }else if ((preNodeData[i] != 0)&&(currNodeData[i] != 0)&&
                  (preNodeData[i] > currNodeData[i])){
            return false;
        }
    }
    return result;
}

