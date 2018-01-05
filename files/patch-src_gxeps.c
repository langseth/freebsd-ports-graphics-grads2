--- src/gxeps.c.orig	2018-01-04 12:55:41.796931000 -0600
+++ src/gxeps.c	2018-01-04 12:54:00.763654000 -0600
@@ -303,6 +303,8 @@
 #include <math.h>
 #include <time.h>
 
+#include "grads.h"
+
 #define max(A, B) ((A) > (B) ? (A) : (B))
 #define min(A, B) ((A) < (B) ? (A) : (B))
 
