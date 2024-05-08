#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_MSG_SIZE 1024

void send_data(int sn, int cn, char *data, int data_len);
void receive_ack(int sn, int cn);

int main(int argc, char *argv[]) {
	if (argc != 11) {
		printf("Usage: host <IP> <Ethernet> <Router IP> <Bridge ID> <Port> <Dest IP> <Dest Network> <Msg>\n");
		exit(1);
	}

	char *msg = argv[10];
	int msg_len = strlen(msg);
	int i = 0;

	// Simulating sending data in 5-byte chunks
	while (i < msg_len) {
		int chunk_size = (msg_len - i < 5) ? msg_len - i : 5;
		send_data(i / 5 % 2, i / 5 % 2, msg + i, chunk_size);
		i += chunk_size;
	}

	return 0;
}

void send_data(int sn, int cn, char *data, int data_len) {
	printf("Sending: SN=%d CN=%d Data=%. *s\n", sn, cn, data_len, data);
	// simulate sending data by writing to a file or through sockets
	receive_ack(sn, cn);
}

void receive_ack(int sn, int cn) {
	// Simulate reveiving an ACK
	printf("Received ACK for: SN=%d CN=%d\n", sn, cn);
}
