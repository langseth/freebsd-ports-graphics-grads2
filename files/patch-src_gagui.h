--- src/gagui.h.orig	2011-10-11 12:36:18.000000000 -0500
+++ src/gagui.h	2017-12-21 11:10:29.334560000 -0600
@@ -22,9 +22,11 @@
 
 */
 
-#include "libsx.h"
+#include "X11/libsx/libsx.h"
+#include "X11/libsx/freq.h"
 
 int init_display(int argc, char **argv, void *data);
+int Default_GUI(int argc, char **argv, void *data);
 int Custom_GUI( char *fname );
 int gagui_main(int argc, char **argv);
 
