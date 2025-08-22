#
# Makefile for the hello world program
# author: bjr
# last-update:
#     21 aug 2025 -bjr: created
#
#
#

K= id_ed25519_aws_csc421

all:
	make run
	make clean

hello: hello.c
	cc -o $@ $<

run: hello
	./hello

git-setup:
	mv config ~/.ssh/
	mv $K ~/.ssh/
	cd ~/.ssh ; chmod -6-- $K

git-test:
	@echo "copy $K.pub into github SSH keys"
	ssh -T github-csc421

git-commit:
	git commit -a -m ok 
	git push

clean:
	rm hello
