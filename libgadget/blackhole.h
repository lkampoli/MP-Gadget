#ifndef __BLACKHOLE_H
#define __BLACKHOLE_H
#include "utils/paramset.h"
#include "timestep.h"

enum BlackHoleFeedbackMethod {
     BH_FEEDBACK_TOPHAT   = 0x2,
     BH_FEEDBACK_SPLINE   = 0x4,
     BH_FEEDBACK_MASS     = 0x8,
     BH_FEEDBACK_VOLUME   = 0x10,
     BH_FEEDBACK_OPTTHIN  = 0x20,
};

/*Set the parameters of the star formation module*/
void set_blackhole_params(ParameterSet * ps);

/* Does the black hole feedback and accretion.
 * Repositioning to the potential minimum is done if Reposition is true.
 * This should be enabled only if the potential was computed this step (ie a PM step)
 * tree is a valid ForceTree. The last two are file handles for output.
 */
void blackhole(int Reposition, const ActiveParticles * act, ForceTree * tree, FILE * FdBlackHoles, FILE * FdBlackholeDetails);

/* Make a black hole from the particle at index*/
void blackhole_make_one(int index);

#endif
