### mutation_server

**Author:** Mustafa Gezen

This component is responsible for all changes that are going to be made to all repositories.

#### Overview

The mutation server is a gRPC service that is responsible for all changes that are going to be made to all repositories.
It is the only component that is allowed to make changes to the repositories. All other components must go through the
mutation server to make changes to the repositories.

#### Design

To allow for quick changes to any repository, all relevant RPM headers are stored in memory.
Relevant in this context means any RPM that is present in *any* repository that is not marked as frozen.

There is a good possibility that this is going to be a real bottleneck in the future but for now it is the easiest
solution. And I don't see a reason for us to prematurely optimize this.

Every uploaded RPM is stored in an object store (like S3 or GCS). An entry is also made in etcd
to keep track of the RPM. The key formats are like this:

* RPM: `/yfs2/{source_nvr}/{nvr} -> {sha256}`
* Source RPM: `/yfs2/{source_nvr}/source -> {sha256}`
* Module Stream: `/yfs2/{module_name}-{module_stream}-{module_context} -> {protobuf}`
* Module RPM: `/yfs2/{module_name}-{module_stream}-{module_context}/{source_nvr}/{nvr} -> {sha256}`
* Module Source RPM: `/yfs2/{module_name}-{module_stream}-{module_context}/{source_nvr}/source -> {sha256}`

All NVRs and modules are globally scoped. From this global registry packages (determined by the source package)
and modules can be tagged into projects. A project is a collection of packages and modules that are going to be
represented in a specific way (as in specific repositories and specific NVAs in specific repositories).
For example BaseOS is a project that contains all packages and modules that are going to be in the BaseOS repository.

Even though only source packages / modules can be tagged into projects, a project can declare to exclude/include certain
NAs. This is useful for example when a project wants to exclude a certain package from a repository.
A module can only be tagged by its stream, and it is not possible to exclude/include certain NAs.
The module document declares filters in its own way.

A project however has a more "structured" design. It has a key that holds the protobuf configuration of the project.
The configuration consists of the following:
* Package declarations with NAs that are going to be included/excluded for each repository
* Module defaults

The project content namespace will live at `/yfs2/projects/{project_name}`

The repository content lives at `/yfs2/projects/{project_name}/repos/{repo_name}`

Under that should be a structure that should be close to what a real-world repository looks like.

Example:
* `/yfs2/projects/BaseOS/repos/BaseOS/x86_64/os/Packages/a/acl-2.2.53-1.el8.1.x86_64.rpm`
* `/yfs2/projects/BaseOS/repos/BaseOS/x86_64/debug/tree/Packages/a/acl-debuginfo-2.2.53-1.el8.1.x86_64.rpm`

This is done so a gateway can serve the repository with directory listings.

For every time we add/remove a package or change configuration the full repository is regenerated.
