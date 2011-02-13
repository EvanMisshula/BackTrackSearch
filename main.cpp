/* 
 * File:   main.cpp
 * Author: EvanMisshula
 *
 * Created on February 13, 2011, 1:36 AM
 */

#include <cstdlib>

using namespace std;

/*
 * 
 */
//int main(int argc, char** argv) {
int next_tree_search_bt(int level,int *list,int maxlevel,int* numposs)
  {
  //printf("next_tree_search: level = %d maxlevel = %d\n",level,maxlevel);
  //printf("                  list[level] = %d\n",list[level]);
  /*                                                            */
  /*          If maxlevel is 0, meaning that there is only one  */
  /*          level, then just increment the value in list      */
  /*          until list[0] goes through all its possible       */
  /*          values and in that case set level to -1 to        */
  /*          indicate the end                                  */
  /*                                                            */
  if(maxlevel==0)
    if(list[0] < numposs[0]-1)
      {
      list[0]=list[0]+1;
      level=0;
      }
    else
      {
      level=-1;
      }
  /*                                                            */
  /*          Number of levels is greater than 1                */
  /*                                                            */
  else
    if(level < maxlevel)
      {
      /*                                                            */
      /*          We are not at the maximum depth                   */
      /*          go one level deeper in tree search                */
      /*                                                            */
        level++;
        list[level]=0;
      }
    else
      {
      /*                                                            */
      /*          We are at the maximum tree depth                  */
      /*                                                            */
      /*          If there is another possible value for this       */
      /*          level, consider it.                               */
      /*                                                            */
      if(list[level] < numposs[level]-1)list[level]++;
      else
        {
        /*                                                            */
        /*          There are no more possibilities to consider for   */
        /*          the last level in the tree search                 */
        /*                                                            */
        /*          So back track to the previous level and try       */
        /*          the next possible value there                     */
        /*                                                            */
        while (level >= 0)
          {
          level--;
          if(level < 0)return level;
          if(list[level] < numposs[level]-1)
            {
            list[level]=list[level]+1;
            return level;
            }
          }
        }
      }
  return level;
  }


  
