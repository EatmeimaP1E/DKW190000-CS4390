#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

int main() {
	int fd, i, j;
	char buf[26]; // Increased by 1 to handle potential string data safely

	fd = open("tempfile", O_RDONLY);
	if (fd < 0) {
		perror("Error opening file");
		exit(1);
	}

	for (int k = 0; k < 2; k++) {
		j = 0;
		while ((i = read(fd, buf, 25)) == 0 && j < 10) {
			sleep(5);
			printf("reader: waiting for file content\n");
			j++;
		};
		if (i > 0) {
			buf[i] = '\0'; // Ensuring the buffer is null terminated
			printf("reader: # bytes read %d which were: %s\n", i, buf);
		} else {
			printf("reader: no data read after %d attempts\n", j);
		}
	}

	printf("reader: done\n");
	close(fd);
	return 0;
}
