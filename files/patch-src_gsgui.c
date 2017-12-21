--- src/gsgui.c.orig	2008-08-08 06:47:56.000000000 -0500
+++ src/gsgui.c	2017-12-20 22:12:01.302732000 -0600
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
 
@@ -457,7 +457,7 @@
       UserColors[4].color = BLUE;
       UserColors[5].color = YELLOW;
       icolors = 5;
-      if(!name) return;
+      if(!name) return 0;
    }
 
    icolors++;
