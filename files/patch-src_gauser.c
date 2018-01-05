--- src/gauser.c.orig	2018-01-03 12:26:03.528412000 -0600
+++ src/gauser.c	2018-01-03 12:26:21.191720000 -0600
@@ -2613,13 +2613,11 @@
 gafloat *fptr=NULL;
 gadouble *dptr=NULL,dval;
 size_t sz;
-#if (USENETCDF == 1 || USEHDF == 1)
 struct dt tdef, tdefi;
 char *tfile, *tfile2;
 gaint ncid=0, rc, error, n_atts, n_gatts;
 gaint sdid=0;
 char dimname[256];
-#endif
 #if USEHDF5 == 1
 gaint h5id=-999;
 hid_t fid=0;
