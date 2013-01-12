--- include/servermd.h.orig	Sun Jan  8 14:05:55 2006
+++ include/servermd.h	Sun Jan  8 14:06:22 2006
@@ -84,6 +84,19 @@
 
 #endif /* __arm32__ */
 
+#if defined(__FreeBSD__) && defined(__arm__)
+
+#ifdef __BIG_ENDIAN
+#define        IMAGE_BYTE_ORDER        MSBFirst
+#define        BITMAP_BIT_ORDER        MSBFirst
+#else
+#define        IMAGE_BYTE_ORDER        LSBFirst
+#define        BITMAP_BIT_ORDER        LSBFirst
+#endif
+#define        GLYPHPADBYTES           4
+
+#endif /* __FreeBSD__ && __arm__ */
+
 #if defined __hppa__
 
 #define IMAGE_BYTE_ORDER       MSBFirst
@@ -133,7 +146,7 @@
     defined(__sparc__) || defined(__mc68000__)
 
 #if defined(__sparc) || defined(__sparc__)
-# if !defined(sparc)
+# if !defined(sparc) && !defined(__FreeBSD__)
 #  define sparc 1
 # endif
 #endif

