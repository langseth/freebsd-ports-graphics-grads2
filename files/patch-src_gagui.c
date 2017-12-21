--- src/gagui.c.orig	2013-10-03 09:13:35.000000000 -0500
+++ src/gagui.c	2017-12-21 11:08:09.582707000 -0600
@@ -54,15 +54,13 @@
 
 #include <time.h>
 
-#include "libsx.h"		
+#include "X11/libsx/libsx.h"		
 #if USEFREQ == 1
-#include "freq.h"	
+#include "X11/libsx/freq.h"	
 #endif
 #include "grads.h"
 #include "gx.h"
 
-extern struct gacmn gcmn;
-
 #include "gagui.h"
 
 static char default_var[128];         /* default variable for display */
@@ -86,6 +84,8 @@
 static char **CmdWinList;   /* Command buffer */
 static Widget Cmd_window, CmdExpr_window, CmdList_window, CmdStr_window;
 
+struct gacmn gcmn;
+
 /*---------------------------------------------------------------------*
 
 /*
@@ -362,7 +362,7 @@
 char *SimpleGetFile(char *path)
 {
 #ifndef GETFILE_SHORT_PROTOTYPE
-  return GetFile("Simple file requestor", path, NULL, NULL);
+  return GetFile(path);
 #else
   return GetFile(path);
 #endif
