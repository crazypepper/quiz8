/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Description: 
 *                                                                             *
 * Written by AnpengChen for COMP9021                                                 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *const input_file = fopen("input.txt", "r");
    if (!input_file) {
        printf("Please create a file named \"input.txt\""
               " in the working directory.\n");
        return EXIT_FAILURE;
    }
    FILE *const output_file = fopen("output.txt", "w");
    fseek(input_file,0L,SEEK_END);
    long length_of_file=ftell(input_file);
    long front_offset=0,rare_offset=-1;
    int c;
    while( front_offset < (length_of_file+rare_offset) ){
        int processing_word=0;
        fseek(input_file,front_offset,SEEK_SET);
        while(processing_word!=2){
            c=getc(input_file);
            if(!isalpha(c)){
                if(processing_word==0){
                    front_offset++;
                    continue;
                }
                if(processing_word==1){
                    //putc('\n',output_file);
                    putc('\n',output_file);
                    processing_word=2;
                    front_offset++;
                    break;
                }
            }
            else{
                processing_word=1;
                front_offset++;
                putc(c,output_file);
                //putc(c,output_file);
            }
        }
        processing_word=0;
        int length_of_word=0;
        while(processing_word!=2){
            fseek(input_file,rare_offset,SEEK_END);
            c=getc(input_file);
            if(!isalpha(c)){
                if(processing_word==0){
                    rare_offset--;
                    continue;
                }
                if(processing_word==1){
                    rare_offset--;
                    processing_word=2;
                    for(int a=1;a<=length_of_word;a++){
                        c=getc(input_file);
                        putc(c,output_file);
                    }
                    putc('\n',output_file);
                    break;
                }
                
                
            }
            else{
                processing_word=1;
                rare_offset--;
                length_of_word++;
            }
            
        }
        
        
    }
    
        
    fclose(input_file);
    fclose(output_file);
    return EXIT_SUCCESS;
}
