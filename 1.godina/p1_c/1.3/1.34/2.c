#include <stdio.h>


int main() {
	char op, c1, c2, c3, c4, c5;
	int s = 0;
	scanf("%c %c%c%c%c%c", &op, &c1, &c2, &c3, &c4, &c5);

	switch(op) {
		case 'C':
			if(c1 >= '0' && c1 <= '9')
				s += c1 - '0';
			if(c2 >= '0' && c2 <= '9')
				s += c2 - '0';
			if(c3 >= '0' && c3 <= '9')
				s += c3 - '0';
			if(c4 >= '0' && c4 <= '9')
				s += c4 - '0';
			if(c5 >= '0' && c5 <= '9')
				s += c5 - '0';
			break;
		case 'M':
			if(c1 >= 'a' && c1 <= 'z')
				s++;
			if(c2 >= 'a' && c2 <= 'z')
				s++;
			if(c3 >= 'a' && c3 <= 'z')
				s++;
			if(c4 >= 'a' && c4 <= 'z')
				s++;
			if(c5 >= 'a' && c5 <= 'z')
				s++;
			break;	
		default:
			printf("-1\n");
			return -1;

	}

	printf("%d\n", s);

	return 0;
}
