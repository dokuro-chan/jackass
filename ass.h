/*
   Description: Jackass main header file 
   Author: William - (dokuro@protonmail.com)
   Github: https://github.com/dokuro-chan
   Contact: xmpp/jabber -> ?@rows.io | email -> dokuro@protonmail.com
*/

#ifndef _ASS_
#define _ASS_

// jackass constants
#define WRD 16    // word size
#define MSL 30    // mas symbol length
#define MLL 80    // max line length
#define ISV 100   // instruction counter startup value
#define DMS 10000 // data memory size
#define IMS 10000 // instruction memory size
#define OML '0x'   // offset mark label
#define OMS "0x"   // offset mark string
#define SEC "?"   // end character symbol
#define LA "ab"   // absolute linker
#define LR "re"   // relocatable linker
#define LE "ex"   // external linker
#define FE ".ass" // file extension

// addressing modes
#define IAM 0  // immediate addressing
#define DAM 1  // direct addressing
#define NAM 2  // index addressing
#define EAM 3  // 2d index addressing
#define RAM 4  // register addressing
#define ABL 3  // addressing bit length
#define RBL 3  // register bit length
#define SAO 4  // source addressing offset
#define SRO 7  // source register offset
#define DAO 10 // destination addressing offset
#define DRO 13 // destination register offset

#define NRO "000"    // non register operand

// jackass keywords
#define DG ".data"   // data guidance
#define EG ".entry"  // entry guidance
#define SG ".string" // string guidance
#define XG ".extern" // external guidance

#define TRUE 1
#define FALSE 0

#define CNV "Error: You have entered an invalid command!"
#define SNV "Error: You have entered an invalid symbol!"

#define NO_ARGS "No arguments/files entered."
#define EN_FAIL "Failed creating entry file %s!\n"
#define OB_FAIL "Failed creating object file %s!\n"
#define EX_FAIL "Failed creating external file %s!\n"
#define EXE_ONE "Execution pass one for '%s' failed!\n"
#define EXE_TWO "Execution pass two for '%s' failed!\n"
#define INV_USE "Usage: jackass <file1> <file2> <etc>...\n"
#define INV_ASS "You have entered an invalid assembly file(%s)!\n"

// statement type
typedef enum state_type
{
   EMP, // empty
   COM, // comment
   DAT, // data guidance
   STR, // string guidance
   ENT, // entry guidance
   EXT, // external guidance
   CMD  // command
} state;

void reset_ass_counters();
void insert_data(char *line);
char *get_instruction_word(unsigned int index);
void insert_instruction(char *word, char *linkerchar);
void add_ass_error(const char *errormsg, int linenumber);
void set_instruction_word(unsigned int index, char *value, char *linkerchar);

unsigned int get_data_counter();
unsigned int get_instruction_counter();

#endif
