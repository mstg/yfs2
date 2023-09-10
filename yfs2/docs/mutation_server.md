### mutation_server

This component is responsible for all changes that are going to be made to all repositories.

The process should be as follows:
* Client starts a new transaction using StartTransaction
  * This returns a transaction ID and the transaction is valid for an hour
* Client starts streaming RPM chunks using UploadRpm
* If module RPM, then client uploads module metadata using UploadModuleMetadata
  * All module artifacts MUST be uploaded before calling UploadModuleMetadata
  * If module RPMs are uploaded but no module metadata is uploaded, then the transaction will fail
* Client calls CommitTransaction
  * This will commit the transaction and make the changes visible to all clients

Internally this should happen:
* After StartTransaction is called, a new etcd lease is acquired for `/transactions/<transaction_id>`
  * This lease is renewed every 30 seconds
