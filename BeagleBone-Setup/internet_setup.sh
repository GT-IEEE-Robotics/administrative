#!/bin/bash

ssh root@192.168.7.2 ifconfig usb0 192.168.7.2 > /dev/null
ssh root@192.168.7.2 route add default gw 192.168.7.2 > /dev/null

ifconfig $1 192.168.7.1 > /dev/null
iptables --table nat --append POSTROUTING --out-interface $2 -j MASQUERADE > /dev/null
iptables --append FORWARD --in-interface $1 -j ACCEPT > /dev/null
echo 1 > /proc/sys/net/ipv4/ip_forward

ssh root@192.168.7.2 echo "nameserver 8.8.8.8" >> /etc/resolv.conf
echo "Done!"
