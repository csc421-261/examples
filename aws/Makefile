#
# makefile for csc421-261
# aws helper file
#

# usage: make connect
#    or make D=1.2.3.4 connect

M= 3.81.166.181
FF= /Applications/Firefox.app/Contents/MacOS/firefox 
K= id_ed25519_aws_csc421

all:
	@echo various targets:
	@echo "    make connect D=$M"
	@echo "    make ssh-keygen"

connect:
	ssh -i ./$K ubuntu@$M

firefox:
	${FF} http://$M

ssh-keygen:
	ssh-keygen -t ed25519 -f $K 
