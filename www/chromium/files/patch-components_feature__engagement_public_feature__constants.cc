--- components/feature_engagement/public/feature_constants.cc.orig	2020-09-08 19:14:03 UTC
+++ components/feature_engagement/public/feature_constants.cc
@@ -14,7 +14,7 @@ const base::Feature kIPHDemoMode{"IPH_DemoMode",
 const base::Feature kIPHDummyFeature{"IPH_Dummy",
                                      base::FEATURE_DISABLED_BY_DEFAULT};
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 const base::Feature kIPHDesktopTabGroupsNewGroupFeature{
     "IPH_DesktopTabGroupsNewGroup", base::FEATURE_DISABLED_BY_DEFAULT};
@@ -37,7 +37,7 @@ const base::Feature kIPHIncognitoWindowFeature{
 const base::Feature kIPHNewTabFeature{"IPH_NewTab",
                                       base::FEATURE_DISABLED_BY_DEFAULT};
 #endif  // BUILDFLAG(ENABLE_LEGACY_DESKTOP_IN_PRODUCT_HELP)
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
 #if defined(OS_ANDROID)
