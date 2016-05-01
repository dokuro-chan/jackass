/*
   Description: Jackass output header file 
   Author: William - (dokuro@protonmail.com)
   Github: https://github.com/dokuro-chan
   Contact: xmpp/jabber -> ?@rows.io | email -> dokuro@protonmail.com
*/

#ifndef _OUT_
#define _OUT_

#define FCWAP 0 // file created without any problems
#define FCNBC 1 // file could not be created
#define FSNVD 2 // file skipped, no valuable data

int create_ext_file(char *ass_name); // create externel file
int create_ent_file(char *ass_name); // create entry file

// creates object filed base on inserted instruction content
int create_object_file(char *ass_name, char **instruction_memory, char **data_memory);

#endif
