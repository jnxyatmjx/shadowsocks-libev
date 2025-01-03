#!/bin/bash

number=$1
method=$2

ss-tunnel -k test -m $method -l 8387 -L 127.0.0.1:8388 -s 127.0.0.1 -p 8389 &
ss_tunnel_pid=$!
ss-server -k test -m $method -s 127.0.0.1 -p 8389 &
ss_server_pid=$!

iperf -s -p 8388 &
iperf_pid=$!

sleep 1

iperf -c 127.0.0.1 -p 8387 -n $number

# Wait for iperf server to receive all data.
# One second should be enough in most cases.
sleep 1

kill $ss_tunnel_pid
kill $ss_server_pid
kill $iperf_pid

sleep 1
echo "Test Finished"

#test in WSL2##
#./ss-server ./ss-server -k test -m none -s 172.17.133.145 -p 14569 -u -6 -v
#./ss-local -s 172.17.133.145 -p 14569  -l 19099 -b 127.0.0.1 -k 123 -m none -v -6 -u
#test end##