#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // Include this for the sleep function

int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("Usage: router <Router Configurations...>\n");
		exit(1);
	}

	printf("Router starting with %d configurations\n", argc - 1);

	// Router logic to handle incoming and outgoing packets
	while (1) {
		// Simulate packet handling
		sleep(1); // Placeholder for actual work
	}

	return 0;
}
