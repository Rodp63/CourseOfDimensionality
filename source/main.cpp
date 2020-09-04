#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <cmath>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

int n[] = {10000, 15000, 20000, 25000};
int d[] = {4, 6, 8, 10, 12, 18, 20};

int main(){
  srand (time(NULL));
  int N = sizeof(n) / sizeof(int);
  int D = sizeof(d) / sizeof(int);
  for(int i = 0; i < N; i++){
    for(int j = 0; j < D; j++){
      vector<vector<int> > points (n[i], vector<int>(d[j]));
      for(int a = 0; a < n[i]; a++){
	for(int b = 0; b < d[j]; b++){
	  points[a][b] = rand() % 10000;
	}
      }
      auto Start = high_resolution_clock::now();
      for(int a = 0; a < n[i]; a++){
	for(int b = a + 1; b < n[i]; b++){
	  double dist = 0;
	  for(int x = 0; x < d[j]; x++){
	    int tmp = points[a][x] - points[b][x];
	    dist += tmp * tmp;
	  }
	  dist = sqrt(dist);
	}
      }
      auto End = high_resolution_clock::now();
      double Time = chrono::duration_cast<chrono::nanoseconds>(End-Start).count() * 1e-6;
      cout<<"Matching " << n[i] << " points of " << d[j] << " dimensions: " << Time << " ms\n";
    }
  }
}
