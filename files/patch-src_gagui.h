--- src/gagui.h.orig	2011-03-17 12:43:49.000000000 -0500
+++ src/gagui.h	2018-01-04 16:11:18.207508000 -0600
@@ -22,7 +22,8 @@
 
 */
 
-#include "libsx.h"
+#include "X11/libsx/libsx.h"
+#include "X11/libsx/freq.h"
 
 int init_display(int argc, char **argv, void *data);
 int Custom_GUI( char *fname );
