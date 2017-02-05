#ifndef __pif_h__
#define __pif_h__

struct _ns4_pif {
    /* The initial program loader stored within the PIF. */
    void *ipl;
};

/* Initializes an emulated PIF instance. */
void pif_create(struct _ns4_pif *pif);

#endif
