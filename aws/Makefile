#
# makefile for csc421-261
# aws helper file
#
# author: bjr
# last-update:
#     21 aug 2025 -bjr: created

# usage: make connect
#    or make M=1.2.3.4 connect

FF= /Applications/Firefox.app/Contents/MacOS/firefox 
K= id_ed25519_aws_csc421

M= 3.81.166.181
F= id_ed25519_ojo_github_may2025 

all:
	@echo various targets:
	@echo "    make connect"
	@echo "    make connect M=$M"
	@echo "    make scp M=$M F=$F"
	@echo "    make ssh-keygen"
	@echo ""
	@echo "set the macro M to the public IP of the instance"
	@echo "or specify as make connect M=1.2.3.4"
	@echo "cut and paste $K.pub as a key pair in AWS"

connect:
	# update macro M or supply M= when used
	ssh -i ./$K ubuntu@$M
 
scp:
	scp -i ./$K $F ubuntu@$M:

firefox:
	# for MacOS`
	${FF} http://$M

ssh-keygen:
	# create a key pair
	ssh-keygen -t ed25519 -f $K 
