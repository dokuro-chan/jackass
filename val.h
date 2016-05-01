/*
   Description: Jackass validator header file 
   Author: William - (dokuro@protonmail.com)
   Github: https://github.com/dokuro-chan
   Contact: xmpp/jabber -> ?@rows.io | email -> dokuro@protonmail.com
*/

#ifndef _VAL_
#define _VAL_

#define MAXB 256
#define NSTR "Error: No string in line\n"
#define INVN "Error: Invalid number of operands\n"
#define BADA "Error: Invalid addressing method\n"
#define TLNG "Error: Invalid command length!\n"
#define INVI "Error: Invalid integer!\n"

char *val_ass_line(char *line);

#endif
