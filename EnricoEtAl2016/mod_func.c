#include <stdio.h>
#include "hocdec.h"
#define IMPORT extern __declspec(dllimport)
IMPORT int nrnmpi_myid, nrn_nobanner_;

extern void _IhDA_reg();
extern void _cabal_reg();
extern void _cachan_reg();
extern void _capump_reg();
extern void _dop_reg();
extern void _hh3_reg();
extern void _kca_reg();
extern void _nabalan_reg();
extern void _netstimd_reg();
extern void _newleak_reg();
extern void _nmdanet_reg();
extern void _pump_reg();

void modl_reg(){
	//nrn_mswindll_stdio(stdin, stdout, stderr);
    if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
	fprintf(stderr, "Additional mechanisms from files\n");

fprintf(stderr," IhDA.mod");
fprintf(stderr," cabal.mod");
fprintf(stderr," cachan.mod");
fprintf(stderr," capump.mod");
fprintf(stderr," dop.mod");
fprintf(stderr," hh3.mod");
fprintf(stderr," kca.mod");
fprintf(stderr," nabalan.mod");
fprintf(stderr," netstimd.mod");
fprintf(stderr," newleak.mod");
fprintf(stderr," nmdanet.mod");
fprintf(stderr," pump.mod");
fprintf(stderr, "\n");
    }
_IhDA_reg();
_cabal_reg();
_cachan_reg();
_capump_reg();
_dop_reg();
_hh3_reg();
_kca_reg();
_nabalan_reg();
_netstimd_reg();
_newleak_reg();
_nmdanet_reg();
_pump_reg();
}
