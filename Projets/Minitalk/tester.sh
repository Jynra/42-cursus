#!/bin/bash

#if [ $# -ne 1 ]; then
#    echo "Usage: ./test.sh <server_pid>"
#    exit 1
#fi

SERVER_PID=2704656

# On envoie les bits pour former 'A' (01000001)
echo "Envoi des bits pour former 'A'..."
kill -SIGUSR1 $SERVER_PID # 0
sleep 0.1
kill -SIGUSR2 $SERVER_PID # 1
sleep 0.1
kill -SIGUSR1 $SERVER_PID # 0
sleep 0.1
kill -SIGUSR1 $SERVER_PID # 0
sleep 0.1
kill -SIGUSR1 $SERVER_PID # 0
sleep 0.1
kill -SIGUSR1 $SERVER_PID # 0
sleep 0.1
kill -SIGUSR1 $SERVER_PID # 0
sleep 0.1
kill -SIGUSR2 $SERVER_PID # 1
sleep 0.1

echo "Test terminé!"