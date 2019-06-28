#include <stdio.h>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

#define left 2
#define right 3
#define up 4
#define down 5

#define visited 1
#define unvisited 0

vector<vector<int>> Graph = {
                            {1,1,1,1,1,1,1},
                            {1,0,1,1,1,0,1},
                            {1,0,1,0,0,0,1},
                            {1,0,0,0,0,0,1},
                            {1,0,0,0,0,0,1},
                            {1,0,0,0,0,0,1},
                            {1,0,0,0,0,0,1},
                            {1,1,1,1,1,1,1}};

void backtracking(vector<vector<int>>& ans, vector<int> cur, int x, int y){
    if(x == 1 && y == 5){
        ans.push_back(cur);
        return;
    }

    if(Graph[x-1][y] == unvisited){
        Graph[x-1][y] = visited; 
        backtracking(ans,cur.push_back(left),x-1,y);
    }
    if(Graph[x+1][y] == unvisited){
        Graph[x-1][y] = visited; 
        backtracking(ans,cur.push_back(right),x+1,y);
    }
    if(Graph[x][y-1] == unvisited){Graph[x-1][y] = visited; backtracking();}
    if(Graph[x][y+1] == unvisited){Graph[x-1][y] = visited; backtracking();}
}

void findPath(vector<vector<int>> G){

}

int main(int argc, char const *argv[]){ 
    findPath(Graph);
    return 0;
}
