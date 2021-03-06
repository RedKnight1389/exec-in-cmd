int execAndGet(char* cmd, char* result){
    char buffer[512];
    FILE* pipe=_popen(cmd,"r");
    if(!pipe){
        return 0;   //Return 0 if fail.
    }
    while(!feof(pipe)){
        if(fgets(buffer,512,pipe)){
            sprintf(result,"%s%s",result,buffer);
        }
    }
    _pclose(pipe);
    return 1;   //Return 0 if success.
}

float exec(char str[]){
    clock_t start,end;
    start=clock();
    system(str);
    end=clock();
    float time=(float)(end-start)/CLOCKS_PER_SEC;
    return time;
}

void clear(char *str){
    str='\0';
}

void error_try_again(){
    //Print highlight and yellow string
    //background-color  40: black
    //font color        31: red  32: green
    //other style       1m: highlight
    printf("\033[40;31;1merror! Try again!\033[0m\n");
    system("pause");
    system("cls");
}
