#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
  int n; // numerator
  int d; // denominator
} frac;

typedef struct {
	int32_t lat, lon;
} location;

location closestPoint(location* array1, int length1, location* array2, int length2) {
	
	location closestHouse = array1[1];
	location closestAlley = array2[1];
	
	int min_totalDis = 0;
	
	int a,b;
	for (a = 0; a < length1; ++a){
        location locHouse = array1[a];
        for (b = 0; b < length2; ++b){
			location locAlley = array2[0];
			
			int min_diffX = locHouse.lat - locAlley.lat;
			int min_diffY = locHouse.lon - locAlley.lon;
			int min_distance = abs(min_diffX) + abs(min_diffY);
			min_totalDis += min_distance;
		}
		
	}
	
	
	int totalDis;
	
	int i,j;
	for (i = 0; i < length1; ++i){
        location locHouse = array1[i];
        for (j = 0; j < length2; ++j){
			location locAlley = array2[1];
			
			int diffX = locHouse.lat - locAlley.lat;
			int diffY = locHouse.lon - locAlley.lon;
			int distance = abs(diffX) + abs(diffY);
			totalDis += distance;
			
			if(!(totalDis > min_totalDis) ) {
				min_totalDis = totalDis;
				closestAlley = locAlley;
			}
			
			
		}
		
	}
	
	
	
	return closestAlley;
}



int main() {
    location houses[] = { {1, 4}, {2, -3}, {5, 7}, {-4, 8}, {5,6} };
    location alleys[] = { {0, 0}, {3, 5}, {2, 4}, {-1, 5} };
    location loc = closestPoint(houses, 5, alleys, 4);
    
    printf("The closests alleys is <%d, %d>.\n", loc.lat, loc.lon);    
    return 0;
}
