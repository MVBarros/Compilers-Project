/*
generated at Wed May 15 15:10:37 2019
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
/*use to determine function return type*/
int isIntFunction(Node* p) {return p->info == 1 ? 1 : MAX_COST;}
/*use to determine if LOCAL or ID is int*/
int isInt(Node* p) {return p->info == 1 ? 1 : MAX_COST;}
/*use to determine if LVAL of ATR is Int*/
int isIntLval(Node* p) {return RIGHT_CHILD(p)->info == 1 ? 1 : MAX_COST;}


/*use to determine function return type*/
int isRealFunction(Node* p) {return p->info == 3 ? 1 : MAX_COST;}
/*use to determine if LOCAL or ID is int*/
int isReal(Node* p) {return p->info == 3 ? 1 : MAX_COST;}
/*use to determine if LVAL of ATR is Real*/
int isRealLval(Node* p) {return RIGHT_CHILD(p)->info == 3 ? 1 : MAX_COST;}

int isString(Node* p) {return p->info == 2 ? 1 : MAX_COST;}
int isStringFunction(Node* p) {return p->info == 2 ? 1 : MAX_COST;}
int isStringLval(Node* p) {return RIGHT_CHILD(p)->info == 2 ? 1 : MAX_COST;}


int isIntPointer(Node* p) {return p->info == 11 ? 1 : MAX_COST;}

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
#define yytipo_NT 7
#define yybase_NT 8
#define yyexpr_NT 9
#define yyiexpr_NT 10
#define yysexpr_NT 11
#define yyrexpr_NT 12
#define yyarguments_NT 13
#define yylval_NT 14
#define yylvec_NT 15
#define yysassign_NT 16
#define yyiptrexpr_NT 17
#define yyscmp_NT 18
#define yyiassign_NT 19
#define yyrassign_NT 20

static YYCONST char *yyntname[] = {
	0,
	"finit",
	"bloco",
	"params",
	"param",
	"list",
	"decls",
	"tipo",
	"base",
	"expr",
	"iexpr",
	"sexpr",
	"rexpr",
	"arguments",
	"lval",
	"lvec",
	"sassign",
	"iptrexpr",
	"scmp",
	"iassign",
	"rassign",
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
	short cost[21];
	struct {
		unsigned int yyfinit:2;
		unsigned int yybloco:1;
		unsigned int yyparams:2;
		unsigned int yyparam:1;
		unsigned int yylist:2;
		unsigned int yydecls:2;
		unsigned int yytipo:2;
		unsigned int yybase:1;
		unsigned int yyexpr:3;
		unsigned int yyiexpr:6;
		unsigned int yysexpr:3;
		unsigned int yyrexpr:4;
		unsigned int yyarguments:2;
		unsigned int yylval:2;
		unsigned int yylvec:1;
		unsigned int yysassign:2;
		unsigned int yyiptrexpr:1;
		unsigned int yyscmp:1;
		unsigned int yyiassign:1;
		unsigned int yyrassign:1;
	} rule;
};

static short yynts_0[] = { yybloco_NT, yyparams_NT, 0 };
static short yynts_1[] = { yybloco_NT, 0 };
static short yynts_2[] = { yyparam_NT, 0 };
static short yynts_3[] = { yyparams_NT, yyparam_NT, 0 };
static short yynts_4[] = { yylist_NT, yydecls_NT, 0 };
static short yynts_5[] = { yydecls_NT, yyparam_NT, 0 };
static short yynts_6[] = { 0 };
static short yynts_7[] = { yytipo_NT, 0 };
static short yynts_8[] = { yybase_NT, 0 };
static short yynts_9[] = { yylist_NT, yybase_NT, 0 };
static short yynts_10[] = { yyexpr_NT, 0 };
static short yynts_11[] = { yyiexpr_NT, 0 };
static short yynts_12[] = { yysexpr_NT, 0 };
static short yynts_13[] = { yyrexpr_NT, 0 };
static short yynts_14[] = { yyarguments_NT, 0 };
static short yynts_15[] = { yylval_NT, 0 };
static short yynts_16[] = { yylvec_NT, yyexpr_NT, 0 };
static short yynts_17[] = { yyiptrexpr_NT, 0 };
static short yynts_18[] = { yysassign_NT, yylval_NT, 0 };
static short yynts_19[] = { yyscmp_NT, yyscmp_NT, 0 };
static short yynts_20[] = { yyiassign_NT, yylval_NT, 0 };
static short yynts_21[] = { yyiexpr_NT, yyiexpr_NT, 0 };
static short yynts_22[] = { yyrexpr_NT, yyrexpr_NT, 0 };
static short yynts_23[] = { yyrassign_NT, yylval_NT, 0 };
static short yynts_24[] = { yyarguments_NT, yyexpr_NT, 0 };

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
	yynts_6,	/* 9 */
	yynts_6,	/* 10 */
	yynts_6,	/* 11 */
	yynts_8,	/* 12 */
	yynts_9,	/* 13 */
	yynts_10,	/* 14 */
	yynts_11,	/* 15 */
	yynts_12,	/* 16 */
	yynts_13,	/* 17 */
	yynts_14,	/* 18 */
	yynts_6,	/* 19 */
	yynts_6,	/* 20 */
	yynts_6,	/* 21 */
	yynts_15,	/* 22 */
	yynts_16,	/* 23 */
	yynts_6,	/* 24 */
	yynts_6,	/* 25 */
	yynts_12,	/* 26 */
	yynts_17,	/* 27 */
	yynts_18,	/* 28 */
	yynts_14,	/* 29 */
	yynts_6,	/* 30 */
	yynts_12,	/* 31 */
	yynts_19,	/* 32 */
	yynts_19,	/* 33 */
	yynts_19,	/* 34 */
	yynts_19,	/* 35 */
	yynts_19,	/* 36 */
	yynts_19,	/* 37 */
	yynts_19,	/* 38 */
	yynts_19,	/* 39 */
	yynts_11,	/* 40 */
	yynts_6,	/* 41 */
	yynts_20,	/* 42 */
	yynts_21,	/* 43 */
	yynts_21,	/* 44 */
	yynts_21,	/* 45 */
	yynts_21,	/* 46 */
	yynts_21,	/* 47 */
	yynts_21,	/* 48 */
	yynts_21,	/* 49 */
	yynts_21,	/* 50 */
	yynts_21,	/* 51 */
	yynts_21,	/* 52 */
	yynts_21,	/* 53 */
	yynts_21,	/* 54 */
	yynts_21,	/* 55 */
	yynts_11,	/* 56 */
	yynts_11,	/* 57 */
	yynts_11,	/* 58 */
	yynts_13,	/* 59 */
	yynts_15,	/* 60 */
	yynts_15,	/* 61 */
	yynts_15,	/* 62 */
	yynts_15,	/* 63 */
	yynts_6,	/* 64 */
	yynts_14,	/* 65 */
	yynts_6,	/* 66 */
	yynts_22,	/* 67 */
	yynts_22,	/* 68 */
	yynts_22,	/* 69 */
	yynts_22,	/* 70 */
	yynts_22,	/* 71 */
	yynts_22,	/* 72 */
	yynts_6,	/* 73 */
	yynts_23,	/* 74 */
	yynts_13,	/* 75 */
	yynts_6,	/* 76 */
	yynts_22,	/* 77 */
	yynts_13,	/* 78 */
	yynts_22,	/* 79 */
	yynts_22,	/* 80 */
	yynts_22,	/* 81 */
	yynts_11,	/* 82 */
	yynts_6,	/* 83 */
	yynts_14,	/* 84 */
	yynts_6,	/* 85 */
	yynts_10,	/* 86 */
	yynts_24,	/* 87 */
};


static YYCONST char *yystring[] = {
/* 0 */	0,
/* 1 */	"finit: ARGB(bloco,params)",
/* 2 */	"finit: ARGB(bloco,NIL)",
/* 3 */	"params: param",
/* 4 */	"params: NEXT(params,param)",
/* 5 */	"bloco: BLOCK(list,decls)",
/* 6 */	"decls: INSTR(decls,param)",
/* 7 */	"decls: NONE",
/* 8 */	"param: PARAM(tipo,ID)",
/* 9 */	"tipo: INTEGER",
/* 10 */	"tipo: STRING",
/* 11 */	"tipo: NUMBER",
/* 12 */	"list: base",
/* 13 */	"list: LIST(list,base)",
/* 14 */	"base: expr",
/* 15 */	"expr: iexpr",
/* 16 */	"expr: sexpr",
/* 17 */	"expr: rexpr",
/* 18 */	"expr: CALL(ID,arguments)",
/* 19 */	"expr: CALL(ID,VOID)",
/* 20 */	"lval: LOCAL",
/* 21 */	"lval: ID",
/* 22 */	"lvec: lval",
/* 23 */	"lval: INDEX(lvec,expr)",
/* 24 */	"sexpr: STR",
/* 25 */	"sexpr: PTR(LOCAL)",
/* 26 */	"sassign: sexpr",
/* 27 */	"sassign: iptrexpr",
/* 28 */	"sexpr: ATR(sassign,lval)",
/* 29 */	"sexpr: CALL(ID,arguments)",
/* 30 */	"sexpr: CALL(ID,VOID)",
/* 31 */	"scmp: sexpr",
/* 32 */	"iexpr: LT(scmp,scmp)",
/* 33 */	"iexpr: GT(scmp,scmp)",
/* 34 */	"iexpr: GE(scmp,scmp)",
/* 35 */	"iexpr: LE(scmp,scmp)",
/* 36 */	"iexpr: NE(scmp,scmp)",
/* 37 */	"iexpr: LOGIC_EQUAL(scmp,scmp)",
/* 38 */	"iexpr: AND(scmp,scmp)",
/* 39 */	"iexpr: OR(scmp,scmp)",
/* 40 */	"iassign: iexpr",
/* 41 */	"iexpr: INT",
/* 42 */	"iexpr: ATR(iassign,lval)",
/* 43 */	"iexpr: ADD(iexpr,iexpr)",
/* 44 */	"iexpr: SUB(iexpr,iexpr)",
/* 45 */	"iexpr: DIV(iexpr,iexpr)",
/* 46 */	"iexpr: MOD(iexpr,iexpr)",
/* 47 */	"iexpr: MUL(iexpr,iexpr)",
/* 48 */	"iexpr: LT(iexpr,iexpr)",
/* 49 */	"iexpr: GT(iexpr,iexpr)",
/* 50 */	"iexpr: GE(iexpr,iexpr)",
/* 51 */	"iexpr: LE(iexpr,iexpr)",
/* 52 */	"iexpr: NE(iexpr,iexpr)",
/* 53 */	"iexpr: LOGIC_EQUAL(iexpr,iexpr)",
/* 54 */	"iexpr: AND(iexpr,iexpr)",
/* 55 */	"iexpr: OR(iexpr,iexpr)",
/* 56 */	"iexpr: FACTORIAL(iexpr)",
/* 57 */	"iexpr: LOGIC_NOT(iexpr)",
/* 58 */	"iexpr: UMINUS(iexpr)",
/* 59 */	"iexpr: rexpr",
/* 60 */	"iexpr: INCR(lval)",
/* 61 */	"iexpr: DECR(lval)",
/* 62 */	"iexpr: POSINC(lval)",
/* 63 */	"iexpr: POSDEC(lval)",
/* 64 */	"iexpr: PTR(LOCAL)",
/* 65 */	"iexpr: CALL(ID,arguments)",
/* 66 */	"iexpr: CALL(ID,VOID)",
/* 67 */	"iexpr: LT(rexpr,rexpr)",
/* 68 */	"iexpr: GT(rexpr,rexpr)",
/* 69 */	"iexpr: GE(rexpr,rexpr)",
/* 70 */	"iexpr: LE(rexpr,rexpr)",
/* 71 */	"iexpr: LOGIC_EQUAL(rexpr,rexpr)",
/* 72 */	"iexpr: NE(rexpr,rexpr)",
/* 73 */	"iptrexpr: REF(LOCAL)",
/* 74 */	"rexpr: ATR(rassign,lval)",
/* 75 */	"rassign: rexpr",
/* 76 */	"rexpr: REAL",
/* 77 */	"rexpr: ADD(rexpr,rexpr)",
/* 78 */	"rexpr: UMINUS(rexpr)",
/* 79 */	"rexpr: SUB(rexpr,rexpr)",
/* 80 */	"rexpr: MUL(rexpr,rexpr)",
/* 81 */	"rexpr: DIV(rexpr,rexpr)",
/* 82 */	"rexpr: iexpr",
/* 83 */	"rexpr: PTR(LOCAL)",
/* 84 */	"rexpr: CALL(ID,arguments)",
/* 85 */	"rexpr: CALL(ID,VOID)",
/* 86 */	"arguments: ARGS(NIL,expr)",
/* 87 */	"arguments: ARGS(arguments,expr)",
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
};

static short yydecode_params[] = {
	0,
	3,
	4,
};

static short yydecode_param[] = {
	0,
	8,
};

static short yydecode_list[] = {
	0,
	12,
	13,
};

static short yydecode_decls[] = {
	0,
	6,
	7,
};

static short yydecode_tipo[] = {
	0,
	9,
	10,
	11,
};

static short yydecode_base[] = {
	0,
	14,
};

static short yydecode_expr[] = {
	0,
	15,
	16,
	17,
	18,
	19,
};

static short yydecode_iexpr[] = {
	0,
	32,
	33,
	34,
	35,
	36,
	37,
	38,
	39,
	41,
	42,
	43,
	44,
	45,
	46,
	47,
	48,
	49,
	50,
	51,
	52,
	53,
	54,
	55,
	56,
	57,
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
	70,
	71,
	72,
};

static short yydecode_sexpr[] = {
	0,
	24,
	25,
	28,
	29,
	30,
};

static short yydecode_rexpr[] = {
	0,
	74,
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

static short yydecode_arguments[] = {
	0,
	86,
	87,
};

static short yydecode_lval[] = {
	0,
	20,
	21,
	23,
};

static short yydecode_lvec[] = {
	0,
	22,
};

static short yydecode_sassign[] = {
	0,
	26,
	27,
};

static short yydecode_iptrexpr[] = {
	0,
	73,
};

static short yydecode_scmp[] = {
	0,
	31,
};

static short yydecode_iassign[] = {
	0,
	40,
};

static short yydecode_rassign[] = {
	0,
	75,
};

static int yyrule(void *state, int goalnt) {
	if (goalnt < 1 || goalnt > 20)
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
	case yytipo_NT:	return yydecode_tipo[((struct yystate *)state)->rule.yytipo];
	case yybase_NT:	return yydecode_base[((struct yystate *)state)->rule.yybase];
	case yyexpr_NT:	return yydecode_expr[((struct yystate *)state)->rule.yyexpr];
	case yyiexpr_NT:	return yydecode_iexpr[((struct yystate *)state)->rule.yyiexpr];
	case yysexpr_NT:	return yydecode_sexpr[((struct yystate *)state)->rule.yysexpr];
	case yyrexpr_NT:	return yydecode_rexpr[((struct yystate *)state)->rule.yyrexpr];
	case yyarguments_NT:	return yydecode_arguments[((struct yystate *)state)->rule.yyarguments];
	case yylval_NT:	return yydecode_lval[((struct yystate *)state)->rule.yylval];
	case yylvec_NT:	return yydecode_lvec[((struct yystate *)state)->rule.yylvec];
	case yysassign_NT:	return yydecode_sassign[((struct yystate *)state)->rule.yysassign];
	case yyiptrexpr_NT:	return yydecode_iptrexpr[((struct yystate *)state)->rule.yyiptrexpr];
	case yyscmp_NT:	return yydecode_scmp[((struct yystate *)state)->rule.yyscmp];
	case yyiassign_NT:	return yydecode_iassign[((struct yystate *)state)->rule.yyiassign];
	case yyrassign_NT:	return yydecode_rassign[((struct yystate *)state)->rule.yyrassign];
	default:
		PANIC("yyrule", "Bad goal nonterminal", goalnt);
		return 0;
	}
}

static void yyclosure_param(NODEPTR_TYPE, int);
static void yyclosure_base(NODEPTR_TYPE, int);
static void yyclosure_expr(NODEPTR_TYPE, int);
static void yyclosure_iexpr(NODEPTR_TYPE, int);
static void yyclosure_sexpr(NODEPTR_TYPE, int);
static void yyclosure_rexpr(NODEPTR_TYPE, int);
static void yyclosure_lval(NODEPTR_TYPE, int);
static void yyclosure_iptrexpr(NODEPTR_TYPE, int);

static void yyclosure_param(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 3, c + 0, p->cost[yyparams_NT]);
	if (c + 0 < p->cost[yyparams_NT]) {
		p->cost[yyparams_NT] = c + 0;
		p->rule.yyparams = 1;
	}
}

static void yyclosure_base(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 12, c + 0, p->cost[yylist_NT]);
	if (c + 0 < p->cost[yylist_NT]) {
		p->cost[yylist_NT] = c + 0;
		p->rule.yylist = 1;
	}
}

static void yyclosure_expr(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 14, c + 1, p->cost[yybase_NT]);
	if (c + 1 < p->cost[yybase_NT]) {
		p->cost[yybase_NT] = c + 1;
		p->rule.yybase = 1;
		yyclosure_base(a, c + 1);
	}
}

static void yyclosure_iexpr(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 82, c + 1, p->cost[yyrexpr_NT]);
	if (c + 1 < p->cost[yyrexpr_NT]) {
		p->cost[yyrexpr_NT] = c + 1;
		p->rule.yyrexpr = 8;
		yyclosure_rexpr(a, c + 1);
	}
	yytrace(a, 40, c + 1, p->cost[yyiassign_NT]);
	if (c + 1 < p->cost[yyiassign_NT]) {
		p->cost[yyiassign_NT] = c + 1;
		p->rule.yyiassign = 1;
	}
	yytrace(a, 15, c + 0, p->cost[yyexpr_NT]);
	if (c + 0 < p->cost[yyexpr_NT]) {
		p->cost[yyexpr_NT] = c + 0;
		p->rule.yyexpr = 1;
		yyclosure_expr(a, c + 0);
	}
}

static void yyclosure_sexpr(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 31, c + 0, p->cost[yyscmp_NT]);
	if (c + 0 < p->cost[yyscmp_NT]) {
		p->cost[yyscmp_NT] = c + 0;
		p->rule.yyscmp = 1;
	}
	yytrace(a, 26, c + 1, p->cost[yysassign_NT]);
	if (c + 1 < p->cost[yysassign_NT]) {
		p->cost[yysassign_NT] = c + 1;
		p->rule.yysassign = 1;
	}
	yytrace(a, 16, c + 0, p->cost[yyexpr_NT]);
	if (c + 0 < p->cost[yyexpr_NT]) {
		p->cost[yyexpr_NT] = c + 0;
		p->rule.yyexpr = 2;
		yyclosure_expr(a, c + 0);
	}
}

static void yyclosure_rexpr(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 75, c + 1, p->cost[yyrassign_NT]);
	if (c + 1 < p->cost[yyrassign_NT]) {
		p->cost[yyrassign_NT] = c + 1;
		p->rule.yyrassign = 1;
	}
	yytrace(a, 59, c + 3, p->cost[yyiexpr_NT]);
	if (c + 3 < p->cost[yyiexpr_NT]) {
		p->cost[yyiexpr_NT] = c + 3;
		p->rule.yyiexpr = 27;
		yyclosure_iexpr(a, c + 3);
	}
	yytrace(a, 17, c + 0, p->cost[yyexpr_NT]);
	if (c + 0 < p->cost[yyexpr_NT]) {
		p->cost[yyexpr_NT] = c + 0;
		p->rule.yyexpr = 3;
		yyclosure_expr(a, c + 0);
	}
}

static void yyclosure_lval(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 22, c + 1, p->cost[yylvec_NT]);
	if (c + 1 < p->cost[yylvec_NT]) {
		p->cost[yylvec_NT] = c + 1;
		p->rule.yylvec = 1;
	}
}

static void yyclosure_iptrexpr(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 27, c + 1, p->cost[yysassign_NT]);
	if (c + 1 < p->cost[yysassign_NT]) {
		p->cost[yysassign_NT] = c + 1;
		p->rule.yysassign = 2;
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
		0x7fff;
	switch (OP_LABEL(a)) {
	case 33: /* FACTORIAL */
		yylabel(LEFT_CHILD(a),a);
		/* iexpr: FACTORIAL(iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 56, c + 0, p->cost[yyiexpr_NT]);
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
		yytrace(a, 46, c + 0, p->cost[yyiexpr_NT]);
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
		yytrace(a, 38, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 7;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: AND(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 54, c + 0, p->cost[yyiexpr_NT]);
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
		yytrace(a, 47, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 15;
			yyclosure_iexpr(a, c + 0);
		}
		/* rexpr: MUL(rexpr,rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 80, c + 0, p->cost[yyrexpr_NT]);
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
		yytrace(a, 43, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 11;
			yyclosure_iexpr(a, c + 0);
		}
		/* rexpr: ADD(rexpr,rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 77, c + 0, p->cost[yyrexpr_NT]);
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
		yytrace(a, 44, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 12;
			yyclosure_iexpr(a, c + 0);
		}
		/* rexpr: SUB(rexpr,rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 79, c + 0, p->cost[yyrexpr_NT]);
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
		yytrace(a, 45, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 13;
			yyclosure_iexpr(a, c + 0);
		}
		/* rexpr: DIV(rexpr,rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 81, c + 0, p->cost[yyrexpr_NT]);
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
		yytrace(a, 6, c + 0, p->cost[yydecls_NT]);
		if (c + 0 < p->cost[yydecls_NT]) {
			p->cost[yydecls_NT] = c + 0;
			p->rule.yydecls = 1;
		}
		break;
	case 60: /* LT */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: LT(scmp,scmp) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyscmp_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyscmp_NT] + 1;
		yytrace(a, 32, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 1;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: LT(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 48, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 16;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: LT(rexpr,rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 67, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 35;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 61: /* LOGIC_EQUAL */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: LOGIC_EQUAL(scmp,scmp) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyscmp_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyscmp_NT] + 1;
		yytrace(a, 37, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 6;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: LOGIC_EQUAL(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 53, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 21;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: LOGIC_EQUAL(rexpr,rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 71, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 39;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 62: /* GT */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: GT(scmp,scmp) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyscmp_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyscmp_NT] + 1;
		yytrace(a, 33, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 2;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: GT(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 49, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 17;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: GT(rexpr,rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 68, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 36;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 91: /* INDEX */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* lval: INDEX(lvec,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylvec_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 23, c + 0, p->cost[yylval_NT]);
		if (c + 0 < p->cost[yylval_NT]) {
			p->cost[yylval_NT] = c + 0;
			p->rule.yylval = 3;
			yyclosure_lval(a, c + 0);
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
		}
		break;
	case 124: /* OR */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: OR(scmp,scmp) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyscmp_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyscmp_NT] + 1;
		yytrace(a, 39, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 8;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: OR(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 55, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 23;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 126: /* LOGIC_NOT */
		yylabel(LEFT_CHILD(a),a);
		/* iexpr: LOGIC_NOT(iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 57, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 25;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 257: /* INT */
		/* iexpr: INT */
		yytrace(a, 41, 1 + 0, p->cost[yyiexpr_NT]);
		if (1 + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = 1 + 0;
			p->rule.yyiexpr = 9;
			yyclosure_iexpr(a, 1 + 0);
		}
		break;
	case 258: /* REAL */
		/* rexpr: REAL */
		yytrace(a, 76, 1 + 0, p->cost[yyrexpr_NT]);
		if (1 + 0 < p->cost[yyrexpr_NT]) {
			p->cost[yyrexpr_NT] = 1 + 0;
			p->rule.yyrexpr = 2;
			yyclosure_rexpr(a, 1 + 0);
		}
		break;
	case 259: /* ID */
		/* lval: ID */
		yytrace(a, 21, 1 + 0, p->cost[yylval_NT]);
		if (1 + 0 < p->cost[yylval_NT]) {
			p->cost[yylval_NT] = 1 + 0;
			p->rule.yylval = 2;
			yyclosure_lval(a, 1 + 0);
		}
		break;
	case 260: /* STR */
		/* sexpr: STR */
		yytrace(a, 24, 1 + 0, p->cost[yysexpr_NT]);
		if (1 + 0 < p->cost[yysexpr_NT]) {
			p->cost[yysexpr_NT] = 1 + 0;
			p->rule.yysexpr = 1;
			yyclosure_sexpr(a, 1 + 0);
		}
		break;
	case 261: /* DO */
		return;
	case 262: /* WHILE */
		return;
	case 263: /* IF */
		return;
	case 264: /* THEN */
		return;
	case 265: /* FOR */
		return;
	case 266: /* IN */
		return;
	case 267: /* UPTO */
		return;
	case 268: /* DOWNTO */
		return;
	case 269: /* STEP */
		return;
	case 270: /* BREAK */
		return;
	case 271: /* CONTINUE */
		return;
	case 272: /* VOID */
		return;
	case 273: /* INTEGER */
		/* tipo: INTEGER */
		yytrace(a, 9, 0 + 0, p->cost[yytipo_NT]);
		if (0 + 0 < p->cost[yytipo_NT]) {
			p->cost[yytipo_NT] = 0 + 0;
			p->rule.yytipo = 1;
		}
		break;
	case 274: /* STRING */
		/* tipo: STRING */
		yytrace(a, 10, 0 + 0, p->cost[yytipo_NT]);
		if (0 + 0 < p->cost[yytipo_NT]) {
			p->cost[yytipo_NT] = 0 + 0;
			p->rule.yytipo = 2;
		}
		break;
	case 275: /* NUMBER */
		/* tipo: NUMBER */
		yytrace(a, 11, 0 + 0, p->cost[yytipo_NT]);
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
		/* iexpr: INCR(lval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylval_NT] + 1;
		yytrace(a, 60, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 28;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 279: /* DECR */
		yylabel(LEFT_CHILD(a),a);
		/* iexpr: DECR(lval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylval_NT] + 1;
		yytrace(a, 61, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 29;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 280: /* IFX */
		return;
	case 281: /* ELSE */
		return;
	case 282: /* ATR */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* sexpr: ATR(sassign,lval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yysassign_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yylval_NT] + (isStringLval(a));
		yytrace(a, 28, c + 0, p->cost[yysexpr_NT]);
		if (c + 0 < p->cost[yysexpr_NT]) {
			p->cost[yysexpr_NT] = c + 0;
			p->rule.yysexpr = 3;
			yyclosure_sexpr(a, c + 0);
		}
		/* iexpr: ATR(iassign,lval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiassign_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yylval_NT] + (isIntLval(a));
		yytrace(a, 42, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 10;
			yyclosure_iexpr(a, c + 0);
		}
		/* rexpr: ATR(rassign,lval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrassign_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yylval_NT] + (isRealLval(a));
		yytrace(a, 74, c + 0, p->cost[yyrexpr_NT]);
		if (c + 0 < p->cost[yyrexpr_NT]) {
			p->cost[yyrexpr_NT] = c + 0;
			p->rule.yyrexpr = 1;
			yyclosure_rexpr(a, c + 0);
		}
		break;
	case 283: /* NE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: NE(scmp,scmp) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyscmp_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyscmp_NT] + 1;
		yytrace(a, 36, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 5;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: NE(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 52, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 20;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: NE(rexpr,rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 72, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 40;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 284: /* GE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: GE(scmp,scmp) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyscmp_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyscmp_NT] + 1;
		yytrace(a, 34, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 3;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: GE(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 50, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 18;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: GE(rexpr,rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 69, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 37;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 285: /* LE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: LE(scmp,scmp) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyscmp_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyscmp_NT] + 1;
		yytrace(a, 35, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 4;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: LE(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 51, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 19;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: LE(rexpr,rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 70, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 38;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 286: /* UMINUS */
		yylabel(LEFT_CHILD(a),a);
		/* iexpr: UMINUS(iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 58, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 26;
			yyclosure_iexpr(a, c + 0);
		}
		/* rexpr: UMINUS(rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 78, c + 0, p->cost[yyrexpr_NT]);
		if (c + 0 < p->cost[yyrexpr_NT]) {
			p->cost[yyrexpr_NT] = c + 0;
			p->rule.yyrexpr = 4;
			yyclosure_rexpr(a, c + 0);
		}
		break;
	case 287: /* NOT */
		return;
	case 288: /* REF */
		yylabel(LEFT_CHILD(a),a);
		if (	/* iptrexpr: REF(LOCAL) */
			OP_LABEL(LEFT_CHILD(a)) == 289 /* LOCAL */
		) {
			c = (isIntPointer(a));
			yytrace(a, 73, c + 0, p->cost[yyiptrexpr_NT]);
			if (c + 0 < p->cost[yyiptrexpr_NT]) {
				p->cost[yyiptrexpr_NT] = c + 0;
				p->rule.yyiptrexpr = 1;
				yyclosure_iptrexpr(a, c + 0);
			}
		}
		break;
	case 289: /* LOCAL */
		/* lval: LOCAL */
		yytrace(a, 20, 1 + 0, p->cost[yylval_NT]);
		if (1 + 0 < p->cost[yylval_NT]) {
			p->cost[yylval_NT] = 1 + 0;
			p->rule.yylval = 1;
			yyclosure_lval(a, 1 + 0);
		}
		break;
	case 290: /* POSINC */
		yylabel(LEFT_CHILD(a),a);
		/* iexpr: POSINC(lval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylval_NT] + 1;
		yytrace(a, 62, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 30;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 291: /* POSDEC */
		yylabel(LEFT_CHILD(a),a);
		/* iexpr: POSDEC(lval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylval_NT] + 1;
		yytrace(a, 63, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 31;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 292: /* PTR */
		yylabel(LEFT_CHILD(a),a);
		if (	/* sexpr: PTR(LOCAL) */
			OP_LABEL(LEFT_CHILD(a)) == 289 /* LOCAL */
		) {
			c = (isString(a));
			yytrace(a, 25, c + 0, p->cost[yysexpr_NT]);
			if (c + 0 < p->cost[yysexpr_NT]) {
				p->cost[yysexpr_NT] = c + 0;
				p->rule.yysexpr = 2;
				yyclosure_sexpr(a, c + 0);
			}
		}
		if (	/* iexpr: PTR(LOCAL) */
			OP_LABEL(LEFT_CHILD(a)) == 289 /* LOCAL */
		) {
			c = (isInt(a));
			yytrace(a, 64, c + 0, p->cost[yyiexpr_NT]);
			if (c + 0 < p->cost[yyiexpr_NT]) {
				p->cost[yyiexpr_NT] = c + 0;
				p->rule.yyiexpr = 32;
				yyclosure_iexpr(a, c + 0);
			}
		}
		if (	/* rexpr: PTR(LOCAL) */
			OP_LABEL(LEFT_CHILD(a)) == 289 /* LOCAL */
		) {
			c = (isReal(a));
			yytrace(a, 83, c + 0, p->cost[yyrexpr_NT]);
			if (c + 0 < p->cost[yyrexpr_NT]) {
				p->cost[yyrexpr_NT] = c + 0;
				p->rule.yyrexpr = 9;
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
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyarguments_NT] + 1;
			yytrace(a, 18, c + 0, p->cost[yyexpr_NT]);
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
			c = 1;
			yytrace(a, 19, c + 0, p->cost[yyexpr_NT]);
			if (c + 0 < p->cost[yyexpr_NT]) {
				p->cost[yyexpr_NT] = c + 0;
				p->rule.yyexpr = 5;
				yyclosure_expr(a, c + 0);
			}
		}
		if (	/* sexpr: CALL(ID,arguments) */
			OP_LABEL(LEFT_CHILD(a)) == 259 /* ID */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyarguments_NT] + (isStringFunction(a));
			yytrace(a, 29, c + 0, p->cost[yysexpr_NT]);
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
			yytrace(a, 30, c + 0, p->cost[yysexpr_NT]);
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
			yytrace(a, 65, c + 0, p->cost[yyiexpr_NT]);
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
			yytrace(a, 66, c + 0, p->cost[yyiexpr_NT]);
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
			yytrace(a, 84, c + 0, p->cost[yyrexpr_NT]);
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
			yytrace(a, 85, c + 0, p->cost[yyrexpr_NT]);
			if (c + 0 < p->cost[yyrexpr_NT]) {
				p->cost[yyrexpr_NT] = c + 0;
				p->rule.yyrexpr = 11;
				yyclosure_rexpr(a, c + 0);
			}
		}
		break;
	case 294: /* START */
		return;
	case 295: /* PARAM */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* param: PARAM(tipo,ID) */
			OP_LABEL(RIGHT_CHILD(a)) == 259 /* ID */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yytipo_NT] + 0;
			yytrace(a, 8, c + 0, p->cost[yyparam_NT]);
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
		yytrace(a, 13, c + 0, p->cost[yylist_NT]);
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
			yytrace(a, 86, c + 0, p->cost[yyarguments_NT]);
			if (c + 0 < p->cost[yyarguments_NT]) {
				p->cost[yyarguments_NT] = c + 0;
				p->rule.yyarguments = 1;
			}
		}
		/* arguments: ARGS(arguments,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyarguments_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 0;
		yytrace(a, 87, c + 0, p->cost[yyarguments_NT]);
		if (c + 0 < p->cost[yyarguments_NT]) {
			p->cost[yyarguments_NT] = c + 0;
			p->rule.yyarguments = 2;
		}
		break;
	case 299: /* NONE */
		/* decls: NONE */
		yytrace(a, 7, 0 + 0, p->cost[yydecls_NT]);
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
	case 87: /* arguments: ARGS(arguments,expr) */
	case 81: /* rexpr: DIV(rexpr,rexpr) */
	case 80: /* rexpr: MUL(rexpr,rexpr) */
	case 79: /* rexpr: SUB(rexpr,rexpr) */
	case 77: /* rexpr: ADD(rexpr,rexpr) */
	case 74: /* rexpr: ATR(rassign,lval) */
	case 72: /* iexpr: NE(rexpr,rexpr) */
	case 71: /* iexpr: LOGIC_EQUAL(rexpr,rexpr) */
	case 70: /* iexpr: LE(rexpr,rexpr) */
	case 69: /* iexpr: GE(rexpr,rexpr) */
	case 68: /* iexpr: GT(rexpr,rexpr) */
	case 67: /* iexpr: LT(rexpr,rexpr) */
	case 55: /* iexpr: OR(iexpr,iexpr) */
	case 54: /* iexpr: AND(iexpr,iexpr) */
	case 53: /* iexpr: LOGIC_EQUAL(iexpr,iexpr) */
	case 52: /* iexpr: NE(iexpr,iexpr) */
	case 51: /* iexpr: LE(iexpr,iexpr) */
	case 50: /* iexpr: GE(iexpr,iexpr) */
	case 49: /* iexpr: GT(iexpr,iexpr) */
	case 48: /* iexpr: LT(iexpr,iexpr) */
	case 47: /* iexpr: MUL(iexpr,iexpr) */
	case 46: /* iexpr: MOD(iexpr,iexpr) */
	case 45: /* iexpr: DIV(iexpr,iexpr) */
	case 44: /* iexpr: SUB(iexpr,iexpr) */
	case 43: /* iexpr: ADD(iexpr,iexpr) */
	case 42: /* iexpr: ATR(iassign,lval) */
	case 39: /* iexpr: OR(scmp,scmp) */
	case 38: /* iexpr: AND(scmp,scmp) */
	case 37: /* iexpr: LOGIC_EQUAL(scmp,scmp) */
	case 36: /* iexpr: NE(scmp,scmp) */
	case 35: /* iexpr: LE(scmp,scmp) */
	case 34: /* iexpr: GE(scmp,scmp) */
	case 33: /* iexpr: GT(scmp,scmp) */
	case 32: /* iexpr: LT(scmp,scmp) */
	case 28: /* sexpr: ATR(sassign,lval) */
	case 23: /* lval: INDEX(lvec,expr) */
	case 13: /* list: LIST(list,base) */
	case 6: /* decls: INSTR(decls,param) */
	case 5: /* bloco: BLOCK(list,decls) */
	case 4: /* params: NEXT(params,param) */
	case 1: /* finit: ARGB(bloco,params) */
		kids[0] = LEFT_CHILD(p);
		kids[1] = RIGHT_CHILD(p);
		break;
	case 78: /* rexpr: UMINUS(rexpr) */
	case 63: /* iexpr: POSDEC(lval) */
	case 62: /* iexpr: POSINC(lval) */
	case 61: /* iexpr: DECR(lval) */
	case 60: /* iexpr: INCR(lval) */
	case 58: /* iexpr: UMINUS(iexpr) */
	case 57: /* iexpr: LOGIC_NOT(iexpr) */
	case 56: /* iexpr: FACTORIAL(iexpr) */
	case 8: /* param: PARAM(tipo,ID) */
	case 2: /* finit: ARGB(bloco,NIL) */
		kids[0] = LEFT_CHILD(p);
		break;
	case 82: /* rexpr: iexpr */
	case 75: /* rassign: rexpr */
	case 59: /* iexpr: rexpr */
	case 40: /* iassign: iexpr */
	case 31: /* scmp: sexpr */
	case 27: /* sassign: iptrexpr */
	case 26: /* sassign: sexpr */
	case 22: /* lvec: lval */
	case 17: /* expr: rexpr */
	case 16: /* expr: sexpr */
	case 15: /* expr: iexpr */
	case 14: /* base: expr */
	case 12: /* list: base */
	case 3: /* params: param */
		kids[0] = p;
		break;
	case 85: /* rexpr: CALL(ID,VOID) */
	case 83: /* rexpr: PTR(LOCAL) */
	case 76: /* rexpr: REAL */
	case 73: /* iptrexpr: REF(LOCAL) */
	case 66: /* iexpr: CALL(ID,VOID) */
	case 64: /* iexpr: PTR(LOCAL) */
	case 41: /* iexpr: INT */
	case 30: /* sexpr: CALL(ID,VOID) */
	case 25: /* sexpr: PTR(LOCAL) */
	case 24: /* sexpr: STR */
	case 21: /* lval: ID */
	case 20: /* lval: LOCAL */
	case 19: /* expr: CALL(ID,VOID) */
	case 11: /* tipo: NUMBER */
	case 10: /* tipo: STRING */
	case 9: /* tipo: INTEGER */
	case 7: /* decls: NONE */
		break;
	case 86: /* arguments: ARGS(NIL,expr) */
	case 84: /* rexpr: CALL(ID,arguments) */
	case 65: /* iexpr: CALL(ID,arguments) */
	case 29: /* sexpr: CALL(ID,arguments) */
	case 18: /* expr: CALL(ID,arguments) */
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
  NODEPTR_TYPE kids[2];
  int i;

  for (yykids(p, eruleno, kids), i = 0; nts[i]; i++)
    yyreduce(kids[i], nts[i]);

  switch(eruleno) {
	case 1: /* finit: ARGB(bloco,params) */
#line 70 "diy.brg"
{if (functionReturnType == 1 || functionReturnType == 2)fprintf(outfp, pfLOCAL pfLOAD pfPOP, 8); else if(functionReturnType == 3) fprintf(outfp, pfLOCAL pfLOAD2 pfDPOP, 8);}
		break;
	case 2: /* finit: ARGB(bloco,NIL) */
#line 71 "diy.brg"
{if (functionReturnType == 1 || functionReturnType == 2) fprintf(outfp, pfLOCAL pfLOAD pfPOP, 8); else if(functionReturnType == 3) fprintf(outfp, pfLOCAL pfLOAD2 pfDPOP, 8);}
		break;
	case 3: /* params: param */
#line 73 "diy.brg"

		break;
	case 4: /* params: NEXT(params,param) */
#line 74 "diy.brg"

		break;
	case 5: /* bloco: BLOCK(list,decls) */
#line 76 "diy.brg"

		break;
	case 6: /* decls: INSTR(decls,param) */
#line 78 "diy.brg"

		break;
	case 7: /* decls: NONE */
#line 79 "diy.brg"

		break;
	case 8: /* param: PARAM(tipo,ID) */
#line 81 "diy.brg"

		break;
	case 9: /* tipo: INTEGER */
#line 83 "diy.brg"

		break;
	case 10: /* tipo: STRING */
#line 84 "diy.brg"

		break;
	case 11: /* tipo: NUMBER */
#line 85 "diy.brg"

		break;
	case 12: /* list: base */
#line 88 "diy.brg"

		break;
	case 13: /* list: LIST(list,base) */
#line 89 "diy.brg"

		break;
	case 14: /* base: expr */
#line 92 "diy.brg"
{fprintf(outfp, pfTRASH, (int)p->place); }
		break;
	case 15: /* expr: iexpr */
#line 97 "diy.brg"
{p->place = 4;}
		break;
	case 16: /* expr: sexpr */
#line 98 "diy.brg"
{p->place = 4;}
		break;
	case 17: /* expr: rexpr */
#line 99 "diy.brg"
{p->place = 8;}
		break;
	case 18: /* expr: CALL(ID,arguments) */
#line 102 "diy.brg"
{fprintf(outfp, pfCALL pfTRASH pfPUSH, mkfunc(LEFT_CHILD(p)->value.s), (int)((RIGHT_CHILD(p)->place))); p->place = IDfind(LEFT_CHILD(p)->value.s, NULL) == 3 ? 8: 4;}
		break;
	case 19: /* expr: CALL(ID,VOID) */
#line 104 "diy.brg"
{fprintf(outfp, pfCALL pfPUSH, mkfunc(LEFT_CHILD(p)->value.s)); p->place = IDfind(LEFT_CHILD(p)->value.s, NULL) == 3 ? 8: 4;}
		break;
	case 20: /* lval: LOCAL */
#line 108 "diy.brg"
{fprintf(outfp, pfLOCAL, p->value.i * (pfWORD/4));}
		break;
	case 21: /* lval: ID */
#line 109 "diy.brg"
{fprintf(outfp, pfADDR, p->value.s);}
		break;
	case 22: /* lvec: lval */
#line 111 "diy.brg"
{fprintf(outfp, pfLOAD);}
		break;
	case 23: /* lval: INDEX(lvec,expr) */
#line 112 "diy.brg"
{ fprintf(outfp, pfIMM pfMUL pfADD,
							LEFT_CHILD(p)->info == 13 ? 8 : 4);}
		break;
	case 24: /* sexpr: STR */
#line 116 "diy.brg"
{	lbl++; fprintf(outfp, pfRODATA pfALIGN pfLABEL, mklbl(lbl));
					outstr(p->value.s); fprintf(outfp, pfTEXT pfADDR, mklbl(lbl));}
		break;
	case 25: /* sexpr: PTR(LOCAL) */
#line 118 "diy.brg"
{fprintf(outfp, pfLOCV, LEFT_CHILD(p)->value.i);}
		break;
	case 26: /* sassign: sexpr */
#line 119 "diy.brg"
{fprintf(outfp, pfDUP);}
		break;
	case 27: /* sassign: iptrexpr */
#line 120 "diy.brg"
{fprintf(outfp, pfDUP);}
		break;
	case 28: /* sexpr: ATR(sassign,lval) */
#line 122 "diy.brg"
{fprintf(outfp, pfSTORE);}
		break;
	case 29: /* sexpr: CALL(ID,arguments) */
#line 124 "diy.brg"
{fprintf(outfp, pfCALL pfTRASH pfPUSH, mkfunc(LEFT_CHILD(p)->value.s), (int)((RIGHT_CHILD(p)->place))); p->place = IDfind(LEFT_CHILD(p)->value.s, NULL) == 3 ? 8: 4;}
		break;
	case 30: /* sexpr: CALL(ID,VOID) */
#line 126 "diy.brg"
{fprintf(outfp, pfCALL pfPUSH, mkfunc(LEFT_CHILD(p)->value.s)); p->place = IDfind(LEFT_CHILD(p)->value.s, NULL) == 3 ? 8: 4;}
		break;
	case 31: /* scmp: sexpr */
#line 128 "diy.brg"
{fprintf(outfp, pfLOAD);}
		break;
	case 32: /* iexpr: LT(scmp,scmp) */
#line 130 "diy.brg"
{fprintf(outfp, pfLT);}
		break;
	case 33: /* iexpr: GT(scmp,scmp) */
#line 131 "diy.brg"
{fprintf(outfp, pfGT);}
		break;
	case 34: /* iexpr: GE(scmp,scmp) */
#line 132 "diy.brg"
{fprintf(outfp, pfGE);}
		break;
	case 35: /* iexpr: LE(scmp,scmp) */
#line 133 "diy.brg"
{fprintf(outfp, pfLE);}
		break;
	case 36: /* iexpr: NE(scmp,scmp) */
#line 134 "diy.brg"
{fprintf(outfp, pfNE);}
		break;
	case 37: /* iexpr: LOGIC_EQUAL(scmp,scmp) */
#line 135 "diy.brg"
{fprintf(outfp, pfEQ);}
		break;
	case 38: /* iexpr: AND(scmp,scmp) */
#line 136 "diy.brg"
{fprintf(outfp, pfAND);}
		break;
	case 39: /* iexpr: OR(scmp,scmp) */
#line 137 "diy.brg"
{fprintf(outfp, pfOR);}
		break;
	case 40: /* iassign: iexpr */
#line 142 "diy.brg"
{fprintf(outfp, pfDUP);}
		break;
	case 41: /* iexpr: INT */
#line 143 "diy.brg"
{fprintf(outfp, pfIMM, p->value.i);}
		break;
	case 42: /* iexpr: ATR(iassign,lval) */
#line 144 "diy.brg"
{fprintf(outfp, pfSTORE);}
		break;
	case 43: /* iexpr: ADD(iexpr,iexpr) */
#line 145 "diy.brg"
{fprintf(outfp, pfADD);}
		break;
	case 44: /* iexpr: SUB(iexpr,iexpr) */
#line 146 "diy.brg"
{fprintf(outfp, pfSUB);}
		break;
	case 45: /* iexpr: DIV(iexpr,iexpr) */
#line 147 "diy.brg"
{fprintf(outfp, pfDIV);}
		break;
	case 46: /* iexpr: MOD(iexpr,iexpr) */
#line 148 "diy.brg"
{fprintf(outfp, pfMOD);}
		break;
	case 47: /* iexpr: MUL(iexpr,iexpr) */
#line 149 "diy.brg"
{fprintf(outfp, pfMUL);}
		break;
	case 48: /* iexpr: LT(iexpr,iexpr) */
#line 150 "diy.brg"
{fprintf(outfp, pfLT);}
		break;
	case 49: /* iexpr: GT(iexpr,iexpr) */
#line 151 "diy.brg"
{fprintf(outfp, pfGT);}
		break;
	case 50: /* iexpr: GE(iexpr,iexpr) */
#line 152 "diy.brg"
{fprintf(outfp, pfGE);}
		break;
	case 51: /* iexpr: LE(iexpr,iexpr) */
#line 153 "diy.brg"
{fprintf(outfp, pfLE);}
		break;
	case 52: /* iexpr: NE(iexpr,iexpr) */
#line 154 "diy.brg"
{fprintf(outfp, pfNE);}
		break;
	case 53: /* iexpr: LOGIC_EQUAL(iexpr,iexpr) */
#line 155 "diy.brg"
{fprintf(outfp, pfEQ);}
		break;
	case 54: /* iexpr: AND(iexpr,iexpr) */
#line 156 "diy.brg"
{fprintf(outfp, pfAND);}
		break;
	case 55: /* iexpr: OR(iexpr,iexpr) */
#line 157 "diy.brg"
{fprintf(outfp, pfOR);}
		break;
	case 56: /* iexpr: FACTORIAL(iexpr) */
#line 158 "diy.brg"
{/*fprintf(outfp)*/ /*FIXME*/}
		break;
	case 57: /* iexpr: LOGIC_NOT(iexpr) */
#line 159 "diy.brg"
{fprintf(outfp, pfNOT);}
		break;
	case 58: /* iexpr: UMINUS(iexpr) */
#line 160 "diy.brg"
{fprintf(outfp, pfNEG);}
		break;
	case 59: /* iexpr: rexpr */
#line 164 "diy.brg"
{fprintf(outfp, pfD2I);}
		break;
	case 60: /* iexpr: INCR(lval) */
#line 167 "diy.brg"
{fprintf(outfp, pfDUP pfINCR pfLOAD, 1);}
		break;
	case 61: /* iexpr: DECR(lval) */
#line 168 "diy.brg"
{fprintf(outfp, pfDUP pfDECR pfLOAD, 1);}
		break;
	case 62: /* iexpr: POSINC(lval) */
#line 169 "diy.brg"
{fprintf(outfp, pfDUP pfLOAD pfSWAP pfINCR, 1);}
		break;
	case 63: /* iexpr: POSDEC(lval) */
#line 170 "diy.brg"
{fprintf(outfp, pfDUP pfLOAD pfSWAP pfDECR, 1);}
		break;
	case 64: /* iexpr: PTR(LOCAL) */
#line 173 "diy.brg"
{fprintf(outfp, pfLOCV, LEFT_CHILD(p)->value.i);}
		break;
	case 65: /* iexpr: CALL(ID,arguments) */
#line 177 "diy.brg"
{fprintf(outfp, pfCALL pfTRASH pfPUSH, mkfunc(LEFT_CHILD(p)->value.s), (int)((RIGHT_CHILD(p)->place))); p->place = IDfind(LEFT_CHILD(p)->value.s, NULL) == 3 ? 8: 4;}
		break;
	case 66: /* iexpr: CALL(ID,VOID) */
#line 179 "diy.brg"
{fprintf(outfp, pfCALL pfPUSH, mkfunc(LEFT_CHILD(p)->value.s)); p->place = IDfind(LEFT_CHILD(p)->value.s, NULL) == 3 ? 8: 4;}
		break;
	case 67: /* iexpr: LT(rexpr,rexpr) */
#line 184 "diy.brg"
{fprintf(outfp, pfDCMP pfIMM pfLT, 0);}
		break;
	case 68: /* iexpr: GT(rexpr,rexpr) */
#line 185 "diy.brg"
{fprintf(outfp, pfDCMP pfIMM pfGT, 0);}
		break;
	case 69: /* iexpr: GE(rexpr,rexpr) */
#line 186 "diy.brg"
{fprintf(outfp, pfDCMP pfIMM pfGE, 0);}
		break;
	case 70: /* iexpr: LE(rexpr,rexpr) */
#line 187 "diy.brg"
{fprintf(outfp, pfDCMP pfIMM pfLE, 0);}
		break;
	case 71: /* iexpr: LOGIC_EQUAL(rexpr,rexpr) */
#line 188 "diy.brg"
{fprintf(outfp, pfDCMP pfIMM pfEQ, 0);}
		break;
	case 72: /* iexpr: NE(rexpr,rexpr) */
#line 189 "diy.brg"
{fprintf(outfp, pfDCMP pfIMM pfNE, 0);}
		break;
	case 73: /* iptrexpr: REF(LOCAL) */
#line 192 "diy.brg"
{fprintf(outfp, pfLOCAL, LEFT_CHILD(p)->value.i);}
		break;
	case 74: /* rexpr: ATR(rassign,lval) */
#line 196 "diy.brg"
{fprintf(outfp, pfSTORE2);}
		break;
	case 75: /* rassign: rexpr */
#line 197 "diy.brg"
{fprintf(outfp, pfDUP2);}
		break;
	case 76: /* rexpr: REAL */
#line 198 "diy.brg"
{lbl++; fprintf(outfp, pfRODATA pfALIGN pfLABEL pfDOUBLE, mklbl(lbl), p->value.r);
					fprintf(outfp, pfTEXT pfADDR pfLOAD2, mklbl(lbl));}
		break;
	case 77: /* rexpr: ADD(rexpr,rexpr) */
#line 200 "diy.brg"
{fprintf(outfp, pfDADD);}
		break;
	case 78: /* rexpr: UMINUS(rexpr) */
#line 201 "diy.brg"
{fprintf(outfp, pfDNEG);}
		break;
	case 79: /* rexpr: SUB(rexpr,rexpr) */
#line 202 "diy.brg"
{fprintf(outfp, pfDSUB);}
		break;
	case 80: /* rexpr: MUL(rexpr,rexpr) */
#line 203 "diy.brg"
{fprintf(outfp, pfDMUL);}
		break;
	case 81: /* rexpr: DIV(rexpr,rexpr) */
#line 204 "diy.brg"
{fprintf(outfp, pfDDIV);}
		break;
	case 82: /* rexpr: iexpr */
#line 205 "diy.brg"
{fprintf(outfp, pfI2D);}
		break;
	case 83: /* rexpr: PTR(LOCAL) */
#line 208 "diy.brg"
{fprintf(outfp, pfLOCAL pfLOAD2, LEFT_CHILD(p)->value.i);}
		break;
	case 84: /* rexpr: CALL(ID,arguments) */
#line 212 "diy.brg"
{fprintf(outfp, pfCALL pfTRASH pfDPUSH, mkfunc(LEFT_CHILD(p)->value.s), (int)((RIGHT_CHILD(p)->place))); p->place = IDfind(LEFT_CHILD(p)->value.s, NULL) == 3 ? 8: 4;}
		break;
	case 85: /* rexpr: CALL(ID,VOID) */
#line 214 "diy.brg"
{fprintf(outfp, pfCALL pfDPUSH, mkfunc(LEFT_CHILD(p)->value.s)); p->place = IDfind(LEFT_CHILD(p)->value.s, NULL) == 3 ? 8: 4;}
		break;
	case 86: /* arguments: ARGS(NIL,expr) */
#line 217 "diy.brg"
{p->place = RIGHT_CHILD(p)->place; }
		break;
	case 87: /* arguments: ARGS(arguments,expr) */
#line 218 "diy.brg"
{p->place = LEFT_CHILD(p)->place + RIGHT_CHILD(p)->place;}
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


#line 221 "diy.brg"

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
  		fprintf(outfp, pfTEXT pfALIGN pfGLOBL pfLABEL pfENTER, mkfunc(name), pfFUNC, mkfunc(name), - localPos * (pfWORD/4));
  		functionReturnType = type->value.i;
  		//printNode(body, stdout, yynames);
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

    //if (pub && !cnst) {
    //	variable is extern
    //	fprintf(outfp, pfEXTRN, name);
    //if(!pub && !cnst) {

    //}
    //}
    //}

    return;
  }
  if (value->attrib = INT && value->value.i == 0 && type->value.i > 10)
  	return; /* NULL pointer */
  if ((typ = value->info) % 10 > 5) typ -= 5;
  if (type->value.i != typ)
    yyerror("wrong types in initialization");
}
