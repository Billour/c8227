#include <iostream>
#include <vector>
using namespace std;
 
class Mountain {
	public:
	bool validMountainArray(vector<int>& A) {
	int n = A.size(), i = 0, j = n - 1;
	while (i + 1 < n && A[i] < A[i + 1]) i++;
	while (j > 0 && A[j - 1] > A[j]) j--;
	return i > 0 && i == j && j < n - 1;
							        }
};

int main()
{
	Mountain mm;
	cout << "Hello, C++!" << endl;
	
	return 0;
}
