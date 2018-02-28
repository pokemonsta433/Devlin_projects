#include <iostream>
#define minnums 0
#define maxnums 100
#define minint 0
#define maxint 100
int main() {
    int arraySize;
    bool noArray = true;
    while( noArray ) {
        puts("how large is your array (numbers between 0 and 100 only!)");
        std::cin >> arraySize;
        if (arraySize < maxnums && arraySize > minnums){
            noArray = false;
        }
    }

    int nums [arraySize];
    printf("your array is %zd numbers long\n",sizeof(nums)/sizeof(nums[0]));
    int i;

    for (i = 0; i < arraySize; i++ ){
        printf("input value for number %i: ",i+1);
        std:: cin >> nums[i];
        if (nums[i] < minint || nums[i] > maxint){
            std::cout << "only numbers between 1 and 100, please!\n";
            i -= 1;
        }
    }
    for (i = 0; i < arraySize; i++ ){
        printf("%i  ",nums[i]);
    }

    //calculate mean
    float mean;
    for (i = 0; i < arraySize; i++ ){
        mean = mean + nums[i];
    }
    mean = mean/arraySize;
    printf("\nthe mean is %2f\n",mean);


//sort
    int j;
    int swapbox;
    for 	(i=0;i<arraySize;i++){
        for (j = 0 ; j < arraySize - i - 1; j++){
            if (nums[j] > nums[j+1]) {
                swapbox       = nums[j];
                nums[j]   = nums[j+1];
                nums[j+1] = swapbox;
            }
        }
    }

    //median
    float median;
    if(arraySize % 2 == 0  ){
        median = (nums[arraySize/2] + nums[arraySize/2 +1])/2;
    }
    else{
        median = nums[arraySize/2];
    }
    printf("the median is %2f\n",median);


    //mode
    int occurrences[maxint] = {0};
    for(i=0 ; i < arraySize;i++){
        occurrences[nums[i]]  += +1;
    }

int maxOccurences = 0;
    for (i=0; i < maxint; i++){
        if (maxOccurences < occurrences[i]){
            maxOccurences = occurrences[i];
        }
    }
    if (maxOccurences == 1){
        puts("there is no mode");
    } else{
        puts("the mode is:");
        for (i=0; i < maxint; i++){
            if (occurrences[i] == maxOccurences){
                printf("%i, ",i);
            }
        }

    }
        return 0;
}

