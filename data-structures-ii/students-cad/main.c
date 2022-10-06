#include <stdio.h>
#include "lib.h"

int main()
{
  FILE *fp, *ind;
  Node *lastIndexNode, *indexList;

  indexList = getIndexListFromFile(ind, &lastIndexNode);
  showMenu(fp, &indexList, &lastIndexNode);
  setIndexesBackup(ind, indexList);

  return 0;
}
