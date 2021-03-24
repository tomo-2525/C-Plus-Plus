// Student ID : s1260032
// Hanoi.cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Prinr three towers situation. 
// A higher number indicates a larger disk.
void print_towers(vector<vector<int>> vv)
{
  cout << "A:[ ";
  for (int i = 0; i < vv[0].size();i++){
    cout << vv[0][i] << " ";
  }
  cout << "]\nB:[ ";
  for (int i = 0; i < vv[1].size();i++){
    cout << vv[1][i] << " ";
  }
  cout << "]\nC:[ ";
  for (int i = 0; i < vv[2].size();i++){
    cout << vv[2][i] << " ";
  }
  cout << "]\n\n";
}

// towers[0] is A, towers[1] is B, towers[2] is C.
// Depending on the arguments, change the kind of towers.
void move_disc_print(int x, int y){
  char towers[] = {'A','B','C'};
  cout << towers[x] << " -> " << towers[y] << endl;
}


void Hanoi(int n, vector<vector<int>>&vv, int a, int b, int c)
{
  if (n == 0)
    return;
  Hanoi(n - 1, vv, a, c, b);
  vv[b].push_back(vv[a][vv[a].size() - 1]);
  move_disc_print(a, b);
  vv[a].pop_back();
  print_towers(vv);
  Hanoi(n - 1, vv, c, b, a);
}

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    cout << "Usage: " << argv[0] << " n" << endl;
    cout << "where n is the number of disks." << endl;
    return 1;
  }
  int n = stoi(argv[1]); // convert the argv[1] to an int

  // COMPLETE:
  // Call Hanoi with n disks
  vector<vector<int>> towers(3);
  for (int i = n; i >= 1; i--)
  {
    towers[0].push_back(i);
  }
  cout << "###################################################\n";
  cout << "A higher number indicates a larger disk.\na:[3 2 1] indicates the status of the disk in tower A.\nThe more to the left in [], the more it is below the tower.\n";
  cout << "###################################################\n";
  print_towers(towers);
  Hanoi(n, towers, 0, 2, 1);
  return 0;
}