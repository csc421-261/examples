#
# makefile for csc421-261
# aws helper file
#
# author: bjr
# last-update:
#     21 aug 2025 -bjr: created

# usage: make connect
#    or make D=1.2.3.4 connect

M= 3.81.166.181
FF= /Applications/Firefox.app/Contents/MacOS/firefox 
K= id_ed25519_aws_csc421

all:
	@echo various targets:
	@echo "    make connect M=$M"
	@echo "    make ssh-keygen"

connect:
	# update macro M or supply M= when used
	ssh -i ./$K ubuntu@$M

firefox:
	# for MacOS`
	${FF} http://$M

ssh-keygen:
	@echo " "
	@echo "*** no password needed"
	@echo "*** cut and paste $K.pub to AWS as a new key pair"
	@echo " "
	-ssh-keygen -t ed25519 -f $K 
