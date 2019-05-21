/*
generated at Tue May 21 10:59:47 2019
by $Id: pburg.c,v 2.5 2017/11/16 09:41:42 prs Exp $
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PBURG_PREFIX "yy"
#define PBURG_VERSION "2.5"
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



/*for cycles*/
typedef struct double_lbl {
	int b_lbl;
	int e_lbl;
	int br_lbl;
	int cnt_lbl;
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
int functionReturnType;
extern int placeofReturn;

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

static void mkdouble(double d) {
	lbl++; fprintf(outfp, pfRODATA pfALIGN pfLABEL pfDOUBLE, mklbl(lbl), d);
					fprintf(outfp, pfTEXT pfADDR pfLOAD2, mklbl(lbl));
}

static void mkint(int i) {
	lbl++; fprintf(outfp, pfRODATA pfALIGN pfLABEL pfINTEGER, mklbl(lbl), i);
					fprintf(outfp, pfTEXT pfADDR pfLOAD, mklbl(lbl));
}

static char *mkfunc(char *s) {
  static char buf[80];
  strcpy(buf, "_");
  strcat(buf, s);
  return buf;
}


/*all pointers are integers*/
int isInt(Node* p) {return ((p->info == 1) || (p->info == 6) || (p->info > 10 )) ? 1 : MAX_COST;}
int isReal(Node* p) {return((p->info == 3) || (p->info == 8)) ? 1 : MAX_COST;}
int isString(Node* p) {return ((p->info == 2) || (p->info == 7)) ? 1 : MAX_COST;}
int isVoid(Node* p) {return (p->info == 4) ? 1 : MAX_COST;}

int compareNodeLeft(Node* p) {return compareNode(LEFT_CHILD(LEFT_CHILD(LEFT_CHILD(p))), RIGHT_CHILD(p), 0) ? MAX_COST : 1;}
int compareNodeRight(Node* p) {return compareNode(LEFT_CHILD(RIGHT_CHILD(LEFT_CHILD(p))), RIGHT_CHILD(p), 0) ? MAX_COST : 1;}


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
#define yyifelse_NT 12
#define yycond2_NT 13
#define yywhile_NT 14
#define yydo_NT 15
#define yyexpr_NT 16
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
#define yyarguments_NT 27
#define yylvec_NT 28
#define yylval_NT 29
#define yyilval_NT 30
#define yyrlval_NT 31
#define yyslval_NT 32
#define yyiassign_NT 33
#define yycmp_NT 34
#define yysassign_NT 35
#define yyrassign_NT 36
#define yyand_NT 37
#define yyor_NT 38

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
	"ifelse",
	"cond2",
	"while",
	"do",
	"expr",
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
	"arguments",
	"lvec",
	"lval",
	"ilval",
	"rlval",
	"slval",
	"iassign",
	"cmp",
	"sassign",
	"rassign",
	"and",
	"or",
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
	short cost[39];
	struct {
		unsigned int yyfinit:2;
		unsigned int yybloco:2;
		unsigned int yyparams:2;
		unsigned int yyparam:1;
		unsigned int yylist:2;
		unsigned int yydecls:2;
		unsigned int yystmt:2;
		unsigned int yytipo:2;
		unsigned int yybase:5;
		unsigned int yyif:1;
		unsigned int yycond:3;
		unsigned int yyifelse:1;
		unsigned int yycond2:1;
		unsigned int yywhile:1;
		unsigned int yydo:1;
		unsigned int yyexpr:3;
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
		unsigned int yyarguments:2;
		unsigned int yylvec:1;
		unsigned int yylval:2;
		unsigned int yyilval:2;
		unsigned int yyrlval:2;
		unsigned int yyslval:2;
		unsigned int yyiassign:2;
		unsigned int yycmp:2;
		unsigned int yysassign:2;
		unsigned int yyrassign:1;
		unsigned int yyand:1;
		unsigned int yyor:1;
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
static short yynts_12[] = { yycond2_NT, yystmt_NT, 0 };
static short yynts_13[] = { yydo_NT, yyexpr_NT, 0 };
static short yynts_14[] = { yybegin_NT, yystmt_NT, 0 };
static short yynts_15[] = { yyexpr_NT, yyforbody_NT, 0 };
static short yynts_16[] = { yyforin_NT, yyforinstr_NT, 0 };
static short yynts_17[] = { yyforstmt_NT, yyexpr_NT, 0 };
static short yynts_18[] = { yystmt_NT, 0 };
static short yynts_19[] = { yyforstart_NT, yyexpr_NT, 0 };
static short yynts_20[] = { yyexpr_NT, 0 };
static short yynts_21[] = { yyif_NT, 0 };
static short yynts_22[] = { yyifelse_NT, 0 };
static short yynts_23[] = { yywhile_NT, 0 };
static short yynts_24[] = { yyfor_NT, 0 };
static short yynts_25[] = { yyiexpr_NT, 0 };
static short yynts_26[] = { yysexpr_NT, 0 };
static short yynts_27[] = { yyrexpr_NT, 0 };
static short yynts_28[] = { yyarguments_NT, 0 };
static short yynts_29[] = { yylval_NT, 0 };
static short yynts_30[] = { yyilval_NT, 0 };
static short yynts_31[] = { yyrlval_NT, 0 };
static short yynts_32[] = { yyslval_NT, 0 };
static short yynts_33[] = { yylvec_NT, yyexpr_NT, 0 };
static short yynts_34[] = { yyiassign_NT, yyilval_NT, 0 };
static short yynts_35[] = { yyiexpr_NT, yyiexpr_NT, 0 };
static short yynts_36[] = { yycmp_NT, yycmp_NT, 0 };
static short yynts_37[] = { yyrexpr_NT, yyrexpr_NT, 0 };
static short yynts_38[] = { yysassign_NT, yyslval_NT, 0 };
static short yynts_39[] = { yyrassign_NT, yyrlval_NT, 0 };
static short yynts_40[] = { yyexpr_NT, yyarguments_NT, 0 };
static short yynts_41[] = { yyand_NT, yyiexpr_NT, 0 };
static short yynts_42[] = { yyor_NT, yyiexpr_NT, 0 };

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
	yynts_11,	/* 17 */
	yynts_13,	/* 18 */
	yynts_14,	/* 19 */
	yynts_7,	/* 20 */
	yynts_15,	/* 21 */
	yynts_16,	/* 22 */
	yynts_17,	/* 23 */
	yynts_18,	/* 24 */
	yynts_19,	/* 25 */
	yynts_7,	/* 26 */
	yynts_9,	/* 27 */
	yynts_7,	/* 28 */
	yynts_7,	/* 29 */
	yynts_20,	/* 30 */
	yynts_21,	/* 31 */
	yynts_22,	/* 32 */
	yynts_23,	/* 33 */
	yynts_24,	/* 34 */
	yynts_1,	/* 35 */
	yynts_25,	/* 36 */
	yynts_26,	/* 37 */
	yynts_27,	/* 38 */
	yynts_28,	/* 39 */
	yynts_7,	/* 40 */
	yynts_29,	/* 41 */
	yynts_30,	/* 42 */
	yynts_31,	/* 43 */
	yynts_32,	/* 44 */
	yynts_7,	/* 45 */
	yynts_7,	/* 46 */
	yynts_33,	/* 47 */
	yynts_25,	/* 48 */
	yynts_27,	/* 49 */
	yynts_7,	/* 50 */
	yynts_34,	/* 51 */
	yynts_35,	/* 52 */
	yynts_35,	/* 53 */
	yynts_35,	/* 54 */
	yynts_35,	/* 55 */
	yynts_35,	/* 56 */
	yynts_25,	/* 57 */
	yynts_25,	/* 58 */
	yynts_25,	/* 59 */
	yynts_30,	/* 60 */
	yynts_30,	/* 61 */
	yynts_30,	/* 62 */
	yynts_30,	/* 63 */
	yynts_29,	/* 64 */
	yynts_30,	/* 65 */
	yynts_30,	/* 66 */
	yynts_32,	/* 67 */
	yynts_28,	/* 68 */
	yynts_7,	/* 69 */
	yynts_25,	/* 70 */
	yynts_26,	/* 71 */
	yynts_36,	/* 72 */
	yynts_36,	/* 73 */
	yynts_36,	/* 74 */
	yynts_36,	/* 75 */
	yynts_36,	/* 76 */
	yynts_36,	/* 77 */
	yynts_36,	/* 78 */
	yynts_36,	/* 79 */
	yynts_37,	/* 80 */
	yynts_37,	/* 81 */
	yynts_37,	/* 82 */
	yynts_37,	/* 83 */
	yynts_37,	/* 84 */
	yynts_37,	/* 85 */
	yynts_7,	/* 86 */
	yynts_7,	/* 87 */
	yynts_33,	/* 88 */
	yynts_7,	/* 89 */
	yynts_32,	/* 90 */
	yynts_30,	/* 91 */
	yynts_26,	/* 92 */
	yynts_25,	/* 93 */
	yynts_38,	/* 94 */
	yynts_28,	/* 95 */
	yynts_7,	/* 96 */
	yynts_31,	/* 97 */
	yynts_30,	/* 98 */
	yynts_7,	/* 99 */
	yynts_7,	/* 100 */
	yynts_33,	/* 101 */
	yynts_39,	/* 102 */
	yynts_27,	/* 103 */
	yynts_7,	/* 104 */
	yynts_37,	/* 105 */
	yynts_27,	/* 106 */
	yynts_37,	/* 107 */
	yynts_37,	/* 108 */
	yynts_37,	/* 109 */
	yynts_25,	/* 110 */
	yynts_28,	/* 111 */
	yynts_7,	/* 112 */
	yynts_20,	/* 113 */
	yynts_40,	/* 114 */
	yynts_41,	/* 115 */
	yynts_25,	/* 116 */
	yynts_42,	/* 117 */
	yynts_25,	/* 118 */
	yynts_36,	/* 119 */
	yynts_36,	/* 120 */
	yynts_36,	/* 121 */
	yynts_36,	/* 122 */
	yynts_36,	/* 123 */
	yynts_36,	/* 124 */
	yynts_20,	/* 125 */
	yynts_30,	/* 126 */
	yynts_30,	/* 127 */
	yynts_30,	/* 128 */
	yynts_30,	/* 129 */
	yynts_30,	/* 130 */
	yynts_30,	/* 131 */
	yynts_30,	/* 132 */
	yynts_30,	/* 133 */
	yynts_30,	/* 134 */
	yynts_30,	/* 135 */
	yynts_30,	/* 136 */
	yynts_30,	/* 137 */
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
/* 16 */	"ifelse: ELSE(cond2,stmt)",
/* 17 */	"cond2: IF(cond,stmt)",
/* 18 */	"while: WHILE(do,expr)",
/* 19 */	"do: DO(begin,stmt)",
/* 20 */	"begin: START",
/* 21 */	"for: INSTR(expr,forbody)",
/* 22 */	"forbody: FOR(forin,forinstr)",
/* 23 */	"forinstr: INSTR(forstmt,expr)",
/* 24 */	"forstmt: stmt",
/* 25 */	"forin: IN(forstart,expr)",
/* 26 */	"forstart: START",
/* 27 */	"stmt: base",
/* 28 */	"stmt: BREAK",
/* 29 */	"stmt: CONTINUE",
/* 30 */	"base: expr",
/* 31 */	"base: if",
/* 32 */	"base: ifelse",
/* 33 */	"base: while",
/* 34 */	"base: for",
/* 35 */	"base: bloco",
/* 36 */	"expr: iexpr",
/* 37 */	"expr: sexpr",
/* 38 */	"expr: rexpr",
/* 39 */	"expr: CALL(ID,arguments)",
/* 40 */	"expr: CALL(ID,VOID)",
/* 41 */	"lvec: lval",
/* 42 */	"lval: ilval",
/* 43 */	"lval: rlval",
/* 44 */	"lval: slval",
/* 45 */	"ilval: LOCAL",
/* 46 */	"ilval: ID",
/* 47 */	"ilval: INDEX(lvec,expr)",
/* 48 */	"iassign: iexpr",
/* 49 */	"iassign: rexpr",
/* 50 */	"iexpr: INT",
/* 51 */	"iexpr: ATR(iassign,ilval)",
/* 52 */	"iexpr: ADD(iexpr,iexpr)",
/* 53 */	"iexpr: SUB(iexpr,iexpr)",
/* 54 */	"iexpr: DIV(iexpr,iexpr)",
/* 55 */	"iexpr: MOD(iexpr,iexpr)",
/* 56 */	"iexpr: MUL(iexpr,iexpr)",
/* 57 */	"rexpr: FACTORIAL(iexpr)",
/* 58 */	"iexpr: NOT(iexpr)",
/* 59 */	"iexpr: UMINUS(iexpr)",
/* 60 */	"iexpr: INCR(ilval)",
/* 61 */	"iexpr: DECR(ilval)",
/* 62 */	"iexpr: POSINC(ilval)",
/* 63 */	"iexpr: POSDEC(ilval)",
/* 64 */	"iexpr: REF(lval)",
/* 65 */	"iexpr: PTR(ilval)",
/* 66 */	"iexpr: PTR(PTR(ilval))",
/* 67 */	"iexpr: PTR(PTR(slval))",
/* 68 */	"iexpr: CALL(ID,arguments)",
/* 69 */	"iexpr: CALL(ID,VOID)",
/* 70 */	"cmp: iexpr",
/* 71 */	"cmp: sexpr",
/* 72 */	"iexpr: LT(cmp,cmp)",
/* 73 */	"iexpr: GT(cmp,cmp)",
/* 74 */	"iexpr: GE(cmp,cmp)",
/* 75 */	"iexpr: LE(cmp,cmp)",
/* 76 */	"iexpr: NE(cmp,cmp)",
/* 77 */	"iexpr: LOGIC_EQUAL(cmp,cmp)",
/* 78 */	"iexpr: AND(cmp,cmp)",
/* 79 */	"iexpr: OR(cmp,cmp)",
/* 80 */	"iexpr: LT(rexpr,rexpr)",
/* 81 */	"iexpr: GT(rexpr,rexpr)",
/* 82 */	"iexpr: GE(rexpr,rexpr)",
/* 83 */	"iexpr: LE(rexpr,rexpr)",
/* 84 */	"iexpr: LOGIC_EQUAL(rexpr,rexpr)",
/* 85 */	"iexpr: NE(rexpr,rexpr)",
/* 86 */	"slval: LOCAL",
/* 87 */	"slval: ID",
/* 88 */	"slval: INDEX(lvec,expr)",
/* 89 */	"sexpr: STR",
/* 90 */	"sexpr: PTR(slval)",
/* 91 */	"sexpr: PTR(PTR(ilval))",
/* 92 */	"sassign: sexpr",
/* 93 */	"sassign: iexpr",
/* 94 */	"sexpr: ATR(sassign,slval)",
/* 95 */	"sexpr: CALL(ID,arguments)",
/* 96 */	"sexpr: CALL(ID,VOID)",
/* 97 */	"rexpr: PTR(rlval)",
/* 98 */	"rexpr: PTR(PTR(ilval))",
/* 99 */	"rlval: LOCAL",
/* 100 */	"rlval: ID",
/* 101 */	"rlval: INDEX(lvec,expr)",
/* 102 */	"rexpr: ATR(rassign,rlval)",
/* 103 */	"rassign: rexpr",
/* 104 */	"rexpr: REAL",
/* 105 */	"rexpr: ADD(rexpr,rexpr)",
/* 106 */	"rexpr: UMINUS(rexpr)",
/* 107 */	"rexpr: SUB(rexpr,rexpr)",
/* 108 */	"rexpr: MUL(rexpr,rexpr)",
/* 109 */	"rexpr: DIV(rexpr,rexpr)",
/* 110 */	"rexpr: iexpr",
/* 111 */	"rexpr: CALL(ID,arguments)",
/* 112 */	"rexpr: CALL(ID,VOID)",
/* 113 */	"arguments: ARGS(expr,NIL)",
/* 114 */	"arguments: ARGS(expr,arguments)",
/* 115 */	"expr: AND(and,iexpr)",
/* 116 */	"and: iexpr",
/* 117 */	"expr: OR(or,iexpr)",
/* 118 */	"or: iexpr",
/* 119 */	"cond: LT(cmp,cmp)",
/* 120 */	"cond: GT(cmp,cmp)",
/* 121 */	"cond: LE(cmp,cmp)",
/* 122 */	"cond: GE(cmp,cmp)",
/* 123 */	"cond: LOGIC_EQUAL(cmp,cmp)",
/* 124 */	"cond: NE(cmp,cmp)",
/* 125 */	"cond: expr",
/* 126 */	"base: ATR(ADD(PTR(ilval),INT),LOCAL)",
/* 127 */	"base: ATR(SUB(PTR(ilval),INT),LOCAL)",
/* 128 */	"base: ATR(ADD(INT,PTR(ilval)),LOCAL)",
/* 129 */	"base: ATR(ADD(PTR(ilval),INT),ID)",
/* 130 */	"base: ATR(SUB(PTR(ilval),INT),ID)",
/* 131 */	"base: ATR(ADD(INT,PTR(ilval)),ID)",
/* 132 */	"base: ATR(ADD(PTR(ilval),INT),INDEX(LOCAL,INT))",
/* 133 */	"base: ATR(SUB(PTR(ilval),INT),INDEX(LOCAL,INT))",
/* 134 */	"base: ATR(ADD(INT,PTR(ilval)),INDEX(LOCAL,INT))",
/* 135 */	"base: ATR(ADD(PTR(ilval),INT),INDEX(ID,INT))",
/* 136 */	"base: ATR(SUB(PTR(ilval),INT),INDEX(ID,INT))",
/* 137 */	"base: ATR(ADD(INT,PTR(ilval)),INDEX(ID,INT))",
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
	27,
	28,
	29,
};

static short yydecode_tipo[] = {
	0,
	10,
	11,
	12,
};

static short yydecode_base[] = {
	0,
	30,
	31,
	32,
	33,
	34,
	35,
	126,
	127,
	128,
	129,
	130,
	131,
	132,
	133,
	134,
	135,
	136,
	137,
};

static short yydecode_if[] = {
	0,
	15,
};

static short yydecode_cond[] = {
	0,
	119,
	120,
	121,
	122,
	123,
	124,
	125,
};

static short yydecode_ifelse[] = {
	0,
	16,
};

static short yydecode_cond2[] = {
	0,
	17,
};

static short yydecode_while[] = {
	0,
	18,
};

static short yydecode_do[] = {
	0,
	19,
};

static short yydecode_expr[] = {
	0,
	36,
	37,
	38,
	39,
	40,
	115,
	117,
};

static short yydecode_begin[] = {
	0,
	20,
};

static short yydecode_for[] = {
	0,
	21,
};

static short yydecode_forbody[] = {
	0,
	22,
};

static short yydecode_forin[] = {
	0,
	25,
};

static short yydecode_forinstr[] = {
	0,
	23,
};

static short yydecode_forstmt[] = {
	0,
	24,
};

static short yydecode_forstart[] = {
	0,
	26,
};

static short yydecode_iexpr[] = {
	0,
	50,
	51,
	52,
	53,
	54,
	55,
	56,
	58,
	59,
	60,
	61,
	62,
	63,
	64,
	65,
	66,
	67,
	68,
	69,
	72,
	73,
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
};

static short yydecode_sexpr[] = {
	0,
	89,
	90,
	91,
	94,
	95,
	96,
};

static short yydecode_rexpr[] = {
	0,
	57,
	97,
	98,
	102,
	104,
	105,
	106,
	107,
	108,
	109,
	110,
	111,
	112,
};

static short yydecode_arguments[] = {
	0,
	113,
	114,
};

static short yydecode_lvec[] = {
	0,
	41,
};

static short yydecode_lval[] = {
	0,
	42,
	43,
	44,
};

static short yydecode_ilval[] = {
	0,
	45,
	46,
	47,
};

static short yydecode_rlval[] = {
	0,
	99,
	100,
	101,
};

static short yydecode_slval[] = {
	0,
	86,
	87,
	88,
};

static short yydecode_iassign[] = {
	0,
	48,
	49,
};

static short yydecode_cmp[] = {
	0,
	70,
	71,
};

static short yydecode_sassign[] = {
	0,
	92,
	93,
};

static short yydecode_rassign[] = {
	0,
	103,
};

static short yydecode_and[] = {
	0,
	116,
};

static short yydecode_or[] = {
	0,
	118,
};

static int yyrule(void *state, int goalnt) {
	if (goalnt < 1 || goalnt > 38)
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
	case yyifelse_NT:	return yydecode_ifelse[((struct yystate *)state)->rule.yyifelse];
	case yycond2_NT:	return yydecode_cond2[((struct yystate *)state)->rule.yycond2];
	case yywhile_NT:	return yydecode_while[((struct yystate *)state)->rule.yywhile];
	case yydo_NT:	return yydecode_do[((struct yystate *)state)->rule.yydo];
	case yyexpr_NT:	return yydecode_expr[((struct yystate *)state)->rule.yyexpr];
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
	case yyarguments_NT:	return yydecode_arguments[((struct yystate *)state)->rule.yyarguments];
	case yylvec_NT:	return yydecode_lvec[((struct yystate *)state)->rule.yylvec];
	case yylval_NT:	return yydecode_lval[((struct yystate *)state)->rule.yylval];
	case yyilval_NT:	return yydecode_ilval[((struct yystate *)state)->rule.yyilval];
	case yyrlval_NT:	return yydecode_rlval[((struct yystate *)state)->rule.yyrlval];
	case yyslval_NT:	return yydecode_slval[((struct yystate *)state)->rule.yyslval];
	case yyiassign_NT:	return yydecode_iassign[((struct yystate *)state)->rule.yyiassign];
	case yycmp_NT:	return yydecode_cmp[((struct yystate *)state)->rule.yycmp];
	case yysassign_NT:	return yydecode_sassign[((struct yystate *)state)->rule.yysassign];
	case yyrassign_NT:	return yydecode_rassign[((struct yystate *)state)->rule.yyrassign];
	case yyand_NT:	return yydecode_and[((struct yystate *)state)->rule.yyand];
	case yyor_NT:	return yydecode_or[((struct yystate *)state)->rule.yyor];
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
static void yyclosure_ifelse(NODEPTR_TYPE, int);
static void yyclosure_while(NODEPTR_TYPE, int);
static void yyclosure_expr(NODEPTR_TYPE, int);
static void yyclosure_for(NODEPTR_TYPE, int);
static void yyclosure_iexpr(NODEPTR_TYPE, int);
static void yyclosure_sexpr(NODEPTR_TYPE, int);
static void yyclosure_rexpr(NODEPTR_TYPE, int);
static void yyclosure_lval(NODEPTR_TYPE, int);
static void yyclosure_ilval(NODEPTR_TYPE, int);
static void yyclosure_rlval(NODEPTR_TYPE, int);
static void yyclosure_slval(NODEPTR_TYPE, int);

static void yyclosure_bloco(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 35, c + 0, p->cost[yybase_NT]);
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
	yytrace(a, 24, c + 1, p->cost[yyforstmt_NT]);
	if (c + 1 < p->cost[yyforstmt_NT]) {
		p->cost[yyforstmt_NT] = c + 1;
		p->rule.yyforstmt = 1;
	}
}

static void yyclosure_base(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 27, c + 0, p->cost[yystmt_NT]);
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
	yytrace(a, 31, c + 0, p->cost[yybase_NT]);
	if (c + 0 < p->cost[yybase_NT]) {
		p->cost[yybase_NT] = c + 0;
		p->rule.yybase = 2;
		yyclosure_base(a, c + 0);
	}
}

static void yyclosure_ifelse(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 32, c + 0, p->cost[yybase_NT]);
	if (c + 0 < p->cost[yybase_NT]) {
		p->cost[yybase_NT] = c + 0;
		p->rule.yybase = 3;
		yyclosure_base(a, c + 0);
	}
}

static void yyclosure_while(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 33, c + 0, p->cost[yybase_NT]);
	if (c + 0 < p->cost[yybase_NT]) {
		p->cost[yybase_NT] = c + 0;
		p->rule.yybase = 4;
		yyclosure_base(a, c + 0);
	}
}

static void yyclosure_expr(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 125, c + 1, p->cost[yycond_NT]);
	if (c + 1 < p->cost[yycond_NT]) {
		p->cost[yycond_NT] = c + 1;
		p->rule.yycond = 7;
	}
	yytrace(a, 30, c + 1, p->cost[yybase_NT]);
	if (c + 1 < p->cost[yybase_NT]) {
		p->cost[yybase_NT] = c + 1;
		p->rule.yybase = 1;
		yyclosure_base(a, c + 1);
	}
}

static void yyclosure_for(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 34, c + 0, p->cost[yybase_NT]);
	if (c + 0 < p->cost[yybase_NT]) {
		p->cost[yybase_NT] = c + 0;
		p->rule.yybase = 5;
		yyclosure_base(a, c + 0);
	}
}

static void yyclosure_iexpr(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 118, c + 1, p->cost[yyor_NT]);
	if (c + 1 < p->cost[yyor_NT]) {
		p->cost[yyor_NT] = c + 1;
		p->rule.yyor = 1;
	}
	yytrace(a, 116, c + 1, p->cost[yyand_NT]);
	if (c + 1 < p->cost[yyand_NT]) {
		p->cost[yyand_NT] = c + 1;
		p->rule.yyand = 1;
	}
	yytrace(a, 110, c + 1, p->cost[yyrexpr_NT]);
	if (c + 1 < p->cost[yyrexpr_NT]) {
		p->cost[yyrexpr_NT] = c + 1;
		p->rule.yyrexpr = 11;
		yyclosure_rexpr(a, c + 1);
	}
	yytrace(a, 93, c + 1, p->cost[yysassign_NT]);
	if (c + 1 < p->cost[yysassign_NT]) {
		p->cost[yysassign_NT] = c + 1;
		p->rule.yysassign = 2;
	}
	yytrace(a, 70, c + 1, p->cost[yycmp_NT]);
	if (c + 1 < p->cost[yycmp_NT]) {
		p->cost[yycmp_NT] = c + 1;
		p->rule.yycmp = 1;
	}
	yytrace(a, 48, c + 1, p->cost[yyiassign_NT]);
	if (c + 1 < p->cost[yyiassign_NT]) {
		p->cost[yyiassign_NT] = c + 1;
		p->rule.yyiassign = 1;
	}
	yytrace(a, 36, c + 0, p->cost[yyexpr_NT]);
	if (c + 0 < p->cost[yyexpr_NT]) {
		p->cost[yyexpr_NT] = c + 0;
		p->rule.yyexpr = 1;
		yyclosure_expr(a, c + 0);
	}
}

static void yyclosure_sexpr(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 92, c + 1, p->cost[yysassign_NT]);
	if (c + 1 < p->cost[yysassign_NT]) {
		p->cost[yysassign_NT] = c + 1;
		p->rule.yysassign = 1;
	}
	yytrace(a, 71, c + 1, p->cost[yycmp_NT]);
	if (c + 1 < p->cost[yycmp_NT]) {
		p->cost[yycmp_NT] = c + 1;
		p->rule.yycmp = 2;
	}
	yytrace(a, 37, c + 0, p->cost[yyexpr_NT]);
	if (c + 0 < p->cost[yyexpr_NT]) {
		p->cost[yyexpr_NT] = c + 0;
		p->rule.yyexpr = 2;
		yyclosure_expr(a, c + 0);
	}
}

static void yyclosure_rexpr(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 103, c + 1, p->cost[yyrassign_NT]);
	if (c + 1 < p->cost[yyrassign_NT]) {
		p->cost[yyrassign_NT] = c + 1;
		p->rule.yyrassign = 1;
	}
	yytrace(a, 49, c + 1, p->cost[yyiassign_NT]);
	if (c + 1 < p->cost[yyiassign_NT]) {
		p->cost[yyiassign_NT] = c + 1;
		p->rule.yyiassign = 2;
	}
	yytrace(a, 38, c + 0, p->cost[yyexpr_NT]);
	if (c + 0 < p->cost[yyexpr_NT]) {
		p->cost[yyexpr_NT] = c + 0;
		p->rule.yyexpr = 3;
		yyclosure_expr(a, c + 0);
	}
}

static void yyclosure_lval(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 41, c + 1, p->cost[yylvec_NT]);
	if (c + 1 < p->cost[yylvec_NT]) {
		p->cost[yylvec_NT] = c + 1;
		p->rule.yylvec = 1;
	}
}

static void yyclosure_ilval(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 42, c + 0, p->cost[yylval_NT]);
	if (c + 0 < p->cost[yylval_NT]) {
		p->cost[yylval_NT] = c + 0;
		p->rule.yylval = 1;
		yyclosure_lval(a, c + 0);
	}
}

static void yyclosure_rlval(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 43, c + 0, p->cost[yylval_NT]);
	if (c + 0 < p->cost[yylval_NT]) {
		p->cost[yylval_NT] = c + 0;
		p->rule.yylval = 2;
		yyclosure_lval(a, c + 0);
	}
}

static void yyclosure_slval(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 44, c + 0, p->cost[yylval_NT]);
	if (c + 0 < p->cost[yylval_NT]) {
		p->cost[yylval_NT] = c + 0;
		p->rule.yylval = 3;
		yyclosure_lval(a, c + 0);
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
		0x7fff;
	switch (OP_LABEL(a)) {
	case 33: /* FACTORIAL */
		yylabel(LEFT_CHILD(a),a);
		/* rexpr: FACTORIAL(iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 57, c + 0, p->cost[yyrexpr_NT]);
		if (c + 0 < p->cost[yyrexpr_NT]) {
			p->cost[yyrexpr_NT] = c + 0;
			p->rule.yyrexpr = 1;
			yyclosure_rexpr(a, c + 0);
		}
		break;
	case 37: /* MOD */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: MOD(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 55, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 6;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 38: /* AND */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: AND(cmp,cmp) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yycmp_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yycmp_NT] + 1;
		yytrace(a, 78, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 26;
			yyclosure_iexpr(a, c + 0);
		}
		/* expr: AND(and,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyand_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 115, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 6;
			yyclosure_expr(a, c + 0);
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
		yytrace(a, 56, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 7;
			yyclosure_iexpr(a, c + 0);
		}
		/* rexpr: MUL(rexpr,rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 108, c + 0, p->cost[yyrexpr_NT]);
		if (c + 0 < p->cost[yyrexpr_NT]) {
			p->cost[yyrexpr_NT] = c + 0;
			p->rule.yyrexpr = 9;
			yyclosure_rexpr(a, c + 0);
		}
		break;
	case 43: /* ADD */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: ADD(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 52, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 3;
			yyclosure_iexpr(a, c + 0);
		}
		/* rexpr: ADD(rexpr,rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 105, c + 0, p->cost[yyrexpr_NT]);
		if (c + 0 < p->cost[yyrexpr_NT]) {
			p->cost[yyrexpr_NT] = c + 0;
			p->rule.yyrexpr = 6;
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
		yytrace(a, 53, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 4;
			yyclosure_iexpr(a, c + 0);
		}
		/* rexpr: SUB(rexpr,rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 107, c + 0, p->cost[yyrexpr_NT]);
		if (c + 0 < p->cost[yyrexpr_NT]) {
			p->cost[yyrexpr_NT] = c + 0;
			p->rule.yyrexpr = 8;
			yyclosure_rexpr(a, c + 0);
		}
		break;
	case 47: /* DIV */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: DIV(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 54, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 5;
			yyclosure_iexpr(a, c + 0);
		}
		/* rexpr: DIV(rexpr,rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 109, c + 0, p->cost[yyrexpr_NT]);
		if (c + 0 < p->cost[yyrexpr_NT]) {
			p->cost[yyrexpr_NT] = c + 0;
			p->rule.yyrexpr = 10;
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
		yytrace(a, 21, c + 0, p->cost[yyfor_NT]);
		if (c + 0 < p->cost[yyfor_NT]) {
			p->cost[yyfor_NT] = c + 0;
			p->rule.yyfor = 1;
			yyclosure_for(a, c + 0);
		}
		/* forinstr: INSTR(forstmt,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyforstmt_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 23, c + 0, p->cost[yyforinstr_NT]);
		if (c + 0 < p->cost[yyforinstr_NT]) {
			p->cost[yyforinstr_NT] = c + 0;
			p->rule.yyforinstr = 1;
		}
		break;
	case 60: /* LT */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: LT(cmp,cmp) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yycmp_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yycmp_NT] + 1;
		yytrace(a, 72, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 20;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: LT(rexpr,rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 80, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 28;
			yyclosure_iexpr(a, c + 0);
		}
		/* cond: LT(cmp,cmp) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yycmp_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yycmp_NT] + 1;
		yytrace(a, 119, c + 0, p->cost[yycond_NT]);
		if (c + 0 < p->cost[yycond_NT]) {
			p->cost[yycond_NT] = c + 0;
			p->rule.yycond = 1;
		}
		break;
	case 61: /* LOGIC_EQUAL */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: LOGIC_EQUAL(cmp,cmp) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yycmp_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yycmp_NT] + 1;
		yytrace(a, 77, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 25;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: LOGIC_EQUAL(rexpr,rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 84, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 32;
			yyclosure_iexpr(a, c + 0);
		}
		/* cond: LOGIC_EQUAL(cmp,cmp) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yycmp_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yycmp_NT] + 1;
		yytrace(a, 123, c + 0, p->cost[yycond_NT]);
		if (c + 0 < p->cost[yycond_NT]) {
			p->cost[yycond_NT] = c + 0;
			p->rule.yycond = 5;
		}
		break;
	case 62: /* GT */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: GT(cmp,cmp) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yycmp_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yycmp_NT] + 1;
		yytrace(a, 73, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 21;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: GT(rexpr,rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 81, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 29;
			yyclosure_iexpr(a, c + 0);
		}
		/* cond: GT(cmp,cmp) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yycmp_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yycmp_NT] + 1;
		yytrace(a, 120, c + 0, p->cost[yycond_NT]);
		if (c + 0 < p->cost[yycond_NT]) {
			p->cost[yycond_NT] = c + 0;
			p->rule.yycond = 2;
		}
		break;
	case 91: /* INDEX */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* ilval: INDEX(lvec,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylvec_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + (isInt(a));
		yytrace(a, 47, c + 0, p->cost[yyilval_NT]);
		if (c + 0 < p->cost[yyilval_NT]) {
			p->cost[yyilval_NT] = c + 0;
			p->rule.yyilval = 3;
			yyclosure_ilval(a, c + 0);
		}
		/* slval: INDEX(lvec,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylvec_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + (isString(a));
		yytrace(a, 88, c + 0, p->cost[yyslval_NT]);
		if (c + 0 < p->cost[yyslval_NT]) {
			p->cost[yyslval_NT] = c + 0;
			p->rule.yyslval = 3;
			yyclosure_slval(a, c + 0);
		}
		/* rlval: INDEX(lvec,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylvec_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + (isReal(a));
		yytrace(a, 101, c + 0, p->cost[yyrlval_NT]);
		if (c + 0 < p->cost[yyrlval_NT]) {
			p->cost[yyrlval_NT] = c + 0;
			p->rule.yyrlval = 3;
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
		/* iexpr: OR(cmp,cmp) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yycmp_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yycmp_NT] + 1;
		yytrace(a, 79, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 27;
			yyclosure_iexpr(a, c + 0);
		}
		/* expr: OR(or,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyor_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 117, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 7;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 126: /* LOGIC_NOT */
		return;
	case 257: /* INT */
		/* iexpr: INT */
		yytrace(a, 50, 1 + 0, p->cost[yyiexpr_NT]);
		if (1 + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = 1 + 0;
			p->rule.yyiexpr = 1;
			yyclosure_iexpr(a, 1 + 0);
		}
		break;
	case 258: /* REAL */
		/* rexpr: REAL */
		yytrace(a, 104, 1 + 0, p->cost[yyrexpr_NT]);
		if (1 + 0 < p->cost[yyrexpr_NT]) {
			p->cost[yyrexpr_NT] = 1 + 0;
			p->rule.yyrexpr = 5;
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
			yyclosure_ilval(a, c + 0);
		}
		/* slval: ID */
		c = (isString(a));
		yytrace(a, 87, c + 0, p->cost[yyslval_NT]);
		if (c + 0 < p->cost[yyslval_NT]) {
			p->cost[yyslval_NT] = c + 0;
			p->rule.yyslval = 2;
			yyclosure_slval(a, c + 0);
		}
		/* rlval: ID */
		c = (isReal(a));
		yytrace(a, 100, c + 0, p->cost[yyrlval_NT]);
		if (c + 0 < p->cost[yyrlval_NT]) {
			p->cost[yyrlval_NT] = c + 0;
			p->rule.yyrlval = 2;
			yyclosure_rlval(a, c + 0);
		}
		break;
	case 260: /* STR */
		/* sexpr: STR */
		yytrace(a, 89, 1 + 0, p->cost[yysexpr_NT]);
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
		yytrace(a, 19, c + 0, p->cost[yydo_NT]);
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
		yytrace(a, 18, c + 0, p->cost[yywhile_NT]);
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
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yycond_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yystmt_NT] + 1;
		yytrace(a, 15, c + 0, p->cost[yyif_NT]);
		if (c + 0 < p->cost[yyif_NT]) {
			p->cost[yyif_NT] = c + 0;
			p->rule.yyif = 1;
			yyclosure_if(a, c + 0);
		}
		/* cond2: IF(cond,stmt) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yycond_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yystmt_NT] + 1;
		yytrace(a, 17, c + 0, p->cost[yycond2_NT]);
		if (c + 0 < p->cost[yycond2_NT]) {
			p->cost[yycond2_NT] = c + 0;
			p->rule.yycond2 = 1;
		}
		break;
	case 264: /* THEN */
		return;
	case 265: /* FOR */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* forbody: FOR(forin,forinstr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyforin_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyforinstr_NT] + 1;
		yytrace(a, 22, c + 0, p->cost[yyforbody_NT]);
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
		yytrace(a, 25, c + 0, p->cost[yyforin_NT]);
		if (c + 0 < p->cost[yyforin_NT]) {
			p->cost[yyforin_NT] = c + 0;
			p->rule.yyforin = 1;
		}
		break;
	case 267: /* UPTO */
		return;
	case 268: /* DOWNTO */
		return;
	case 269: /* STEP */
		return;
	case 270: /* BREAK */
		/* stmt: BREAK */
		yytrace(a, 28, 1 + 0, p->cost[yystmt_NT]);
		if (1 + 0 < p->cost[yystmt_NT]) {
			p->cost[yystmt_NT] = 1 + 0;
			p->rule.yystmt = 2;
			yyclosure_stmt(a, 1 + 0);
		}
		break;
	case 271: /* CONTINUE */
		/* stmt: CONTINUE */
		yytrace(a, 29, 1 + 0, p->cost[yystmt_NT]);
		if (1 + 0 < p->cost[yystmt_NT]) {
			p->cost[yystmt_NT] = 1 + 0;
			p->rule.yystmt = 3;
			yyclosure_stmt(a, 1 + 0);
		}
		break;
	case 272: /* VOID */
		return;
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
		return;
	case 277: /* PUBLIC */
		return;
	case 278: /* INCR */
		yylabel(LEFT_CHILD(a),a);
		/* iexpr: INCR(ilval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyilval_NT] + 1;
		yytrace(a, 60, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 10;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 279: /* DECR */
		yylabel(LEFT_CHILD(a),a);
		/* iexpr: DECR(ilval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyilval_NT] + 1;
		yytrace(a, 61, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 11;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 280: /* IFX */
		return;
	case 281: /* ELSE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* ifelse: ELSE(cond2,stmt) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yycond2_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yystmt_NT] + 1;
		yytrace(a, 16, c + 0, p->cost[yyifelse_NT]);
		if (c + 0 < p->cost[yyifelse_NT]) {
			p->cost[yyifelse_NT] = c + 0;
			p->rule.yyifelse = 1;
			yyclosure_ifelse(a, c + 0);
		}
		break;
	case 282: /* ATR */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: ATR(iassign,ilval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiassign_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyilval_NT] + 1;
		yytrace(a, 51, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 2;
			yyclosure_iexpr(a, c + 0);
		}
		/* sexpr: ATR(sassign,slval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yysassign_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyslval_NT] + 1;
		yytrace(a, 94, c + 0, p->cost[yysexpr_NT]);
		if (c + 0 < p->cost[yysexpr_NT]) {
			p->cost[yysexpr_NT] = c + 0;
			p->rule.yysexpr = 4;
			yyclosure_sexpr(a, c + 0);
		}
		/* rexpr: ATR(rassign,rlval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrassign_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrlval_NT] + 1;
		yytrace(a, 102, c + 0, p->cost[yyrexpr_NT]);
		if (c + 0 < p->cost[yyrexpr_NT]) {
			p->cost[yyrexpr_NT] = c + 0;
			p->rule.yyrexpr = 4;
			yyclosure_rexpr(a, c + 0);
		}
		if (	/* base: ATR(ADD(PTR(ilval),INT),LOCAL) */
			OP_LABEL(LEFT_CHILD(a)) == 43 && /* ADD */
			OP_LABEL(LEFT_CHILD(LEFT_CHILD(a))) == 292 && /* PTR */
			OP_LABEL(RIGHT_CHILD(LEFT_CHILD(a))) == 257 && /* INT */
			OP_LABEL(RIGHT_CHILD(a)) == 289 /* LOCAL */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(LEFT_CHILD(a)))))->cost[yyilval_NT] + (compareNodeLeft(a));
			yytrace(a, 126, c + 0, p->cost[yybase_NT]);
			if (c + 0 < p->cost[yybase_NT]) {
				p->cost[yybase_NT] = c + 0;
				p->rule.yybase = 7;
				yyclosure_base(a, c + 0);
			}
		}
		if (	/* base: ATR(SUB(PTR(ilval),INT),LOCAL) */
			OP_LABEL(LEFT_CHILD(a)) == 45 && /* SUB */
			OP_LABEL(LEFT_CHILD(LEFT_CHILD(a))) == 292 && /* PTR */
			OP_LABEL(RIGHT_CHILD(LEFT_CHILD(a))) == 257 && /* INT */
			OP_LABEL(RIGHT_CHILD(a)) == 289 /* LOCAL */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(LEFT_CHILD(a)))))->cost[yyilval_NT] + (compareNodeLeft(a));
			yytrace(a, 127, c + 0, p->cost[yybase_NT]);
			if (c + 0 < p->cost[yybase_NT]) {
				p->cost[yybase_NT] = c + 0;
				p->rule.yybase = 8;
				yyclosure_base(a, c + 0);
			}
		}
		if (	/* base: ATR(ADD(INT,PTR(ilval)),LOCAL) */
			OP_LABEL(LEFT_CHILD(a)) == 43 && /* ADD */
			OP_LABEL(LEFT_CHILD(LEFT_CHILD(a))) == 257 && /* INT */
			OP_LABEL(RIGHT_CHILD(LEFT_CHILD(a))) == 292 && /* PTR */
			OP_LABEL(RIGHT_CHILD(a)) == 289 /* LOCAL */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(RIGHT_CHILD(LEFT_CHILD(a)))))->cost[yyilval_NT] + (compareNodeRight(a));
			yytrace(a, 128, c + 0, p->cost[yybase_NT]);
			if (c + 0 < p->cost[yybase_NT]) {
				p->cost[yybase_NT] = c + 0;
				p->rule.yybase = 9;
				yyclosure_base(a, c + 0);
			}
		}
		if (	/* base: ATR(ADD(PTR(ilval),INT),ID) */
			OP_LABEL(LEFT_CHILD(a)) == 43 && /* ADD */
			OP_LABEL(LEFT_CHILD(LEFT_CHILD(a))) == 292 && /* PTR */
			OP_LABEL(RIGHT_CHILD(LEFT_CHILD(a))) == 257 && /* INT */
			OP_LABEL(RIGHT_CHILD(a)) == 259 /* ID */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(LEFT_CHILD(a)))))->cost[yyilval_NT] + (compareNodeLeft(a));
			yytrace(a, 129, c + 0, p->cost[yybase_NT]);
			if (c + 0 < p->cost[yybase_NT]) {
				p->cost[yybase_NT] = c + 0;
				p->rule.yybase = 10;
				yyclosure_base(a, c + 0);
			}
		}
		if (	/* base: ATR(SUB(PTR(ilval),INT),ID) */
			OP_LABEL(LEFT_CHILD(a)) == 45 && /* SUB */
			OP_LABEL(LEFT_CHILD(LEFT_CHILD(a))) == 292 && /* PTR */
			OP_LABEL(RIGHT_CHILD(LEFT_CHILD(a))) == 257 && /* INT */
			OP_LABEL(RIGHT_CHILD(a)) == 259 /* ID */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(LEFT_CHILD(a)))))->cost[yyilval_NT] + (compareNodeLeft(a));
			yytrace(a, 130, c + 0, p->cost[yybase_NT]);
			if (c + 0 < p->cost[yybase_NT]) {
				p->cost[yybase_NT] = c + 0;
				p->rule.yybase = 11;
				yyclosure_base(a, c + 0);
			}
		}
		if (	/* base: ATR(ADD(INT,PTR(ilval)),ID) */
			OP_LABEL(LEFT_CHILD(a)) == 43 && /* ADD */
			OP_LABEL(LEFT_CHILD(LEFT_CHILD(a))) == 257 && /* INT */
			OP_LABEL(RIGHT_CHILD(LEFT_CHILD(a))) == 292 && /* PTR */
			OP_LABEL(RIGHT_CHILD(a)) == 259 /* ID */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(RIGHT_CHILD(LEFT_CHILD(a)))))->cost[yyilval_NT] + (compareNodeRight(a));
			yytrace(a, 131, c + 0, p->cost[yybase_NT]);
			if (c + 0 < p->cost[yybase_NT]) {
				p->cost[yybase_NT] = c + 0;
				p->rule.yybase = 12;
				yyclosure_base(a, c + 0);
			}
		}
		if (	/* base: ATR(ADD(PTR(ilval),INT),INDEX(LOCAL,INT)) */
			OP_LABEL(LEFT_CHILD(a)) == 43 && /* ADD */
			OP_LABEL(LEFT_CHILD(LEFT_CHILD(a))) == 292 && /* PTR */
			OP_LABEL(RIGHT_CHILD(LEFT_CHILD(a))) == 257 && /* INT */
			OP_LABEL(RIGHT_CHILD(a)) == 91 && /* INDEX */
			OP_LABEL(LEFT_CHILD(RIGHT_CHILD(a))) == 289 && /* LOCAL */
			OP_LABEL(RIGHT_CHILD(RIGHT_CHILD(a))) == 257 /* INT */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(LEFT_CHILD(a)))))->cost[yyilval_NT] + (compareNodeLeft(a));
			yytrace(a, 132, c + 0, p->cost[yybase_NT]);
			if (c + 0 < p->cost[yybase_NT]) {
				p->cost[yybase_NT] = c + 0;
				p->rule.yybase = 13;
				yyclosure_base(a, c + 0);
			}
		}
		if (	/* base: ATR(SUB(PTR(ilval),INT),INDEX(LOCAL,INT)) */
			OP_LABEL(LEFT_CHILD(a)) == 45 && /* SUB */
			OP_LABEL(LEFT_CHILD(LEFT_CHILD(a))) == 292 && /* PTR */
			OP_LABEL(RIGHT_CHILD(LEFT_CHILD(a))) == 257 && /* INT */
			OP_LABEL(RIGHT_CHILD(a)) == 91 && /* INDEX */
			OP_LABEL(LEFT_CHILD(RIGHT_CHILD(a))) == 289 && /* LOCAL */
			OP_LABEL(RIGHT_CHILD(RIGHT_CHILD(a))) == 257 /* INT */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(LEFT_CHILD(a)))))->cost[yyilval_NT] + (compareNodeLeft(a));
			yytrace(a, 133, c + 0, p->cost[yybase_NT]);
			if (c + 0 < p->cost[yybase_NT]) {
				p->cost[yybase_NT] = c + 0;
				p->rule.yybase = 14;
				yyclosure_base(a, c + 0);
			}
		}
		if (	/* base: ATR(ADD(INT,PTR(ilval)),INDEX(LOCAL,INT)) */
			OP_LABEL(LEFT_CHILD(a)) == 43 && /* ADD */
			OP_LABEL(LEFT_CHILD(LEFT_CHILD(a))) == 257 && /* INT */
			OP_LABEL(RIGHT_CHILD(LEFT_CHILD(a))) == 292 && /* PTR */
			OP_LABEL(RIGHT_CHILD(a)) == 91 && /* INDEX */
			OP_LABEL(LEFT_CHILD(RIGHT_CHILD(a))) == 289 && /* LOCAL */
			OP_LABEL(RIGHT_CHILD(RIGHT_CHILD(a))) == 257 /* INT */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(RIGHT_CHILD(LEFT_CHILD(a)))))->cost[yyilval_NT] + (compareNodeRight(a));
			yytrace(a, 134, c + 0, p->cost[yybase_NT]);
			if (c + 0 < p->cost[yybase_NT]) {
				p->cost[yybase_NT] = c + 0;
				p->rule.yybase = 15;
				yyclosure_base(a, c + 0);
			}
		}
		if (	/* base: ATR(ADD(PTR(ilval),INT),INDEX(ID,INT)) */
			OP_LABEL(LEFT_CHILD(a)) == 43 && /* ADD */
			OP_LABEL(LEFT_CHILD(LEFT_CHILD(a))) == 292 && /* PTR */
			OP_LABEL(RIGHT_CHILD(LEFT_CHILD(a))) == 257 && /* INT */
			OP_LABEL(RIGHT_CHILD(a)) == 91 && /* INDEX */
			OP_LABEL(LEFT_CHILD(RIGHT_CHILD(a))) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(RIGHT_CHILD(a))) == 257 /* INT */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(LEFT_CHILD(a)))))->cost[yyilval_NT] + (compareNodeLeft(a));
			yytrace(a, 135, c + 0, p->cost[yybase_NT]);
			if (c + 0 < p->cost[yybase_NT]) {
				p->cost[yybase_NT] = c + 0;
				p->rule.yybase = 16;
				yyclosure_base(a, c + 0);
			}
		}
		if (	/* base: ATR(SUB(PTR(ilval),INT),INDEX(ID,INT)) */
			OP_LABEL(LEFT_CHILD(a)) == 45 && /* SUB */
			OP_LABEL(LEFT_CHILD(LEFT_CHILD(a))) == 292 && /* PTR */
			OP_LABEL(RIGHT_CHILD(LEFT_CHILD(a))) == 257 && /* INT */
			OP_LABEL(RIGHT_CHILD(a)) == 91 && /* INDEX */
			OP_LABEL(LEFT_CHILD(RIGHT_CHILD(a))) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(RIGHT_CHILD(a))) == 257 /* INT */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(LEFT_CHILD(a)))))->cost[yyilval_NT] + (compareNodeLeft(a));
			yytrace(a, 136, c + 0, p->cost[yybase_NT]);
			if (c + 0 < p->cost[yybase_NT]) {
				p->cost[yybase_NT] = c + 0;
				p->rule.yybase = 17;
				yyclosure_base(a, c + 0);
			}
		}
		if (	/* base: ATR(ADD(INT,PTR(ilval)),INDEX(ID,INT)) */
			OP_LABEL(LEFT_CHILD(a)) == 43 && /* ADD */
			OP_LABEL(LEFT_CHILD(LEFT_CHILD(a))) == 257 && /* INT */
			OP_LABEL(RIGHT_CHILD(LEFT_CHILD(a))) == 292 && /* PTR */
			OP_LABEL(RIGHT_CHILD(a)) == 91 && /* INDEX */
			OP_LABEL(LEFT_CHILD(RIGHT_CHILD(a))) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(RIGHT_CHILD(a))) == 257 /* INT */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(RIGHT_CHILD(LEFT_CHILD(a)))))->cost[yyilval_NT] + (compareNodeRight(a));
			yytrace(a, 137, c + 0, p->cost[yybase_NT]);
			if (c + 0 < p->cost[yybase_NT]) {
				p->cost[yybase_NT] = c + 0;
				p->rule.yybase = 18;
				yyclosure_base(a, c + 0);
			}
		}
		break;
	case 283: /* NE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: NE(cmp,cmp) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yycmp_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yycmp_NT] + 1;
		yytrace(a, 76, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 24;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: NE(rexpr,rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 85, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 33;
			yyclosure_iexpr(a, c + 0);
		}
		/* cond: NE(cmp,cmp) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yycmp_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yycmp_NT] + 1;
		yytrace(a, 124, c + 0, p->cost[yycond_NT]);
		if (c + 0 < p->cost[yycond_NT]) {
			p->cost[yycond_NT] = c + 0;
			p->rule.yycond = 6;
		}
		break;
	case 284: /* GE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: GE(cmp,cmp) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yycmp_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yycmp_NT] + 1;
		yytrace(a, 74, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 22;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: GE(rexpr,rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 82, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 30;
			yyclosure_iexpr(a, c + 0);
		}
		/* cond: GE(cmp,cmp) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yycmp_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yycmp_NT] + 1;
		yytrace(a, 122, c + 0, p->cost[yycond_NT]);
		if (c + 0 < p->cost[yycond_NT]) {
			p->cost[yycond_NT] = c + 0;
			p->rule.yycond = 4;
		}
		break;
	case 285: /* LE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: LE(cmp,cmp) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yycmp_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yycmp_NT] + 1;
		yytrace(a, 75, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 23;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: LE(rexpr,rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 83, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 31;
			yyclosure_iexpr(a, c + 0);
		}
		/* cond: LE(cmp,cmp) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yycmp_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yycmp_NT] + 1;
		yytrace(a, 121, c + 0, p->cost[yycond_NT]);
		if (c + 0 < p->cost[yycond_NT]) {
			p->cost[yycond_NT] = c + 0;
			p->rule.yycond = 3;
		}
		break;
	case 286: /* UMINUS */
		yylabel(LEFT_CHILD(a),a);
		/* iexpr: UMINUS(iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 59, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 9;
			yyclosure_iexpr(a, c + 0);
		}
		/* rexpr: UMINUS(rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 106, c + 0, p->cost[yyrexpr_NT]);
		if (c + 0 < p->cost[yyrexpr_NT]) {
			p->cost[yyrexpr_NT] = c + 0;
			p->rule.yyrexpr = 7;
			yyclosure_rexpr(a, c + 0);
		}
		break;
	case 287: /* NOT */
		yylabel(LEFT_CHILD(a),a);
		/* iexpr: NOT(iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 58, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 8;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 288: /* REF */
		yylabel(LEFT_CHILD(a),a);
		/* iexpr: REF(lval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylval_NT] + 0;
		yytrace(a, 64, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 14;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 289: /* LOCAL */
		/* ilval: LOCAL */
		c = (isInt(a));
		yytrace(a, 45, c + 0, p->cost[yyilval_NT]);
		if (c + 0 < p->cost[yyilval_NT]) {
			p->cost[yyilval_NT] = c + 0;
			p->rule.yyilval = 1;
			yyclosure_ilval(a, c + 0);
		}
		/* slval: LOCAL */
		c = (isString(a));
		yytrace(a, 86, c + 0, p->cost[yyslval_NT]);
		if (c + 0 < p->cost[yyslval_NT]) {
			p->cost[yyslval_NT] = c + 0;
			p->rule.yyslval = 1;
			yyclosure_slval(a, c + 0);
		}
		/* rlval: LOCAL */
		c = (isReal(a));
		yytrace(a, 99, c + 0, p->cost[yyrlval_NT]);
		if (c + 0 < p->cost[yyrlval_NT]) {
			p->cost[yyrlval_NT] = c + 0;
			p->rule.yyrlval = 1;
			yyclosure_rlval(a, c + 0);
		}
		break;
	case 290: /* POSINC */
		yylabel(LEFT_CHILD(a),a);
		/* iexpr: POSINC(ilval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyilval_NT] + 1;
		yytrace(a, 62, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 12;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 291: /* POSDEC */
		yylabel(LEFT_CHILD(a),a);
		/* iexpr: POSDEC(ilval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyilval_NT] + 1;
		yytrace(a, 63, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 13;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 292: /* PTR */
		yylabel(LEFT_CHILD(a),a);
		/* iexpr: PTR(ilval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyilval_NT] + (isInt(a));
		yytrace(a, 65, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 15;
			yyclosure_iexpr(a, c + 0);
		}
		if (	/* iexpr: PTR(PTR(ilval)) */
			OP_LABEL(LEFT_CHILD(a)) == 292 /* PTR */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(a))))->cost[yyilval_NT] + (isInt(a));
			yytrace(a, 66, c + 0, p->cost[yyiexpr_NT]);
			if (c + 0 < p->cost[yyiexpr_NT]) {
				p->cost[yyiexpr_NT] = c + 0;
				p->rule.yyiexpr = 16;
				yyclosure_iexpr(a, c + 0);
			}
		}
		if (	/* iexpr: PTR(PTR(slval)) */
			OP_LABEL(LEFT_CHILD(a)) == 292 /* PTR */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(a))))->cost[yyslval_NT] + (isInt(a));
			yytrace(a, 67, c + 0, p->cost[yyiexpr_NT]);
			if (c + 0 < p->cost[yyiexpr_NT]) {
				p->cost[yyiexpr_NT] = c + 0;
				p->rule.yyiexpr = 17;
				yyclosure_iexpr(a, c + 0);
			}
		}
		/* sexpr: PTR(slval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyslval_NT] + (isString(a));
		yytrace(a, 90, c + 0, p->cost[yysexpr_NT]);
		if (c + 0 < p->cost[yysexpr_NT]) {
			p->cost[yysexpr_NT] = c + 0;
			p->rule.yysexpr = 2;
			yyclosure_sexpr(a, c + 0);
		}
		if (	/* sexpr: PTR(PTR(ilval)) */
			OP_LABEL(LEFT_CHILD(a)) == 292 /* PTR */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(a))))->cost[yyilval_NT] + (isString(a));
			yytrace(a, 91, c + 0, p->cost[yysexpr_NT]);
			if (c + 0 < p->cost[yysexpr_NT]) {
				p->cost[yysexpr_NT] = c + 0;
				p->rule.yysexpr = 3;
				yyclosure_sexpr(a, c + 0);
			}
		}
		/* rexpr: PTR(rlval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrlval_NT] + (isReal(a));
		yytrace(a, 97, c + 0, p->cost[yyrexpr_NT]);
		if (c + 0 < p->cost[yyrexpr_NT]) {
			p->cost[yyrexpr_NT] = c + 0;
			p->rule.yyrexpr = 2;
			yyclosure_rexpr(a, c + 0);
		}
		if (	/* rexpr: PTR(PTR(ilval)) */
			OP_LABEL(LEFT_CHILD(a)) == 292 /* PTR */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(a))))->cost[yyilval_NT] + (isReal(a));
			yytrace(a, 98, c + 0, p->cost[yyrexpr_NT]);
			if (c + 0 < p->cost[yyrexpr_NT]) {
				p->cost[yyrexpr_NT] = c + 0;
				p->rule.yyrexpr = 3;
				yyclosure_rexpr(a, c + 0);
			}
		}
		break;
	case 293: /* CALL */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* expr: CALL(ID,arguments) */
			OP_LABEL(LEFT_CHILD(a)) == 259 /* ID */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyarguments_NT] + (isVoid(a));
			yytrace(a, 39, c + 0, p->cost[yyexpr_NT]);
			if (c + 0 < p->cost[yyexpr_NT]) {
				p->cost[yyexpr_NT] = c + 0;
				p->rule.yyexpr = 4;
				yyclosure_expr(a, c + 0);
			}
		}
		if (	/* expr: CALL(ID,VOID) */
			OP_LABEL(LEFT_CHILD(a)) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(a)) == 272 /* VOID */
		) {
			c = (isVoid(a));
			yytrace(a, 40, c + 0, p->cost[yyexpr_NT]);
			if (c + 0 < p->cost[yyexpr_NT]) {
				p->cost[yyexpr_NT] = c + 0;
				p->rule.yyexpr = 5;
				yyclosure_expr(a, c + 0);
			}
		}
		if (	/* iexpr: CALL(ID,arguments) */
			OP_LABEL(LEFT_CHILD(a)) == 259 /* ID */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyarguments_NT] + (isInt(a));
			yytrace(a, 68, c + 0, p->cost[yyiexpr_NT]);
			if (c + 0 < p->cost[yyiexpr_NT]) {
				p->cost[yyiexpr_NT] = c + 0;
				p->rule.yyiexpr = 18;
				yyclosure_iexpr(a, c + 0);
			}
		}
		if (	/* iexpr: CALL(ID,VOID) */
			OP_LABEL(LEFT_CHILD(a)) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(a)) == 272 /* VOID */
		) {
			c = (isInt(a));
			yytrace(a, 69, c + 0, p->cost[yyiexpr_NT]);
			if (c + 0 < p->cost[yyiexpr_NT]) {
				p->cost[yyiexpr_NT] = c + 0;
				p->rule.yyiexpr = 19;
				yyclosure_iexpr(a, c + 0);
			}
		}
		if (	/* sexpr: CALL(ID,arguments) */
			OP_LABEL(LEFT_CHILD(a)) == 259 /* ID */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyarguments_NT] + (isString(a));
			yytrace(a, 95, c + 0, p->cost[yysexpr_NT]);
			if (c + 0 < p->cost[yysexpr_NT]) {
				p->cost[yysexpr_NT] = c + 0;
				p->rule.yysexpr = 5;
				yyclosure_sexpr(a, c + 0);
			}
		}
		if (	/* sexpr: CALL(ID,VOID) */
			OP_LABEL(LEFT_CHILD(a)) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(a)) == 272 /* VOID */
		) {
			c = (isString(a));
			yytrace(a, 96, c + 0, p->cost[yysexpr_NT]);
			if (c + 0 < p->cost[yysexpr_NT]) {
				p->cost[yysexpr_NT] = c + 0;
				p->rule.yysexpr = 6;
				yyclosure_sexpr(a, c + 0);
			}
		}
		if (	/* rexpr: CALL(ID,arguments) */
			OP_LABEL(LEFT_CHILD(a)) == 259 /* ID */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyarguments_NT] + (isReal(a));
			yytrace(a, 111, c + 0, p->cost[yyrexpr_NT]);
			if (c + 0 < p->cost[yyrexpr_NT]) {
				p->cost[yyrexpr_NT] = c + 0;
				p->rule.yyrexpr = 12;
				yyclosure_rexpr(a, c + 0);
			}
		}
		if (	/* rexpr: CALL(ID,VOID) */
			OP_LABEL(LEFT_CHILD(a)) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(a)) == 272 /* VOID */
		) {
			c = (isReal(a));
			yytrace(a, 112, c + 0, p->cost[yyrexpr_NT]);
			if (c + 0 < p->cost[yyrexpr_NT]) {
				p->cost[yyrexpr_NT] = c + 0;
				p->rule.yyrexpr = 13;
				yyclosure_rexpr(a, c + 0);
			}
		}
		break;
	case 294: /* START */
		/* begin: START */
		yytrace(a, 20, 1 + 0, p->cost[yybegin_NT]);
		if (1 + 0 < p->cost[yybegin_NT]) {
			p->cost[yybegin_NT] = 1 + 0;
			p->rule.yybegin = 1;
		}
		/* forstart: START */
		yytrace(a, 26, 1 + 0, p->cost[yyforstart_NT]);
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
		return;
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
		if (	/* arguments: ARGS(expr,NIL) */
			OP_LABEL(RIGHT_CHILD(a)) == 296 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + 0;
			yytrace(a, 113, c + 0, p->cost[yyarguments_NT]);
			if (c + 0 < p->cost[yyarguments_NT]) {
				p->cost[yyarguments_NT] = c + 0;
				p->rule.yyarguments = 1;
			}
		}
		/* arguments: ARGS(expr,arguments) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyarguments_NT] + 0;
		yytrace(a, 114, c + 0, p->cost[yyarguments_NT]);
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
	case 124: /* cond: NE(cmp,cmp) */
	case 123: /* cond: LOGIC_EQUAL(cmp,cmp) */
	case 122: /* cond: GE(cmp,cmp) */
	case 121: /* cond: LE(cmp,cmp) */
	case 120: /* cond: GT(cmp,cmp) */
	case 119: /* cond: LT(cmp,cmp) */
	case 117: /* expr: OR(or,iexpr) */
	case 115: /* expr: AND(and,iexpr) */
	case 114: /* arguments: ARGS(expr,arguments) */
	case 109: /* rexpr: DIV(rexpr,rexpr) */
	case 108: /* rexpr: MUL(rexpr,rexpr) */
	case 107: /* rexpr: SUB(rexpr,rexpr) */
	case 105: /* rexpr: ADD(rexpr,rexpr) */
	case 102: /* rexpr: ATR(rassign,rlval) */
	case 101: /* rlval: INDEX(lvec,expr) */
	case 94: /* sexpr: ATR(sassign,slval) */
	case 88: /* slval: INDEX(lvec,expr) */
	case 85: /* iexpr: NE(rexpr,rexpr) */
	case 84: /* iexpr: LOGIC_EQUAL(rexpr,rexpr) */
	case 83: /* iexpr: LE(rexpr,rexpr) */
	case 82: /* iexpr: GE(rexpr,rexpr) */
	case 81: /* iexpr: GT(rexpr,rexpr) */
	case 80: /* iexpr: LT(rexpr,rexpr) */
	case 79: /* iexpr: OR(cmp,cmp) */
	case 78: /* iexpr: AND(cmp,cmp) */
	case 77: /* iexpr: LOGIC_EQUAL(cmp,cmp) */
	case 76: /* iexpr: NE(cmp,cmp) */
	case 75: /* iexpr: LE(cmp,cmp) */
	case 74: /* iexpr: GE(cmp,cmp) */
	case 73: /* iexpr: GT(cmp,cmp) */
	case 72: /* iexpr: LT(cmp,cmp) */
	case 56: /* iexpr: MUL(iexpr,iexpr) */
	case 55: /* iexpr: MOD(iexpr,iexpr) */
	case 54: /* iexpr: DIV(iexpr,iexpr) */
	case 53: /* iexpr: SUB(iexpr,iexpr) */
	case 52: /* iexpr: ADD(iexpr,iexpr) */
	case 51: /* iexpr: ATR(iassign,ilval) */
	case 47: /* ilval: INDEX(lvec,expr) */
	case 25: /* forin: IN(forstart,expr) */
	case 23: /* forinstr: INSTR(forstmt,expr) */
	case 22: /* forbody: FOR(forin,forinstr) */
	case 21: /* for: INSTR(expr,forbody) */
	case 19: /* do: DO(begin,stmt) */
	case 18: /* while: WHILE(do,expr) */
	case 17: /* cond2: IF(cond,stmt) */
	case 16: /* ifelse: ELSE(cond2,stmt) */
	case 15: /* if: IF(cond,stmt) */
	case 14: /* list: LIST(list,base) */
	case 7: /* decls: INSTR(decls,param) */
	case 5: /* bloco: BLOCK(list,decls) */
	case 4: /* params: NEXT(params,param) */
	case 1: /* finit: ARGB(bloco,params) */
		kids[0] = LEFT_CHILD(p);
		kids[1] = RIGHT_CHILD(p);
		break;
	case 113: /* arguments: ARGS(expr,NIL) */
	case 106: /* rexpr: UMINUS(rexpr) */
	case 97: /* rexpr: PTR(rlval) */
	case 90: /* sexpr: PTR(slval) */
	case 65: /* iexpr: PTR(ilval) */
	case 64: /* iexpr: REF(lval) */
	case 63: /* iexpr: POSDEC(ilval) */
	case 62: /* iexpr: POSINC(ilval) */
	case 61: /* iexpr: DECR(ilval) */
	case 60: /* iexpr: INCR(ilval) */
	case 59: /* iexpr: UMINUS(iexpr) */
	case 58: /* iexpr: NOT(iexpr) */
	case 57: /* rexpr: FACTORIAL(iexpr) */
	case 9: /* param: PARAM(tipo,ID) */
	case 2: /* finit: ARGB(bloco,NIL) */
		kids[0] = LEFT_CHILD(p);
		break;
	case 125: /* cond: expr */
	case 118: /* or: iexpr */
	case 116: /* and: iexpr */
	case 110: /* rexpr: iexpr */
	case 103: /* rassign: rexpr */
	case 93: /* sassign: iexpr */
	case 92: /* sassign: sexpr */
	case 71: /* cmp: sexpr */
	case 70: /* cmp: iexpr */
	case 49: /* iassign: rexpr */
	case 48: /* iassign: iexpr */
	case 44: /* lval: slval */
	case 43: /* lval: rlval */
	case 42: /* lval: ilval */
	case 41: /* lvec: lval */
	case 38: /* expr: rexpr */
	case 37: /* expr: sexpr */
	case 36: /* expr: iexpr */
	case 35: /* base: bloco */
	case 34: /* base: for */
	case 33: /* base: while */
	case 32: /* base: ifelse */
	case 31: /* base: if */
	case 30: /* base: expr */
	case 27: /* stmt: base */
	case 24: /* forstmt: stmt */
	case 13: /* list: base */
	case 3: /* params: param */
		kids[0] = p;
		break;
	case 6: /* bloco: BLOCK(INSTR(list,stmt),decls) */
		kids[0] = LEFT_CHILD(LEFT_CHILD(p));
		kids[1] = RIGHT_CHILD(LEFT_CHILD(p));
		kids[2] = RIGHT_CHILD(p);
		break;
	case 112: /* rexpr: CALL(ID,VOID) */
	case 104: /* rexpr: REAL */
	case 100: /* rlval: ID */
	case 99: /* rlval: LOCAL */
	case 96: /* sexpr: CALL(ID,VOID) */
	case 89: /* sexpr: STR */
	case 87: /* slval: ID */
	case 86: /* slval: LOCAL */
	case 69: /* iexpr: CALL(ID,VOID) */
	case 50: /* iexpr: INT */
	case 46: /* ilval: ID */
	case 45: /* ilval: LOCAL */
	case 40: /* expr: CALL(ID,VOID) */
	case 29: /* stmt: CONTINUE */
	case 28: /* stmt: BREAK */
	case 26: /* forstart: START */
	case 20: /* begin: START */
	case 12: /* tipo: NUMBER */
	case 11: /* tipo: STRING */
	case 10: /* tipo: INTEGER */
	case 8: /* decls: NONE */
		break;
	case 111: /* rexpr: CALL(ID,arguments) */
	case 95: /* sexpr: CALL(ID,arguments) */
	case 68: /* iexpr: CALL(ID,arguments) */
	case 39: /* expr: CALL(ID,arguments) */
		kids[0] = RIGHT_CHILD(p);
		break;
	case 98: /* rexpr: PTR(PTR(ilval)) */
	case 91: /* sexpr: PTR(PTR(ilval)) */
	case 67: /* iexpr: PTR(PTR(slval)) */
	case 66: /* iexpr: PTR(PTR(ilval)) */
		kids[0] = LEFT_CHILD(LEFT_CHILD(p));
		break;
	case 136: /* base: ATR(SUB(PTR(ilval),INT),INDEX(ID,INT)) */
	case 135: /* base: ATR(ADD(PTR(ilval),INT),INDEX(ID,INT)) */
	case 133: /* base: ATR(SUB(PTR(ilval),INT),INDEX(LOCAL,INT)) */
	case 132: /* base: ATR(ADD(PTR(ilval),INT),INDEX(LOCAL,INT)) */
	case 130: /* base: ATR(SUB(PTR(ilval),INT),ID) */
	case 129: /* base: ATR(ADD(PTR(ilval),INT),ID) */
	case 127: /* base: ATR(SUB(PTR(ilval),INT),LOCAL) */
	case 126: /* base: ATR(ADD(PTR(ilval),INT),LOCAL) */
		kids[0] = LEFT_CHILD(LEFT_CHILD(LEFT_CHILD(p)));
		break;
	case 137: /* base: ATR(ADD(INT,PTR(ilval)),INDEX(ID,INT)) */
	case 134: /* base: ATR(ADD(INT,PTR(ilval)),INDEX(LOCAL,INT)) */
	case 131: /* base: ATR(ADD(INT,PTR(ilval)),ID) */
	case 128: /* base: ATR(ADD(INT,PTR(ilval)),LOCAL) */
		kids[0] = LEFT_CHILD(RIGHT_CHILD(LEFT_CHILD(p)));
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
{if (functionReturnType != 4) {if (functionReturnType != 3)fprintf(outfp, pfLOCAL pfLOAD pfPOP, -4);
															else if(functionReturnType == 3) fprintf(outfp, pfLOCAL pfLOAD2 pfDPOP, -8);}}
		break;
	case 2: /* finit: ARGB(bloco,NIL) */
#line 84 "diy.brg"
{if (functionReturnType != 4) {if (functionReturnType != 3)fprintf(outfp, pfLOCAL pfLOAD pfPOP, -4);
															else if(functionReturnType == 3) fprintf(outfp, pfLOCAL pfLOAD2 pfDPOP, -8);}}
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
#line 108 "diy.brg"
{fprintf(outfp, pfLABEL, mklbl(LEFT_CHILD(p)->place)); }
		break;
	case 16: /* ifelse: ELSE(cond2,stmt) */
#line 112 "diy.brg"
{ fprintf(outfp, pfLABEL, mklbl(LEFT_CHILD(p)->place)); }
		break;
	case 17: /* cond2: IF(cond,stmt) */
#line 113 "diy.brg"
{ p->place = ++lbl; fprintf(outfp, pfJMP pfLABEL,
							mklbl(p->place), mklbl(LEFT_CHILD(p)->place)); }
		break;
	case 18: /* while: WHILE(do,expr) */
#line 118 "diy.brg"
{dblcnt--; brkcnt--; fprintf(outfp, pfJNZ pfLABEL,
						mklbl(lbls[dblcnt].b_lbl), mklbl(lbls[dblcnt].e_lbl)); }
		break;
	case 19: /* do: DO(begin,stmt) */
#line 120 "diy.brg"
{}
		break;
	case 20: /* begin: START */
#line 121 "diy.brg"
{ fprintf(outfp, pfLABEL, mklbl(++lbl)); lbls[dblcnt].b_lbl = lbl; lbls[dblcnt].e_lbl = ++lbl;
				brklbl[brkcnt++] = lbls[dblcnt].e_lbl;
				lbls[dblcnt].br_lbl = lbls[dblcnt].e_lbl; lbls[dblcnt++].cnt_lbl = lbls[dblcnt].b_lbl;
			 }
		break;
	case 21: /* for: INSTR(expr,forbody) */
#line 128 "diy.brg"

		break;
	case 22: /* forbody: FOR(forin,forinstr) */
#line 129 "diy.brg"
{fprintf(outfp, pfLABEL, mklbl(lbls[--dblcnt].e_lbl));}
		break;
	case 23: /* forinstr: INSTR(forstmt,expr) */
#line 130 "diy.brg"
{fprintf(outfp, pfJMP, mklbl(lbls[dblcnt - 1].b_lbl));}
		break;
	case 24: /* forstmt: stmt */
#line 131 "diy.brg"
{}
		break;
	case 25: /* forin: IN(forstart,expr) */
#line 132 "diy.brg"
{fprintf(outfp, pfJZ, mklbl(++lbl)); lbls[dblcnt].e_lbl = lbl; brklbl[brkcnt++] = lbls[dblcnt++].e_lbl;}
		break;
	case 26: /* forstart: START */
#line 133 "diy.brg"
{fprintf(outfp, pfLABEL, mklbl(++lbl)); lbls[dblcnt].b_lbl = lbl; }
		break;
	case 27: /* stmt: base */
#line 137 "diy.brg"

		break;
	case 28: /* stmt: BREAK */
#line 138 "diy.brg"
{ fprintf(outfp, pfJMP, mklbl(lbls[dblcnt - p->value.i].br_lbl)); }
		break;
	case 29: /* stmt: CONTINUE */
#line 139 "diy.brg"
{ fprintf(outfp, pfJMP, mklbl(lbls[dblcnt - p->value.i].cnt_lbl)); }
		break;
	case 30: /* base: expr */
#line 143 "diy.brg"
{if (p->place != 0) fprintf(outfp, pfTRASH, (int)p->place); }
		break;
	case 31: /* base: if */
#line 144 "diy.brg"

		break;
	case 32: /* base: ifelse */
#line 145 "diy.brg"

		break;
	case 33: /* base: while */
#line 146 "diy.brg"

		break;
	case 34: /* base: for */
#line 147 "diy.brg"

		break;
	case 35: /* base: bloco */
#line 148 "diy.brg"

		break;
	case 36: /* expr: iexpr */
#line 152 "diy.brg"
{p->place = 4;}
		break;
	case 37: /* expr: sexpr */
#line 153 "diy.brg"
{p->place = 4;}
		break;
	case 38: /* expr: rexpr */
#line 154 "diy.brg"
{p->place = 8;}
		break;
	case 39: /* expr: CALL(ID,arguments) */
#line 158 "diy.brg"
{fprintf(outfp, pfCALL pfTRASH, mkfunc(LEFT_CHILD(p)->value.s),
														 (int)((RIGHT_CHILD(p)->place))); p->place = 0;}
		break;
	case 40: /* expr: CALL(ID,VOID) */
#line 160 "diy.brg"
{fprintf(outfp, pfCALL, mkfunc(LEFT_CHILD(p)->value.s));
												p->place = 0;}
		break;
	case 41: /* lvec: lval */
#line 164 "diy.brg"
{fprintf(outfp, pfLOAD);}
		break;
	case 42: /* lval: ilval */
#line 165 "diy.brg"

		break;
	case 43: /* lval: rlval */
#line 166 "diy.brg"

		break;
	case 44: /* lval: slval */
#line 167 "diy.brg"

		break;
	case 45: /* ilval: LOCAL */
#line 171 "diy.brg"
{fprintf(outfp, pfLOCAL, p->value.i * (pfWORD/4));}
		break;
	case 46: /* ilval: ID */
#line 172 "diy.brg"
{fprintf(outfp, pfADDR, p->value.s);}
		break;
	case 47: /* ilval: INDEX(lvec,expr) */
#line 173 "diy.brg"
{ if (isString(LEFT_CHILD(p)) == 1) fprintf(outfp, pfADD);
								else fprintf(outfp, pfIMM pfMUL pfADD, 4);}
		break;
	case 48: /* iassign: iexpr */
#line 177 "diy.brg"
{fprintf(outfp, pfDUP);}
		break;
	case 49: /* iassign: rexpr */
#line 178 "diy.brg"
{fprintf(outfp, pfD2I pfDUP);}
		break;
	case 50: /* iexpr: INT */
#line 179 "diy.brg"
{fprintf(outfp, pfIMM, p->value.i);}
		break;
	case 51: /* iexpr: ATR(iassign,ilval) */
#line 180 "diy.brg"
{fprintf(outfp, pfSTORE);}
		break;
	case 52: /* iexpr: ADD(iexpr,iexpr) */
#line 181 "diy.brg"
{fprintf(outfp, pfADD);}
		break;
	case 53: /* iexpr: SUB(iexpr,iexpr) */
#line 182 "diy.brg"
{fprintf(outfp, pfSUB);}
		break;
	case 54: /* iexpr: DIV(iexpr,iexpr) */
#line 183 "diy.brg"
{fprintf(outfp, pfDIV);}
		break;
	case 55: /* iexpr: MOD(iexpr,iexpr) */
#line 184 "diy.brg"
{fprintf(outfp, pfMOD);}
		break;
	case 56: /* iexpr: MUL(iexpr,iexpr) */
#line 185 "diy.brg"
{fprintf(outfp, pfMUL);}
		break;
	case 57: /* rexpr: FACTORIAL(iexpr) */
#line 186 "diy.brg"
{fprintf(outfp, pfCALL pfTRASH pfDPUSH, "_factorial", 4);}
		break;
	case 58: /* iexpr: NOT(iexpr) */
#line 187 "diy.brg"
{fprintf(outfp, pfIMM pfEQ, 0);}
		break;
	case 59: /* iexpr: UMINUS(iexpr) */
#line 188 "diy.brg"
{fprintf(outfp, pfNEG);}
		break;
	case 60: /* iexpr: INCR(ilval) */
#line 192 "diy.brg"
{fprintf(outfp, pfDUP pfINCR pfLOAD, 1);}
		break;
	case 61: /* iexpr: DECR(ilval) */
#line 193 "diy.brg"
{fprintf(outfp, pfDUP pfDECR pfLOAD, 1);}
		break;
	case 62: /* iexpr: POSINC(ilval) */
#line 194 "diy.brg"
{fprintf(outfp, pfDUP pfLOAD pfSWAP pfINCR, 1);}
		break;
	case 63: /* iexpr: POSDEC(ilval) */
#line 195 "diy.brg"
{fprintf(outfp, pfDUP pfLOAD pfSWAP pfDECR, 1);}
		break;
	case 64: /* iexpr: REF(lval) */
#line 196 "diy.brg"

		break;
	case 65: /* iexpr: PTR(ilval) */
#line 200 "diy.brg"
{if (LEFT_CHILD(p)->place == 2) { fprintf(outfp, pfLDCHR);}
                        else {fprintf(outfp, pfLOAD);}}
		break;
	case 66: /* iexpr: PTR(PTR(ilval)) */
#line 202 "diy.brg"
{fprintf(outfp, pfLOAD pfLOAD);}
		break;
	case 67: /* iexpr: PTR(PTR(slval)) */
#line 203 "diy.brg"
{fprintf(outfp, pfLOAD pfLDCHR);}
		break;
	case 68: /* iexpr: CALL(ID,arguments) */
#line 206 "diy.brg"
{fprintf(outfp, pfCALL pfTRASH pfPUSH, mkfunc(LEFT_CHILD(p)->value.s),(int)((RIGHT_CHILD(p)->place)));
p->place = IDfind(LEFT_CHILD(p)->value.s, NULL) == 3 ? 8: 4;}
		break;
	case 69: /* iexpr: CALL(ID,VOID) */
#line 209 "diy.brg"
{fprintf(outfp, pfCALL pfPUSH, mkfunc(LEFT_CHILD(p)->value.s));
									p->place = IDfind(LEFT_CHILD(p)->value.s, NULL) == 3 ? 8: 4;}
		break;
	case 70: /* cmp: iexpr */
#line 213 "diy.brg"
{}
		break;
	case 71: /* cmp: sexpr */
#line 214 "diy.brg"
{fprintf(outfp, pfLDCHR);}
		break;
	case 72: /* iexpr: LT(cmp,cmp) */
#line 215 "diy.brg"
{fprintf(outfp, pfLT);}
		break;
	case 73: /* iexpr: GT(cmp,cmp) */
#line 216 "diy.brg"
{fprintf(outfp, pfGT);}
		break;
	case 74: /* iexpr: GE(cmp,cmp) */
#line 217 "diy.brg"
{fprintf(outfp, pfGE);}
		break;
	case 75: /* iexpr: LE(cmp,cmp) */
#line 218 "diy.brg"
{fprintf(outfp, pfLE);}
		break;
	case 76: /* iexpr: NE(cmp,cmp) */
#line 219 "diy.brg"
{fprintf(outfp, pfNE);}
		break;
	case 77: /* iexpr: LOGIC_EQUAL(cmp,cmp) */
#line 220 "diy.brg"
{fprintf(outfp, pfEQ);}
		break;
	case 78: /* iexpr: AND(cmp,cmp) */
#line 221 "diy.brg"
{fprintf(outfp, pfAND);}
		break;
	case 79: /* iexpr: OR(cmp,cmp) */
#line 222 "diy.brg"
{fprintf(outfp, pfOR);}
		break;
	case 80: /* iexpr: LT(rexpr,rexpr) */
#line 224 "diy.brg"
{fprintf(outfp, pfDCMP pfIMM pfLT, 0);}
		break;
	case 81: /* iexpr: GT(rexpr,rexpr) */
#line 225 "diy.brg"
{fprintf(outfp, pfDCMP pfIMM pfGT, 0);}
		break;
	case 82: /* iexpr: GE(rexpr,rexpr) */
#line 226 "diy.brg"
{fprintf(outfp, pfDCMP pfIMM pfGE, 0);}
		break;
	case 83: /* iexpr: LE(rexpr,rexpr) */
#line 227 "diy.brg"
{fprintf(outfp, pfDCMP pfIMM pfLE, 0);}
		break;
	case 84: /* iexpr: LOGIC_EQUAL(rexpr,rexpr) */
#line 228 "diy.brg"
{fprintf(outfp, pfDCMP pfIMM pfEQ, 0);}
		break;
	case 85: /* iexpr: NE(rexpr,rexpr) */
#line 229 "diy.brg"
{fprintf(outfp, pfDCMP pfIMM pfNE, 0);}
		break;
	case 86: /* slval: LOCAL */
#line 232 "diy.brg"
{fprintf(outfp, pfLOCAL, p->value.i * (pfWORD/4));}
		break;
	case 87: /* slval: ID */
#line 233 "diy.brg"
{fprintf(outfp, pfADDR, p->value.s);}
		break;
	case 88: /* slval: INDEX(lvec,expr) */
#line 234 "diy.brg"
{ fprintf(outfp, pfIMM pfMUL pfADD, 4);}
		break;
	case 89: /* sexpr: STR */
#line 236 "diy.brg"
{	lbl++; fprintf(outfp, pfRODATA pfALIGN pfLABEL, mklbl(lbl));
					outstr(p->value.s); fprintf(outfp, pfTEXT pfADDR, mklbl(lbl));}
		break;
	case 90: /* sexpr: PTR(slval) */
#line 238 "diy.brg"
{fprintf(outfp, pfLOAD);}
		break;
	case 91: /* sexpr: PTR(PTR(ilval)) */
#line 239 "diy.brg"
{fprintf(outfp, pfLOAD pfLOAD);}
		break;
	case 92: /* sassign: sexpr */
#line 241 "diy.brg"
{fprintf(outfp, pfDUP);}
		break;
	case 93: /* sassign: iexpr */
#line 242 "diy.brg"
{fprintf(outfp, pfDUP); /*assign to pointer or null (0)*/}
		break;
	case 94: /* sexpr: ATR(sassign,slval) */
#line 243 "diy.brg"
{fprintf(outfp, pfSTORE);}
		break;
	case 95: /* sexpr: CALL(ID,arguments) */
#line 244 "diy.brg"
{fprintf(outfp, pfCALL pfTRASH pfPUSH, mkfunc(LEFT_CHILD(p)->value.s),
													 (int)((RIGHT_CHILD(p)->place))); p->place = IDfind(LEFT_CHILD(p)->value.s, NULL) == 3 ? 8: 4;}
		break;
	case 96: /* sexpr: CALL(ID,VOID) */
#line 246 "diy.brg"
{fprintf(outfp, pfCALL pfPUSH, mkfunc(LEFT_CHILD(p)->value.s));
							 	p->place = IDfind(LEFT_CHILD(p)->value.s, NULL) == 3 ? 8: 4;}
		break;
	case 97: /* rexpr: PTR(rlval) */
#line 250 "diy.brg"
{fprintf(outfp, pfLOAD2);}
		break;
	case 98: /* rexpr: PTR(PTR(ilval)) */
#line 251 "diy.brg"
{fprintf(outfp, pfLOAD pfLOAD2);}
		break;
	case 99: /* rlval: LOCAL */
#line 252 "diy.brg"
{fprintf(outfp, pfLOCAL, p->value.i * (pfWORD/4));}
		break;
	case 100: /* rlval: ID */
#line 253 "diy.brg"
{fprintf(outfp, pfADDR, p->value.s);}
		break;
	case 101: /* rlval: INDEX(lvec,expr) */
#line 254 "diy.brg"
{ fprintf(outfp, pfIMM pfMUL pfADD, 8);}
		break;
	case 102: /* rexpr: ATR(rassign,rlval) */
#line 255 "diy.brg"
{fprintf(outfp, pfSTORE2);}
		break;
	case 103: /* rassign: rexpr */
#line 256 "diy.brg"
{fprintf(outfp, pfDUP2);}
		break;
	case 104: /* rexpr: REAL */
#line 257 "diy.brg"
{lbl++; fprintf(outfp, pfRODATA pfALIGN pfLABEL pfDOUBLE, mklbl(lbl), p->value.r);
					fprintf(outfp, pfTEXT pfADDR pfLOAD2, mklbl(lbl));}
		break;
	case 105: /* rexpr: ADD(rexpr,rexpr) */
#line 259 "diy.brg"
{fprintf(outfp, pfDADD);}
		break;
	case 106: /* rexpr: UMINUS(rexpr) */
#line 260 "diy.brg"
{fprintf(outfp, pfDNEG);}
		break;
	case 107: /* rexpr: SUB(rexpr,rexpr) */
#line 261 "diy.brg"
{fprintf(outfp, pfDSUB);}
		break;
	case 108: /* rexpr: MUL(rexpr,rexpr) */
#line 262 "diy.brg"
{fprintf(outfp, pfDMUL);}
		break;
	case 109: /* rexpr: DIV(rexpr,rexpr) */
#line 263 "diy.brg"
{fprintf(outfp, pfDDIV);}
		break;
	case 110: /* rexpr: iexpr */
#line 264 "diy.brg"
{fprintf(outfp, pfI2D);}
		break;
	case 111: /* rexpr: CALL(ID,arguments) */
#line 265 "diy.brg"
{fprintf(outfp, pfCALL pfTRASH pfDPUSH, mkfunc(LEFT_CHILD(p)->value.s),
														 (int)((RIGHT_CHILD(p)->place))); p->place = IDfind(LEFT_CHILD(p)->value.s, NULL) == 3 ? 8 : 4;}
		break;
	case 112: /* rexpr: CALL(ID,VOID) */
#line 267 "diy.brg"
{ fprintf(outfp, pfCALL pfDPUSH, mkfunc(LEFT_CHILD(p)->value.s));
									 p->place = IDfind(LEFT_CHILD(p)->value.s, NULL) == 3 ? 8: 4;}
		break;
	case 113: /* arguments: ARGS(expr,NIL) */
#line 272 "diy.brg"
{p->place = LEFT_CHILD(p)->place;}
		break;
	case 114: /* arguments: ARGS(expr,arguments) */
#line 273 "diy.brg"
{p->place = LEFT_CHILD(p)->place + RIGHT_CHILD(p)->place;}
		break;
	case 115: /* expr: AND(and,iexpr) */
#line 276 "diy.brg"
{ fprintf(outfp, pfLABEL, mklbl(LEFT_CHILD(p)->place)); }
		break;
	case 116: /* and: iexpr */
#line 277 "diy.brg"
{ p->place = ++lbl; fprintf(outfp, pfDUP pfJZ pfTRASH, mklbl(p->place), 4); }
		break;
	case 117: /* expr: OR(or,iexpr) */
#line 278 "diy.brg"
{ fprintf(outfp, pfLABEL, mklbl(LEFT_CHILD(p)->place)); }
		break;
	case 118: /* or: iexpr */
#line 279 "diy.brg"
{ p->place = ++lbl; fprintf(outfp, pfDUP pfJNZ pfTRASH, mklbl(p->place), 4); }
		break;
	case 119: /* cond: LT(cmp,cmp) */
#line 283 "diy.brg"
{p->place = ++lbl; fprintf(outfp, pfJGE, mklbl(p->place));}
		break;
	case 120: /* cond: GT(cmp,cmp) */
#line 284 "diy.brg"
{p->place = ++lbl; fprintf(outfp, pfJLE, mklbl(p->place));}
		break;
	case 121: /* cond: LE(cmp,cmp) */
#line 285 "diy.brg"
{p->place = ++lbl; fprintf(outfp, pfJGT, mklbl(p->place));}
		break;
	case 122: /* cond: GE(cmp,cmp) */
#line 286 "diy.brg"
{p->place = ++lbl; fprintf(outfp, pfJLT, mklbl(p->place));}
		break;
	case 123: /* cond: LOGIC_EQUAL(cmp,cmp) */
#line 287 "diy.brg"
{p->place = ++lbl; fprintf(outfp, pfJNE, mklbl(p->place));}
		break;
	case 124: /* cond: NE(cmp,cmp) */
#line 288 "diy.brg"
{p->place = ++lbl; fprintf(outfp, pfJEQ, mklbl(p->place));}
		break;
	case 125: /* cond: expr */
#line 289 "diy.brg"
{p->place = ++lbl; fprintf(outfp, pfJZ, mklbl(p->place));}
		break;
	case 126: /* base: ATR(ADD(PTR(ilval),INT),LOCAL) */
#line 292 "diy.brg"
{fprintf(outfp, pfINCR, RIGHT_CHILD(LEFT_CHILD(p))->value.i);}
		break;
	case 127: /* base: ATR(SUB(PTR(ilval),INT),LOCAL) */
#line 293 "diy.brg"
{fprintf(outfp, pfDECR, RIGHT_CHILD(LEFT_CHILD(p))->value.i);}
		break;
	case 128: /* base: ATR(ADD(INT,PTR(ilval)),LOCAL) */
#line 294 "diy.brg"
{fprintf(outfp, pfINCR, LEFT_CHILD(LEFT_CHILD(p))->value.i);}
		break;
	case 129: /* base: ATR(ADD(PTR(ilval),INT),ID) */
#line 297 "diy.brg"
{fprintf(outfp, pfINCR, RIGHT_CHILD(LEFT_CHILD(p))->value.i);}
		break;
	case 130: /* base: ATR(SUB(PTR(ilval),INT),ID) */
#line 298 "diy.brg"
{fprintf(outfp, pfDECR, RIGHT_CHILD(LEFT_CHILD(p))->value.i);}
		break;
	case 131: /* base: ATR(ADD(INT,PTR(ilval)),ID) */
#line 299 "diy.brg"
{fprintf(outfp, pfINCR, LEFT_CHILD(LEFT_CHILD(p))->value.i);}
		break;
	case 132: /* base: ATR(ADD(PTR(ilval),INT),INDEX(LOCAL,INT)) */
#line 302 "diy.brg"
{fprintf(outfp, pfINCR, RIGHT_CHILD(LEFT_CHILD(p))->value.i);}
		break;
	case 133: /* base: ATR(SUB(PTR(ilval),INT),INDEX(LOCAL,INT)) */
#line 303 "diy.brg"
{fprintf(outfp, pfDECR, RIGHT_CHILD(LEFT_CHILD(p))->value.i);}
		break;
	case 134: /* base: ATR(ADD(INT,PTR(ilval)),INDEX(LOCAL,INT)) */
#line 304 "diy.brg"
{fprintf(outfp, pfINCR, LEFT_CHILD(LEFT_CHILD(p))->value.i);}
		break;
	case 135: /* base: ATR(ADD(PTR(ilval),INT),INDEX(ID,INT)) */
#line 306 "diy.brg"
{fprintf(outfp, pfINCR, RIGHT_CHILD(LEFT_CHILD(p))->value.i);}
		break;
	case 136: /* base: ATR(SUB(PTR(ilval),INT),INDEX(ID,INT)) */
#line 307 "diy.brg"
{fprintf(outfp, pfDECR, RIGHT_CHILD(LEFT_CHILD(p))->value.i);}
		break;
	case 137: /* base: ATR(ADD(INT,PTR(ilval)),INDEX(ID,INT)) */
#line 308 "diy.brg"
{fprintf(outfp, pfINCR, LEFT_CHILD(LEFT_CHILD(p))->value.i);}
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


#line 312 "diy.brg"

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

  fprintf(outfp, pfEXTRN, "_factorial");
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

