#include <iostream>
#include <string>
using namespace std;

int main() {
    string a;
	cin >> a;
    string b;
    cin >> b;
    
    cout << a.size() << " " << b.size() <<"\n";
    cout << a+b <<"\n";
    char temp = a[0];
    a[0] = b[0];
    b[0] = temp;
    cout << a << " " << b;
  
    return 0;
}