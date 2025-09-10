


P= lazy-stack


$P: $P.c
	cc -o $@ $<

run: $P
	./$P > $P.out
	cat $P.out

clean:
	rm $P $P.out
