--- src/gagui.c.orig	2011-03-17 12:43:49.000000000 -0500
+++ src/gagui.c	2018-01-04 16:19:26.663636000 -0600
@@ -51,13 +51,11 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <unistd.h>
 
 #include <time.h>
 
-#include "libsx.h"		
-#if USEFREQ == 1
-#include "freq.h"	
-#endif
+#include "X11/libsx/libsx.h"
 #include "grads.h"
 #include "gx.h"
 
@@ -359,16 +357,10 @@
   
 }
 
-#ifndef HAVE_SIMPLEGETFILE
 char *SimpleGetFile(char *path)
 {
-#ifndef GETFILE_SHORT_PROTOTYPE
-  return GetFile("Simple file requestor", path, NULL, NULL);
-#else
   return GetFile(path);
-#endif
 }
-#endif
 
 /*
  * CB_Load() - Callback function for the load button.  This just calls
