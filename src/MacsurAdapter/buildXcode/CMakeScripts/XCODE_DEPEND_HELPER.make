# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# For each target create a dummy rule so the target does not have to exist


# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.MacsurAdapter.Debug:
/Users/arkygeek/QtProjects/macsur-adapter/src/MacsurAdapter/buildXcode/Debug/MacsurAdapter:
	/bin/rm -f /Users/arkygeek/QtProjects/macsur-adapter/src/MacsurAdapter/buildXcode/Debug/MacsurAdapter


PostBuild.MacsurAdapter.Release:
/Users/arkygeek/QtProjects/macsur-adapter/src/MacsurAdapter/buildXcode/Release/MacsurAdapter:
	/bin/rm -f /Users/arkygeek/QtProjects/macsur-adapter/src/MacsurAdapter/buildXcode/Release/MacsurAdapter


PostBuild.MacsurAdapter.MinSizeRel:
/Users/arkygeek/QtProjects/macsur-adapter/src/MacsurAdapter/buildXcode/MinSizeRel/MacsurAdapter:
	/bin/rm -f /Users/arkygeek/QtProjects/macsur-adapter/src/MacsurAdapter/buildXcode/MinSizeRel/MacsurAdapter


PostBuild.MacsurAdapter.RelWithDebInfo:
/Users/arkygeek/QtProjects/macsur-adapter/src/MacsurAdapter/buildXcode/RelWithDebInfo/MacsurAdapter:
	/bin/rm -f /Users/arkygeek/QtProjects/macsur-adapter/src/MacsurAdapter/buildXcode/RelWithDebInfo/MacsurAdapter


