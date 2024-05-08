#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	int fd, oflag;
	char *filename = "tempfile";

	oflag = O_TRUNC | O_CREAT | O_WRONLY;
	fd = open(filename, oflag, 0x1c0); // using 0700 for permissions which is more typical
	if (fd < 0) {
		perror("Error opening file");
		exit(1);
	}

	printf("writer: waiting before first write\n");
	sleep(4);
	printf("writer: writing 'This is a test' to file|n");
	if (write(fd, "This is a test", 14) != 14) { // Using 14 instead of 15 to not write the null terminator
		perror("Failed to write 'This is a test'");
	}

	sleep(4);
	printf("writer: writing 'Second test' to file\n");
	if (write(fd, "Second test", 11) != 11) { // Using 11 instead of 12 to not write the null terminator
		perror("Failed to write 'Second test'");
	}

	close(fd);
	printf("writer: done\n");

	return 0;
}
