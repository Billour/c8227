
int validMountainArray(int * A, int ASize){
	int ptr;
	if(ASize< 3) return 0;
	if((A[0] >= A[1]) || (A[ASize-1] >= A[ASize-2])) return 0;
	ptr=1;

	while((ptr< ASize-1)&& (A[ptr]<A[ptr+1])) ptr++;
	while((ptr< ASize-1)&& (A[ptr]>A[ptr+1])) ptr++;

	if(ptr == ASize-1) return 1;
	return 0;
}


// This is a test 
void texth(int * a){

	printf("head.file a value = %d \n", *a );
}
