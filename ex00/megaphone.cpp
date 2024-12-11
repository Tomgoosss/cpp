#include <iostream>     // For input/output operations
#include <string>    

using namespace std;

int main(int argc, char **argv){
	if (argc == 1) {
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return(0);
	}
	for (int i = 1; argv[i]; i++) {
		for(int j = 0; argv[i][j]; j++){
			cout << (char)toupper(argv[i][j]);
		}
	}
	cout << '\n';
	return(0);
}