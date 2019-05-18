/*
generated at Sat May 18 11:56:33 2019
by $Id: pburg.c,v 2.4 2013/07/19 16:39:16 prs Exp $
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PBURG_PREFIX "yy"
#define PBURG_VERSION "2.4"
#define MAX_COST 0x7fff
#if defined(__STDC__) || defined(__cplusplus)
#define YYCONST const
#else
#define YYCONST
#endif

#line 1 "diy.brg"

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "tabid.h"
#include "postfix.h"


/*
TODO: Variaveis globais (hoje a noite) (done except const str)
			Ponteiros (sabado)
			Otimizacoes (amanha fazer em ES e antes do autocarro)
			Felicidade (TBD)
*/


/*for cycles*/
typedef struct double_lbl {
	int b_lbl;
	int e_lbl;
} doublelbl;

static doublelbl lbls[100];
static int dblcnt = 0;
extern FILE *outfp;
char *dupstr(const char *s);

static long brklbl[20], brkcnt; /* break labels */
/* label _L0 is a break without a while/switch) */

static char *extrns[100]; /* emit externs at the end only */
static int extcnt;
extern int localPos;

int lbl;
char *mklbl(int n) {
  static char buf[20];
  sprintf(buf, "_i%d", n);
  return strcpy(malloc(strlen(buf)+1),buf);
}

static void outstr(char *s) {
  while (*s) fprintf(outfp, pfCHAR, (unsigned char)*s++);
  fprintf(outfp, pfCHAR, 0);
}

int functionReturnType;

static char *mkfunc(char *s) {
  static char buf[80];
  strcpy(buf, "_");
  strcat(buf, s);
  return buf;
}

int isIntFunction(Node* p) {return p->info == 1 ? 1 : MAX_COST;}
int isInt(Node* p) {return ((p->info == 1) || (p->info == 6)) ? 1 : MAX_COST;}
int isIntPointer(Node* p) {return ((p->info == 11) || (p->info == 16)) ? 1 : MAX_COST;}


int isRealFunction(Node* p) {return p->info == 3 ? 1 : MAX_COST;}
int isReal(Node* p) {return((p->info == 3) || (p->info == 8)) ? 1 : MAX_COST;}
int isRealPointer(Node* p) {return ((p->info == 13) || (p->info == 18)) ? 1 : MAX_COST;}


int isString(Node* p) {return ((p->info == 2) || (p->info == 7)) ? 1 : MAX_COST;}
int isStringFunction(Node* p) {return p->info == 2 ? 1 : MAX_COST;}
int isStringPointer(Node* p) {return ((p->info == 12) || (p->info == 17)) ? 1 : MAX_COST;}



#ifndef PANIC
#define PANIC yypanic
static void yypanic(YYCONST char *rot, YYCONST char *msg, int val) {
	fprintf(stderr, "Internal Error in %s: %s %d\nexiting...\n",
		rot, msg, val);
	exit(2);
}
#endif
static void yykids(NODEPTR_TYPE, int, NODEPTR_TYPE[]);
#define yyfinit_NT 1
#define yybloco_NT 2
#define yyparams_NT 3
#define yyparam_NT 4
#define yylist_NT 5
#define yydecls_NT 6
#define yystmt_NT 7
#define yytipo_NT 8
#define yybase_NT 9
#define yyif_NT 10
#define yycond_NT 11
#define yyexpr_NT 12
#define yyifelse_NT 13
#define yycond2_NT 14
#define yywhile_NT 15
#define yydo_NT 16
#define yybegin_NT 17
#define yyfor_NT 18
#define yyforbody_NT 19
#define yyforin_NT 20
#define yyforinstr_NT 21
#define yyforstmt_NT 22
#define yyforstart_NT 23
#define yyiexpr_NT 24
#define yysexpr_NT 25
#define yyrexpr_NT 26
#define yyiptrexpr_NT 27
#define yysptrexpr_NT 28
#define yyrptrexpr_NT 29
#define yyarguments_NT 30
#define yyilval_NT 31
#define yyslvec_NT 32
#define yyrlval_NT 33
#define yyrlvec_NT 34
#define yyslval_NT 35
#define yysassign_NT 36
#define yyscmp_NT 37
#define yyiassign_NT 38
#define yyrassign_NT 39
#define yyiptrlval_NT 40
#define yyiptrlvec_NT 41
#define yyiptrassign_NT 42
#define yysptrlval_NT 43
#define yysptrlvec_NT 44
#define yysptrassign_NT 45
#define yyrptrlval_NT 46
#define yyrptrlvec_NT 47
#define yyrptrassign_NT 48
#define yyiptrcmp_NT 49

static YYCONST char *yyntname[] = {
	0,
	"finit",
	"bloco",
	"params",
	"param",
	"list",
	"decls",
	"stmt",
	"tipo",
	"base",
	"if",
	"cond",
	"expr",
	"ifelse",
	"cond2",
	"while",
	"do",
	"begin",
	"for",
	"forbody",
	"forin",
	"forinstr",
	"forstmt",
	"forstart",
	"iexpr",
	"sexpr",
	"rexpr",
	"iptrexpr",
	"sptrexpr",
	"rptrexpr",
	"arguments",
	"ilval",
	"slvec",
	"rlval",
	"rlvec",
	"slval",
	"sassign",
	"scmp",
	"iassign",
	"rassign",
	"iptrlval",
	"iptrlvec",
	"iptrassign",
	"sptrlval",
	"sptrlvec",
	"sptrassign",
	"rptrlval",
	"rptrlvec",
	"rptrassign",
	"iptrcmp",
	0
};

static YYCONST char *yytermname[] = {
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "",
	/* 34 */ "FACTORIAL",
 "", "", "",
	/* 38 */ "MOD",
	/* 39 */ "AND",
 "",
	/* 41 */ "ARGB",
 "",
	/* 43 */ "MUL",
	/* 44 */ "ADD",
	/* 45 */ "NEXT",
	/* 46 */ "SUB",
 "",
	/* 48 */ "DIV",
 "", "", "", "", "", "", "", "", "", "", "",
	/* 60 */ "INSTR",
	/* 61 */ "LT",
	/* 62 */ "LOGIC_EQUAL",
	/* 63 */ "GT",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "",
	/* 92 */ "INDEX",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "",
	/* 124 */ "BLOCK",
	/* 125 */ "OR",
 "",
	/* 127 */ "LOGIC_NOT",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "",
	/* 258 */ "INT",
	/* 259 */ "REAL",
	/* 260 */ "ID",
	/* 261 */ "STR",
	/* 262 */ "DO",
	/* 263 */ "WHILE",
	/* 264 */ "IF",
	/* 265 */ "THEN",
	/* 266 */ "FOR",
	/* 267 */ "IN",
	/* 268 */ "UPTO",
	/* 269 */ "DOWNTO",
	/* 270 */ "STEP",
	/* 271 */ "BREAK",
	/* 272 */ "CONTINUE",
	/* 273 */ "VOID",
	/* 274 */ "INTEGER",
	/* 275 */ "STRING",
	/* 276 */ "NUMBER",
	/* 277 */ "CONST",
	/* 278 */ "PUBLIC",
	/* 279 */ "INCR",
	/* 280 */ "DECR",
	/* 281 */ "IFX",
	/* 282 */ "ELSE",
	/* 283 */ "ATR",
	/* 284 */ "NE",
	/* 285 */ "GE",
	/* 286 */ "LE",
	/* 287 */ "UMINUS",
	/* 288 */ "NOT",
	/* 289 */ "REF",
	/* 290 */ "LOCAL",
	/* 291 */ "POSINC",
	/* 292 */ "POSDEC",
	/* 293 */ "PTR",
	/* 294 */ "CALL",
	/* 295 */ "START",
	/* 296 */ "PARAM",
	/* 297 */ "NIL",
	/* 298 */ "LIST",
	/* 299 */ "ARGS",
	/* 300 */ "NONE",
	""
};

struct yystate {
	short cost[50];
	struct {
		unsigned int yyfinit:2;
		unsigned int yybloco:2;
		unsigned int yyparams:2;
		unsigned int yyparam:1;
		unsigned int yylist:2;
		unsigned int yydecls:2;
		unsigned int yystmt:2;
		unsigned int yytipo:2;
		unsigned int yybase:3;
		unsigned int yyif:1;
		unsigned int yycond:4;
		unsigned int yyexpr:4;
		unsigned int yyifelse:1;
		unsigned int yycond2:1;
		unsigned int yywhile:1;
		unsigned int yydo:1;
		unsigned int yybegin:1;
		unsigned int yyfor:1;
		unsigned int yyforbody:1;
		unsigned int yyforin:1;
		unsigned int yyforinstr:1;
		unsigned int yyforstmt:1;
		unsigned int yyforstart:1;
		unsigned int yyiexpr:6;
		unsigned int yysexpr:3;
		unsigned int yyrexpr:4;
		unsigned int yyiptrexpr:3;
		unsigned int yysptrexpr:3;
		unsigned int yyrptrexpr:3;
		unsigned int yyarguments:2;
		unsigned int yyilval:3;
		unsigned int yyslvec:1;
		unsigned int yyrlval:3;
		unsigned int yyrlvec:1;
		unsigned int yyslval:2;
		unsigned int yysassign:2;
		unsigned int yyscmp:1;
		unsigned int yyiassign:2;
		unsigned int yyrassign:1;
		unsigned int yyiptrlval:2;
		unsigned int yyiptrlvec:1;
		unsigned int yyiptrassign:1;
		unsigned int yysptrlval:2;
		unsigned int yysptrlvec:1;
		unsigned int yysptrassign:1;
		unsigned int yyrptrlval:2;
		unsigned int yyrptrlvec:1;
		unsigned int yyrptrassign:1;
		unsigned int yyiptrcmp:1;
	} rule;
};

static short yynts_0[] = { yybloco_NT, yyparams_NT, 0 };
static short yynts_1[] = { yybloco_NT, 0 };
static short yynts_2[] = { yyparam_NT, 0 };
static short yynts_3[] = { yyparams_NT, yyparam_NT, 0 };
static short yynts_4[] = { yylist_NT, yydecls_NT, 0 };
static short yynts_5[] = { yylist_NT, yystmt_NT, yydecls_NT, 0 };
static short yynts_6[] = { yydecls_NT, yyparam_NT, 0 };
static short yynts_7[] = { 0 };
static short yynts_8[] = { yytipo_NT, 0 };
static short yynts_9[] = { yybase_NT, 0 };
static short yynts_10[] = { yylist_NT, yybase_NT, 0 };
static short yynts_11[] = { yycond_NT, yystmt_NT, 0 };
static short yynts_12[] = { yyexpr_NT, 0 };
static short yynts_13[] = { yycond2_NT, yystmt_NT, 0 };
static short yynts_14[] = { yydo_NT, yyexpr_NT, 0 };
static short yynts_15[] = { yybegin_NT, yystmt_NT, 0 };
static short yynts_16[] = { yyexpr_NT, yyforbody_NT, 0 };
static short yynts_17[] = { yyforin_NT, yyforinstr_NT, 0 };
static short yynts_18[] = { yyforstmt_NT, yyexpr_NT, 0 };
static short yynts_19[] = { yystmt_NT, 0 };
static short yynts_20[] = { yyforstart_NT, yyexpr_NT, 0 };
static short yynts_21[] = { yyif_NT, 0 };
static short yynts_22[] = { yyifelse_NT, 0 };
static short yynts_23[] = { yywhile_NT, 0 };
static short yynts_24[] = { yyfor_NT, 0 };
static short yynts_25[] = { yyiexpr_NT, 0 };
static short yynts_26[] = { yysexpr_NT, 0 };
static short yynts_27[] = { yyrexpr_NT, 0 };
static short yynts_28[] = { yyiptrexpr_NT, 0 };
static short yynts_29[] = { yysptrexpr_NT, 0 };
static short yynts_30[] = { yyrptrexpr_NT, 0 };
static short yynts_31[] = { yyarguments_NT, 0 };
static short yynts_32[] = { yyslvec_NT, yyexpr_NT, 0 };
static short yynts_33[] = { yyrlval_NT, 0 };
static short yynts_34[] = { yyrlvec_NT, yyexpr_NT, 0 };
static short yynts_35[] = { yyslval_NT, 0 };
static short yynts_36[] = { yysassign_NT, yyslval_NT, 0 };
static short yynts_37[] = { yyscmp_NT, yyscmp_NT, 0 };
static short yynts_38[] = { yyiassign_NT, yyilval_NT, 0 };
static short yynts_39[] = { yyiexpr_NT, yyiexpr_NT, 0 };
static short yynts_40[] = { yyilval_NT, 0 };
static short yynts_41[] = { yyrexpr_NT, yyrexpr_NT, 0 };
static short yynts_42[] = { yyrassign_NT, yyrlval_NT, 0 };
static short yynts_43[] = { yyarguments_NT, yyexpr_NT, 0 };
static short yynts_44[] = { yyiptrlval_NT, 0 };
static short yynts_45[] = { yyiptrlvec_NT, yyexpr_NT, 0 };
static short yynts_46[] = { yyiptrassign_NT, yyiptrlval_NT, 0 };
static short yynts_47[] = { yysptrlval_NT, 0 };
static short yynts_48[] = { yysptrlvec_NT, yyexpr_NT, 0 };
static short yynts_49[] = { yysptrassign_NT, yysptrlval_NT, 0 };
static short yynts_50[] = { yyrptrlval_NT, 0 };
static short yynts_51[] = { yyrptrlvec_NT, yyexpr_NT, 0 };
static short yynts_52[] = { yyrptrassign_NT, yyrptrlval_NT, 0 };
static short yynts_53[] = { yyiptrcmp_NT, yyiptrcmp_NT, 0 };

static short *yynts[] = {
	0,	/* 0 */
	yynts_0,	/* 1 */
	yynts_1,	/* 2 */
	yynts_2,	/* 3 */
	yynts_3,	/* 4 */
	yynts_4,	/* 5 */
	yynts_5,	/* 6 */
	yynts_6,	/* 7 */
	yynts_7,	/* 8 */
	yynts_8,	/* 9 */
	yynts_7,	/* 10 */
	yynts_7,	/* 11 */
	yynts_7,	/* 12 */
	yynts_9,	/* 13 */
	yynts_10,	/* 14 */
	yynts_11,	/* 15 */
	yynts_12,	/* 16 */
	yynts_13,	/* 17 */
	yynts_11,	/* 18 */
	yynts_14,	/* 19 */
	yynts_15,	/* 20 */
	yynts_7,	/* 21 */
	yynts_16,	/* 22 */
	yynts_17,	/* 23 */
	yynts_18,	/* 24 */
	yynts_19,	/* 25 */
	yynts_20,	/* 26 */
	yynts_7,	/* 27 */
	yynts_9,	/* 28 */
	yynts_7,	/* 29 */
	yynts_7,	/* 30 */
	yynts_12,	/* 31 */
	yynts_21,	/* 32 */
	yynts_22,	/* 33 */
	yynts_23,	/* 34 */
	yynts_24,	/* 35 */
	yynts_1,	/* 36 */
	yynts_25,	/* 37 */
	yynts_26,	/* 38 */
	yynts_27,	/* 39 */
	yynts_28,	/* 40 */
	yynts_29,	/* 41 */
	yynts_30,	/* 42 */
	yynts_31,	/* 43 */
	yynts_7,	/* 44 */
	yynts_7,	/* 45 */
	yynts_7,	/* 46 */
	yynts_32,	/* 47 */
	yynts_7,	/* 48 */
	yynts_7,	/* 49 */
	yynts_33,	/* 50 */
	yynts_34,	/* 51 */
	yynts_7,	/* 52 */
	yynts_7,	/* 53 */
	yynts_35,	/* 54 */
	yynts_7,	/* 55 */
	yynts_35,	/* 56 */
	yynts_26,	/* 57 */
	yynts_25,	/* 58 */
	yynts_28,	/* 59 */
	yynts_36,	/* 60 */
	yynts_31,	/* 61 */
	yynts_7,	/* 62 */
	yynts_26,	/* 63 */
	yynts_37,	/* 64 */
	yynts_37,	/* 65 */
	yynts_37,	/* 66 */
	yynts_37,	/* 67 */
	yynts_37,	/* 68 */
	yynts_37,	/* 69 */
	yynts_37,	/* 70 */
	yynts_37,	/* 71 */
	yynts_25,	/* 72 */
	yynts_27,	/* 73 */
	yynts_7,	/* 74 */
	yynts_38,	/* 75 */
	yynts_39,	/* 76 */
	yynts_39,	/* 77 */
	yynts_39,	/* 78 */
	yynts_39,	/* 79 */
	yynts_39,	/* 80 */
	yynts_39,	/* 81 */
	yynts_39,	/* 82 */
	yynts_39,	/* 83 */
	yynts_39,	/* 84 */
	yynts_39,	/* 85 */
	yynts_39,	/* 86 */
	yynts_39,	/* 87 */
	yynts_39,	/* 88 */
	yynts_25,	/* 89 */
	yynts_25,	/* 90 */
	yynts_25,	/* 91 */
	yynts_40,	/* 92 */
	yynts_40,	/* 93 */
	yynts_40,	/* 94 */
	yynts_40,	/* 95 */
	yynts_40,	/* 96 */
	yynts_35,	/* 97 */
	yynts_31,	/* 98 */
	yynts_7,	/* 99 */
	yynts_41,	/* 100 */
	yynts_41,	/* 101 */
	yynts_41,	/* 102 */
	yynts_41,	/* 103 */
	yynts_41,	/* 104 */
	yynts_41,	/* 105 */
	yynts_40,	/* 106 */
	yynts_42,	/* 107 */
	yynts_27,	/* 108 */
	yynts_7,	/* 109 */
	yynts_41,	/* 110 */
	yynts_27,	/* 111 */
	yynts_41,	/* 112 */
	yynts_41,	/* 113 */
	yynts_41,	/* 114 */
	yynts_25,	/* 115 */
	yynts_33,	/* 116 */
	yynts_31,	/* 117 */
	yynts_7,	/* 118 */
	yynts_12,	/* 119 */
	yynts_43,	/* 120 */
	yynts_7,	/* 121 */
	yynts_7,	/* 122 */
	yynts_44,	/* 123 */
	yynts_40,	/* 124 */
	yynts_45,	/* 125 */
	yynts_44,	/* 126 */
	yynts_28,	/* 127 */
	yynts_40,	/* 128 */
	yynts_28,	/* 129 */
	yynts_46,	/* 130 */
	yynts_7,	/* 131 */
	yynts_7,	/* 132 */
	yynts_47,	/* 133 */
	yynts_35,	/* 134 */
	yynts_48,	/* 135 */
	yynts_47,	/* 136 */
	yynts_29,	/* 137 */
	yynts_35,	/* 138 */
	yynts_29,	/* 139 */
	yynts_49,	/* 140 */
	yynts_7,	/* 141 */
	yynts_7,	/* 142 */
	yynts_50,	/* 143 */
	yynts_33,	/* 144 */
	yynts_51,	/* 145 */
	yynts_50,	/* 146 */
	yynts_30,	/* 147 */
	yynts_33,	/* 148 */
	yynts_30,	/* 149 */
	yynts_52,	/* 150 */
	yynts_28,	/* 151 */
	yynts_53,	/* 152 */
	yynts_53,	/* 153 */
	yynts_53,	/* 154 */
	yynts_53,	/* 155 */
	yynts_53,	/* 156 */
	yynts_53,	/* 157 */
	yynts_39,	/* 158 */
	yynts_39,	/* 159 */
	yynts_39,	/* 160 */
	yynts_39,	/* 161 */
	yynts_39,	/* 162 */
	yynts_39,	/* 163 */
	yynts_37,	/* 164 */
	yynts_37,	/* 165 */
	yynts_37,	/* 166 */
	yynts_37,	/* 167 */
	yynts_37,	/* 168 */
	yynts_37,	/* 169 */
};


static YYCONST char *yystring[] = {
/* 0 */	0,
/* 1 */	"finit: ARGB(bloco,params)",
/* 2 */	"finit: ARGB(bloco,NIL)",
/* 3 */	"params: param",
/* 4 */	"params: NEXT(params,param)",
/* 5 */	"bloco: BLOCK(list,decls)",
/* 6 */	"bloco: BLOCK(INSTR(list,stmt),decls)",
/* 7 */	"decls: INSTR(decls,param)",
/* 8 */	"decls: NONE",
/* 9 */	"param: PARAM(tipo,ID)",
/* 10 */	"tipo: INTEGER",
/* 11 */	"tipo: STRING",
/* 12 */	"tipo: NUMBER",
/* 13 */	"list: base",
/* 14 */	"list: LIST(list,base)",
/* 15 */	"if: IF(cond,stmt)",
/* 16 */	"cond: expr",
/* 17 */	"ifelse: ELSE(cond2,stmt)",
/* 18 */	"cond2: IF(cond,stmt)",
/* 19 */	"while: WHILE(do,expr)",
/* 20 */	"do: DO(begin,stmt)",
/* 21 */	"begin: START",
/* 22 */	"for: INSTR(expr,forbody)",
/* 23 */	"forbody: FOR(forin,forinstr)",
/* 24 */	"forinstr: INSTR(forstmt,expr)",
/* 25 */	"forstmt: stmt",
/* 26 */	"forin: IN(forstart,expr)",
/* 27 */	"forstart: START",
/* 28 */	"stmt: base",
/* 29 */	"stmt: BREAK",
/* 30 */	"stmt: CONTINUE",
/* 31 */	"base: expr",
/* 32 */	"base: if",
/* 33 */	"base: ifelse",
/* 34 */	"base: while",
/* 35 */	"base: for",
/* 36 */	"base: bloco",
/* 37 */	"expr: iexpr",
/* 38 */	"expr: sexpr",
/* 39 */	"expr: rexpr",
/* 40 */	"expr: iptrexpr",
/* 41 */	"expr: sptrexpr",
/* 42 */	"expr: rptrexpr",
/* 43 */	"expr: CALL(ID,arguments)",
/* 44 */	"expr: CALL(ID,VOID)",
/* 45 */	"ilval: LOCAL",
/* 46 */	"ilval: ID",
/* 47 */	"ilval: INDEX(slvec,expr)",
/* 48 */	"rlval: LOCAL",
/* 49 */	"rlval: ID",
/* 50 */	"rlvec: rlval",
/* 51 */	"rlval: INDEX(rlvec,expr)",
/* 52 */	"slval: LOCAL",
/* 53 */	"slval: ID",
/* 54 */	"slvec: slval",
/* 55 */	"sexpr: STR",
/* 56 */	"sexpr: PTR(slval)",
/* 57 */	"sassign: sexpr",
/* 58 */	"sassign: iexpr",
/* 59 */	"sassign: iptrexpr",
/* 60 */	"sexpr: ATR(sassign,slval)",
/* 61 */	"sexpr: CALL(ID,arguments)",
/* 62 */	"sexpr: CALL(ID,VOID)",
/* 63 */	"scmp: sexpr",
/* 64 */	"iexpr: LT(scmp,scmp)",
/* 65 */	"iexpr: GT(scmp,scmp)",
/* 66 */	"iexpr: GE(scmp,scmp)",
/* 67 */	"iexpr: LE(scmp,scmp)",
/* 68 */	"iexpr: NE(scmp,scmp)",
/* 69 */	"iexpr: LOGIC_EQUAL(scmp,scmp)",
/* 70 */	"iexpr: AND(scmp,scmp)",
/* 71 */	"iexpr: OR(scmp,scmp)",
/* 72 */	"iassign: iexpr",
/* 73 */	"iassign: rexpr",
/* 74 */	"iexpr: INT",
/* 75 */	"iexpr: ATR(iassign,ilval)",
/* 76 */	"iexpr: ADD(iexpr,iexpr)",
/* 77 */	"iexpr: SUB(iexpr,iexpr)",
/* 78 */	"iexpr: DIV(iexpr,iexpr)",
/* 79 */	"iexpr: MOD(iexpr,iexpr)",
/* 80 */	"iexpr: MUL(iexpr,iexpr)",
/* 81 */	"iexpr: LT(iexpr,iexpr)",
/* 82 */	"iexpr: GT(iexpr,iexpr)",
/* 83 */	"iexpr: GE(iexpr,iexpr)",
/* 84 */	"iexpr: LE(iexpr,iexpr)",
/* 85 */	"iexpr: NE(iexpr,iexpr)",
/* 86 */	"iexpr: LOGIC_EQUAL(iexpr,iexpr)",
/* 87 */	"iexpr: AND(iexpr,iexpr)",
/* 88 */	"iexpr: OR(iexpr,iexpr)",
/* 89 */	"iexpr: FACTORIAL(iexpr)",
/* 90 */	"iexpr: NOT(iexpr)",
/* 91 */	"iexpr: UMINUS(iexpr)",
/* 92 */	"iexpr: INCR(ilval)",
/* 93 */	"iexpr: DECR(ilval)",
/* 94 */	"iexpr: POSINC(ilval)",
/* 95 */	"iexpr: POSDEC(ilval)",
/* 96 */	"iexpr: PTR(ilval)",
/* 97 */	"iexpr: PTR(slval)",
/* 98 */	"iexpr: CALL(ID,arguments)",
/* 99 */	"iexpr: CALL(ID,VOID)",
/* 100 */	"iexpr: LT(rexpr,rexpr)",
/* 101 */	"iexpr: GT(rexpr,rexpr)",
/* 102 */	"iexpr: GE(rexpr,rexpr)",
/* 103 */	"iexpr: LE(rexpr,rexpr)",
/* 104 */	"iexpr: LOGIC_EQUAL(rexpr,rexpr)",
/* 105 */	"iexpr: NE(rexpr,rexpr)",
/* 106 */	"iptrexpr: REF(ilval)",
/* 107 */	"rexpr: ATR(rassign,rlval)",
/* 108 */	"rassign: rexpr",
/* 109 */	"rexpr: REAL",
/* 110 */	"rexpr: ADD(rexpr,rexpr)",
/* 111 */	"rexpr: UMINUS(rexpr)",
/* 112 */	"rexpr: SUB(rexpr,rexpr)",
/* 113 */	"rexpr: MUL(rexpr,rexpr)",
/* 114 */	"rexpr: DIV(rexpr,rexpr)",
/* 115 */	"rexpr: iexpr",
/* 116 */	"rexpr: PTR(rlval)",
/* 117 */	"rexpr: CALL(ID,arguments)",
/* 118 */	"rexpr: CALL(ID,VOID)",
/* 119 */	"arguments: ARGS(NIL,expr)",
/* 120 */	"arguments: ARGS(arguments,expr)",
/* 121 */	"iptrlval: LOCAL",
/* 122 */	"iptrlval: ID",
/* 123 */	"iptrlvec: iptrlval",
/* 124 */	"iptrexpr: REF(ilval)",
/* 125 */	"ilval: INDEX(iptrlvec,expr)",
/* 126 */	"iptrexpr: PTR(iptrlval)",
/* 127 */	"iexpr: PTR(iptrexpr)",
/* 128 */	"iptrexpr: REF(ilval)",
/* 129 */	"iptrassign: iptrexpr",
/* 130 */	"iptrexpr: ATR(iptrassign,iptrlval)",
/* 131 */	"sptrlval: LOCAL",
/* 132 */	"sptrlval: ID",
/* 133 */	"sptrlvec: sptrlval",
/* 134 */	"sptrexpr: REF(slval)",
/* 135 */	"slval: INDEX(sptrlvec,expr)",
/* 136 */	"sptrexpr: PTR(sptrlval)",
/* 137 */	"sexpr: PTR(sptrexpr)",
/* 138 */	"sptrexpr: REF(slval)",
/* 139 */	"sptrassign: sptrexpr",
/* 140 */	"sptrexpr: ATR(sptrassign,sptrlval)",
/* 141 */	"rptrlval: LOCAL",
/* 142 */	"rptrlval: ID",
/* 143 */	"rptrlvec: rptrlval",
/* 144 */	"rptrexpr: REF(rlval)",
/* 145 */	"rlval: INDEX(rptrlvec,expr)",
/* 146 */	"rptrexpr: PTR(rptrlval)",
/* 147 */	"rexpr: PTR(rptrexpr)",
/* 148 */	"rptrexpr: REF(rlval)",
/* 149 */	"rptrassign: rptrexpr",
/* 150 */	"rptrexpr: ATR(rptrassign,rptrlval)",
/* 151 */	"iptrcmp: iptrexpr",
/* 152 */	"iexpr: LT(iptrcmp,iptrcmp)",
/* 153 */	"iexpr: GT(iptrcmp,iptrcmp)",
/* 154 */	"iexpr: GE(iptrcmp,iptrcmp)",
/* 155 */	"iexpr: LE(iptrcmp,iptrcmp)",
/* 156 */	"iexpr: LOGIC_EQUAL(iptrcmp,iptrcmp)",
/* 157 */	"iexpr: NE(iptrcmp,iptrcmp)",
/* 158 */	"cond: LT(iexpr,iexpr)",
/* 159 */	"cond: GT(iexpr,iexpr)",
/* 160 */	"cond: LE(iexpr,iexpr)",
/* 161 */	"cond: GE(iexpr,iexpr)",
/* 162 */	"cond: LOGIC_EQUAL(iexpr,iexpr)",
/* 163 */	"cond: NE(iexpr,iexpr)",
/* 164 */	"cond: LT(scmp,scmp)",
/* 165 */	"cond: GT(scmp,scmp)",
/* 166 */	"cond: LE(scmp,scmp)",
/* 167 */	"cond: GE(scmp,scmp)",
/* 168 */	"cond: LOGIC_EQUAL(scmp,scmp)",
/* 169 */	"cond: NE(scmp,scmp)",
};

#ifndef TRACE
static void yytrace(NODEPTR_TYPE p, int eruleno, int cost, int bestcost)
{
	int op = OP_LABEL(p);
	YYCONST char *tname = yytermname[op] ? yytermname[op] : "?";
	fprintf(stderr, "0x%lx:%s matched %s with cost %d vs. %d\n", (long)p, tname, yystring[eruleno], cost, bestcost);
}
#endif

static short yydecode_finit[] = {
	0,
	1,
	2,
};

static short yydecode_bloco[] = {
	0,
	5,
	6,
};

static short yydecode_params[] = {
	0,
	3,
	4,
};

static short yydecode_param[] = {
	0,
	9,
};

static short yydecode_list[] = {
	0,
	13,
	14,
};

static short yydecode_decls[] = {
	0,
	7,
	8,
};

static short yydecode_stmt[] = {
	0,
	28,
	29,
	30,
};

static short yydecode_tipo[] = {
	0,
	10,
	11,
	12,
};

static short yydecode_base[] = {
	0,
	31,
	32,
	33,
	34,
	35,
	36,
};

static short yydecode_if[] = {
	0,
	15,
};

static short yydecode_cond[] = {
	0,
	16,
	158,
	159,
	160,
	161,
	162,
	163,
	164,
	165,
	166,
	167,
	168,
	169,
};

static short yydecode_expr[] = {
	0,
	37,
	38,
	39,
	40,
	41,
	42,
	43,
	44,
};

static short yydecode_ifelse[] = {
	0,
	17,
};

static short yydecode_cond2[] = {
	0,
	18,
};

static short yydecode_while[] = {
	0,
	19,
};

static short yydecode_do[] = {
	0,
	20,
};

static short yydecode_begin[] = {
	0,
	21,
};

static short yydecode_for[] = {
	0,
	22,
};

static short yydecode_forbody[] = {
	0,
	23,
};

static short yydecode_forin[] = {
	0,
	26,
};

static short yydecode_forinstr[] = {
	0,
	24,
};

static short yydecode_forstmt[] = {
	0,
	25,
};

static short yydecode_forstart[] = {
	0,
	27,
};

static short yydecode_iexpr[] = {
	0,
	64,
	65,
	66,
	67,
	68,
	69,
	70,
	71,
	74,
	75,
	76,
	77,
	78,
	79,
	80,
	81,
	82,
	83,
	84,
	85,
	86,
	87,
	88,
	89,
	90,
	91,
	92,
	93,
	94,
	95,
	96,
	97,
	98,
	99,
	100,
	101,
	102,
	103,
	104,
	105,
	127,
	152,
	153,
	154,
	155,
	156,
	157,
};

static short yydecode_sexpr[] = {
	0,
	55,
	56,
	60,
	61,
	62,
	137,
};

static short yydecode_rexpr[] = {
	0,
	107,
	109,
	110,
	111,
	112,
	113,
	114,
	115,
	116,
	117,
	118,
	147,
};

static short yydecode_iptrexpr[] = {
	0,
	106,
	124,
	126,
	128,
	130,
};

static short yydecode_sptrexpr[] = {
	0,
	134,
	136,
	138,
	140,
};

static short yydecode_rptrexpr[] = {
	0,
	144,
	146,
	148,
	150,
};

static short yydecode_arguments[] = {
	0,
	119,
	120,
};

static short yydecode_ilval[] = {
	0,
	45,
	46,
	47,
	125,
};

static short yydecode_slvec[] = {
	0,
	54,
};

static short yydecode_rlval[] = {
	0,
	48,
	49,
	51,
	145,
};

static short yydecode_rlvec[] = {
	0,
	50,
};

static short yydecode_slval[] = {
	0,
	52,
	53,
	135,
};

static short yydecode_sassign[] = {
	0,
	57,
	58,
	59,
};

static short yydecode_scmp[] = {
	0,
	63,
};

static short yydecode_iassign[] = {
	0,
	72,
	73,
};

static short yydecode_rassign[] = {
	0,
	108,
};

static short yydecode_iptrlval[] = {
	0,
	121,
	122,
};

static short yydecode_iptrlvec[] = {
	0,
	123,
};

static short yydecode_iptrassign[] = {
	0,
	129,
};

static short yydecode_sptrlval[] = {
	0,
	131,
	132,
};

static short yydecode_sptrlvec[] = {
	0,
	133,
};

static short yydecode_sptrassign[] = {
	0,
	139,
};

static short yydecode_rptrlval[] = {
	0,
	141,
	142,
};

static short yydecode_rptrlvec[] = {
	0,
	143,
};

static short yydecode_rptrassign[] = {
	0,
	149,
};

static short yydecode_iptrcmp[] = {
	0,
	151,
};

static int yyrule(void *state, int goalnt) {
	if (goalnt < 1 || goalnt > 49)
		PANIC("yyrule", "Bad goal nonterminal", goalnt);
	if (!state)
		return 0;
	switch (goalnt) {
	case yyfinit_NT:	return yydecode_finit[((struct yystate *)state)->rule.yyfinit];
	case yybloco_NT:	return yydecode_bloco[((struct yystate *)state)->rule.yybloco];
	case yyparams_NT:	return yydecode_params[((struct yystate *)state)->rule.yyparams];
	case yyparam_NT:	return yydecode_param[((struct yystate *)state)->rule.yyparam];
	case yylist_NT:	return yydecode_list[((struct yystate *)state)->rule.yylist];
	case yydecls_NT:	return yydecode_decls[((struct yystate *)state)->rule.yydecls];
	case yystmt_NT:	return yydecode_stmt[((struct yystate *)state)->rule.yystmt];
	case yytipo_NT:	return yydecode_tipo[((struct yystate *)state)->rule.yytipo];
	case yybase_NT:	return yydecode_base[((struct yystate *)state)->rule.yybase];
	case yyif_NT:	return yydecode_if[((struct yystate *)state)->rule.yyif];
	case yycond_NT:	return yydecode_cond[((struct yystate *)state)->rule.yycond];
	case yyexpr_NT:	return yydecode_expr[((struct yystate *)state)->rule.yyexpr];
	case yyifelse_NT:	return yydecode_ifelse[((struct yystate *)state)->rule.yyifelse];
	case yycond2_NT:	return yydecode_cond2[((struct yystate *)state)->rule.yycond2];
	case yywhile_NT:	return yydecode_while[((struct yystate *)state)->rule.yywhile];
	case yydo_NT:	return yydecode_do[((struct yystate *)state)->rule.yydo];
	case yybegin_NT:	return yydecode_begin[((struct yystate *)state)->rule.yybegin];
	case yyfor_NT:	return yydecode_for[((struct yystate *)state)->rule.yyfor];
	case yyforbody_NT:	return yydecode_forbody[((struct yystate *)state)->rule.yyforbody];
	case yyforin_NT:	return yydecode_forin[((struct yystate *)state)->rule.yyforin];
	case yyforinstr_NT:	return yydecode_forinstr[((struct yystate *)state)->rule.yyforinstr];
	case yyforstmt_NT:	return yydecode_forstmt[((struct yystate *)state)->rule.yyforstmt];
	case yyforstart_NT:	return yydecode_forstart[((struct yystate *)state)->rule.yyforstart];
	case yyiexpr_NT:	return yydecode_iexpr[((struct yystate *)state)->rule.yyiexpr];
	case yysexpr_NT:	return yydecode_sexpr[((struct yystate *)state)->rule.yysexpr];
	case yyrexpr_NT:	return yydecode_rexpr[((struct yystate *)state)->rule.yyrexpr];
	case yyiptrexpr_NT:	return yydecode_iptrexpr[((struct yystate *)state)->rule.yyiptrexpr];
	case yysptrexpr_NT:	return yydecode_sptrexpr[((struct yystate *)state)->rule.yysptrexpr];
	case yyrptrexpr_NT:	return yydecode_rptrexpr[((struct yystate *)state)->rule.yyrptrexpr];
	case yyarguments_NT:	return yydecode_arguments[((struct yystate *)state)->rule.yyarguments];
	case yyilval_NT:	return yydecode_ilval[((struct yystate *)state)->rule.yyilval];
	case yyslvec_NT:	return yydecode_slvec[((struct yystate *)state)->rule.yyslvec];
	case yyrlval_NT:	return yydecode_rlval[((struct yystate *)state)->rule.yyrlval];
	case yyrlvec_NT:	return yydecode_rlvec[((struct yystate *)state)->rule.yyrlvec];
	case yyslval_NT:	return yydecode_slval[((struct yystate *)state)->rule.yyslval];
	case yysassign_NT:	return yydecode_sassign[((struct yystate *)state)->rule.yysassign];
	case yyscmp_NT:	return yydecode_scmp[((struct yystate *)state)->rule.yyscmp];
	case yyiassign_NT:	return yydecode_iassign[((struct yystate *)state)->rule.yyiassign];
	case yyrassign_NT:	return yydecode_rassign[((struct yystate *)state)->rule.yyrassign];
	case yyiptrlval_NT:	return yydecode_iptrlval[((struct yystate *)state)->rule.yyiptrlval];
	case yyiptrlvec_NT:	return yydecode_iptrlvec[((struct yystate *)state)->rule.yyiptrlvec];
	case yyiptrassign_NT:	return yydecode_iptrassign[((struct yystate *)state)->rule.yyiptrassign];
	case yysptrlval_NT:	return yydecode_sptrlval[((struct yystate *)state)->rule.yysptrlval];
	case yysptrlvec_NT:	return yydecode_sptrlvec[((struct yystate *)state)->rule.yysptrlvec];
	case yysptrassign_NT:	return yydecode_sptrassign[((struct yystate *)state)->rule.yysptrassign];
	case yyrptrlval_NT:	return yydecode_rptrlval[((struct yystate *)state)->rule.yyrptrlval];
	case yyrptrlvec_NT:	return yydecode_rptrlvec[((struct yystate *)state)->rule.yyrptrlvec];
	case yyrptrassign_NT:	return yydecode_rptrassign[((struct yystate *)state)->rule.yyrptrassign];
	case yyiptrcmp_NT:	return yydecode_iptrcmp[((struct yystate *)state)->rule.yyiptrcmp];
	default:
		PANIC("yyrule", "Bad goal nonterminal", goalnt);
		return 0;
	}
}

static void yyclosure_bloco(NODEPTR_TYPE, int);
static void yyclosure_param(NODEPTR_TYPE, int);
static void yyclosure_stmt(NODEPTR_TYPE, int);
static void yyclosure_base(NODEPTR_TYPE, int);
static void yyclosure_if(NODEPTR_TYPE, int);
static void yyclosure_expr(NODEPTR_TYPE, int);
static void yyclosure_ifelse(NODEPTR_TYPE, int);
static void yyclosure_while(NODEPTR_TYPE, int);
static void yyclosure_for(NODEPTR_TYPE, int);
static void yyclosure_iexpr(NODEPTR_TYPE, int);
static void yyclosure_sexpr(NODEPTR_TYPE, int);
static void yyclosure_rexpr(NODEPTR_TYPE, int);
static void yyclosure_iptrexpr(NODEPTR_TYPE, int);
static void yyclosure_sptrexpr(NODEPTR_TYPE, int);
static void yyclosure_rptrexpr(NODEPTR_TYPE, int);
static void yyclosure_rlval(NODEPTR_TYPE, int);
static void yyclosure_slval(NODEPTR_TYPE, int);
static void yyclosure_iptrlval(NODEPTR_TYPE, int);
static void yyclosure_sptrlval(NODEPTR_TYPE, int);
static void yyclosure_rptrlval(NODEPTR_TYPE, int);

static void yyclosure_bloco(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 36, c + 0, p->cost[yybase_NT]);
	if (c + 0 < p->cost[yybase_NT]) {
		p->cost[yybase_NT] = c + 0;
		p->rule.yybase = 6;
		yyclosure_base(a, c + 0);
	}
}

static void yyclosure_param(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 3, c + 0, p->cost[yyparams_NT]);
	if (c + 0 < p->cost[yyparams_NT]) {
		p->cost[yyparams_NT] = c + 0;
		p->rule.yyparams = 1;
	}
}

static void yyclosure_stmt(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 25, c + 1, p->cost[yyforstmt_NT]);
	if (c + 1 < p->cost[yyforstmt_NT]) {
		p->cost[yyforstmt_NT] = c + 1;
		p->rule.yyforstmt = 1;
	}
}

static void yyclosure_base(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 28, c + 0, p->cost[yystmt_NT]);
	if (c + 0 < p->cost[yystmt_NT]) {
		p->cost[yystmt_NT] = c + 0;
		p->rule.yystmt = 1;
		yyclosure_stmt(a, c + 0);
	}
	yytrace(a, 13, c + 0, p->cost[yylist_NT]);
	if (c + 0 < p->cost[yylist_NT]) {
		p->cost[yylist_NT] = c + 0;
		p->rule.yylist = 1;
	}
}

static void yyclosure_if(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 32, c + 0, p->cost[yybase_NT]);
	if (c + 0 < p->cost[yybase_NT]) {
		p->cost[yybase_NT] = c + 0;
		p->rule.yybase = 2;
		yyclosure_base(a, c + 0);
	}
}

static void yyclosure_expr(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 31, c + 1, p->cost[yybase_NT]);
	if (c + 1 < p->cost[yybase_NT]) {
		p->cost[yybase_NT] = c + 1;
		p->rule.yybase = 1;
		yyclosure_base(a, c + 1);
	}
	yytrace(a, 16, c + 1, p->cost[yycond_NT]);
	if (c + 1 < p->cost[yycond_NT]) {
		p->cost[yycond_NT] = c + 1;
		p->rule.yycond = 1;
	}
}

static void yyclosure_ifelse(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 33, c + 0, p->cost[yybase_NT]);
	if (c + 0 < p->cost[yybase_NT]) {
		p->cost[yybase_NT] = c + 0;
		p->rule.yybase = 3;
		yyclosure_base(a, c + 0);
	}
}

static void yyclosure_while(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 34, c + 0, p->cost[yybase_NT]);
	if (c + 0 < p->cost[yybase_NT]) {
		p->cost[yybase_NT] = c + 0;
		p->rule.yybase = 4;
		yyclosure_base(a, c + 0);
	}
}

static void yyclosure_for(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 35, c + 0, p->cost[yybase_NT]);
	if (c + 0 < p->cost[yybase_NT]) {
		p->cost[yybase_NT] = c + 0;
		p->rule.yybase = 5;
		yyclosure_base(a, c + 0);
	}
}

static void yyclosure_iexpr(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 115, c + 1, p->cost[yyrexpr_NT]);
	if (c + 1 < p->cost[yyrexpr_NT]) {
		p->cost[yyrexpr_NT] = c + 1;
		p->rule.yyrexpr = 8;
		yyclosure_rexpr(a, c + 1);
	}
	yytrace(a, 72, c + 1, p->cost[yyiassign_NT]);
	if (c + 1 < p->cost[yyiassign_NT]) {
		p->cost[yyiassign_NT] = c + 1;
		p->rule.yyiassign = 1;
	}
	yytrace(a, 58, c + 1, p->cost[yysassign_NT]);
	if (c + 1 < p->cost[yysassign_NT]) {
		p->cost[yysassign_NT] = c + 1;
		p->rule.yysassign = 2;
	}
	yytrace(a, 37, c + 0, p->cost[yyexpr_NT]);
	if (c + 0 < p->cost[yyexpr_NT]) {
		p->cost[yyexpr_NT] = c + 0;
		p->rule.yyexpr = 1;
		yyclosure_expr(a, c + 0);
	}
}

static void yyclosure_sexpr(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 63, c + 0, p->cost[yyscmp_NT]);
	if (c + 0 < p->cost[yyscmp_NT]) {
		p->cost[yyscmp_NT] = c + 0;
		p->rule.yyscmp = 1;
	}
	yytrace(a, 57, c + 1, p->cost[yysassign_NT]);
	if (c + 1 < p->cost[yysassign_NT]) {
		p->cost[yysassign_NT] = c + 1;
		p->rule.yysassign = 1;
	}
	yytrace(a, 38, c + 0, p->cost[yyexpr_NT]);
	if (c + 0 < p->cost[yyexpr_NT]) {
		p->cost[yyexpr_NT] = c + 0;
		p->rule.yyexpr = 2;
		yyclosure_expr(a, c + 0);
	}
}

static void yyclosure_rexpr(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 108, c + 1, p->cost[yyrassign_NT]);
	if (c + 1 < p->cost[yyrassign_NT]) {
		p->cost[yyrassign_NT] = c + 1;
		p->rule.yyrassign = 1;
	}
	yytrace(a, 73, c + 1, p->cost[yyiassign_NT]);
	if (c + 1 < p->cost[yyiassign_NT]) {
		p->cost[yyiassign_NT] = c + 1;
		p->rule.yyiassign = 2;
	}
	yytrace(a, 39, c + 0, p->cost[yyexpr_NT]);
	if (c + 0 < p->cost[yyexpr_NT]) {
		p->cost[yyexpr_NT] = c + 0;
		p->rule.yyexpr = 3;
		yyclosure_expr(a, c + 0);
	}
}

static void yyclosure_iptrexpr(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 151, c + 1, p->cost[yyiptrcmp_NT]);
	if (c + 1 < p->cost[yyiptrcmp_NT]) {
		p->cost[yyiptrcmp_NT] = c + 1;
		p->rule.yyiptrcmp = 1;
	}
	yytrace(a, 129, c + 1, p->cost[yyiptrassign_NT]);
	if (c + 1 < p->cost[yyiptrassign_NT]) {
		p->cost[yyiptrassign_NT] = c + 1;
		p->rule.yyiptrassign = 1;
	}
	yytrace(a, 59, c + 1, p->cost[yysassign_NT]);
	if (c + 1 < p->cost[yysassign_NT]) {
		p->cost[yysassign_NT] = c + 1;
		p->rule.yysassign = 3;
	}
	yytrace(a, 40, c + 0, p->cost[yyexpr_NT]);
	if (c + 0 < p->cost[yyexpr_NT]) {
		p->cost[yyexpr_NT] = c + 0;
		p->rule.yyexpr = 4;
		yyclosure_expr(a, c + 0);
	}
}

static void yyclosure_sptrexpr(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 139, c + 1, p->cost[yysptrassign_NT]);
	if (c + 1 < p->cost[yysptrassign_NT]) {
		p->cost[yysptrassign_NT] = c + 1;
		p->rule.yysptrassign = 1;
	}
	yytrace(a, 41, c + 0, p->cost[yyexpr_NT]);
	if (c + 0 < p->cost[yyexpr_NT]) {
		p->cost[yyexpr_NT] = c + 0;
		p->rule.yyexpr = 5;
		yyclosure_expr(a, c + 0);
	}
}

static void yyclosure_rptrexpr(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 149, c + 1, p->cost[yyrptrassign_NT]);
	if (c + 1 < p->cost[yyrptrassign_NT]) {
		p->cost[yyrptrassign_NT] = c + 1;
		p->rule.yyrptrassign = 1;
	}
	yytrace(a, 42, c + 0, p->cost[yyexpr_NT]);
	if (c + 0 < p->cost[yyexpr_NT]) {
		p->cost[yyexpr_NT] = c + 0;
		p->rule.yyexpr = 6;
		yyclosure_expr(a, c + 0);
	}
}

static void yyclosure_rlval(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 50, c + 1, p->cost[yyrlvec_NT]);
	if (c + 1 < p->cost[yyrlvec_NT]) {
		p->cost[yyrlvec_NT] = c + 1;
		p->rule.yyrlvec = 1;
	}
}

static void yyclosure_slval(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 54, c + 1, p->cost[yyslvec_NT]);
	if (c + 1 < p->cost[yyslvec_NT]) {
		p->cost[yyslvec_NT] = c + 1;
		p->rule.yyslvec = 1;
	}
}

static void yyclosure_iptrlval(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 123, c + 1, p->cost[yyiptrlvec_NT]);
	if (c + 1 < p->cost[yyiptrlvec_NT]) {
		p->cost[yyiptrlvec_NT] = c + 1;
		p->rule.yyiptrlvec = 1;
	}
}

static void yyclosure_sptrlval(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 133, c + 1, p->cost[yysptrlvec_NT]);
	if (c + 1 < p->cost[yysptrlvec_NT]) {
		p->cost[yysptrlvec_NT] = c + 1;
		p->rule.yysptrlvec = 1;
	}
}

static void yyclosure_rptrlval(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 143, c + 1, p->cost[yyrptrlvec_NT]);
	if (c + 1 < p->cost[yyrptrlvec_NT]) {
		p->cost[yyrptrlvec_NT] = c + 1;
		p->rule.yyrptrlvec = 1;
	}
}

static void yylabel(NODEPTR_TYPE a, NODEPTR_TYPE u) {
	int c;
	struct yystate *p;

	if (!a)
		PANIC("yylabel", "Null tree in", OP_LABEL(u));
	STATE_LABEL(a) = p = (struct yystate *)malloc(sizeof *p);
	memset(p, 0, sizeof *p);
	p->cost[1] =
	p->cost[2] =
	p->cost[3] =
	p->cost[4] =
	p->cost[5] =
	p->cost[6] =
	p->cost[7] =
	p->cost[8] =
	p->cost[9] =
	p->cost[10] =
	p->cost[11] =
	p->cost[12] =
	p->cost[13] =
	p->cost[14] =
	p->cost[15] =
	p->cost[16] =
	p->cost[17] =
	p->cost[18] =
	p->cost[19] =
	p->cost[20] =
	p->cost[21] =
	p->cost[22] =
	p->cost[23] =
	p->cost[24] =
	p->cost[25] =
	p->cost[26] =
	p->cost[27] =
	p->cost[28] =
	p->cost[29] =
	p->cost[30] =
	p->cost[31] =
	p->cost[32] =
	p->cost[33] =
	p->cost[34] =
	p->cost[35] =
	p->cost[36] =
	p->cost[37] =
	p->cost[38] =
	p->cost[39] =
	p->cost[40] =
	p->cost[41] =
	p->cost[42] =
	p->cost[43] =
	p->cost[44] =
	p->cost[45] =
	p->cost[46] =
	p->cost[47] =
	p->cost[48] =
	p->cost[49] =
		0x7fff;
	switch (OP_LABEL(a)) {
	case 33: /* FACTORIAL */
		yylabel(LEFT_CHILD(a),a);
		/* iexpr: FACTORIAL(iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 89, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 24;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 37: /* MOD */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: MOD(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 79, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 14;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 38: /* AND */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: AND(scmp,scmp) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyscmp_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyscmp_NT] + 1;
		yytrace(a, 70, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 7;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: AND(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 87, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 22;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 40: /* ARGB */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* finit: ARGB(bloco,params) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yybloco_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyparams_NT] + 1;
		yytrace(a, 1, c + 0, p->cost[yyfinit_NT]);
		if (c + 0 < p->cost[yyfinit_NT]) {
			p->cost[yyfinit_NT] = c + 0;
			p->rule.yyfinit = 1;
		}
		if (	/* finit: ARGB(bloco,NIL) */
			OP_LABEL(RIGHT_CHILD(a)) == 296 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yybloco_NT] + 1;
			yytrace(a, 2, c + 0, p->cost[yyfinit_NT]);
			if (c + 0 < p->cost[yyfinit_NT]) {
				p->cost[yyfinit_NT] = c + 0;
				p->rule.yyfinit = 2;
			}
		}
		break;
	case 42: /* MUL */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: MUL(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 80, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 15;
			yyclosure_iexpr(a, c + 0);
		}
		/* rexpr: MUL(rexpr,rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 113, c + 0, p->cost[yyrexpr_NT]);
		if (c + 0 < p->cost[yyrexpr_NT]) {
			p->cost[yyrexpr_NT] = c + 0;
			p->rule.yyrexpr = 6;
			yyclosure_rexpr(a, c + 0);
		}
		break;
	case 43: /* ADD */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: ADD(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 76, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 11;
			yyclosure_iexpr(a, c + 0);
		}
		/* rexpr: ADD(rexpr,rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 110, c + 0, p->cost[yyrexpr_NT]);
		if (c + 0 < p->cost[yyrexpr_NT]) {
			p->cost[yyrexpr_NT] = c + 0;
			p->rule.yyrexpr = 3;
			yyclosure_rexpr(a, c + 0);
		}
		break;
	case 44: /* NEXT */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* params: NEXT(params,param) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyparams_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyparam_NT] + 0;
		yytrace(a, 4, c + 0, p->cost[yyparams_NT]);
		if (c + 0 < p->cost[yyparams_NT]) {
			p->cost[yyparams_NT] = c + 0;
			p->rule.yyparams = 2;
		}
		break;
	case 45: /* SUB */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: SUB(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 77, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 12;
			yyclosure_iexpr(a, c + 0);
		}
		/* rexpr: SUB(rexpr,rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 112, c + 0, p->cost[yyrexpr_NT]);
		if (c + 0 < p->cost[yyrexpr_NT]) {
			p->cost[yyrexpr_NT] = c + 0;
			p->rule.yyrexpr = 5;
			yyclosure_rexpr(a, c + 0);
		}
		break;
	case 47: /* DIV */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: DIV(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 78, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 13;
			yyclosure_iexpr(a, c + 0);
		}
		/* rexpr: DIV(rexpr,rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 114, c + 0, p->cost[yyrexpr_NT]);
		if (c + 0 < p->cost[yyrexpr_NT]) {
			p->cost[yyrexpr_NT] = c + 0;
			p->rule.yyrexpr = 7;
			yyclosure_rexpr(a, c + 0);
		}
		break;
	case 59: /* INSTR */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* decls: INSTR(decls,param) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yydecls_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyparam_NT] + 0;
		yytrace(a, 7, c + 0, p->cost[yydecls_NT]);
		if (c + 0 < p->cost[yydecls_NT]) {
			p->cost[yydecls_NT] = c + 0;
			p->rule.yydecls = 1;
		}
		/* for: INSTR(expr,forbody) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyforbody_NT] + 0;
		yytrace(a, 22, c + 0, p->cost[yyfor_NT]);
		if (c + 0 < p->cost[yyfor_NT]) {
			p->cost[yyfor_NT] = c + 0;
			p->rule.yyfor = 1;
			yyclosure_for(a, c + 0);
		}
		/* forinstr: INSTR(forstmt,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyforstmt_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 24, c + 0, p->cost[yyforinstr_NT]);
		if (c + 0 < p->cost[yyforinstr_NT]) {
			p->cost[yyforinstr_NT] = c + 0;
			p->rule.yyforinstr = 1;
		}
		break;
	case 60: /* LT */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: LT(scmp,scmp) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyscmp_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyscmp_NT] + 1;
		yytrace(a, 64, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 1;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: LT(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 81, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 16;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: LT(rexpr,rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 100, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 35;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: LT(iptrcmp,iptrcmp) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiptrcmp_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiptrcmp_NT] + 1;
		yytrace(a, 152, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 42;
			yyclosure_iexpr(a, c + 0);
		}
		/* cond: LT(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 0;
		yytrace(a, 158, c + 0, p->cost[yycond_NT]);
		if (c + 0 < p->cost[yycond_NT]) {
			p->cost[yycond_NT] = c + 0;
			p->rule.yycond = 2;
		}
		/* cond: LT(scmp,scmp) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyscmp_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyscmp_NT] + 0;
		yytrace(a, 164, c + 0, p->cost[yycond_NT]);
		if (c + 0 < p->cost[yycond_NT]) {
			p->cost[yycond_NT] = c + 0;
			p->rule.yycond = 8;
		}
		break;
	case 61: /* LOGIC_EQUAL */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: LOGIC_EQUAL(scmp,scmp) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyscmp_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyscmp_NT] + 1;
		yytrace(a, 69, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 6;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: LOGIC_EQUAL(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 86, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 21;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: LOGIC_EQUAL(rexpr,rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 104, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 39;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: LOGIC_EQUAL(iptrcmp,iptrcmp) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiptrcmp_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiptrcmp_NT] + 1;
		yytrace(a, 156, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 46;
			yyclosure_iexpr(a, c + 0);
		}
		/* cond: LOGIC_EQUAL(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 0;
		yytrace(a, 162, c + 0, p->cost[yycond_NT]);
		if (c + 0 < p->cost[yycond_NT]) {
			p->cost[yycond_NT] = c + 0;
			p->rule.yycond = 6;
		}
		/* cond: LOGIC_EQUAL(scmp,scmp) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyscmp_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyscmp_NT] + 0;
		yytrace(a, 168, c + 0, p->cost[yycond_NT]);
		if (c + 0 < p->cost[yycond_NT]) {
			p->cost[yycond_NT] = c + 0;
			p->rule.yycond = 12;
		}
		break;
	case 62: /* GT */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: GT(scmp,scmp) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyscmp_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyscmp_NT] + 1;
		yytrace(a, 65, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 2;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: GT(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 82, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 17;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: GT(rexpr,rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 101, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 36;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: GT(iptrcmp,iptrcmp) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiptrcmp_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiptrcmp_NT] + 1;
		yytrace(a, 153, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 43;
			yyclosure_iexpr(a, c + 0);
		}
		/* cond: GT(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 0;
		yytrace(a, 159, c + 0, p->cost[yycond_NT]);
		if (c + 0 < p->cost[yycond_NT]) {
			p->cost[yycond_NT] = c + 0;
			p->rule.yycond = 3;
		}
		/* cond: GT(scmp,scmp) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyscmp_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyscmp_NT] + 0;
		yytrace(a, 165, c + 0, p->cost[yycond_NT]);
		if (c + 0 < p->cost[yycond_NT]) {
			p->cost[yycond_NT] = c + 0;
			p->rule.yycond = 9;
		}
		break;
	case 91: /* INDEX */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* ilval: INDEX(slvec,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyslvec_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + (isInt(a));
		yytrace(a, 47, c + 0, p->cost[yyilval_NT]);
		if (c + 0 < p->cost[yyilval_NT]) {
			p->cost[yyilval_NT] = c + 0;
			p->rule.yyilval = 3;
		}
		/* rlval: INDEX(rlvec,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrlvec_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + (isReal(a));
		yytrace(a, 51, c + 0, p->cost[yyrlval_NT]);
		if (c + 0 < p->cost[yyrlval_NT]) {
			p->cost[yyrlval_NT] = c + 0;
			p->rule.yyrlval = 3;
			yyclosure_rlval(a, c + 0);
		}
		/* ilval: INDEX(iptrlvec,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiptrlvec_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + (isInt(a));
		yytrace(a, 125, c + 0, p->cost[yyilval_NT]);
		if (c + 0 < p->cost[yyilval_NT]) {
			p->cost[yyilval_NT] = c + 0;
			p->rule.yyilval = 4;
		}
		/* slval: INDEX(sptrlvec,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yysptrlvec_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + (isString(a));
		yytrace(a, 135, c + 0, p->cost[yyslval_NT]);
		if (c + 0 < p->cost[yyslval_NT]) {
			p->cost[yyslval_NT] = c + 0;
			p->rule.yyslval = 3;
			yyclosure_slval(a, c + 0);
		}
		/* rlval: INDEX(rptrlvec,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrptrlvec_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + (isReal(a));
		yytrace(a, 145, c + 0, p->cost[yyrlval_NT]);
		if (c + 0 < p->cost[yyrlval_NT]) {
			p->cost[yyrlval_NT] = c + 0;
			p->rule.yyrlval = 4;
			yyclosure_rlval(a, c + 0);
		}
		break;
	case 123: /* BLOCK */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* bloco: BLOCK(list,decls) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylist_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yydecls_NT] + 0;
		yytrace(a, 5, c + 0, p->cost[yybloco_NT]);
		if (c + 0 < p->cost[yybloco_NT]) {
			p->cost[yybloco_NT] = c + 0;
			p->rule.yybloco = 1;
			yyclosure_bloco(a, c + 0);
		}
		if (	/* bloco: BLOCK(INSTR(list,stmt),decls) */
			OP_LABEL(LEFT_CHILD(a)) == 59 /* INSTR */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(a))))->cost[yylist_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(LEFT_CHILD(a))))->cost[yystmt_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yydecls_NT] + 0;
			yytrace(a, 6, c + 0, p->cost[yybloco_NT]);
			if (c + 0 < p->cost[yybloco_NT]) {
				p->cost[yybloco_NT] = c + 0;
				p->rule.yybloco = 2;
				yyclosure_bloco(a, c + 0);
			}
		}
		break;
	case 124: /* OR */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: OR(scmp,scmp) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyscmp_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyscmp_NT] + 1;
		yytrace(a, 71, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 8;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: OR(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 88, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 23;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 126: /* LOGIC_NOT */
		break;
	case 257: /* INT */
		/* iexpr: INT */
		yytrace(a, 74, 1 + 0, p->cost[yyiexpr_NT]);
		if (1 + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = 1 + 0;
			p->rule.yyiexpr = 9;
			yyclosure_iexpr(a, 1 + 0);
		}
		break;
	case 258: /* REAL */
		/* rexpr: REAL */
		yytrace(a, 109, 1 + 0, p->cost[yyrexpr_NT]);
		if (1 + 0 < p->cost[yyrexpr_NT]) {
			p->cost[yyrexpr_NT] = 1 + 0;
			p->rule.yyrexpr = 2;
			yyclosure_rexpr(a, 1 + 0);
		}
		break;
	case 259: /* ID */
		/* ilval: ID */
		c = (isInt(a));
		yytrace(a, 46, c + 0, p->cost[yyilval_NT]);
		if (c + 0 < p->cost[yyilval_NT]) {
			p->cost[yyilval_NT] = c + 0;
			p->rule.yyilval = 2;
		}
		/* rlval: ID */
		c = (isReal(a));
		yytrace(a, 49, c + 0, p->cost[yyrlval_NT]);
		if (c + 0 < p->cost[yyrlval_NT]) {
			p->cost[yyrlval_NT] = c + 0;
			p->rule.yyrlval = 2;
			yyclosure_rlval(a, c + 0);
		}
		/* slval: ID */
		c = (isString(a));
		yytrace(a, 53, c + 0, p->cost[yyslval_NT]);
		if (c + 0 < p->cost[yyslval_NT]) {
			p->cost[yyslval_NT] = c + 0;
			p->rule.yyslval = 2;
			yyclosure_slval(a, c + 0);
		}
		/* iptrlval: ID */
		c = (isIntPointer(a));
		yytrace(a, 122, c + 0, p->cost[yyiptrlval_NT]);
		if (c + 0 < p->cost[yyiptrlval_NT]) {
			p->cost[yyiptrlval_NT] = c + 0;
			p->rule.yyiptrlval = 2;
			yyclosure_iptrlval(a, c + 0);
		}
		/* sptrlval: ID */
		c = (isStringPointer(a));
		yytrace(a, 132, c + 0, p->cost[yysptrlval_NT]);
		if (c + 0 < p->cost[yysptrlval_NT]) {
			p->cost[yysptrlval_NT] = c + 0;
			p->rule.yysptrlval = 2;
			yyclosure_sptrlval(a, c + 0);
		}
		/* rptrlval: ID */
		c = (isRealPointer(a));
		yytrace(a, 142, c + 0, p->cost[yyrptrlval_NT]);
		if (c + 0 < p->cost[yyrptrlval_NT]) {
			p->cost[yyrptrlval_NT] = c + 0;
			p->rule.yyrptrlval = 2;
			yyclosure_rptrlval(a, c + 0);
		}
		break;
	case 260: /* STR */
		/* sexpr: STR */
		yytrace(a, 55, 1 + 0, p->cost[yysexpr_NT]);
		if (1 + 0 < p->cost[yysexpr_NT]) {
			p->cost[yysexpr_NT] = 1 + 0;
			p->rule.yysexpr = 1;
			yyclosure_sexpr(a, 1 + 0);
		}
		break;
	case 261: /* DO */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* do: DO(begin,stmt) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yybegin_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yystmt_NT] + 1;
		yytrace(a, 20, c + 0, p->cost[yydo_NT]);
		if (c + 0 < p->cost[yydo_NT]) {
			p->cost[yydo_NT] = c + 0;
			p->rule.yydo = 1;
		}
		break;
	case 262: /* WHILE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* while: WHILE(do,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yydo_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 19, c + 0, p->cost[yywhile_NT]);
		if (c + 0 < p->cost[yywhile_NT]) {
			p->cost[yywhile_NT] = c + 0;
			p->rule.yywhile = 1;
			yyclosure_while(a, c + 0);
		}
		break;
	case 263: /* IF */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* if: IF(cond,stmt) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yycond_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yystmt_NT] + 0;
		yytrace(a, 15, c + 0, p->cost[yyif_NT]);
		if (c + 0 < p->cost[yyif_NT]) {
			p->cost[yyif_NT] = c + 0;
			p->rule.yyif = 1;
			yyclosure_if(a, c + 0);
		}
		/* cond2: IF(cond,stmt) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yycond_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yystmt_NT] + 1;
		yytrace(a, 18, c + 0, p->cost[yycond2_NT]);
		if (c + 0 < p->cost[yycond2_NT]) {
			p->cost[yycond2_NT] = c + 0;
			p->rule.yycond2 = 1;
		}
		break;
	case 264: /* THEN */
		break;
	case 265: /* FOR */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* forbody: FOR(forin,forinstr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyforin_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyforinstr_NT] + 0;
		yytrace(a, 23, c + 0, p->cost[yyforbody_NT]);
		if (c + 0 < p->cost[yyforbody_NT]) {
			p->cost[yyforbody_NT] = c + 0;
			p->rule.yyforbody = 1;
		}
		break;
	case 266: /* IN */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* forin: IN(forstart,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyforstart_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 26, c + 0, p->cost[yyforin_NT]);
		if (c + 0 < p->cost[yyforin_NT]) {
			p->cost[yyforin_NT] = c + 0;
			p->rule.yyforin = 1;
		}
		break;
	case 267: /* UPTO */
		break;
	case 268: /* DOWNTO */
		break;
	case 269: /* STEP */
		break;
	case 270: /* BREAK */
		/* stmt: BREAK */
		yytrace(a, 29, 1 + 0, p->cost[yystmt_NT]);
		if (1 + 0 < p->cost[yystmt_NT]) {
			p->cost[yystmt_NT] = 1 + 0;
			p->rule.yystmt = 2;
			yyclosure_stmt(a, 1 + 0);
		}
		break;
	case 271: /* CONTINUE */
		/* stmt: CONTINUE */
		yytrace(a, 30, 1 + 0, p->cost[yystmt_NT]);
		if (1 + 0 < p->cost[yystmt_NT]) {
			p->cost[yystmt_NT] = 1 + 0;
			p->rule.yystmt = 3;
			yyclosure_stmt(a, 1 + 0);
		}
		break;
	case 272: /* VOID */
		break;
	case 273: /* INTEGER */
		/* tipo: INTEGER */
		yytrace(a, 10, 0 + 0, p->cost[yytipo_NT]);
		if (0 + 0 < p->cost[yytipo_NT]) {
			p->cost[yytipo_NT] = 0 + 0;
			p->rule.yytipo = 1;
		}
		break;
	case 274: /* STRING */
		/* tipo: STRING */
		yytrace(a, 11, 0 + 0, p->cost[yytipo_NT]);
		if (0 + 0 < p->cost[yytipo_NT]) {
			p->cost[yytipo_NT] = 0 + 0;
			p->rule.yytipo = 2;
		}
		break;
	case 275: /* NUMBER */
		/* tipo: NUMBER */
		yytrace(a, 12, 0 + 0, p->cost[yytipo_NT]);
		if (0 + 0 < p->cost[yytipo_NT]) {
			p->cost[yytipo_NT] = 0 + 0;
			p->rule.yytipo = 3;
		}
		break;
	case 276: /* CONST */
		break;
	case 277: /* PUBLIC */
		break;
	case 278: /* INCR */
		yylabel(LEFT_CHILD(a),a);
		/* iexpr: INCR(ilval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyilval_NT] + 1;
		yytrace(a, 92, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 27;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 279: /* DECR */
		yylabel(LEFT_CHILD(a),a);
		/* iexpr: DECR(ilval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyilval_NT] + 1;
		yytrace(a, 93, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 28;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 280: /* IFX */
		break;
	case 281: /* ELSE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* ifelse: ELSE(cond2,stmt) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yycond2_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yystmt_NT] + 1;
		yytrace(a, 17, c + 0, p->cost[yyifelse_NT]);
		if (c + 0 < p->cost[yyifelse_NT]) {
			p->cost[yyifelse_NT] = c + 0;
			p->rule.yyifelse = 1;
			yyclosure_ifelse(a, c + 0);
		}
		break;
	case 282: /* ATR */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* sexpr: ATR(sassign,slval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yysassign_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyslval_NT] + 1;
		yytrace(a, 60, c + 0, p->cost[yysexpr_NT]);
		if (c + 0 < p->cost[yysexpr_NT]) {
			p->cost[yysexpr_NT] = c + 0;
			p->rule.yysexpr = 3;
			yyclosure_sexpr(a, c + 0);
		}
		/* iexpr: ATR(iassign,ilval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiassign_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyilval_NT] + 1;
		yytrace(a, 75, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 10;
			yyclosure_iexpr(a, c + 0);
		}
		/* rexpr: ATR(rassign,rlval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrassign_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrlval_NT] + 1;
		yytrace(a, 107, c + 0, p->cost[yyrexpr_NT]);
		if (c + 0 < p->cost[yyrexpr_NT]) {
			p->cost[yyrexpr_NT] = c + 0;
			p->rule.yyrexpr = 1;
			yyclosure_rexpr(a, c + 0);
		}
		/* iptrexpr: ATR(iptrassign,iptrlval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiptrassign_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiptrlval_NT] + 1;
		yytrace(a, 130, c + 0, p->cost[yyiptrexpr_NT]);
		if (c + 0 < p->cost[yyiptrexpr_NT]) {
			p->cost[yyiptrexpr_NT] = c + 0;
			p->rule.yyiptrexpr = 5;
			yyclosure_iptrexpr(a, c + 0);
		}
		/* sptrexpr: ATR(sptrassign,sptrlval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yysptrassign_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yysptrlval_NT] + 1;
		yytrace(a, 140, c + 0, p->cost[yysptrexpr_NT]);
		if (c + 0 < p->cost[yysptrexpr_NT]) {
			p->cost[yysptrexpr_NT] = c + 0;
			p->rule.yysptrexpr = 4;
			yyclosure_sptrexpr(a, c + 0);
		}
		/* rptrexpr: ATR(rptrassign,rptrlval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrptrassign_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrptrlval_NT] + 1;
		yytrace(a, 150, c + 0, p->cost[yyrptrexpr_NT]);
		if (c + 0 < p->cost[yyrptrexpr_NT]) {
			p->cost[yyrptrexpr_NT] = c + 0;
			p->rule.yyrptrexpr = 4;
			yyclosure_rptrexpr(a, c + 0);
		}
		break;
	case 283: /* NE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: NE(scmp,scmp) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyscmp_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyscmp_NT] + 1;
		yytrace(a, 68, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 5;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: NE(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 85, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 20;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: NE(rexpr,rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 105, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 40;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: NE(iptrcmp,iptrcmp) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiptrcmp_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiptrcmp_NT] + 1;
		yytrace(a, 157, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 47;
			yyclosure_iexpr(a, c + 0);
		}
		/* cond: NE(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 0;
		yytrace(a, 163, c + 0, p->cost[yycond_NT]);
		if (c + 0 < p->cost[yycond_NT]) {
			p->cost[yycond_NT] = c + 0;
			p->rule.yycond = 7;
		}
		/* cond: NE(scmp,scmp) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyscmp_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyscmp_NT] + 0;
		yytrace(a, 169, c + 0, p->cost[yycond_NT]);
		if (c + 0 < p->cost[yycond_NT]) {
			p->cost[yycond_NT] = c + 0;
			p->rule.yycond = 13;
		}
		break;
	case 284: /* GE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: GE(scmp,scmp) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyscmp_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyscmp_NT] + 1;
		yytrace(a, 66, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 3;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: GE(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 83, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 18;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: GE(rexpr,rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 102, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 37;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: GE(iptrcmp,iptrcmp) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiptrcmp_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiptrcmp_NT] + 1;
		yytrace(a, 154, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 44;
			yyclosure_iexpr(a, c + 0);
		}
		/* cond: GE(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 0;
		yytrace(a, 161, c + 0, p->cost[yycond_NT]);
		if (c + 0 < p->cost[yycond_NT]) {
			p->cost[yycond_NT] = c + 0;
			p->rule.yycond = 5;
		}
		/* cond: GE(scmp,scmp) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyscmp_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyscmp_NT] + 0;
		yytrace(a, 167, c + 0, p->cost[yycond_NT]);
		if (c + 0 < p->cost[yycond_NT]) {
			p->cost[yycond_NT] = c + 0;
			p->rule.yycond = 11;
		}
		break;
	case 285: /* LE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: LE(scmp,scmp) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyscmp_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyscmp_NT] + 1;
		yytrace(a, 67, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 4;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: LE(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 84, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 19;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: LE(rexpr,rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 103, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 38;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: LE(iptrcmp,iptrcmp) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiptrcmp_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiptrcmp_NT] + 1;
		yytrace(a, 155, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 45;
			yyclosure_iexpr(a, c + 0);
		}
		/* cond: LE(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 0;
		yytrace(a, 160, c + 0, p->cost[yycond_NT]);
		if (c + 0 < p->cost[yycond_NT]) {
			p->cost[yycond_NT] = c + 0;
			p->rule.yycond = 4;
		}
		/* cond: LE(scmp,scmp) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyscmp_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyscmp_NT] + 0;
		yytrace(a, 166, c + 0, p->cost[yycond_NT]);
		if (c + 0 < p->cost[yycond_NT]) {
			p->cost[yycond_NT] = c + 0;
			p->rule.yycond = 10;
		}
		break;
	case 286: /* UMINUS */
		yylabel(LEFT_CHILD(a),a);
		/* iexpr: UMINUS(iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 91, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 26;
			yyclosure_iexpr(a, c + 0);
		}
		/* rexpr: UMINUS(rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 111, c + 0, p->cost[yyrexpr_NT]);
		if (c + 0 < p->cost[yyrexpr_NT]) {
			p->cost[yyrexpr_NT] = c + 0;
			p->rule.yyrexpr = 4;
			yyclosure_rexpr(a, c + 0);
		}
		break;
	case 287: /* NOT */
		yylabel(LEFT_CHILD(a),a);
		/* iexpr: NOT(iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 90, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 25;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 288: /* REF */
		yylabel(LEFT_CHILD(a),a);
		/* iptrexpr: REF(ilval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyilval_NT] + 0;
		yytrace(a, 106, c + 0, p->cost[yyiptrexpr_NT]);
		if (c + 0 < p->cost[yyiptrexpr_NT]) {
			p->cost[yyiptrexpr_NT] = c + 0;
			p->rule.yyiptrexpr = 1;
			yyclosure_iptrexpr(a, c + 0);
		}
		/* iptrexpr: REF(ilval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyilval_NT] + 1;
		yytrace(a, 124, c + 0, p->cost[yyiptrexpr_NT]);
		if (c + 0 < p->cost[yyiptrexpr_NT]) {
			p->cost[yyiptrexpr_NT] = c + 0;
			p->rule.yyiptrexpr = 2;
			yyclosure_iptrexpr(a, c + 0);
		}
		/* iptrexpr: REF(ilval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyilval_NT] + 1;
		yytrace(a, 128, c + 0, p->cost[yyiptrexpr_NT]);
		if (c + 0 < p->cost[yyiptrexpr_NT]) {
			p->cost[yyiptrexpr_NT] = c + 0;
			p->rule.yyiptrexpr = 4;
			yyclosure_iptrexpr(a, c + 0);
		}
		/* sptrexpr: REF(slval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyslval_NT] + 1;
		yytrace(a, 134, c + 0, p->cost[yysptrexpr_NT]);
		if (c + 0 < p->cost[yysptrexpr_NT]) {
			p->cost[yysptrexpr_NT] = c + 0;
			p->rule.yysptrexpr = 1;
			yyclosure_sptrexpr(a, c + 0);
		}
		/* sptrexpr: REF(slval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyslval_NT] + 1;
		yytrace(a, 138, c + 0, p->cost[yysptrexpr_NT]);
		if (c + 0 < p->cost[yysptrexpr_NT]) {
			p->cost[yysptrexpr_NT] = c + 0;
			p->rule.yysptrexpr = 3;
			yyclosure_sptrexpr(a, c + 0);
		}
		/* rptrexpr: REF(rlval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrlval_NT] + 1;
		yytrace(a, 144, c + 0, p->cost[yyrptrexpr_NT]);
		if (c + 0 < p->cost[yyrptrexpr_NT]) {
			p->cost[yyrptrexpr_NT] = c + 0;
			p->rule.yyrptrexpr = 1;
			yyclosure_rptrexpr(a, c + 0);
		}
		/* rptrexpr: REF(rlval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrlval_NT] + 1;
		yytrace(a, 148, c + 0, p->cost[yyrptrexpr_NT]);
		if (c + 0 < p->cost[yyrptrexpr_NT]) {
			p->cost[yyrptrexpr_NT] = c + 0;
			p->rule.yyrptrexpr = 3;
			yyclosure_rptrexpr(a, c + 0);
		}
		break;
	case 289: /* LOCAL */
		/* ilval: LOCAL */
		c = (isInt(a));
		yytrace(a, 45, c + 0, p->cost[yyilval_NT]);
		if (c + 0 < p->cost[yyilval_NT]) {
			p->cost[yyilval_NT] = c + 0;
			p->rule.yyilval = 1;
		}
		/* rlval: LOCAL */
		c = (isReal(a));
		yytrace(a, 48, c + 0, p->cost[yyrlval_NT]);
		if (c + 0 < p->cost[yyrlval_NT]) {
			p->cost[yyrlval_NT] = c + 0;
			p->rule.yyrlval = 1;
			yyclosure_rlval(a, c + 0);
		}
		/* slval: LOCAL */
		c = (isString(a));
		yytrace(a, 52, c + 0, p->cost[yyslval_NT]);
		if (c + 0 < p->cost[yyslval_NT]) {
			p->cost[yyslval_NT] = c + 0;
			p->rule.yyslval = 1;
			yyclosure_slval(a, c + 0);
		}
		/* iptrlval: LOCAL */
		c = (isIntPointer(a));
		yytrace(a, 121, c + 0, p->cost[yyiptrlval_NT]);
		if (c + 0 < p->cost[yyiptrlval_NT]) {
			p->cost[yyiptrlval_NT] = c + 0;
			p->rule.yyiptrlval = 1;
			yyclosure_iptrlval(a, c + 0);
		}
		/* sptrlval: LOCAL */
		c = (isStringPointer(a));
		yytrace(a, 131, c + 0, p->cost[yysptrlval_NT]);
		if (c + 0 < p->cost[yysptrlval_NT]) {
			p->cost[yysptrlval_NT] = c + 0;
			p->rule.yysptrlval = 1;
			yyclosure_sptrlval(a, c + 0);
		}
		/* rptrlval: LOCAL */
		c = (isRealPointer(a));
		yytrace(a, 141, c + 0, p->cost[yyrptrlval_NT]);
		if (c + 0 < p->cost[yyrptrlval_NT]) {
			p->cost[yyrptrlval_NT] = c + 0;
			p->rule.yyrptrlval = 1;
			yyclosure_rptrlval(a, c + 0);
		}
		break;
	case 290: /* POSINC */
		yylabel(LEFT_CHILD(a),a);
		/* iexpr: POSINC(ilval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyilval_NT] + 1;
		yytrace(a, 94, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 29;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 291: /* POSDEC */
		yylabel(LEFT_CHILD(a),a);
		/* iexpr: POSDEC(ilval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyilval_NT] + 1;
		yytrace(a, 95, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 30;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 292: /* PTR */
		yylabel(LEFT_CHILD(a),a);
		/* sexpr: PTR(slval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyslval_NT] + 1;
		yytrace(a, 56, c + 0, p->cost[yysexpr_NT]);
		if (c + 0 < p->cost[yysexpr_NT]) {
			p->cost[yysexpr_NT] = c + 0;
			p->rule.yysexpr = 2;
			yyclosure_sexpr(a, c + 0);
		}
		/* iexpr: PTR(ilval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyilval_NT] + 1;
		yytrace(a, 96, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 31;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: PTR(slval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyslval_NT] + 1;
		yytrace(a, 97, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 32;
			yyclosure_iexpr(a, c + 0);
		}
		/* rexpr: PTR(rlval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrlval_NT] + 1;
		yytrace(a, 116, c + 0, p->cost[yyrexpr_NT]);
		if (c + 0 < p->cost[yyrexpr_NT]) {
			p->cost[yyrexpr_NT] = c + 0;
			p->rule.yyrexpr = 9;
			yyclosure_rexpr(a, c + 0);
		}
		/* iptrexpr: PTR(iptrlval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiptrlval_NT] + 1;
		yytrace(a, 126, c + 0, p->cost[yyiptrexpr_NT]);
		if (c + 0 < p->cost[yyiptrexpr_NT]) {
			p->cost[yyiptrexpr_NT] = c + 0;
			p->rule.yyiptrexpr = 3;
			yyclosure_iptrexpr(a, c + 0);
		}
		/* iexpr: PTR(iptrexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiptrexpr_NT] + 1;
		yytrace(a, 127, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 41;
			yyclosure_iexpr(a, c + 0);
		}
		/* sptrexpr: PTR(sptrlval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yysptrlval_NT] + 1;
		yytrace(a, 136, c + 0, p->cost[yysptrexpr_NT]);
		if (c + 0 < p->cost[yysptrexpr_NT]) {
			p->cost[yysptrexpr_NT] = c + 0;
			p->rule.yysptrexpr = 2;
			yyclosure_sptrexpr(a, c + 0);
		}
		/* sexpr: PTR(sptrexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yysptrexpr_NT] + 1;
		yytrace(a, 137, c + 0, p->cost[yysexpr_NT]);
		if (c + 0 < p->cost[yysexpr_NT]) {
			p->cost[yysexpr_NT] = c + 0;
			p->rule.yysexpr = 6;
			yyclosure_sexpr(a, c + 0);
		}
		/* rptrexpr: PTR(rptrlval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrptrlval_NT] + 1;
		yytrace(a, 146, c + 0, p->cost[yyrptrexpr_NT]);
		if (c + 0 < p->cost[yyrptrexpr_NT]) {
			p->cost[yyrptrexpr_NT] = c + 0;
			p->rule.yyrptrexpr = 2;
			yyclosure_rptrexpr(a, c + 0);
		}
		/* rexpr: PTR(rptrexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrptrexpr_NT] + 1;
		yytrace(a, 147, c + 0, p->cost[yyrexpr_NT]);
		if (c + 0 < p->cost[yyrexpr_NT]) {
			p->cost[yyrexpr_NT] = c + 0;
			p->rule.yyrexpr = 12;
			yyclosure_rexpr(a, c + 0);
		}
		break;
	case 293: /* CALL */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* expr: CALL(ID,arguments) */
			OP_LABEL(LEFT_CHILD(a)) == 259 /* ID */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyarguments_NT] + 1;
			yytrace(a, 43, c + 0, p->cost[yyexpr_NT]);
			if (c + 0 < p->cost[yyexpr_NT]) {
				p->cost[yyexpr_NT] = c + 0;
				p->rule.yyexpr = 7;
				yyclosure_expr(a, c + 0);
			}
		}
		if (	/* expr: CALL(ID,VOID) */
			OP_LABEL(LEFT_CHILD(a)) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(a)) == 272 /* VOID */
		) {
			c = 1;
			yytrace(a, 44, c + 0, p->cost[yyexpr_NT]);
			if (c + 0 < p->cost[yyexpr_NT]) {
				p->cost[yyexpr_NT] = c + 0;
				p->rule.yyexpr = 8;
				yyclosure_expr(a, c + 0);
			}
		}
		if (	/* sexpr: CALL(ID,arguments) */
			OP_LABEL(LEFT_CHILD(a)) == 259 /* ID */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyarguments_NT] + (isStringFunction(a));
			yytrace(a, 61, c + 0, p->cost[yysexpr_NT]);
			if (c + 0 < p->cost[yysexpr_NT]) {
				p->cost[yysexpr_NT] = c + 0;
				p->rule.yysexpr = 4;
				yyclosure_sexpr(a, c + 0);
			}
		}
		if (	/* sexpr: CALL(ID,VOID) */
			OP_LABEL(LEFT_CHILD(a)) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(a)) == 272 /* VOID */
		) {
			c = (isStringFunction(a));
			yytrace(a, 62, c + 0, p->cost[yysexpr_NT]);
			if (c + 0 < p->cost[yysexpr_NT]) {
				p->cost[yysexpr_NT] = c + 0;
				p->rule.yysexpr = 5;
				yyclosure_sexpr(a, c + 0);
			}
		}
		if (	/* iexpr: CALL(ID,arguments) */
			OP_LABEL(LEFT_CHILD(a)) == 259 /* ID */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyarguments_NT] + (isIntFunction(a));
			yytrace(a, 98, c + 0, p->cost[yyiexpr_NT]);
			if (c + 0 < p->cost[yyiexpr_NT]) {
				p->cost[yyiexpr_NT] = c + 0;
				p->rule.yyiexpr = 33;
				yyclosure_iexpr(a, c + 0);
			}
		}
		if (	/* iexpr: CALL(ID,VOID) */
			OP_LABEL(LEFT_CHILD(a)) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(a)) == 272 /* VOID */
		) {
			c = (isIntFunction(a));
			yytrace(a, 99, c + 0, p->cost[yyiexpr_NT]);
			if (c + 0 < p->cost[yyiexpr_NT]) {
				p->cost[yyiexpr_NT] = c + 0;
				p->rule.yyiexpr = 34;
				yyclosure_iexpr(a, c + 0);
			}
		}
		if (	/* rexpr: CALL(ID,arguments) */
			OP_LABEL(LEFT_CHILD(a)) == 259 /* ID */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyarguments_NT] + (isRealFunction(a));
			yytrace(a, 117, c + 0, p->cost[yyrexpr_NT]);
			if (c + 0 < p->cost[yyrexpr_NT]) {
				p->cost[yyrexpr_NT] = c + 0;
				p->rule.yyrexpr = 10;
				yyclosure_rexpr(a, c + 0);
			}
		}
		if (	/* rexpr: CALL(ID,VOID) */
			OP_LABEL(LEFT_CHILD(a)) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(a)) == 272 /* VOID */
		) {
			c = (isRealFunction(a));
			yytrace(a, 118, c + 0, p->cost[yyrexpr_NT]);
			if (c + 0 < p->cost[yyrexpr_NT]) {
				p->cost[yyrexpr_NT] = c + 0;
				p->rule.yyrexpr = 11;
				yyclosure_rexpr(a, c + 0);
			}
		}
		break;
	case 294: /* START */
		/* begin: START */
		yytrace(a, 21, 1 + 0, p->cost[yybegin_NT]);
		if (1 + 0 < p->cost[yybegin_NT]) {
			p->cost[yybegin_NT] = 1 + 0;
			p->rule.yybegin = 1;
		}
		/* forstart: START */
		yytrace(a, 27, 1 + 0, p->cost[yyforstart_NT]);
		if (1 + 0 < p->cost[yyforstart_NT]) {
			p->cost[yyforstart_NT] = 1 + 0;
			p->rule.yyforstart = 1;
		}
		break;
	case 295: /* PARAM */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* param: PARAM(tipo,ID) */
			OP_LABEL(RIGHT_CHILD(a)) == 259 /* ID */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yytipo_NT] + 0;
			yytrace(a, 9, c + 0, p->cost[yyparam_NT]);
			if (c + 0 < p->cost[yyparam_NT]) {
				p->cost[yyparam_NT] = c + 0;
				p->rule.yyparam = 1;
				yyclosure_param(a, c + 0);
			}
		}
		break;
	case 296: /* NIL */
		break;
	case 297: /* LIST */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* list: LIST(list,base) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylist_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yybase_NT] + 0;
		yytrace(a, 14, c + 0, p->cost[yylist_NT]);
		if (c + 0 < p->cost[yylist_NT]) {
			p->cost[yylist_NT] = c + 0;
			p->rule.yylist = 2;
		}
		break;
	case 298: /* ARGS */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* arguments: ARGS(NIL,expr) */
			OP_LABEL(LEFT_CHILD(a)) == 296 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 0;
			yytrace(a, 119, c + 0, p->cost[yyarguments_NT]);
			if (c + 0 < p->cost[yyarguments_NT]) {
				p->cost[yyarguments_NT] = c + 0;
				p->rule.yyarguments = 1;
			}
		}
		/* arguments: ARGS(arguments,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyarguments_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 0;
		yytrace(a, 120, c + 0, p->cost[yyarguments_NT]);
		if (c + 0 < p->cost[yyarguments_NT]) {
			p->cost[yyarguments_NT] = c + 0;
			p->rule.yyarguments = 2;
		}
		break;
	case 299: /* NONE */
		/* decls: NONE */
		yytrace(a, 8, 0 + 0, p->cost[yydecls_NT]);
		if (0 + 0 < p->cost[yydecls_NT]) {
			p->cost[yydecls_NT] = 0 + 0;
			p->rule.yydecls = 2;
		}
		break;
	default:
		PANIC("yylabel", "Bad terminal", OP_LABEL(a));
	}
}

static void yykids(NODEPTR_TYPE p, int eruleno, NODEPTR_TYPE kids[]) {
	if (!p)
		PANIC("yykids", "Null tree in rule", eruleno);
	if (!kids)
		PANIC("yykids", "Null kids in", OP_LABEL(p));
	switch (eruleno) {
	case 169: /* cond: NE(scmp,scmp) */
	case 168: /* cond: LOGIC_EQUAL(scmp,scmp) */
	case 167: /* cond: GE(scmp,scmp) */
	case 166: /* cond: LE(scmp,scmp) */
	case 165: /* cond: GT(scmp,scmp) */
	case 164: /* cond: LT(scmp,scmp) */
	case 163: /* cond: NE(iexpr,iexpr) */
	case 162: /* cond: LOGIC_EQUAL(iexpr,iexpr) */
	case 161: /* cond: GE(iexpr,iexpr) */
	case 160: /* cond: LE(iexpr,iexpr) */
	case 159: /* cond: GT(iexpr,iexpr) */
	case 158: /* cond: LT(iexpr,iexpr) */
	case 157: /* iexpr: NE(iptrcmp,iptrcmp) */
	case 156: /* iexpr: LOGIC_EQUAL(iptrcmp,iptrcmp) */
	case 155: /* iexpr: LE(iptrcmp,iptrcmp) */
	case 154: /* iexpr: GE(iptrcmp,iptrcmp) */
	case 153: /* iexpr: GT(iptrcmp,iptrcmp) */
	case 152: /* iexpr: LT(iptrcmp,iptrcmp) */
	case 150: /* rptrexpr: ATR(rptrassign,rptrlval) */
	case 145: /* rlval: INDEX(rptrlvec,expr) */
	case 140: /* sptrexpr: ATR(sptrassign,sptrlval) */
	case 135: /* slval: INDEX(sptrlvec,expr) */
	case 130: /* iptrexpr: ATR(iptrassign,iptrlval) */
	case 125: /* ilval: INDEX(iptrlvec,expr) */
	case 120: /* arguments: ARGS(arguments,expr) */
	case 114: /* rexpr: DIV(rexpr,rexpr) */
	case 113: /* rexpr: MUL(rexpr,rexpr) */
	case 112: /* rexpr: SUB(rexpr,rexpr) */
	case 110: /* rexpr: ADD(rexpr,rexpr) */
	case 107: /* rexpr: ATR(rassign,rlval) */
	case 105: /* iexpr: NE(rexpr,rexpr) */
	case 104: /* iexpr: LOGIC_EQUAL(rexpr,rexpr) */
	case 103: /* iexpr: LE(rexpr,rexpr) */
	case 102: /* iexpr: GE(rexpr,rexpr) */
	case 101: /* iexpr: GT(rexpr,rexpr) */
	case 100: /* iexpr: LT(rexpr,rexpr) */
	case 88: /* iexpr: OR(iexpr,iexpr) */
	case 87: /* iexpr: AND(iexpr,iexpr) */
	case 86: /* iexpr: LOGIC_EQUAL(iexpr,iexpr) */
	case 85: /* iexpr: NE(iexpr,iexpr) */
	case 84: /* iexpr: LE(iexpr,iexpr) */
	case 83: /* iexpr: GE(iexpr,iexpr) */
	case 82: /* iexpr: GT(iexpr,iexpr) */
	case 81: /* iexpr: LT(iexpr,iexpr) */
	case 80: /* iexpr: MUL(iexpr,iexpr) */
	case 79: /* iexpr: MOD(iexpr,iexpr) */
	case 78: /* iexpr: DIV(iexpr,iexpr) */
	case 77: /* iexpr: SUB(iexpr,iexpr) */
	case 76: /* iexpr: ADD(iexpr,iexpr) */
	case 75: /* iexpr: ATR(iassign,ilval) */
	case 71: /* iexpr: OR(scmp,scmp) */
	case 70: /* iexpr: AND(scmp,scmp) */
	case 69: /* iexpr: LOGIC_EQUAL(scmp,scmp) */
	case 68: /* iexpr: NE(scmp,scmp) */
	case 67: /* iexpr: LE(scmp,scmp) */
	case 66: /* iexpr: GE(scmp,scmp) */
	case 65: /* iexpr: GT(scmp,scmp) */
	case 64: /* iexpr: LT(scmp,scmp) */
	case 60: /* sexpr: ATR(sassign,slval) */
	case 51: /* rlval: INDEX(rlvec,expr) */
	case 47: /* ilval: INDEX(slvec,expr) */
	case 26: /* forin: IN(forstart,expr) */
	case 24: /* forinstr: INSTR(forstmt,expr) */
	case 23: /* forbody: FOR(forin,forinstr) */
	case 22: /* for: INSTR(expr,forbody) */
	case 20: /* do: DO(begin,stmt) */
	case 19: /* while: WHILE(do,expr) */
	case 18: /* cond2: IF(cond,stmt) */
	case 17: /* ifelse: ELSE(cond2,stmt) */
	case 15: /* if: IF(cond,stmt) */
	case 14: /* list: LIST(list,base) */
	case 7: /* decls: INSTR(decls,param) */
	case 5: /* bloco: BLOCK(list,decls) */
	case 4: /* params: NEXT(params,param) */
	case 1: /* finit: ARGB(bloco,params) */
		kids[0] = LEFT_CHILD(p);
		kids[1] = RIGHT_CHILD(p);
		break;
	case 148: /* rptrexpr: REF(rlval) */
	case 147: /* rexpr: PTR(rptrexpr) */
	case 146: /* rptrexpr: PTR(rptrlval) */
	case 144: /* rptrexpr: REF(rlval) */
	case 138: /* sptrexpr: REF(slval) */
	case 137: /* sexpr: PTR(sptrexpr) */
	case 136: /* sptrexpr: PTR(sptrlval) */
	case 134: /* sptrexpr: REF(slval) */
	case 128: /* iptrexpr: REF(ilval) */
	case 127: /* iexpr: PTR(iptrexpr) */
	case 126: /* iptrexpr: PTR(iptrlval) */
	case 124: /* iptrexpr: REF(ilval) */
	case 116: /* rexpr: PTR(rlval) */
	case 111: /* rexpr: UMINUS(rexpr) */
	case 106: /* iptrexpr: REF(ilval) */
	case 97: /* iexpr: PTR(slval) */
	case 96: /* iexpr: PTR(ilval) */
	case 95: /* iexpr: POSDEC(ilval) */
	case 94: /* iexpr: POSINC(ilval) */
	case 93: /* iexpr: DECR(ilval) */
	case 92: /* iexpr: INCR(ilval) */
	case 91: /* iexpr: UMINUS(iexpr) */
	case 90: /* iexpr: NOT(iexpr) */
	case 89: /* iexpr: FACTORIAL(iexpr) */
	case 56: /* sexpr: PTR(slval) */
	case 9: /* param: PARAM(tipo,ID) */
	case 2: /* finit: ARGB(bloco,NIL) */
		kids[0] = LEFT_CHILD(p);
		break;
	case 151: /* iptrcmp: iptrexpr */
	case 149: /* rptrassign: rptrexpr */
	case 143: /* rptrlvec: rptrlval */
	case 139: /* sptrassign: sptrexpr */
	case 133: /* sptrlvec: sptrlval */
	case 129: /* iptrassign: iptrexpr */
	case 123: /* iptrlvec: iptrlval */
	case 115: /* rexpr: iexpr */
	case 108: /* rassign: rexpr */
	case 73: /* iassign: rexpr */
	case 72: /* iassign: iexpr */
	case 63: /* scmp: sexpr */
	case 59: /* sassign: iptrexpr */
	case 58: /* sassign: iexpr */
	case 57: /* sassign: sexpr */
	case 54: /* slvec: slval */
	case 50: /* rlvec: rlval */
	case 42: /* expr: rptrexpr */
	case 41: /* expr: sptrexpr */
	case 40: /* expr: iptrexpr */
	case 39: /* expr: rexpr */
	case 38: /* expr: sexpr */
	case 37: /* expr: iexpr */
	case 36: /* base: bloco */
	case 35: /* base: for */
	case 34: /* base: while */
	case 33: /* base: ifelse */
	case 32: /* base: if */
	case 31: /* base: expr */
	case 28: /* stmt: base */
	case 25: /* forstmt: stmt */
	case 16: /* cond: expr */
	case 13: /* list: base */
	case 3: /* params: param */
		kids[0] = p;
		break;
	case 6: /* bloco: BLOCK(INSTR(list,stmt),decls) */
		kids[0] = LEFT_CHILD(LEFT_CHILD(p));
		kids[1] = RIGHT_CHILD(LEFT_CHILD(p));
		kids[2] = RIGHT_CHILD(p);
		break;
	case 142: /* rptrlval: ID */
	case 141: /* rptrlval: LOCAL */
	case 132: /* sptrlval: ID */
	case 131: /* sptrlval: LOCAL */
	case 122: /* iptrlval: ID */
	case 121: /* iptrlval: LOCAL */
	case 118: /* rexpr: CALL(ID,VOID) */
	case 109: /* rexpr: REAL */
	case 99: /* iexpr: CALL(ID,VOID) */
	case 74: /* iexpr: INT */
	case 62: /* sexpr: CALL(ID,VOID) */
	case 55: /* sexpr: STR */
	case 53: /* slval: ID */
	case 52: /* slval: LOCAL */
	case 49: /* rlval: ID */
	case 48: /* rlval: LOCAL */
	case 46: /* ilval: ID */
	case 45: /* ilval: LOCAL */
	case 44: /* expr: CALL(ID,VOID) */
	case 30: /* stmt: CONTINUE */
	case 29: /* stmt: BREAK */
	case 27: /* forstart: START */
	case 21: /* begin: START */
	case 12: /* tipo: NUMBER */
	case 11: /* tipo: STRING */
	case 10: /* tipo: INTEGER */
	case 8: /* decls: NONE */
		break;
	case 119: /* arguments: ARGS(NIL,expr) */
	case 117: /* rexpr: CALL(ID,arguments) */
	case 98: /* iexpr: CALL(ID,arguments) */
	case 61: /* sexpr: CALL(ID,arguments) */
	case 43: /* expr: CALL(ID,arguments) */
		kids[0] = RIGHT_CHILD(p);
		break;
	default:
		PANIC("yykids", "Bad rule number", eruleno);
	}
}

static void yyreduce(NODEPTR_TYPE p, int goalnt)
{
  int eruleno = yyrule(STATE_LABEL(p), goalnt);
  short *nts = yynts[eruleno];
  NODEPTR_TYPE kids[3];
  int i;

  for (yykids(p, eruleno, kids), i = 0; nts[i]; i++)
    yyreduce(kids[i], nts[i]);

  switch(eruleno) {
	case 1: /* finit: ARGB(bloco,params) */
#line 82 "diy.brg"
{if (functionReturnType != 4) {if (functionReturnType != 3)fprintf(outfp, pfLOCAL pfLOAD pfPOP, 8);
															else if(functionReturnType == 3) fprintf(outfp, pfLOCAL pfLOAD2 pfDPOP, 8);}}
		break;
	case 2: /* finit: ARGB(bloco,NIL) */
#line 84 "diy.brg"
{if (functionReturnType != 4) {if (functionReturnType != 3)fprintf(outfp, pfLOCAL pfLOAD pfPOP, 8);
															else if(functionReturnType == 3) fprintf(outfp, pfLOCAL pfLOAD2 pfDPOP, 8);}}
		break;
	case 3: /* params: param */
#line 87 "diy.brg"

		break;
	case 4: /* params: NEXT(params,param) */
#line 88 "diy.brg"

		break;
	case 5: /* bloco: BLOCK(list,decls) */
#line 90 "diy.brg"

		break;
	case 6: /* bloco: BLOCK(INSTR(list,stmt),decls) */
#line 91 "diy.brg"

		break;
	case 7: /* decls: INSTR(decls,param) */
#line 93 "diy.brg"

		break;
	case 8: /* decls: NONE */
#line 94 "diy.brg"

		break;
	case 9: /* param: PARAM(tipo,ID) */
#line 96 "diy.brg"

		break;
	case 10: /* tipo: INTEGER */
#line 98 "diy.brg"

		break;
	case 11: /* tipo: STRING */
#line 99 "diy.brg"

		break;
	case 12: /* tipo: NUMBER */
#line 100 "diy.brg"

		break;
	case 13: /* list: base */
#line 103 "diy.brg"

		break;
	case 14: /* list: LIST(list,base) */
#line 104 "diy.brg"

		break;
	case 15: /* if: IF(cond,stmt) */
#line 107 "diy.brg"
{fprintf(outfp, pfLABEL, mklbl(LEFT_CHILD(p)->place)); }
		break;
	case 16: /* cond: expr */
#line 108 "diy.brg"
{p->place = ++lbl; fprintf(outfp, pfJZ, mklbl(p->place));}
		break;
	case 17: /* ifelse: ELSE(cond2,stmt) */
#line 112 "diy.brg"
{ fprintf(outfp, pfLABEL, mklbl(LEFT_CHILD(p)->place)); }
		break;
	case 18: /* cond2: IF(cond,stmt) */
#line 113 "diy.brg"
{ p->place = ++lbl; fprintf(outfp, pfJMP pfLABEL,
mklbl(p->place), mklbl(LEFT_CHILD(p)->place)); }
		break;
	case 19: /* while: WHILE(do,expr) */
#line 118 "diy.brg"
{dblcnt--; brkcnt--; fprintf(outfp, pfJNZ pfLABEL,
													mklbl(lbls[dblcnt].b_lbl), mklbl(lbls[dblcnt].e_lbl)); }
		break;
	case 20: /* do: DO(begin,stmt) */
#line 120 "diy.brg"
{}
		break;
	case 21: /* begin: START */
#line 121 "diy.brg"
{ fprintf(outfp, pfLABEL, mklbl(++lbl)); lbls[dblcnt].b_lbl = lbl; lbls[dblcnt].e_lbl = ++lbl;
				brklbl[brkcnt++] = lbls[dblcnt++].e_lbl; }
		break;
	case 22: /* for: INSTR(expr,forbody) */
#line 126 "diy.brg"

		break;
	case 23: /* forbody: FOR(forin,forinstr) */
#line 127 "diy.brg"
{fprintf(outfp, pfLABEL, mklbl(lbls[--dblcnt].e_lbl));}
		break;
	case 24: /* forinstr: INSTR(forstmt,expr) */
#line 128 "diy.brg"
{fprintf(outfp, pfJMP, mklbl(lbls[dblcnt - 1].b_lbl));}
		break;
	case 25: /* forstmt: stmt */
#line 129 "diy.brg"
{}
		break;
	case 26: /* forin: IN(forstart,expr) */
#line 130 "diy.brg"
{fprintf(outfp, pfJZ, mklbl(++lbl)); lbls[dblcnt].e_lbl = lbl; brklbl[brkcnt++] = lbls[dblcnt++].e_lbl;}
		break;
	case 27: /* forstart: START */
#line 131 "diy.brg"
{fprintf(outfp, pfLABEL, mklbl(++lbl)); lbls[dblcnt].b_lbl = lbl; }
		break;
	case 28: /* stmt: base */
#line 135 "diy.brg"

		break;
	case 29: /* stmt: BREAK */
#line 136 "diy.brg"
{ fprintf(outfp, pfJMP, mklbl(brklbl[brkcnt - p->value.i])); }
		break;
	case 30: /* stmt: CONTINUE */
#line 137 "diy.brg"
{ fprintf(outfp, pfJMP, mklbl(brklbl[p->value.i])); }
		break;
	case 31: /* base: expr */
#line 141 "diy.brg"
{fprintf(outfp, pfTRASH, (int)p->place); }
		break;
	case 32: /* base: if */
#line 142 "diy.brg"

		break;
	case 33: /* base: ifelse */
#line 143 "diy.brg"

		break;
	case 34: /* base: while */
#line 144 "diy.brg"

		break;
	case 35: /* base: for */
#line 145 "diy.brg"

		break;
	case 36: /* base: bloco */
#line 146 "diy.brg"

		break;
	case 37: /* expr: iexpr */
#line 152 "diy.brg"
{p->place = 4;}
		break;
	case 38: /* expr: sexpr */
#line 153 "diy.brg"
{p->place = 4;}
		break;
	case 39: /* expr: rexpr */
#line 154 "diy.brg"
{p->place = 8;}
		break;
	case 40: /* expr: iptrexpr */
#line 155 "diy.brg"
{p->place = 4;}
		break;
	case 41: /* expr: sptrexpr */
#line 156 "diy.brg"
{p->place = 4;}
		break;
	case 42: /* expr: rptrexpr */
#line 157 "diy.brg"
{p->place = 4;}
		break;
	case 43: /* expr: CALL(ID,arguments) */
#line 160 "diy.brg"
{fprintf(outfp, pfCALL pfTRASH pfPUSH, mkfunc(LEFT_CHILD(p)->value.s),
														 (int)((RIGHT_CHILD(p)->place))); p->place = IDfind(LEFT_CHILD(p)->value.s, NULL) == 3 ? 8: 4;}
		break;
	case 44: /* expr: CALL(ID,VOID) */
#line 162 "diy.brg"
{fprintf(outfp, pfCALL pfPUSH, mkfunc(LEFT_CHILD(p)->value.s));
												p->place = IDfind(LEFT_CHILD(p)->value.s, NULL) == 3 ? 8: 4;}
		break;
	case 45: /* ilval: LOCAL */
#line 167 "diy.brg"
{fprintf(outfp, pfLOCAL, p->value.i * (pfWORD/4));}
		break;
	case 46: /* ilval: ID */
#line 168 "diy.brg"
{fprintf(outfp, pfADDR, p->value.s);}
		break;
	case 47: /* ilval: INDEX(slvec,expr) */
#line 169 "diy.brg"
{fprintf(outfp, pfADD);}
		break;
	case 48: /* rlval: LOCAL */
#line 172 "diy.brg"
{fprintf(outfp, pfLOCAL, p->value.i * (pfWORD/4));}
		break;
	case 49: /* rlval: ID */
#line 173 "diy.brg"
{fprintf(outfp, pfADDR, p->value.s);}
		break;
	case 50: /* rlvec: rlval */
#line 174 "diy.brg"
{fprintf(outfp, pfLOAD);}
		break;
	case 51: /* rlval: INDEX(rlvec,expr) */
#line 175 "diy.brg"
{ fprintf(outfp, pfIMM pfMUL pfADD, 8);}
		break;
	case 52: /* slval: LOCAL */
#line 178 "diy.brg"
{fprintf(outfp, pfLOCAL, p->value.i * (pfWORD/4));}
		break;
	case 53: /* slval: ID */
#line 179 "diy.brg"
{fprintf(outfp, pfADDR, p->value.s);}
		break;
	case 54: /* slvec: slval */
#line 180 "diy.brg"
{fprintf(outfp, pfLOAD);}
		break;
	case 55: /* sexpr: STR */
#line 183 "diy.brg"
{	lbl++; fprintf(outfp, pfRODATA pfALIGN pfLABEL, mklbl(lbl));
					outstr(p->value.s); fprintf(outfp, pfTEXT pfADDR, mklbl(lbl));}
		break;
	case 56: /* sexpr: PTR(slval) */
#line 186 "diy.brg"
{fprintf(outfp, pfLOAD);}
		break;
	case 57: /* sassign: sexpr */
#line 188 "diy.brg"
{fprintf(outfp, pfDUP);}
		break;
	case 58: /* sassign: iexpr */
#line 189 "diy.brg"
{fprintf(outfp, pfDUP); /*assign to null (0)*/}
		break;
	case 59: /* sassign: iptrexpr */
#line 190 "diy.brg"
{fprintf(outfp, pfDUP); /*assign to pointer type*/}
		break;
	case 60: /* sexpr: ATR(sassign,slval) */
#line 192 "diy.brg"
{fprintf(outfp, pfSTORE);}
		break;
	case 61: /* sexpr: CALL(ID,arguments) */
#line 193 "diy.brg"
{fprintf(outfp, pfCALL pfTRASH pfPUSH, mkfunc(LEFT_CHILD(p)->value.s),
													 (int)((RIGHT_CHILD(p)->place))); p->place = IDfind(LEFT_CHILD(p)->value.s, NULL) == 3 ? 8: 4;}
		break;
	case 62: /* sexpr: CALL(ID,VOID) */
#line 195 "diy.brg"
{fprintf(outfp, pfCALL pfPUSH, mkfunc(LEFT_CHILD(p)->value.s));
																			 p->place = IDfind(LEFT_CHILD(p)->value.s, NULL) == 3 ? 8: 4;}
		break;
	case 63: /* scmp: sexpr */
#line 199 "diy.brg"
{fprintf(outfp, pfLDCHR);}
		break;
	case 64: /* iexpr: LT(scmp,scmp) */
#line 200 "diy.brg"
{fprintf(outfp, pfLT);}
		break;
	case 65: /* iexpr: GT(scmp,scmp) */
#line 201 "diy.brg"
{fprintf(outfp, pfGT);}
		break;
	case 66: /* iexpr: GE(scmp,scmp) */
#line 202 "diy.brg"
{fprintf(outfp, pfGE);}
		break;
	case 67: /* iexpr: LE(scmp,scmp) */
#line 203 "diy.brg"
{fprintf(outfp, pfLE);}
		break;
	case 68: /* iexpr: NE(scmp,scmp) */
#line 204 "diy.brg"
{fprintf(outfp, pfNE);}
		break;
	case 69: /* iexpr: LOGIC_EQUAL(scmp,scmp) */
#line 205 "diy.brg"
{fprintf(outfp, pfEQ);}
		break;
	case 70: /* iexpr: AND(scmp,scmp) */
#line 206 "diy.brg"
{fprintf(outfp, pfAND);}
		break;
	case 71: /* iexpr: OR(scmp,scmp) */
#line 207 "diy.brg"
{fprintf(outfp, pfOR);}
		break;
	case 72: /* iassign: iexpr */
#line 210 "diy.brg"
{fprintf(outfp, pfDUP);}
		break;
	case 73: /* iassign: rexpr */
#line 213 "diy.brg"
{fprintf(outfp, pfD2I pfDUP);}
		break;
	case 74: /* iexpr: INT */
#line 215 "diy.brg"
{fprintf(outfp, pfIMM, p->value.i);}
		break;
	case 75: /* iexpr: ATR(iassign,ilval) */
#line 216 "diy.brg"
{fprintf(outfp, pfSTORE);}
		break;
	case 76: /* iexpr: ADD(iexpr,iexpr) */
#line 217 "diy.brg"
{fprintf(outfp, pfADD);}
		break;
	case 77: /* iexpr: SUB(iexpr,iexpr) */
#line 218 "diy.brg"
{fprintf(outfp, pfSUB);}
		break;
	case 78: /* iexpr: DIV(iexpr,iexpr) */
#line 219 "diy.brg"
{fprintf(outfp, pfDIV);}
		break;
	case 79: /* iexpr: MOD(iexpr,iexpr) */
#line 220 "diy.brg"
{fprintf(outfp, pfMOD);}
		break;
	case 80: /* iexpr: MUL(iexpr,iexpr) */
#line 221 "diy.brg"
{fprintf(outfp, pfMUL);}
		break;
	case 81: /* iexpr: LT(iexpr,iexpr) */
#line 222 "diy.brg"
{fprintf(outfp, pfLT);}
		break;
	case 82: /* iexpr: GT(iexpr,iexpr) */
#line 223 "diy.brg"
{fprintf(outfp, pfGT);}
		break;
	case 83: /* iexpr: GE(iexpr,iexpr) */
#line 224 "diy.brg"
{fprintf(outfp, pfGE);}
		break;
	case 84: /* iexpr: LE(iexpr,iexpr) */
#line 225 "diy.brg"
{fprintf(outfp, pfLE);}
		break;
	case 85: /* iexpr: NE(iexpr,iexpr) */
#line 226 "diy.brg"
{fprintf(outfp, pfNE);}
		break;
	case 86: /* iexpr: LOGIC_EQUAL(iexpr,iexpr) */
#line 227 "diy.brg"
{fprintf(outfp, pfEQ);}
		break;
	case 87: /* iexpr: AND(iexpr,iexpr) */
#line 228 "diy.brg"
{fprintf(outfp, pfAND);}
		break;
	case 88: /* iexpr: OR(iexpr,iexpr) */
#line 229 "diy.brg"
{fprintf(outfp, pfOR);}
		break;
	case 89: /* iexpr: FACTORIAL(iexpr) */
#line 230 "diy.brg"
{/*fprintf(outfp)*/ /*FIXME*/}
		break;
	case 90: /* iexpr: NOT(iexpr) */
#line 231 "diy.brg"
{fprintf(outfp, pfIMM pfEQ, 0);}
		break;
	case 91: /* iexpr: UMINUS(iexpr) */
#line 232 "diy.brg"
{fprintf(outfp, pfNEG);}
		break;
	case 92: /* iexpr: INCR(ilval) */
#line 236 "diy.brg"
{fprintf(outfp, pfDUP pfINCR pfLOAD, 1);}
		break;
	case 93: /* iexpr: DECR(ilval) */
#line 237 "diy.brg"
{fprintf(outfp, pfDUP pfDECR pfLOAD, 1);}
		break;
	case 94: /* iexpr: POSINC(ilval) */
#line 238 "diy.brg"
{fprintf(outfp, pfDUP pfLOAD pfSWAP pfINCR, 1);}
		break;
	case 95: /* iexpr: POSDEC(ilval) */
#line 239 "diy.brg"
{fprintf(outfp, pfDUP pfLOAD pfSWAP pfDECR, 1);}
		break;
	case 96: /* iexpr: PTR(ilval) */
#line 242 "diy.brg"
{if (LEFT_CHILD(p)->place == 2) { fprintf(outfp, pfLDCHR);}
                        else {fprintf(outfp, pfLOAD);}}
		break;
	case 97: /* iexpr: PTR(slval) */
#line 245 "diy.brg"
{fprintf(outfp, pfLDCHR);}
		break;
	case 98: /* iexpr: CALL(ID,arguments) */
#line 248 "diy.brg"
{fprintf(outfp, pfCALL pfTRASH pfPUSH, mkfunc(LEFT_CHILD(p)->value.s), (int)((RIGHT_CHILD(p)->place)));
																					 p->place = IDfind(LEFT_CHILD(p)->value.s, NULL) == 3 ? 8: 4;}
		break;
	case 99: /* iexpr: CALL(ID,VOID) */
#line 251 "diy.brg"
{fprintf(outfp, pfCALL pfPUSH, mkfunc(LEFT_CHILD(p)->value.s));
																			p->place = IDfind(LEFT_CHILD(p)->value.s, NULL) == 3 ? 8: 4;}
		break;
	case 100: /* iexpr: LT(rexpr,rexpr) */
#line 257 "diy.brg"
{fprintf(outfp, pfDCMP pfIMM pfLT, 0);}
		break;
	case 101: /* iexpr: GT(rexpr,rexpr) */
#line 258 "diy.brg"
{fprintf(outfp, pfDCMP pfIMM pfGT, 0);}
		break;
	case 102: /* iexpr: GE(rexpr,rexpr) */
#line 259 "diy.brg"
{fprintf(outfp, pfDCMP pfIMM pfGE, 0);}
		break;
	case 103: /* iexpr: LE(rexpr,rexpr) */
#line 260 "diy.brg"
{fprintf(outfp, pfDCMP pfIMM pfLE, 0);}
		break;
	case 104: /* iexpr: LOGIC_EQUAL(rexpr,rexpr) */
#line 261 "diy.brg"
{fprintf(outfp, pfDCMP pfIMM pfEQ, 0);}
		break;
	case 105: /* iexpr: NE(rexpr,rexpr) */
#line 262 "diy.brg"
{fprintf(outfp, pfDCMP pfIMM pfNE, 0);}
		break;
	case 106: /* iptrexpr: REF(ilval) */
#line 273 "diy.brg"

		break;
	case 107: /* rexpr: ATR(rassign,rlval) */
#line 277 "diy.brg"
{fprintf(outfp, pfSTORE2);}
		break;
	case 108: /* rassign: rexpr */
#line 278 "diy.brg"
{fprintf(outfp, pfDUP2);}
		break;
	case 109: /* rexpr: REAL */
#line 279 "diy.brg"
{lbl++; fprintf(outfp, pfRODATA pfALIGN pfLABEL pfDOUBLE, mklbl(lbl), p->value.r);
					fprintf(outfp, pfTEXT pfADDR pfLOAD2, mklbl(lbl));}
		break;
	case 110: /* rexpr: ADD(rexpr,rexpr) */
#line 281 "diy.brg"
{fprintf(outfp, pfDADD);}
		break;
	case 111: /* rexpr: UMINUS(rexpr) */
#line 282 "diy.brg"
{fprintf(outfp, pfDNEG);}
		break;
	case 112: /* rexpr: SUB(rexpr,rexpr) */
#line 283 "diy.brg"
{fprintf(outfp, pfDSUB);}
		break;
	case 113: /* rexpr: MUL(rexpr,rexpr) */
#line 284 "diy.brg"
{fprintf(outfp, pfDMUL);}
		break;
	case 114: /* rexpr: DIV(rexpr,rexpr) */
#line 285 "diy.brg"
{fprintf(outfp, pfDDIV);}
		break;
	case 115: /* rexpr: iexpr */
#line 286 "diy.brg"
{fprintf(outfp, pfI2D);}
		break;
	case 116: /* rexpr: PTR(rlval) */
#line 289 "diy.brg"
{fprintf(outfp, pfLOAD2);}
		break;
	case 117: /* rexpr: CALL(ID,arguments) */
#line 292 "diy.brg"
{fprintf(outfp, pfCALL pfTRASH pfDPUSH, mkfunc(LEFT_CHILD(p)->value.s),
														 (int)((RIGHT_CHILD(p)->place))); p->place = IDfind(LEFT_CHILD(p)->value.s, NULL) == 3 ? 8 : 4;}
		break;
	case 118: /* rexpr: CALL(ID,VOID) */
#line 295 "diy.brg"
{fprintf(outfp, pfCALL pfDPUSH, mkfunc(LEFT_CHILD(p)->value.s));
									 p->place = IDfind(LEFT_CHILD(p)->value.s, NULL) == 3 ? 8: 4;}
		break;
	case 119: /* arguments: ARGS(NIL,expr) */
#line 299 "diy.brg"
{p->place = RIGHT_CHILD(p)->place; }
		break;
	case 120: /* arguments: ARGS(arguments,expr) */
#line 300 "diy.brg"
{p->place = LEFT_CHILD(p)->place + RIGHT_CHILD(p)->place;}
		break;
	case 121: /* iptrlval: LOCAL */
#line 304 "diy.brg"
{fprintf(outfp, pfLOCAL, p->value.i * (pfWORD/4));}
		break;
	case 122: /* iptrlval: ID */
#line 305 "diy.brg"
{fprintf(outfp, pfADDR, p->value.s);}
		break;
	case 123: /* iptrlvec: iptrlval */
#line 306 "diy.brg"
{fprintf(outfp, pfLOAD);}
		break;
	case 124: /* iptrexpr: REF(ilval) */
#line 307 "diy.brg"

		break;
	case 125: /* ilval: INDEX(iptrlvec,expr) */
#line 309 "diy.brg"
{ fprintf(outfp, pfIMM pfMUL pfADD, 4);}
		break;
	case 126: /* iptrexpr: PTR(iptrlval) */
#line 310 "diy.brg"
{fprintf(outfp, pfLOAD);}
		break;
	case 127: /* iexpr: PTR(iptrexpr) */
#line 311 "diy.brg"
{fprintf(outfp, pfLOAD);}
		break;
	case 128: /* iptrexpr: REF(ilval) */
#line 312 "diy.brg"
{/*generate no code*/}
		break;
	case 129: /* iptrassign: iptrexpr */
#line 313 "diy.brg"
{fprintf(outfp, pfDUP);}
		break;
	case 130: /* iptrexpr: ATR(iptrassign,iptrlval) */
#line 314 "diy.brg"
{fprintf(outfp, pfSTORE);}
		break;
	case 131: /* sptrlval: LOCAL */
#line 317 "diy.brg"
{fprintf(outfp, pfLOCAL, p->value.i * (pfWORD/4));}
		break;
	case 132: /* sptrlval: ID */
#line 318 "diy.brg"
{fprintf(outfp, pfADDR, p->value.s);}
		break;
	case 133: /* sptrlvec: sptrlval */
#line 319 "diy.brg"
{fprintf(outfp, pfLOAD);}
		break;
	case 134: /* sptrexpr: REF(slval) */
#line 320 "diy.brg"

		break;
	case 135: /* slval: INDEX(sptrlvec,expr) */
#line 322 "diy.brg"
{ fprintf(outfp, pfIMM pfMUL pfADD, 4);}
		break;
	case 136: /* sptrexpr: PTR(sptrlval) */
#line 324 "diy.brg"
{fprintf(outfp, pfLOAD);}
		break;
	case 137: /* sexpr: PTR(sptrexpr) */
#line 325 "diy.brg"
{fprintf(outfp, pfLOAD);}
		break;
	case 138: /* sptrexpr: REF(slval) */
#line 327 "diy.brg"
{/*generate no code*/}
		break;
	case 139: /* sptrassign: sptrexpr */
#line 328 "diy.brg"
{fprintf(outfp, pfDUP);}
		break;
	case 140: /* sptrexpr: ATR(sptrassign,sptrlval) */
#line 329 "diy.brg"
{fprintf(outfp, pfSTORE);}
		break;
	case 141: /* rptrlval: LOCAL */
#line 333 "diy.brg"
{fprintf(outfp, pfLOCAL, p->value.i * (pfWORD/4));}
		break;
	case 142: /* rptrlval: ID */
#line 334 "diy.brg"
{fprintf(outfp, pfADDR, p->value.s);}
		break;
	case 143: /* rptrlvec: rptrlval */
#line 335 "diy.brg"
{fprintf(outfp, pfLOAD);}
		break;
	case 144: /* rptrexpr: REF(rlval) */
#line 336 "diy.brg"

		break;
	case 145: /* rlval: INDEX(rptrlvec,expr) */
#line 338 "diy.brg"
{ fprintf(outfp, pfIMM pfMUL pfADD, 4);}
		break;
	case 146: /* rptrexpr: PTR(rptrlval) */
#line 340 "diy.brg"
{fprintf(outfp, pfLOAD);}
		break;
	case 147: /* rexpr: PTR(rptrexpr) */
#line 341 "diy.brg"
{fprintf(outfp, pfLOAD2);}
		break;
	case 148: /* rptrexpr: REF(rlval) */
#line 343 "diy.brg"
{/*generate no code*/}
		break;
	case 149: /* rptrassign: rptrexpr */
#line 344 "diy.brg"
{fprintf(outfp, pfDUP);}
		break;
	case 150: /* rptrexpr: ATR(rptrassign,rptrlval) */
#line 345 "diy.brg"
{fprintf(outfp, pfSTORE);}
		break;
	case 151: /* iptrcmp: iptrexpr */
#line 348 "diy.brg"
{fprintf(outfp, pfSTORE);}
		break;
	case 152: /* iexpr: LT(iptrcmp,iptrcmp) */
#line 349 "diy.brg"
{fprintf(outfp, pfLT);}
		break;
	case 153: /* iexpr: GT(iptrcmp,iptrcmp) */
#line 350 "diy.brg"
{fprintf(outfp, pfGT);}
		break;
	case 154: /* iexpr: GE(iptrcmp,iptrcmp) */
#line 351 "diy.brg"
{fprintf(outfp, pfGE);}
		break;
	case 155: /* iexpr: LE(iptrcmp,iptrcmp) */
#line 352 "diy.brg"
{fprintf(outfp, pfLE);}
		break;
	case 156: /* iexpr: LOGIC_EQUAL(iptrcmp,iptrcmp) */
#line 353 "diy.brg"
{fprintf(outfp, pfEQ);}
		break;
	case 157: /* iexpr: NE(iptrcmp,iptrcmp) */
#line 354 "diy.brg"
{fprintf(outfp, pfNE);}
		break;
	case 158: /* cond: LT(iexpr,iexpr) */
#line 359 "diy.brg"
{p->place = ++lbl; fprintf(outfp, pfJGE, mklbl(p->place));}
		break;
	case 159: /* cond: GT(iexpr,iexpr) */
#line 360 "diy.brg"
{p->place = ++lbl; fprintf(outfp, pfJLE, mklbl(p->place));}
		break;
	case 160: /* cond: LE(iexpr,iexpr) */
#line 361 "diy.brg"
{p->place = ++lbl; fprintf(outfp, pfJGT, mklbl(p->place));}
		break;
	case 161: /* cond: GE(iexpr,iexpr) */
#line 362 "diy.brg"
{p->place = ++lbl; fprintf(outfp, pfJLT, mklbl(p->place));}
		break;
	case 162: /* cond: LOGIC_EQUAL(iexpr,iexpr) */
#line 363 "diy.brg"
{p->place = ++lbl; fprintf(outfp, pfJNE, mklbl(p->place));}
		break;
	case 163: /* cond: NE(iexpr,iexpr) */
#line 364 "diy.brg"
{p->place = ++lbl; fprintf(outfp, pfJEQ, mklbl(p->place));}
		break;
	case 164: /* cond: LT(scmp,scmp) */
#line 366 "diy.brg"
{p->place = ++lbl; fprintf(outfp, pfJGE, mklbl(p->place));}
		break;
	case 165: /* cond: GT(scmp,scmp) */
#line 367 "diy.brg"
{p->place = ++lbl; fprintf(outfp, pfJLE, mklbl(p->place));}
		break;
	case 166: /* cond: LE(scmp,scmp) */
#line 368 "diy.brg"
{p->place = ++lbl; fprintf(outfp, pfJGT, mklbl(p->place));}
		break;
	case 167: /* cond: GE(scmp,scmp) */
#line 369 "diy.brg"
{p->place = ++lbl; fprintf(outfp, pfJLT, mklbl(p->place));}
		break;
	case 168: /* cond: LOGIC_EQUAL(scmp,scmp) */
#line 370 "diy.brg"
{p->place = ++lbl; fprintf(outfp, pfJNE, mklbl(p->place));}
		break;
	case 169: /* cond: NE(scmp,scmp) */
#line 371 "diy.brg"
{p->place = ++lbl; fprintf(outfp, pfJEQ, mklbl(p->place));}
		break;
	default: break;
  }
}

int yyselect(NODEPTR_TYPE p)
{
	yylabel(p,p);
	if (((struct yystate *)STATE_LABEL(p))->rule.yyfinit == 0) {
		fprintf(stderr, "No match for start symbol (%s).\n", yyntname[1]);
		return 1;
	}
	yyreduce(p, 1);
	return 0;
}


#line 373 "diy.brg"

#include "y.tab.h"
extern void yyerror(const char*);
extern char **yynames;
extern int trace;
extern int localCounter;

void externs()
{
  int i;

  for (i = 0; i < extcnt; i++)
    if (extrns[i])
      fprintf(outfp, pfEXTRN, extrns[i]);
}


void function(int pub, Node *type, char *name, Node *body)
{
	Node *bloco = LEFT_CHILD(body);
	IDpop();
	if (bloco != 0) { /* not a forward declaration */
		long par;
		int fwd = IDfind(name, &par);
		if (fwd > 40) yyerror("duplicate function");
		else {
			IDreplace(fwd+40, name, par);
			fflush(stdout);
  		fprintf(outfp, pfTEXT pfALIGN);
  		if(pub) {
  		 fprintf(outfp, pfGLOBL, mkfunc(name), pfFUNC); 
  		}
  		fprintf(outfp, pfLABEL pfENTER, mkfunc(name), - localPos * (pfWORD/4));
  		functionReturnType = type->value.i;
  		printNode(body, stdout, yynames);
  		yyselect(body);
  		fprintf(outfp, pfLEAVE pfRET); /* just in case ... */
			freeNode(body);
			for (int i = 0; i < extcnt; i++)
		    if (extrns[i] && strcmp(extrns[i], mkfunc(name)) == 0) extrns[i] = 0;
		}
	}
	else {
		char* buffer = (char*) malloc(sizeof(char) * 80);
		*buffer = '\0';
  		strcpy(buffer, "_");
  		strcat(buffer, name);
		extrns[extcnt++] = buffer;
	}
}


void declare(int pub, int cnst, Node *type, char *name, Node *value)
{
  int typ;
  if (!value) {
    if (!pub && cnst) yyerror("local constants must be initialised");

    return;
  }
  if (value->attrib = INT && value->value.i == 0 && type->value.i > 10)
  	return; /* NULL pointer */
  if ((typ = value->info) % 10 > 5) typ -= 5;

  printf("type of id: %d\n", typ);
  printf("my type: %d\n", type->value.i);

  if (type->value.i != typ)
    yyerror("wrong types in initialization");
}

void assign(int pub, int cnst, Node* type, char* name, Node* value) {
	if(pub && !value) {
		/*public variable not initialized must be extern*/
		fprintf(outfp, pfEXTRN, name);
		return;
	}
	if (pub) {
		fprintf(outfp, pfGLOBL, name, pfOBJ);
	}

	char* memseg = 0;

	if (value && cnst) {
	 memseg = pfRODATA;
	}

	else if (value && !cnst) {
		memseg = pfDATA;
	}
	if (memseg) {
		/*cnst must be RODATA*/
		fprintf(outfp, "%s", memseg);
		fprintf(outfp, pfALIGN);
		fprintf(outfp, pfLABEL, name);
		if (value->info == 1) {
			/*integer*/
			fprintf(outfp, pfINTEGER, value->value.i);
		}

		else if (value->info == 3) {
			/*double*/
			fprintf(outfp, pfDOUBLE, value->value.r);
		}
		else if (value->info == 2 || value->info == 7) {
			if(strcmp(memseg, pfRODATA) == 0) {
				outstr(value->value.s);
			}
			else {
			char *l = mklbl(++lbl);
			fprintf(outfp, pfRODATA pfALIGN pfLABEL, l);
			outstr(value->value.s);
			fprintf(outfp, "%s", memseg);
			fprintf(outfp, pfID, l);
			}
		}
		else if (value->info > 10) {
			/*value is an id*/
			fprintf(outfp, pfID, value->value.s);
		}

	}
	else {
		fprintf(outfp, pfBSS pfALIGN pfLABEL pfBYTE, name, type->value.i == 3 ? 8 : 4);

	}
}

