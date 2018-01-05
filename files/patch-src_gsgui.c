--- src/gsgui.c.orig	2008-08-08 06:47:56.000000000 -0500
+++ src/gsgui.c	2017-12-19 17:11:17.504405000 -0600
@@ -42,9 +42,9 @@
 #include <stdio.h>
 #include <stdlib.h>
 
-#include "libsx.h"
+#include "X11/libsx/libsx.h"
 #if USEFREQ == 1
-#include "freq.h"
+#include "X11/libsx/freq.h"
 #endif
 #include "gagui.h"
 
