static const struct headerTagTableEntry_s rpmTagTable[] = {
    { "RPMTAG_ARCH", "Arch", RPMTAG_ARCH, RPM_STRING_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_ARCHIVESIZE", "Archivesize", RPMTAG_ARCHIVESIZE, RPM_INT32_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_ARCHSUFFIX", "Archsuffix", RPMTAG_ARCHSUFFIX, RPM_STRING_TYPE, RPM_SCALAR_RETURN_TYPE, 1 },
    { "RPMTAG_BASENAMES", "Basenames", RPMTAG_BASENAMES, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_BUGURL", "Bugurl", RPMTAG_BUGURL, RPM_STRING_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_BUILDARCHS", "Buildarchs", RPMTAG_BUILDARCHS, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_BUILDHOST", "Buildhost", RPMTAG_BUILDHOST, RPM_STRING_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_BUILDTIME", "Buildtime", RPMTAG_BUILDTIME, RPM_INT32_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_C", "C", RPMTAG_CONFLICTNAME, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_CHANGELOGNAME", "Changelogname", RPMTAG_CHANGELOGNAME, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_CHANGELOGTEXT", "Changelogtext", RPMTAG_CHANGELOGTEXT, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_CHANGELOGTIME", "Changelogtime", RPMTAG_CHANGELOGTIME, RPM_INT32_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_CLASSDICT", "Classdict", RPMTAG_CLASSDICT, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_CONFLICTFLAGS", "Conflictflags", RPMTAG_CONFLICTFLAGS, RPM_INT32_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_CONFLICTNAME", "Conflictname", RPMTAG_CONFLICTNAME, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_CONFLICTNEVRS", "Conflictnevrs", RPMTAG_CONFLICTNEVRS, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 1 },
    { "RPMTAG_CONFLICTS", "Conflicts", RPMTAG_CONFLICTNAME, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_CONFLICTVERSION", "Conflictversion", RPMTAG_CONFLICTVERSION, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_COOKIE", "Cookie", RPMTAG_COOKIE, RPM_STRING_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_DBINSTANCE", "Dbinstance", RPMTAG_DBINSTANCE, RPM_INT32_TYPE, RPM_SCALAR_RETURN_TYPE, 1 },
    { "RPMTAG_DEPENDSDICT", "Dependsdict", RPMTAG_DEPENDSDICT, RPM_INT32_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_DESCRIPTION", "Description", RPMTAG_DESCRIPTION, RPM_I18NSTRING_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_DIRINDEXES", "Dirindexes", RPMTAG_DIRINDEXES, RPM_INT32_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_DIRNAMES", "Dirnames", RPMTAG_DIRNAMES, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_DISTRIBUTION", "Distribution", RPMTAG_DISTRIBUTION, RPM_STRING_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_DISTTAG", "Disttag", RPMTAG_DISTTAG, RPM_STRING_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_DISTURL", "Disturl", RPMTAG_DISTURL, RPM_STRING_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_DSAHEADER", "Dsaheader", RPMTAG_DSAHEADER, RPM_BIN_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_E", "E", RPMTAG_EPOCH, RPM_INT32_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_ENCODING", "Encoding", RPMTAG_ENCODING, RPM_STRING_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_ENHANCEFLAGS", "Enhanceflags", RPMTAG_ENHANCEFLAGS, RPM_INT32_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_ENHANCENAME", "Enhancename", RPMTAG_ENHANCENAME, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_ENHANCENEVRS", "Enhancenevrs", RPMTAG_ENHANCENEVRS, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 1 },
    { "RPMTAG_ENHANCES", "Enhances", RPMTAG_ENHANCENAME, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_ENHANCEVERSION", "Enhanceversion", RPMTAG_ENHANCEVERSION, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_EPOCH", "Epoch", RPMTAG_EPOCH, RPM_INT32_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_EPOCHNUM", "Epochnum", RPMTAG_EPOCHNUM, RPM_INT32_TYPE, RPM_SCALAR_RETURN_TYPE, 1 },
    { "RPMTAG_EVR", "Evr", RPMTAG_EVR, RPM_STRING_TYPE, RPM_SCALAR_RETURN_TYPE, 1 },
    { "RPMTAG_EXCLUDEARCH", "Excludearch", RPMTAG_EXCLUDEARCH, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_EXCLUDEOS", "Excludeos", RPMTAG_EXCLUDEOS, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_EXCLUSIVEARCH", "Exclusivearch", RPMTAG_EXCLUSIVEARCH, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_EXCLUSIVEOS", "Exclusiveos", RPMTAG_EXCLUSIVEOS, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_FILECAPS", "Filecaps", RPMTAG_FILECAPS, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_FILECLASS", "Fileclass", RPMTAG_FILECLASS, RPM_INT32_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_FILECOLORS", "Filecolors", RPMTAG_FILECOLORS, RPM_INT32_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_FILECONTEXTS", "Filecontexts", RPMTAG_FILECONTEXTS, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_FILEDEPENDSN", "Filedependsn", RPMTAG_FILEDEPENDSN, RPM_INT32_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_FILEDEPENDSX", "Filedependsx", RPMTAG_FILEDEPENDSX, RPM_INT32_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_FILEDEVICES", "Filedevices", RPMTAG_FILEDEVICES, RPM_INT32_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_FILEDIGESTALGO", "Filedigestalgo", RPMTAG_FILEDIGESTALGO, RPM_INT32_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_FILEDIGESTS", "Filedigests", RPMTAG_FILEDIGESTS, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_FILEFLAGS", "Fileflags", RPMTAG_FILEFLAGS, RPM_INT32_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_FILEGROUPNAME", "Filegroupname", RPMTAG_FILEGROUPNAME, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_FILEINODES", "Fileinodes", RPMTAG_FILEINODES, RPM_INT32_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_FILELANGS", "Filelangs", RPMTAG_FILELANGS, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_FILELINKTOS", "Filelinktos", RPMTAG_FILELINKTOS, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_FILEMD5S", "Filemd5s", RPMTAG_FILEDIGESTS, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_FILEMODES", "Filemodes", RPMTAG_FILEMODES, RPM_INT16_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_FILEMTIMES", "Filemtimes", RPMTAG_FILEMTIMES, RPM_INT32_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_FILENAMES", "Filenames", RPMTAG_FILENAMES, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 1 },
    { "RPMTAG_FILENLINKS", "Filenlinks", RPMTAG_FILENLINKS, RPM_INT32_TYPE, RPM_ARRAY_RETURN_TYPE, 1 },
    { "RPMTAG_FILEPROVIDE", "Fileprovide", RPMTAG_FILEPROVIDE, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 1 },
    { "RPMTAG_FILERDEVS", "Filerdevs", RPMTAG_FILERDEVS, RPM_INT16_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_FILEREQUIRE", "Filerequire", RPMTAG_FILEREQUIRE, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 1 },
    { "RPMTAG_FILESIGNATURELENGTH", "Filesignaturelength", RPMTAG_FILESIGNATURELENGTH, RPM_INT32_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_FILESIGNATURES", "Filesignatures", RPMTAG_FILESIGNATURES, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_FILESIZES", "Filesizes", RPMTAG_FILESIZES, RPM_INT32_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_FILESTATES", "Filestates", RPMTAG_FILESTATES, RPM_CHAR_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_FILETRIGGERCONDS", "Filetriggerconds", RPMTAG_FILETRIGGERCONDS, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 1 },
    { "RPMTAG_FILETRIGGERFLAGS", "Filetriggerflags", RPMTAG_FILETRIGGERFLAGS, RPM_INT32_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_FILETRIGGERINDEX", "Filetriggerindex", RPMTAG_FILETRIGGERINDEX, RPM_INT32_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_FILETRIGGERNAME", "Filetriggername", RPMTAG_FILETRIGGERNAME, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_FILETRIGGERPRIORITIES", "Filetriggerpriorities", RPMTAG_FILETRIGGERPRIORITIES, RPM_INT32_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_FILETRIGGERSCRIPTFLAGS", "Filetriggerscriptflags", RPMTAG_FILETRIGGERSCRIPTFLAGS, RPM_INT32_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_FILETRIGGERSCRIPTPROG", "Filetriggerscriptprog", RPMTAG_FILETRIGGERSCRIPTPROG, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_FILETRIGGERSCRIPTS", "Filetriggerscripts", RPMTAG_FILETRIGGERSCRIPTS, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_FILETRIGGERTYPE", "Filetriggertype", RPMTAG_FILETRIGGERTYPE, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 1 },
    { "RPMTAG_FILETRIGGERVERSION", "Filetriggerversion", RPMTAG_FILETRIGGERVERSION, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_FILEUSERNAME", "Fileusername", RPMTAG_FILEUSERNAME, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_FILEVERIFYFLAGS", "Fileverifyflags", RPMTAG_FILEVERIFYFLAGS, RPM_INT32_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_FSCONTEXTS", "Fscontexts", RPMTAG_FSCONTEXTS, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 1 },
    { "RPMTAG_GIF", "Gif", RPMTAG_GIF, RPM_BIN_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_GROUP", "Group", RPMTAG_GROUP, RPM_I18NSTRING_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_HDRID", "Hdrid", RPMTAG_SHA1HEADER, RPM_STRING_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_HEADERCOLOR", "Headercolor", RPMTAG_HEADERCOLOR, RPM_INT32_TYPE, RPM_SCALAR_RETURN_TYPE, 1 },
    { "RPMTAG_HEADERI18NTABLE", "Headeri18ntable", RPMTAG_HEADERI18NTABLE, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_HEADERIMAGE", "Headerimage", RPMTAG_HEADERIMAGE, RPM_NULL_TYPE, RPM_ANY_RETURN_TYPE, 0 },
    { "RPMTAG_HEADERIMMUTABLE", "Headerimmutable", RPMTAG_HEADERIMMUTABLE, RPM_NULL_TYPE, RPM_ANY_RETURN_TYPE, 0 },
    { "RPMTAG_HEADERREGIONS", "Headerregions", RPMTAG_HEADERREGIONS, RPM_NULL_TYPE, RPM_ANY_RETURN_TYPE, 0 },
    { "RPMTAG_HEADERSIGNATURES", "Headersignatures", RPMTAG_HEADERSIGNATURES, RPM_NULL_TYPE, RPM_ANY_RETURN_TYPE, 0 },
    { "RPMTAG_ICON", "Icon", RPMTAG_ICON, RPM_BIN_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_INSTALLCOLOR", "Installcolor", RPMTAG_INSTALLCOLOR, RPM_INT32_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_INSTALLTID", "Installtid", RPMTAG_INSTALLTID, RPM_INT32_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_INSTALLTIME", "Installtime", RPMTAG_INSTALLTIME, RPM_INT32_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_INSTFILENAMES", "Instfilenames", RPMTAG_INSTFILENAMES, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 1 },
    { "RPMTAG_INSTPREFIXES", "Instprefixes", RPMTAG_INSTPREFIXES, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_LICENSE", "License", RPMTAG_LICENSE, RPM_STRING_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_LONGARCHIVESIZE", "Longarchivesize", RPMTAG_LONGARCHIVESIZE, RPM_INT64_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_LONGFILESIZES", "Longfilesizes", RPMTAG_LONGFILESIZES, RPM_INT64_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_LONGSIGSIZE", "Longsigsize", RPMTAG_LONGSIGSIZE, RPM_INT64_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_LONGSIZE", "Longsize", RPMTAG_LONGSIZE, RPM_INT64_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_MODULARITYLABEL", "Modularitylabel", RPMTAG_MODULARITYLABEL, RPM_STRING_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_N", "N", RPMTAG_NAME, RPM_STRING_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_NAME", "Name", RPMTAG_NAME, RPM_STRING_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_NEVR", "Nevr", RPMTAG_NEVR, RPM_STRING_TYPE, RPM_SCALAR_RETURN_TYPE, 1 },
    { "RPMTAG_NEVRA", "Nevra", RPMTAG_NEVRA, RPM_STRING_TYPE, RPM_SCALAR_RETURN_TYPE, 1 },
    { "RPMTAG_NOPATCH", "Nopatch", RPMTAG_NOPATCH, RPM_INT32_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_NOSOURCE", "Nosource", RPMTAG_NOSOURCE, RPM_INT32_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_NVR", "Nvr", RPMTAG_NVR, RPM_STRING_TYPE, RPM_SCALAR_RETURN_TYPE, 1 },
    { "RPMTAG_NVRA", "Nvra", RPMTAG_NVRA, RPM_STRING_TYPE, RPM_SCALAR_RETURN_TYPE, 1 },
    { "RPMTAG_O", "O", RPMTAG_OBSOLETENAME, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_OBSOLETEFLAGS", "Obsoleteflags", RPMTAG_OBSOLETEFLAGS, RPM_INT32_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_OBSOLETENAME", "Obsoletename", RPMTAG_OBSOLETENAME, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_OBSOLETENEVRS", "Obsoletenevrs", RPMTAG_OBSOLETENEVRS, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 1 },
    { "RPMTAG_OBSOLETES", "Obsoletes", RPMTAG_OBSOLETENAME, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_OBSOLETEVERSION", "Obsoleteversion", RPMTAG_OBSOLETEVERSION, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_OLDENHANCES", "Oldenhances", RPMTAG_OLDENHANCESNAME, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_OLDENHANCESFLAGS", "Oldenhancesflags", RPMTAG_OLDENHANCESFLAGS, RPM_INT32_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_OLDENHANCESNAME", "Oldenhancesname", RPMTAG_OLDENHANCESNAME, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_OLDENHANCESVERSION", "Oldenhancesversion", RPMTAG_OLDENHANCESVERSION, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_OLDFILENAMES", "Oldfilenames", RPMTAG_OLDFILENAMES, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_OLDSUGGESTS", "Oldsuggests", RPMTAG_OLDSUGGESTSNAME, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_OLDSUGGESTSFLAGS", "Oldsuggestsflags", RPMTAG_OLDSUGGESTSFLAGS, RPM_INT32_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_OLDSUGGESTSNAME", "Oldsuggestsname", RPMTAG_OLDSUGGESTSNAME, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_OLDSUGGESTSVERSION", "Oldsuggestsversion", RPMTAG_OLDSUGGESTSVERSION, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_OPTFLAGS", "Optflags", RPMTAG_OPTFLAGS, RPM_STRING_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_ORDERFLAGS", "Orderflags", RPMTAG_ORDERFLAGS, RPM_INT32_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_ORDERNAME", "Ordername", RPMTAG_ORDERNAME, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_ORDERVERSION", "Orderversion", RPMTAG_ORDERVERSION, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_ORIGBASENAMES", "Origbasenames", RPMTAG_ORIGBASENAMES, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_ORIGDIRINDEXES", "Origdirindexes", RPMTAG_ORIGDIRINDEXES, RPM_INT32_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_ORIGDIRNAMES", "Origdirnames", RPMTAG_ORIGDIRNAMES, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_ORIGFILENAMES", "Origfilenames", RPMTAG_ORIGFILENAMES, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 1 },
    { "RPMTAG_OS", "Os", RPMTAG_OS, RPM_STRING_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_P", "P", RPMTAG_PROVIDENAME, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_PACKAGER", "Packager", RPMTAG_PACKAGER, RPM_STRING_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_PATCH", "Patch", RPMTAG_PATCH, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_PATCHESFLAGS", "Patchesflags", RPMTAG_PATCHESFLAGS, RPM_INT32_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_PATCHESNAME", "Patchesname", RPMTAG_PATCHESNAME, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_PATCHESVERSION", "Patchesversion", RPMTAG_PATCHESVERSION, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_PAYLOADCOMPRESSOR", "Payloadcompressor", RPMTAG_PAYLOADCOMPRESSOR, RPM_STRING_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_PAYLOADDIGEST", "Payloaddigest", RPMTAG_PAYLOADDIGEST, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_PAYLOADDIGESTALGO", "Payloaddigestalgo", RPMTAG_PAYLOADDIGESTALGO, RPM_INT32_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_PAYLOADDIGESTALT", "Payloaddigestalt", RPMTAG_PAYLOADDIGESTALT, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_PAYLOADFLAGS", "Payloadflags", RPMTAG_PAYLOADFLAGS, RPM_STRING_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_PAYLOADFORMAT", "Payloadformat", RPMTAG_PAYLOADFORMAT, RPM_STRING_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_PKGID", "Pkgid", RPMTAG_SIGMD5, RPM_BIN_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_PLATFORM", "Platform", RPMTAG_PLATFORM, RPM_STRING_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_POLICIES", "Policies", RPMTAG_POLICIES, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_POLICYFLAGS", "Policyflags", RPMTAG_POLICYFLAGS, RPM_INT32_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_POLICYNAMES", "Policynames", RPMTAG_POLICYNAMES, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_POLICYTYPES", "Policytypes", RPMTAG_POLICYTYPES, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_POLICYTYPESINDEXES", "Policytypesindexes", RPMTAG_POLICYTYPESINDEXES, RPM_INT32_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_POSTIN", "Postin", RPMTAG_POSTIN, RPM_STRING_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_POSTINFLAGS", "Postinflags", RPMTAG_POSTINFLAGS, RPM_INT32_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_POSTINPROG", "Postinprog", RPMTAG_POSTINPROG, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_POSTTRANS", "Posttrans", RPMTAG_POSTTRANS, RPM_STRING_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_POSTTRANSFLAGS", "Posttransflags", RPMTAG_POSTTRANSFLAGS, RPM_INT32_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_POSTTRANSPROG", "Posttransprog", RPMTAG_POSTTRANSPROG, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_POSTUN", "Postun", RPMTAG_POSTUN, RPM_STRING_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_POSTUNFLAGS", "Postunflags", RPMTAG_POSTUNFLAGS, RPM_INT32_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_POSTUNPROG", "Postunprog", RPMTAG_POSTUNPROG, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_PREFIXES", "Prefixes", RPMTAG_PREFIXES, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_PREIN", "Prein", RPMTAG_PREIN, RPM_STRING_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_PREINFLAGS", "Preinflags", RPMTAG_PREINFLAGS, RPM_INT32_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_PREINPROG", "Preinprog", RPMTAG_PREINPROG, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_PRETRANS", "Pretrans", RPMTAG_PRETRANS, RPM_STRING_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_PRETRANSFLAGS", "Pretransflags", RPMTAG_PRETRANSFLAGS, RPM_INT32_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_PRETRANSPROG", "Pretransprog", RPMTAG_PRETRANSPROG, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_PREUN", "Preun", RPMTAG_PREUN, RPM_STRING_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_PREUNFLAGS", "Preunflags", RPMTAG_PREUNFLAGS, RPM_INT32_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_PREUNPROG", "Preunprog", RPMTAG_PREUNPROG, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_PROVIDEFLAGS", "Provideflags", RPMTAG_PROVIDEFLAGS, RPM_INT32_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_PROVIDENAME", "Providename", RPMTAG_PROVIDENAME, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_PROVIDENEVRS", "Providenevrs", RPMTAG_PROVIDENEVRS, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 1 },
    { "RPMTAG_PROVIDES", "Provides", RPMTAG_PROVIDENAME, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_PROVIDEVERSION", "Provideversion", RPMTAG_PROVIDEVERSION, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_PUBKEYS", "Pubkeys", RPMTAG_PUBKEYS, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_R", "R", RPMTAG_RELEASE, RPM_STRING_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_RECOMMENDFLAGS", "Recommendflags", RPMTAG_RECOMMENDFLAGS, RPM_INT32_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_RECOMMENDNAME", "Recommendname", RPMTAG_RECOMMENDNAME, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_RECOMMENDNEVRS", "Recommendnevrs", RPMTAG_RECOMMENDNEVRS, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 1 },
    { "RPMTAG_RECOMMENDS", "Recommends", RPMTAG_RECOMMENDNAME, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_RECOMMENDVERSION", "Recommendversion", RPMTAG_RECOMMENDVERSION, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_RECONTEXTS", "Recontexts", RPMTAG_RECONTEXTS, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 1 },
    { "RPMTAG_RELEASE", "Release", RPMTAG_RELEASE, RPM_STRING_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_REMOVETID", "Removetid", RPMTAG_REMOVETID, RPM_INT32_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_REQUIREFLAGS", "Requireflags", RPMTAG_REQUIREFLAGS, RPM_INT32_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_REQUIRENAME", "Requirename", RPMTAG_REQUIRENAME, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_REQUIRENEVRS", "Requirenevrs", RPMTAG_REQUIRENEVRS, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 1 },
    { "RPMTAG_REQUIRES", "Requires", RPMTAG_REQUIRENAME, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_REQUIREVERSION", "Requireversion", RPMTAG_REQUIREVERSION, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_RPMVERSION", "Rpmversion", RPMTAG_RPMVERSION, RPM_STRING_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_RSAHEADER", "Rsaheader", RPMTAG_RSAHEADER, RPM_BIN_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_SHA1HEADER", "Sha1header", RPMTAG_SHA1HEADER, RPM_STRING_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_SHA256HEADER", "Sha256header", RPMTAG_SHA256HEADER, RPM_STRING_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_SIGGPG", "Siggpg", RPMTAG_SIGGPG, RPM_BIN_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_SIGMD5", "Sigmd5", RPMTAG_SIGMD5, RPM_BIN_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_SIGPGP", "Sigpgp", RPMTAG_SIGPGP, RPM_BIN_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_SIGSIZE", "Sigsize", RPMTAG_SIGSIZE, RPM_INT32_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_SIZE", "Size", RPMTAG_SIZE, RPM_INT32_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_SOURCE", "Source", RPMTAG_SOURCE, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_SOURCEPACKAGE", "Sourcepackage", RPMTAG_SOURCEPACKAGE, RPM_INT32_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_SOURCEPKGID", "Sourcepkgid", RPMTAG_SOURCEPKGID, RPM_BIN_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_SOURCERPM", "Sourcerpm", RPMTAG_SOURCERPM, RPM_STRING_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_SPEC", "Spec", RPMTAG_SPEC, RPM_STRING_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_SUGGESTFLAGS", "Suggestflags", RPMTAG_SUGGESTFLAGS, RPM_INT32_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_SUGGESTNAME", "Suggestname", RPMTAG_SUGGESTNAME, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_SUGGESTNEVRS", "Suggestnevrs", RPMTAG_SUGGESTNEVRS, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 1 },
    { "RPMTAG_SUGGESTS", "Suggests", RPMTAG_SUGGESTNAME, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_SUGGESTVERSION", "Suggestversion", RPMTAG_SUGGESTVERSION, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_SUMMARY", "Summary", RPMTAG_SUMMARY, RPM_I18NSTRING_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_SUPPLEMENTFLAGS", "Supplementflags", RPMTAG_SUPPLEMENTFLAGS, RPM_INT32_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_SUPPLEMENTNAME", "Supplementname", RPMTAG_SUPPLEMENTNAME, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_SUPPLEMENTNEVRS", "Supplementnevrs", RPMTAG_SUPPLEMENTNEVRS, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 1 },
    { "RPMTAG_SUPPLEMENTS", "Supplements", RPMTAG_SUPPLEMENTNAME, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_SUPPLEMENTVERSION", "Supplementversion", RPMTAG_SUPPLEMENTVERSION, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_TRANSFILETRIGGERCONDS", "Transfiletriggerconds", RPMTAG_TRANSFILETRIGGERCONDS, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 1 },
    { "RPMTAG_TRANSFILETRIGGERFLAGS", "Transfiletriggerflags", RPMTAG_TRANSFILETRIGGERFLAGS, RPM_INT32_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_TRANSFILETRIGGERINDEX", "Transfiletriggerindex", RPMTAG_TRANSFILETRIGGERINDEX, RPM_INT32_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_TRANSFILETRIGGERNAME", "Transfiletriggername", RPMTAG_TRANSFILETRIGGERNAME, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_TRANSFILETRIGGERPRIORITIES", "Transfiletriggerpriorities", RPMTAG_TRANSFILETRIGGERPRIORITIES, RPM_INT32_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_TRANSFILETRIGGERSCRIPTFLAGS", "Transfiletriggerscriptflags", RPMTAG_TRANSFILETRIGGERSCRIPTFLAGS, RPM_INT32_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_TRANSFILETRIGGERSCRIPTPROG", "Transfiletriggerscriptprog", RPMTAG_TRANSFILETRIGGERSCRIPTPROG, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_TRANSFILETRIGGERSCRIPTS", "Transfiletriggerscripts", RPMTAG_TRANSFILETRIGGERSCRIPTS, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_TRANSFILETRIGGERTYPE", "Transfiletriggertype", RPMTAG_TRANSFILETRIGGERTYPE, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 1 },
    { "RPMTAG_TRANSFILETRIGGERVERSION", "Transfiletriggerversion", RPMTAG_TRANSFILETRIGGERVERSION, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_TRANSLATIONURL", "Translationurl", RPMTAG_TRANSLATIONURL, RPM_STRING_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_TRIGGERCONDS", "Triggerconds", RPMTAG_TRIGGERCONDS, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 1 },
    { "RPMTAG_TRIGGERFLAGS", "Triggerflags", RPMTAG_TRIGGERFLAGS, RPM_INT32_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_TRIGGERINDEX", "Triggerindex", RPMTAG_TRIGGERINDEX, RPM_INT32_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_TRIGGERNAME", "Triggername", RPMTAG_TRIGGERNAME, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_TRIGGERSCRIPTFLAGS", "Triggerscriptflags", RPMTAG_TRIGGERSCRIPTFLAGS, RPM_INT32_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_TRIGGERSCRIPTPROG", "Triggerscriptprog", RPMTAG_TRIGGERSCRIPTPROG, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_TRIGGERSCRIPTS", "Triggerscripts", RPMTAG_TRIGGERSCRIPTS, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_TRIGGERTYPE", "Triggertype", RPMTAG_TRIGGERTYPE, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 1 },
    { "RPMTAG_TRIGGERVERSION", "Triggerversion", RPMTAG_TRIGGERVERSION, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_UPSTREAMRELEASES", "Upstreamreleases", RPMTAG_UPSTREAMRELEASES, RPM_STRING_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_URL", "Url", RPMTAG_URL, RPM_STRING_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_V", "V", RPMTAG_VERSION, RPM_STRING_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_VCS", "Vcs", RPMTAG_VCS, RPM_STRING_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_VENDOR", "Vendor", RPMTAG_VENDOR, RPM_STRING_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_VERBOSE", "Verbose", RPMTAG_VERBOSE, RPM_INT32_TYPE, RPM_SCALAR_RETURN_TYPE, 1 },
    { "RPMTAG_VERIFYSCRIPT", "Verifyscript", RPMTAG_VERIFYSCRIPT, RPM_STRING_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_VERIFYSCRIPTFLAGS", "Verifyscriptflags", RPMTAG_VERIFYSCRIPTFLAGS, RPM_INT32_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_VERIFYSCRIPTPROG", "Verifyscriptprog", RPMTAG_VERIFYSCRIPTPROG, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_VERITYSIGNATUREALGO", "Veritysignaturealgo", RPMTAG_VERITYSIGNATUREALGO, RPM_INT32_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_VERITYSIGNATURES", "Veritysignatures", RPMTAG_VERITYSIGNATURES, RPM_STRING_ARRAY_TYPE, RPM_ARRAY_RETURN_TYPE, 0 },
    { "RPMTAG_VERSION", "Version", RPMTAG_VERSION, RPM_STRING_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { "RPMTAG_XPM", "Xpm", RPMTAG_XPM, RPM_BIN_TYPE, RPM_SCALAR_RETURN_TYPE, 0 },
    { NULL, NULL, RPMTAG_NOT_FOUND, RPM_NULL_TYPE, 0 }
};
