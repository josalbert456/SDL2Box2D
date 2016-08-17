BEGIN{	
}
{
	for(i=0; i<NF; i++){
		printf("%s.o : %s.h\n", $i, $i);
	}
}
END{}