#!/bin/bash

# Clean up existing link files and environment setup
rm -f *.txt # Modify as needed to match your actual file patterns

# Starting hosts
echo "Starting hosts..."
host 1 1 29 1 2 1 1 3 3 "This is a string I want to send to node (3, 3)" &
host 3 3 17 3 2 5 1 &

# Starting bridges (assuming basic single connection bridges for simplicity)
echo "Starting bridges..."
bridge 1 2 2 &   # Bridge 1 with 2 ports, connects to host 1 and router 1
bridge 2 2 3 &   # Bridge 2 with 2 ports, connects to host 3 and router 3
bridge 3 4 1 2 & # Bridge 3 with 4 ports, connects routers 1 and 2
bridge 4 4 2 3 & # Bridge 4 with 4 ports, connects routers 2 and 3
bridge 5 2 3 &   # Bridge 5 with 2 ports, conncects to router 3 and another network (hypothetical)

# Starting routers (coniguring with asssumed networks)
echo "Starting routers..."
router 1 1 1 1 2 29 1 1 4 1 40 &
router 2 1 4 1 4 50 1 4 3 3 60 &
router 3 1 5 1 5 70 3 2 4 3 80 &

# Confirm processes are running
echo "Setup complete. Process running:"
ps -aef | grep $USER
