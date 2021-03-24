#include <iostream>
#include <iterator>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;


vector<int> v;

void numbers(int n){
  if((n % 3 == 0) && (n % 5 != 0)){
    v.push_back(n);
  }
}
int main(){
  istream_iterator<int> is(cin);
  istream_iterator<int> last;

  for_each(is,last,numbers);
  for (int i = 0; i < v.size();i++)
  {
    cout << v[i];
  }
    ofstream os("numbers.txt");
  copy(v.begin(),v.end(),ostream_iterator<int>(os," ")); 

  return 0;
}
