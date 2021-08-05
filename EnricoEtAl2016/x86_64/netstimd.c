/* Created by Language version: 7.7.0 */
/* NOT VECTORIZED */
#define NRN_VECTORIZED 0
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "scoplib_ansi.h"
#undef PI
#define nil 0
#include "md1redef.h"
#include "section.h"
#include "nrniv_mf.h"
#include "md2redef.h"
 
#if METHOD3
extern int _method3;
#endif

#if !NRNGPU
#undef exp
#define exp hoc_Exp
extern double hoc_Exp(double);
#endif
 
#define nrn_init _nrn_init__NetStimd
#define _nrn_initial _nrn_initial__NetStimd
#define nrn_cur _nrn_cur__NetStimd
#define _nrn_current _nrn_current__NetStimd
#define nrn_jacob _nrn_jacob__NetStimd
#define nrn_state _nrn_state__NetStimd
#define _net_receive _net_receive__NetStimd 
#define event_time event_time__NetStimd 
#define init_sequence init_sequence__NetStimd 
#define seed seed__NetStimd 
 
#define _threadargscomma_ /**/
#define _threadargsprotocomma_ /**/
#define _threadargs_ /**/
#define _threadargsproto_ /**/
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 static double *_p; static Datum *_ppvar;
 
#define t nrn_threads->_t
#define dt nrn_threads->_dt
#define interv1 _p[0]
#define interv2 _p[1]
#define number _p[2]
#define start _p[3]
#define noise _p[4]
#define swu _p[5]
#define swd _p[6]
#define y _p[7]
#define event _p[8]
#define on _p[9]
#define end _p[10]
#define _tsav _p[11]
#define _nd_area  *_ppvar[0]._pval
 
#if MAC
#if !defined(v)
#define v _mlhv
#endif
#if !defined(h)
#define h _mlhh
#endif
#endif
 
#if defined(__cplusplus)
extern "C" {
#endif
 static int hoc_nrnpointerindex =  -1;
 /* external NEURON variables */
 /* declaration of user functions */
 static double _hoc_event_time();
 static double _hoc_init_sequence();
 static double _hoc_invl();
 static double _hoc_seed();
 static int _mechtype;
extern void _nrn_cacheloop_reg(int, int);
extern void hoc_register_prop_size(int, int, int);
extern void hoc_register_limits(int, HocParmLimits*);
extern void hoc_register_units(int, HocParmUnits*);
extern void nrn_promote(Prop*, int, int);
extern Memb_func* memb_func;
 
#define NMODL_TEXT 1
#if NMODL_TEXT
static const char* nmodl_file_text;
static const char* nmodl_filename;
extern void hoc_reg_nmodl_text(int, const char*);
extern void hoc_reg_nmodl_filename(int, const char*);
#endif

 extern Prop* nrn_point_prop_;
 static int _pointtype;
 static void* _hoc_create_pnt(_ho) Object* _ho; { void* create_point_process();
 return create_point_process(_pointtype, _ho);
}
 static void _hoc_destroy_pnt();
 static double _hoc_loc_pnt(_vptr) void* _vptr; {double loc_point_process();
 return loc_point_process(_pointtype, _vptr);
}
 static double _hoc_has_loc(_vptr) void* _vptr; {double has_loc_point();
 return has_loc_point(_vptr);
}
 static double _hoc_get_loc_pnt(_vptr)void* _vptr; {
 double get_loc_point_process(); return (get_loc_point_process(_vptr));
}
 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _p = _prop->param; _ppvar = _prop->dparam;
 }
 static void _hoc_setdata(void* _vptr) { Prop* _prop;
 _prop = ((Point_process*)_vptr)->_prop;
   _setdata(_prop);
 }
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 0,0
};
 static Member_func _member_func[] = {
 "loc", _hoc_loc_pnt,
 "has_loc", _hoc_has_loc,
 "get_loc", _hoc_get_loc_pnt,
 "event_time", _hoc_event_time,
 "init_sequence", _hoc_init_sequence,
 "invl", _hoc_invl,
 "seed", _hoc_seed,
 0, 0
};
#define invl invl_NetStimd
 extern double invl( double );
 /* declare global and static user variables */
#define flag flag_NetStimd
 double flag = 0;
#define interval interval_NetStimd
 double interval = 10;
#define sw sw_NetStimd
 double sw = 2000;
#define tpre tpre_NetStimd
 double tpre = 0;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 "interv2", 1e-09, 1e+09,
 "interv1", 1e-09, 1e+09,
 "noise", 0, 1,
 "number", 0, 1e+09,
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "interv1", "ms",
 "interv2", "ms",
 "start", "ms",
 0,0
};
 static double v = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "interval_NetStimd", &interval_NetStimd,
 "sw_NetStimd", &sw_NetStimd,
 "flag_NetStimd", &flag_NetStimd,
 "tpre_NetStimd", &tpre_NetStimd,
 0,0
};
 static DoubVec hoc_vdoub[] = {
 0,0,0
};
 static double _sav_indep;
 static void nrn_alloc(Prop*);
static void  nrn_init(_NrnThread*, _Memb_list*, int);
static void nrn_state(_NrnThread*, _Memb_list*, int);
 static void _hoc_destroy_pnt(_vptr) void* _vptr; {
   destroy_point_process(_vptr);
}
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"NetStimd",
 "interv1",
 "interv2",
 "number",
 "start",
 "noise",
 "swu",
 "swd",
 0,
 "y",
 0,
 0,
 0};
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
  if (nrn_point_prop_) {
	_prop->_alloc_seq = nrn_point_prop_->_alloc_seq;
	_p = nrn_point_prop_->param;
	_ppvar = nrn_point_prop_->dparam;
 }else{
 	_p = nrn_prop_data_alloc(_mechtype, 12, _prop);
 	/*initialize range parameters*/
 	interv1 = 10;
 	interv2 = 10;
 	number = 10;
 	start = 50;
 	noise = 0;
 	swu = 400;
 	swd = 2000;
  }
 	_prop->param = _p;
 	_prop->param_size = 12;
  if (!nrn_point_prop_) {
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 3, _prop);
  }
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 
}
 static void _initlists();
 
#define _tqitem &(_ppvar[2]._pvoid)
 static void _net_receive(Point_process*, double*, double);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _netstimd_reg() {
	int _vectorized = 0;
  _initlists();
 	_pointtype = point_register_mech(_mechanism,
	 nrn_alloc,(void*)0, (void*)0, (void*)0, nrn_init,
	 hoc_nrnpointerindex, 0,
	 _hoc_create_pnt, _hoc_destroy_pnt, _member_func);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 12, 3);
  hoc_register_dparam_semantics(_mechtype, 0, "area");
  hoc_register_dparam_semantics(_mechtype, 1, "pntproc");
  hoc_register_dparam_semantics(_mechtype, 2, "netsend");
 add_nrn_has_net_event(_mechtype);
 pnt_receive[_mechtype] = _net_receive;
 pnt_receive_size[_mechtype] = 1;
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 NetStimd /mnt/c/Users/lawre/OneDrive/Documents/burise/VTA-neurons-opiates-withdrawal/EnricoEtAl2016/netstimd.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int event_time();
static int init_sequence(double);
static int seed(double);
 
static int  seed (  double _lx ) {
   set_seed ( _lx ) ;
    return 0; }
 
static double _hoc_seed(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 seed (  *getarg(1) );
 return(_r);
}
 
static int  init_sequence (  double _lt ) {
   if ( number > 0.0 ) {
     on = 1.0 ;
     event = _lt ;
     end = _lt + 1e-6 + invl ( _threadargscomma_ interv1 ) * ( number - 1.0 ) ;
     }
    return 0; }
 
static double _hoc_init_sequence(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 init_sequence (  *getarg(1) );
 return(_r);
}
 
double invl (  double _lmean ) {
   double _linvl;
 if ( _lmean <= 0. ) {
     _lmean = .01 ;
     }
   if ( noise  == 0.0 ) {
     _linvl = _lmean ;
     }
   else {
     _linvl = ( 1. - noise ) * _lmean + noise * _lmean * exprand ( 1.0 ) ;
     }
   
return _linvl;
 }
 
static double _hoc_invl(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  invl (  *getarg(1) );
 return(_r);
}
 
static int  event_time (  ) {
   if ( flag  == 0.0  && t - tpre > swd ) {
     flag = 1.0 ;
     tpre = t ;
     }
   if ( flag  == 1.0  && t - tpre >= swu ) {
     flag = 0.0 ;
     tpre = t ;
     }
   if ( flag  == 0.0 ) {
     interval = interv1 ;
     }
   else {
     interval = interv2 ;
     }
   if ( number > 0.0 ) {
     event = event + invl ( _threadargscomma_ interval ) ;
     }
   if ( event > end ) {
     on = 0.0 ;
     }
    return 0; }
 
static double _hoc_event_time(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 event_time (  );
 return(_r);
}
 
static void _net_receive (_pnt, _args, _lflag) Point_process* _pnt; double* _args; double _lflag; 
{    _p = _pnt->_prop->param; _ppvar = _pnt->_prop->dparam;
  if (_tsav > t){ extern char* hoc_object_name(); hoc_execerror(hoc_object_name(_pnt->ob), ":Event arrived out of order. Must call ParallelContext.set_maxstep AFTER assigning minimum NetCon.delay");}
 _tsav = t;   if (_lflag == 1. ) {*(_tqitem) = 0;}
 {
   if ( _lflag  == 0.0 ) {
     if ( _args[0] > 0.0  && on  == 0.0 ) {
       init_sequence ( _threadargscomma_ t ) ;
       net_send ( _tqitem, _args, _pnt, t +  0.0 , 1.0 ) ;
       }
     else if ( _args[0] < 0.0  && on  == 1.0 ) {
       on = 0.0 ;
       }
     }
   if ( _lflag  == 3.0 ) {
     if ( on  == 0.0 ) {
       init_sequence ( _threadargscomma_ t ) ;
       net_send ( _tqitem, _args, _pnt, t +  0.0 , 1.0 ) ;
       }
     }
   if ( _lflag  == 1.0  && on  == 1.0 ) {
     y = 2.0 ;
     net_event ( _pnt, t ) ;
     event_time ( _threadargs_ ) ;
     if ( on  == 1.0 ) {
       net_send ( _tqitem, _args, _pnt, t +  event - t , 1.0 ) ;
       }
     net_send ( _tqitem, _args, _pnt, t +  .1 , 2.0 ) ;
     }
   if ( _lflag  == 2.0 ) {
     y = 0.0 ;
     }
   } }

static void initmodel() {
  int _i; double _save;_ninits++;
{
 {
   on = 0.0 ;
   y = 0.0 ;
   flag = 0.0 ;
   tpre = 0.0 ;
   sw = 2000.0 ;
   if ( noise < 0.0 ) {
     noise = 0.0 ;
     }
   if ( noise > 1.0 ) {
     noise = 1.0 ;
     }
   if ( start >= 0.0  && number > 0.0 ) {
     event = start + invl ( _threadargscomma_ interv1 ) ;
     net_send ( _tqitem, (double*)0, _ppvar[1]._pvoid, t +  event , 3.0 ) ;
     }
   }

}
}

static void nrn_init(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _tsav = -1e20;
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v = _v;
 initmodel();
}}

static double _nrn_current(double _v){double _current=0.;v=_v;{
} return _current;
}

static void nrn_state(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; double _v = 0.0; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _nd = _ml->_nodelist[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v=_v;
{
}}

}

static void terminal(){}

static void _initlists() {
 int _i; static int _first = 1;
  if (!_first) return;
_first = 0;
}

#if NMODL_TEXT
static const char* nmodl_filename = "/mnt/c/Users/lawre/OneDrive/Documents/burise/VTA-neurons-opiates-withdrawal/EnricoEtAl2016/netstimd.mod";
static const char* nmodl_file_text = 
  ": $Id: netstim.mod,v 1.1.1.1 2001/01/01 20:30:37 hines Exp $\n"
  ": modified in such a way that the first event will never be before start\n"
  ": M.Migliore Dec.2001\n"
  "\n"
  "NEURON	{ \n"
  "  POINT_PROCESS NetStimd\n"
  "  RANGE y\n"
  "  RANGE interv1, interv2, swu, swd, number, start\n"
  "  RANGE noise\n"
  "}\n"
  "\n"
  "PARAMETER {\n"
  "	interv1	= 10 (ms) <1e-9,1e9>: time between spikes (msec)\n"
  "	interv2	= 10 (ms) <1e-9,1e9>: time between spikes (msec)\n"
  "	interval	= 10\n"
  "	number	= 10 <0,1e9>	: number of spikes\n"
  "	start		= 50 (ms)	: start of first spike\n"
  "	noise		= 0 <0,1>	: amount of randomeaness (0.0 - 1.0)\n"
  "	swu		= 400\n"
  "	swd		= 2000\n"
  "	sw		= 2000\n"
  "	flag		= 0\n"
  "	tpre		= 0\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "	y\n"
  "	event (ms)\n"
  "	on\n"
  "	end (ms)\n"
  "}\n"
  "\n"
  "PROCEDURE seed(x) {\n"
  "	set_seed(x)\n"
  "}\n"
  "\n"
  "INITIAL {\n"
  "	on = 0\n"
  "	y = 0\n"
  "	flag=0\n"
  "	tpre=0\n"
  "	sw=2000\n"
  "	if (noise < 0) {\n"
  "		noise = 0\n"
  "	}\n"
  "	if (noise > 1) {\n"
  "		noise = 1\n"
  "	}\n"
  "	if (start >= 0 && number > 0) {\n"
  "		: randomize the first spike so on average it occurs at start+interval\n"
  "		event = start + invl(interv1)\n"
  "		net_send(event, 3)\n"
  "	}\n"
  "}	\n"
  "\n"
  "PROCEDURE init_sequence(t(ms)) {\n"
  "	if (number > 0) {\n"
  "		on = 1\n"
  "		event = t\n"
  "		end = t + 1e-6 + invl(interv1)*(number-1)\n"
  "	}\n"
  "}\n"
  "\n"
  "FUNCTION invl(mean (ms)) (ms) {\n"
  "	if (mean <= 0.) {\n"
  "		mean = .01 (ms) : I would worry if it were 0.\n"
  "	}\n"
  "	if (noise == 0) {\n"
  "		invl = mean\n"
  "	}else{\n"
  "		invl = (1. - noise)*mean + noise*mean*exprand(1)\n"
  "	}\n"
  "}\n"
  "\n"
  "PROCEDURE event_time() {\n"
  "	if (flag==0 && t-tpre>swd) {\n"
  "		flag=1 \n"
  "		tpre=t\n"
  ":		printf (\" switch at %g %d %g \\n\", t, flag, swd)\n"
  "	}\n"
  "	if (flag==1 && t-tpre>=swu) {\n"
  "		flag=0 \n"
  "		tpre=t\n"
  ":		printf (\" switch at %g %d %g \\n\", t, flag, swu)\n"
  "	}\n"
  "	if (flag==0) {interval=interv1} else {interval=interv2}\n"
  ":	printf (\"interval %g gap %g \\n\", interval, t-tpre)\n"
  "	if (number > 0) {\n"
  "		event = event + invl(interval)\n"
  "	}\n"
  "	if (event > end) {\n"
  "		on = 0\n"
  "	}\n"
  "}\n"
  "\n"
  "NET_RECEIVE (w) {\n"
  "	if (flag == 0) { : external event\n"
  "		if (w > 0 && on == 0) { : turn on spike sequence\n"
  "			init_sequence(t)\n"
  "			net_send(0, 1)\n"
  "		}else if (w < 0 && on == 1) { : turn off spiking\n"
  "			on = 0\n"
  "		}\n"
  "	}\n"
  "	if (flag == 3) { : from INITIAL\n"
  "		if (on == 0) {\n"
  "			init_sequence(t)\n"
  "			net_send(0, 1)\n"
  "		}\n"
  "	}\n"
  "	if (flag == 1 && on == 1) {\n"
  "		y = 2\n"
  "		net_event(t)\n"
  "		event_time()\n"
  "		if (on == 1) {\n"
  "			net_send(event - t, 1)\n"
  "		}\n"
  "		net_send(.1, 2)\n"
  "	}\n"
  "	if (flag == 2) {\n"
  "		y = 0\n"
  "	}\n"
  "}\n"
  "\n"
  "COMMENT\n"
  "Presynaptic spike generator\n"
  "---------------------------\n"
  "\n"
  "This mechanism has been written to be able to use synapses in a single\n"
  "neuron receiving various types of presynaptic trains.  This is a \"fake\"\n"
  "presynaptic compartment containing a spike generator.  The trains\n"
  "of spikes can be either periodic or noisy (Poisson-distributed)\n"
  "\n"
  "Parameters;\n"
  "   noise: 	between 0 (no noise-periodic) and 1 (fully noisy)\n"
  "   interval: 	mean time between spikes (ms)\n"
  "   number: 	mean number of spikes\n"
  "\n"
  "Written by Z. Mainen, modified by A. Destexhe, The Salk Institute\n"
  "\n"
  "Modified by Michael Hines for use with CVode\n"
  "The intrinsic bursting parameters have been removed since\n"
  "generators can stimulate other generators to create complicated bursting\n"
  "patterns with independent statistics (see below)\n"
  "\n"
  "Modified by Michael Hines to use logical event style with NET_RECEIVE\n"
  "This stimulator can also be triggered by an input event.\n"
  "If the stimulator is in the on=0 state and receives a positive weight\n"
  "event, then the stimulator changes to the on=1 state and goes through\n"
  "its entire spike sequence before changing to the on=0 state. During\n"
  "that time it ignores any positive weight events. If, in the on=1 state,\n"
  "the stimulator receives a negative weight event, the stimulator will\n"
  "change to the off state. In the off state, it will ignore negative weight\n"
  "events. A change to the on state immediately fires the first spike of\n"
  "its sequence.\n"
  "\n"
  "ENDCOMMENT\n"
  "\n"
  ;
#endif
