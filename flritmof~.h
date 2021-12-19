#ifndef fl_ritmof_h
#define fl_ritmof_h

#include "ext.h"
#include "z_dsp.h"
#include "ext_obex.h"
#include <math.h>

#define MAX_UNOS_SIZE 127

typedef struct _fl_beat {
	float dur_beat;
	float inicio_beat;
}fl_beat;

typedef struct _fl_ritmof {
	t_pxobject obj;

	fl_beat *old_unos;
	fl_beat *new_unos;
	long total_old_unos;
	long total_new_unos;
	float old_cifra; 
	float new_cifra;
	long index_old_unos;
	long index_new_unos;

	long samp_count;
	double beat_ms;

	short new_list_available;
	short onoff;
	short loop;
	short fasor_connected;

	short isnewlist;
	long index_out;

	double fs;

	void *m_outlet1;
	void *m_clock;

} t_fl_ritmof;

enum INLETS { I_BAR, I_MSBEAT, NUM_INLETS };
enum OUTLETS { O_OUTPUT, O_FINALFLAG, NUM_OUTLETS };

static t_class *fl_ritmof_class;

void *fl_ritmof_new(t_symbol *s, short argc, t_atom *argv);
void fl_ritmof_assist(t_fl_ritmof *x, void *b, long msg, long arg, char *dst);
void fl_ritmof_bar(t_fl_ritmof *x, t_symbol *msg, short argc, t_atom *argv);

void fl_ritmof_out(t_fl_ritmof *x);
void fl_ritmof_bar(t_fl_ritmof *x, t_symbol *msg, short argc, t_atom *argv);

void fl_ritmof_free(t_fl_ritmof *x);

void fl_ritmof_dsp64(t_fl_ritmof *x, t_object *dsp64, short *count, double samplerate, long maxvectorsize, long flags);
void fl_ritmof_perform64(t_fl_ritmof *x, t_object *dsp64, double **inputs, long numinputs, double **outputs, long numoutputs, long vectorsize, long flags, void *userparams);

#endif
