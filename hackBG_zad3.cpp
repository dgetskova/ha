#include <iostream>
#include <string>
using namespace std;

void ceasar( char &c, int shift )
{
	if (c >= 'a' && c <='z')
       c = (((c-'a')+shift) % 26) + 'a';
	else 
		c = ( ( (c-'A') + shift ) %26 ) + 'A';
}

string caesar_encrypt(string str, int shift)
{
	for (int i =0; i<str.length(); i++)
		ceasar (str[i], shift);
	return str;
}

int main ()
{
	string str;
	cout << "Enter string : ";
	getline (cin, str);
	int shift;
	cout << "Enter shift : ";
	cin >> shift;
	for (size_t i=0; i< str.length(); i++)
	{
		if ( (str[i] <'A' || str[i] >'Z') 
			 && (str[i] < 'a' || str [i] >'z')  )
		{
			cout <<" Wrong data input !"<<endl;
			return -1;
		}
	}
	cout << "Changed string : " <<caesar_encrypt(str, shift)<<endl;
}