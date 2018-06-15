// C++ STL bitset, manipulation to bit
// uva 594 - Little/ Big Endians, Accepted

#include <iostream>
#include <bitset>

using namespace std;

int convert(int);

int
main()
{
	int	num;
	
	while (cin >> num) {
		cout << num << " converts to " 
		     << convert(num) << endl;
	}

	return 0;
}

int
convert(int num)
{
	int	i;
	bool	b;
	bitset<32> bits(num);	// there is no other way to convert int to
				// bitset but only the construct function
	for (i = 0; i < 8; ++i) {	// [0~7] exchange with [24~31]
		b = bits[0 + i];
		bits[0 + i] = bits[24 + i];
		bits[24 + i] = b;
	}
	for (i = 0; i < 8; ++i) {	// [8~15] exchange with [16~23]
		b = bits[8 + i];
		bits[8 + i] = bits[16 + i];
		bits[16 + i] = b;
	}

	return (int)bits.to_ulong();	// there is no other way to convert
					// bitset to int but only to unsigned
					// long int, so explicitly convert to
					// int.
}
