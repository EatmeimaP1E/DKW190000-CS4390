#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // Inlcude this for the sleep function

int main(int argc, char *argv[]) {
	if (argc < 3) {
		printf("Usage: bridge <Bridge ID> <Port Count> <Neighbor IDs...>\n");
		exit(1);
	}

	int bridge_id = atoi(argv[1]);
	int port_count = atoi(argv[2]);

	printf("Bridge %d starting with %d ports\n", bridge_id, port_count);

	// Bridge forwarding logic here
	while (1) {
		// Simulate forwarding logic
		sleep(1); // Placeholder for actual work
	}

	return 0;
}
