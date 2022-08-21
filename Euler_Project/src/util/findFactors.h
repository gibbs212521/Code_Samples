#ifndef __FACTORS_UTIL_H__
#define __FACTORS_UTIL_H__

#include "base.h"
#include "stdint.h"

#ifdef _WIN32
#elif __linux__
#endif

bool isFactor(long test_value, uint64_t target);

void buildFactorStack(struct StackHandler * ptrStackFILO, uint64_t target);
void buildFactorInvStack(struct InvStackHandler * ptrStackFIFO, uint64_t target);
int * getLCMFactors(struct StackHandler * ptrStackFILO);
int * getFactorArray(struct StackHandler * ptrStackFILO);

#endif
