#include <stdio.h>

int main() {
	int n, x, i, stotina, max_stotina = 0, zbir_cifara;

	scanf("%d", &n);
	if(n <= 0) {
		printf("-1\n");
		return -1;
	}
	
	for(i = 0; i < n; i++) {
		scanf("%d", &x);
		if(x < 0)
			x = -x;

		if(x < 1000 || x > 9999) {
			printf("-1\n");
			return -1;
		}

		stotina = (x / 100) % 10;

		if(stotina >= max_stotina) {
			max_stotina = stotina;
			zbir_cifara = x / 1000 + stotina + (x / 10) % 10 + x % 10;
		}
		
	}

	printf("%d\n", zbir_cifara);
	
	return 0;
}
