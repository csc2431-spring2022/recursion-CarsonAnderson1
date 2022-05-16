#include <iostream>
#include <string>
#include <sstream>
using std::cout;
using std::endl;
using std::cerr;
using std::stringstream ;
using std::string;
using std::ostream;

unsigned long long int Fibonacci(unsigned int n);
void PrintReverseString(const string& str, ostream& output = cout);
// You may change the parameters of these functions
size_t MinimumPosition(int array[], size_t size, size_t min = 0);
void SelectionSort(int array[], size_t size, size_t a = 0);


int main() {
	const size_t ELEMENTS = 7;
	const size_t TESTS = 3;
	int data[][ELEMENTS] = {
			{7, 5, 4, 1, 3, 0, 9},
			{1, 5, 9, 11, 13, 20, 29},
			{8, 5, 4, 1, 3, 4, 0}};

	int minimumSolutions[] = {5, 0, 6};
	int sortedArrays[][7] = {
			{0, 1, 3, 4, 5, 7, 9},
			{1, 5, 9, 11, 13, 20, 29},
			{0, 1, 3, 4, 4, 5, 8}};

	unsigned long long int fibonacciSequence[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};

	string strings[] = {"hello", "aardvark", "reviver"};
	string reverses[] = {"olleh", "kravdraa", "reviver"};
	size_t passed = 0;
	int minimumResponses[TESTS];
	for (int i = 0; i < TESTS; ++i) {
		minimumResponses[i] = -1;
	}

	cout << "Testing Fibonacci" << endl;
	for (int i = 0; i < 10; ++i) {
		unsigned long long int fibonacci = Fibonacci(i);
		if (fibonacci == fibonacciSequence[i])
			cout << "\tPassed " << ++passed << " tests" << endl;
	}


	cout << "Testing Minimum Position Finding" << endl;
	for (int i = 0; i < TESTS; ++i) {
		minimumResponses[i] = MinimumPosition(data[i], ELEMENTS);
		if (minimumResponses[i] == minimumSolutions[i]){
			cout << "\tPassed " << ++passed << " tests" << endl;
		}
	}
	cout << "Testing Sorting" << endl;
	bool equal;
	for (int i = 0; i < TESTS; ++i) {
		SelectionSort(data[i], ELEMENTS);
		equal = true;
		for (int j = 0; j < ELEMENTS; ++j) {
			if (data[i][j] != sortedArrays[i][j]){
				equal = false;
				cerr << "Test " << i << " position " << j << " values: ";
				cerr << data[i][j] << " " << sortedArrays[i][j] << endl;
				break;
			}
		}
		if (equal){
			cout << "\tPassed " << ++passed << " tests" << endl;
		}
	}
	cout << "Testing Reverse Strings" << endl;
	stringstream out;
	for (int i = 0; i < TESTS; ++i) {
		out.clear();
		out.str("") ;
		PrintReverseString(strings[i], out);
		if (out.str() == reverses[i])
			cout << "\tPassed " << ++passed << " tests" << endl;
	}

	return 0;
}

unsigned long long int Fibonacci(unsigned int n){
    if(n == 1 || n == 0){
        return n;
    }
    else{
        return (Fibonacci(n - 1) + Fibonacci(n - 2));
    }
}
void PrintReverseString(const string& str, ostream& output){
    if(str.size() == 0){
        return;
    }
    else{
        PrintReverseString(str.substr(1),output);
        output << str[0];
    }
}
// You may change the parameters of these functions
size_t MinimumPosition(int array[], size_t size, size_t min){
    if(size == 0){
        return min;
    }
    if(array[size - 1] < array[min]){
        min = size;
    }
    MinimumPosition(array,size - 1, min);


}
void SelectionSort(int array[], size_t size, size_t a){
     if(a == size){
         return;
     }
     int small = 0;
     int tmp = 0;
     int tmp2 = 0;
     int tmp3 = 0;

     for(tmp = 0; tmp < size - 1; ++tmp){
         small = tmp;
         for(tmp2 = tmp; tmp2 < size; ++tmp2){
             if(array[tmp2] < array[small]){
                 small = tmp2;
             }
         }
         if(small != tmp){
             tmp3 = array[tmp];
             array[tmp] = array[small];
             array[small] = tmp3;
         }
     }
    SelectionSort(array,size,a + 1);

}
