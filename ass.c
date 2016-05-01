/*
   Description: Jackass main source file 
   Author: William - (dokuro@protonmail.com)
   Github: https://github.com/dokuro-chan
   Contact: xmpp/jabber -> ?@rows.io | email -> dokuro@protonmail.com
*/

// standard/common headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// custom jackass headers
#include "ass.h"
#include "out.h"
#include "one.h"
#include "two.h"
#include "split.h"

#define _GNU_SOURCE
#define _ASS_EXEC_FAIL 1

unsigned int data_counter; // data counter
unsigned int instruction_counter; // instruction counter

char *data_memory[DMS]; // data memory size
char *instruction_memory[IMS + 1]; // instruction memory size
void *insert_int_data_memory(int value);

// reset counters
void reset_ass_counters()
{
   data_counter = 0;
   instruction_counter = 0;
}

// insert data counter
void insert_int_data_memory(int value)
{
   char *word;
   word = convert_base_val(value);
   data_memory[data_counter] = word;
}

// get instruction index
char *get_instruction_word(unsigned int index)
{
   return instruction_memory[index];
}

unsigned int get_data_counter() { return data_counter; } // get data counter
unsigned int get_instruction_counter() { return instruction_counter; } // get instruction counter

// handle error in supplied soure
void add_ass_error(const char *errormsg, int linenumber)
{
   fprintf(stderr, "Code error on line %d:%s\n", linenumber, errormsg);
}

// set instruction word index to linker value
void set_instruction_word(unsigned int index, char *value, char *linkerchar)
{
   instruction_memory[index] = strcat(value, linkerchar);
}

// assemble instruction
void insert_instruction(char *word, char *linkerchar)
{
   if(linkerchar != NULL)
   {
      instruction_memory[instruction_counter] = strcat(word, linkerchar);
   }
   else
   {
      instruction_memory[instruction_counter] = word;
   }
   
   instruction_counter++;
}

void insert_data(char *line)
{
   int i;
   char *data;
   state type;
   
   // get line statetype
   type = get_state_type(line);
   
   // if statetype is guidance data
   if(type = DAT)
   {
      data = snag_gdata(line);
      data = snag_fdata(data);
      
      // if guidance data is not empty, insert value to memory
      while(data != NULL)
      {
         insert_int_data_memory(atoi(data));
         
         data_counter++;
         data = snag_ndata();
      }
   }
   else
   {
      // if statetype is something other than guidance data
      // handle data as string
      data = snag_gstring(line);
      
      for(i = 0; i < strlen(data); i++)
      {
         insert_int_data_memory(data[i]);
         data_counter++;
      }
      
      insert_int_data_memory(0);
      data_counter++;
   }
}

int main(int argc, char *argv[])
{
   FILE *f;
   int i, f_result;
   
   // file name, file name without extension
   char *ass_name, *ass_name_no_ext;
   
   // count arguments
   if(argc < 2) { fprintf(stderr, NO_ARGS, INV_USE); }
   
   // iterate through entered source files/args
   for(i = 1; i < argc; i++)
   {
      // duplicate string
      ass_name_no_ext = strdup(argv[1]);
      
      // allocate memory for duplicated string
      ass_name = (char *)malloc(strlen(ass_name_no_ext) + strlen(FE + 1));
      
      // exit if memory allocation failed
      if(ass_name == NULL) { exit(_ASS_EXEC_FAIL); }
      
      // build full string
      ass_name = strdup(argv[1]);
      strcat(ass_name, FE);
      
      // if source file is not empty, check passes
      if((f = fopen(ass_name, "r")) != NULL)
      {
         // check pass one execution status
         if(!exec_pass_one(f)) { fprintf(stderr, EXE_ONE, ass_name); continue; }
         
         // check pass two execution status
         if(!exec_pass_two()) { fprintf(stderr, EXE_TWO, ass_name); continue; }
         
         // create object file, handle error
         f_result = create_obj_file(ass_name_no_ext, instruction_memory, data_memory);
         if(f_result == 1) { fprintf(stderr, OB_FAIL, ass_name); }
         
         // create external file, handle error
         f_result = create_ext_file(ass_name_no_ext);
         if(f_result == 1) { fprintf(stderr, EX_FAIL, ass_name); }
         
         // create entry file, handle error
         f_result = create_ent_file(ass_name_no_ext);
         if(f_result == 1) { fprintf(stderr, EN_FAIL, ass_name); }
      }
      else
      {
         // if source file is empty, exit
         fprintf(stderr, INV_ASS, ass_name);
         exit(_ASS_EXEC_FAIL);
      }
      
      // free source file
      free(ass_name);
   }
   return 0;
}



