// Choosing a quick solution to code is also important.
#include <stdio.h>

char kb[60] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";	//keyboard

int
main()
{
	char	ch;
	int	i;

	while (~scanf("%c", &ch)) {
		for (i = 0; kb[i] != '\0' && kb[i] != ch; ++i); 
		if (kb[i] != '\0')
			putchar(kb[i - 1]);
		else
			putchar(ch);
	}

	return 0;
}

