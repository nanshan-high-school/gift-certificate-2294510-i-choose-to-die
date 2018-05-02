#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "請問要買幾個東西";
    cin >> n;
    
    int num[n];
    for(int x = 0; x < n; x++){
        cout << "第" << x + 1 << "樣的價錢是?";
        cin >> num[x];
    }
	int choose[(int)pow(2, n)][n] = {0}; // 陣列初始化

	for (int x = 0; x < n; x++) {
		int change = pow(2, x);
		int k = 1;
		for (int y = 0; y < pow(2, n); y++) {
			if (y % change == 0) {
				k = (k == 0) ? 1 : 0;
			}
			choose[y][x] = k;

			cout << choose[y][x] << " ";
		}
		cout << endl;
	}
	int personOne = 0;
	int personTwo = 0;	
	int all = 0;
	int answer = 200;
	for(int y = 0; y < pow(2, n); y++){
	    for(int x = 0; x < n; x++){
	        if(choose[y][x] == 0){
	            personOne = personOne + num[x];
	        }
        for(int x = 0; x < n; x++){
	            all = all + num[x];
	        }
	    personTwo = all - personOne;
	    if(personOne % 100 + personTwo %100 < answer){
	        answer = personOne % 100 + personTwo %100;
	    }
	    
	    }
	}

	
    cout << "最多可找回" << 200 - answer << "元";

    return 0;
}
