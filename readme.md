# yfs2
Yumrepofs2 - Virtual Yum server (RWM read-write-many)

## Experimental software
This is purely an experiment. No expectation that it will be the final solution.

## Introduction
Regular Yum servers are present on disk. For build systems this means having a common NFS share for all workers to re-use
previous artifacts, as well as outputting the new artifacts to the same NFS share. This is not ideal, and it cannot be
deployed in a way that is scalable (or easy).

Yfs2 is a virtual Yum server. It is a Yum server that is not present on disk, but RPMs are present in an object store.
RPMs managed by Yfs2 can be used to construct any number of virtual Yum repositories. These repositories can be
constructed on the fly, and can be used to install RPMs from the object store.

The virtual repositories can still be treated as on-disk if needed. This means that the virtual repositories can be
used as a drop-in replacement for regular Yum repositories. They are also browsable like any other Yum repository.

Yfs2 also stores additional information in a data store to quickly swap RPMs/modules in and out of repositories. This
information is also used to construct the virtual repositories.

## License
GPL-2.0 except for third-party code in the `third_party` directory explicitly marked with its own license file.
