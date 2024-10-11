#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	srand(time(0));
	
	for (int i = 0; i < n; i++)
		a[i] = rand();
	
	for (int i = 1; i < n - 1; i++)
		if (!(((i % 2 == 0) && (a[i] >= a[i - 1])) || ((i % 2 != 0) && (a[i] <= (a[i - 1])))))
			swap(a[i], a[i - 1]);
	
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}