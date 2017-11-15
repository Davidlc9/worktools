#!/bin/bash

if [ $# != 1 ]; then
	echo "error: need start or stop !!!"
	exit 0
fi

TARGET=${1}

case "$TARGET" in
	"start")
	cp config proxyauth ~/.ssh/
	;;
	"stop")
	rm ~/.ssh/config -rf
	rm ~/.ssh/proxyauth -rf
	;;
esac
