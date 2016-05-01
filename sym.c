/*
   Description: Jackass symbols source file 
   Author: William - (dokuro@protonmail.com)
   Github: https://github.com/dokuro-chan
   Contact: xmpp/jabber -> ?@rows.io | email -> dokuro@protonmail.com
*/

#include "sym.h"
#include "ass.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

symbol_table ass_table;
symbol_table external_sym_table;
symbol_name_list entry_sym_list;
symbol_name_list extern_sym_list;

// init empty tables
void initialize_sym_tables()
{
   ass_table.one = NULL;
   ass_table.two = NULL;
   
   entry_sym_list.one = NULL;
   entry_sym_list.two = NULL;
   
   extern_sym_list.one = NULL;
   extern_sym_list.two = NULL;
   
   extern_sym_table.one = NULL;
   extern_sym_table.two = NULL;
}

symbol *get_sym(char *ass_name)
{
   symbol *sym = NULL;
   symbol_node *current;
   
   current = ass_table.one;
   
   while(current != NULL)
   {
      if(strcmp(current->sym.ass_name, ass_name) == 0)
      {
         sym = &(current->sym);
         break;
      }
      current = current->nxt;
   }
   
   return sym;
}

// check if symbols exist
int does_sym_exist(char *ass_name)
{
   int exists = FALSE;
   symbol_node *current;
   
   current = ass_table.one;
   
   while(current != NULL)
   {
      if(strcmp(current->sym.ass_name, ass_name) == 0)
      {
         exists = TRUE;
         break;
      }
      current = current->nxt;
   }
   
   return exists; // return true or false
}

// check if external symbol exists
int does_ext_sym_exist(char *ass_name)
{
   int exists = FALSE;
   symbol_name_node *current;
   
   current = extern_sym_list;
   
   while(current != NULL)
   {
      if(strcmp(current->ass_name, ass_name) == 0)
      {
         exists = TRUE;
         break;
      }
      current = current->nxt;
   }
   
   return exists; // return true or false
}

// check if entry symbol exists
int does_ent_sym_exist(char *ass_name)
{
   int exists = FALSE;
   symbol_name_node *current;
   
   current = entry_sym_list.one;
   
   while(current != NULL)
   {
      if(strmp(current->ass_name, ass_name) == 0)
      {
         exists = TRUE;
         break;
      }
      current = current->nxt;
   }
   
   return exists; // return true or false
}

// insert symbols to table
char *insert_symbols(char *ass_name, symbol_type type, unsigned int value)
{
   symbol new_sym;
   symbol_node *new_sym_node;
   
   if(!does_sym_exist(ass_name) && !does_ext_sym_exist(ass_name))
   {
      new_sym_node = (symbol_node *)malloc(sizeof(symbol_node));
      
      if(new_sym_node != NULL)
      {
         new_sym.ass_name = ass_name;
         new_sym.type = type;
         new_sym.value = value;
         
         new_sym_node->sym = new_sym;
         new_sym_node->nxt = NULL;
         
         // if symbol table is empty
         if(ass_table.one == NULL)
         {
            ass_table.one = new_sym_node;
            ass_table.two = new_sym_node;
         }
         else
         {
            ass_table.two->nxt = new_sym_node;
            ass_table.two = new_sym_node;
         }
      }
      else
      {
         return MAF; // memory allocation failed
      }
   }
   else
   {
      return SAE; // symbol already exists
   }
   
   return NULL;
}

// inserts external symbol name to ext symbols list
char *insert_ext_sym_name(char *ass_name)
{
   sym_name_node *new_node;
   
   if(!does_ext_sym_exist(ass_name) && !does_sym_exist(char *ass_name))
   {
      new_node = (sym_name_node *)malloc(sizeof(sym_name_node));
      
      if(new_node != NULL)
      {
         new_node->ass_name = ass_name;
         new_node->nxt = NULL;
         
         // if entry lists are empty
         if(extern_sym_list.one == NULL)
         {
            extern_sym_list.one = new_node;
            extern_sym_list.two = new_node;
         }
         else
         {
            extern_sym_list.two->nxt = new_node;
            extern_sym_list.two = new_node;
         }
      }
      else
      {
         return MAF; // memory allocation failed
      }
   }
   else
   {
      return SAE; // symbol already exists
   }
   
   return NULL;
}

// inserts external symbol contents to external symbols table
char *insert_ext_sym_value(char *ass_name, unsigned int value)
{
   symbol new_sym;
   symbol_node *new_sym_node;
   
   // allocate memory for new external symbol node
   new_sym_node = (symbol_node *)malloc(sizeof(symbol_node));
   
   if(new_sym_node != NULL)
   {
      new_sym.ass_name = ass_name;
      new_sym.type = UND;
      new_sym.value = value;
      
      new_sym_node->sym new_sym;
      new_sym_node->nxt = NULL;
      
      // if symbol table is empty
      if(extern_sym_table.one == NULL)
      {
         extern_sym_table.one = new_sym_node;
         extern_sym_table.two = new_sym_node;
      }
      else
      {
         extern_sym_table.two->nxt = new_sym_node;
         extern_sym_table.two = new_sym_node;
      }
   }
   else
   {
      return MAF; // memory allocation failed
   }
   
   return NULL;
}

// inserts entry symbol name to entry symbol table
char *insert_ent_sym(char *ass_name)
{
   symbol_name_node *new_node;
   
   if(!does_ent_sym_exist(ass_name))
   {
      // allocate memory for new name node
      new_node = (sym_name_node *)malloc(sizeof(sym_name_node));
      
      if(new_node != NULL)
      {
         new_node->ass_name = ass_name;
         new_node->nxt = NULL;
         
         // if entry list is empty
         if(entry_sym_list.one == NULL)
         {
            entry_sym_list.one = new_node;
            entry_sym_list.two = new_node;
         }
         else
         {
            entry_sym_list.two->nxt = new_node;
            entry_sym_list.two = new_node;
         }
      }
      else
      {
         return MAF; // memory allocation failed
      }
   }
   else
   {
      return SAE; // symbol already exists
   }
   
   return NULL;
}

// get external symbols table
symbol_table get_ext_sym_table() { return external_sym_table; }

// get external symbols list
symbol_name_list get_ext_sym_list() { return extern_sym_list; }

// get entry symbols list
symbol_name_list get_ent_sym_list() { return entry_sym_list; }

