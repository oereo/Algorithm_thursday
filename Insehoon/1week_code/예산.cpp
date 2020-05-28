#include <string>
#include <vector>
#include <algorithm>

int result = 0;
using namespace std;
int mid = 0;

int solution(vector<int> budgets, int M) {
    int answer = 0;
    int low = 0;
    int high = 100000;
    int mid = 0;
    int cnt = 0;
    long sum = 0;
    sort(budgets.begin(), budgets.end());
    for(int i = 0; i<budgets.size();i++){
       sum += budgets[i];
    }
    if(sum<=M){
        return budgets[budgets.size() - 1];
    }

    
    //high = budgets[budgets.size()-1];
    
    
   while(low+1 < high){
			mid = (low+high)/2;
			sum = 0; 

			for(int i=0; i<budgets.size(); i++){

				if(budgets[i] < mid)
					sum += budgets[i];
				else
					sum += mid;

			}

			if(sum <= M)
				low = mid;

			else 
				high = mid;
		}	
    
    answer = low;
    return answer;
}