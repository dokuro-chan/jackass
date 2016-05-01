/*
   Description: Jackass symbols header file 
   Author: William - (dokuro@protonmail.com)
   Github: https://github.com/dokuro-chan
   Contact: xmpp/jabber -> ?@rows.io | email -> dokuro@protonmail.com
*/

#ifndef _SYM_
#define _SYM_

#define BVS 8 // base value size

#define SAE "Error: Symbol already exists!\n"
#define MAF "Error: Memory allocation failed!\n"

void initialize_sym_tables();

// symbol types
typedef enum { UND, CDE, DTA } symbol_type;

// symbol name, type, value
typedef struct { char *ass_name; unsigned int value; symbol_type type; } symbol;

// symbol list node
typedef struct sym_node { symbol sym; struct sym_node *nxt; } symbol_node;

// symbol name node
typedef struct sym_name_node { char *ass_name; struct sym_name_node *nxt; } symbol_name_node;

// symbol name list
typedef struct { symbol_name_node *one; symbol_name_node *two; } symbol_name_list;

// symbol table
typedef struct { symbol_node *one; symbol_node *two; } symbol_table;

symbol *get_sym(char *ass_name); // get symbols

symbol_table get_ext_sym_table(); // get external symbols table
symbol_name_list get_ext_sym_list(); // get external symbols list
symbol_name_list get_ent_sym_list(); // get entry symbols list

char *insert_ent_sym(char *ass_name); // insert entry symbols

int *does_ent_sym_exist(char *ass_name); // check if entry sumbols exist
int *does_sym_exist(char *ass_name); // check if symbols exists
int *does_ext_sym_exist(char *ass_name); // check if external symbols exist

// insert external symbol name into external symbol list
char *insert_ext_sym_name(char *ass_name);

// insert external symbol value to external symbol table
char *insert_ext_sym_value(char *ass_name, unsigned int value);

// insert symbols into symbol table
char *insert_symbols(char *ass_name, symbol_type type, unsigned int value);

#endif
